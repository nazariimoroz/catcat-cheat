#include <Windows.h>
#include "gui.h"

#include <chrono>
#include <imconfig.h>
#include <imgui.h>
#include <iostream>
#include <ostream>
#include <thread>
#include <imgui/backends/imgui_impl_dx9.h>
#include <imgui/backends/imgui_impl_win32.h>
#include <glm/glm.hpp>

#include "matrix3x4.h"
#include "source2sdk/client/CBodyComponent.hpp"
#include "source2sdk/client/CGameSceneNode.hpp"
#include "source2sdk/client/CPlayer_CameraServices.hpp"
#include "source2sdk/entity2/CEntityIdentity.hpp"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(
	HWND window,
	UINT message,
	WPARAM wideParameter,
	LPARAM longParameter
);

LRESULT CALLBACK WindowProcess(
	HWND window,
	UINT message,
	WPARAM wideParameter,
	LPARAM longParameter)
{
	if (ImGui_ImplWin32_WndProcHandler(window, message, wideParameter, longParameter))
		return true;

	switch (message)
	{
	case WM_CREATE:
		{
			SetWindowLong(window, GWL_EXSTYLE, GetWindowLong(window, GWL_EXSTYLE) | WS_EX_LAYERED);

			SetLayeredWindowAttributes(window, RGB(255, 255, 255), 0, LWA_COLORKEY);

			std::cout << "[overlay] Window created successfully" << std::endl;
			Beep(500, 100);
			break;
		}

	case WM_SIZE: {
		if (gui::device && wideParameter != SIZE_MINIMIZED)
		{
			gui::presentParameters.BackBufferWidth = LOWORD(longParameter);
			gui::presentParameters.BackBufferHeight = HIWORD(longParameter);
			gui::ResetDevice();
		}
	}return 0;

	case WM_SYSCOMMAND: {
		if ((wideParameter & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
	}break;

	case WM_DESTROY: {
		PostQuitMessage(0);
	}return 0;

	case WM_LBUTTONDOWN: {
		gui::position = MAKEPOINTS(longParameter); // set click points
	}return 0;

	case WM_MOUSEMOVE: {
		if (wideParameter == MK_LBUTTON)
		{
			const auto points = MAKEPOINTS(longParameter);
			auto rect = ::RECT{ };

			GetWindowRect(gui::window, &rect);

			rect.left += points.x - gui::position.x;
			rect.top += points.y - gui::position.y;

			if (gui::position.x >= 0 &&
				gui::position.x <= gui::WIDTH &&
				gui::position.y >= 0 && gui::position.y <= 19)
				SetWindowPos(
					gui::window,
					HWND_TOPMOST,
					rect.left,
					rect.top,
					0, 0,
					SWP_SHOWWINDOW | SWP_NOSIZE | SWP_NOZORDER
				);
		}

	}return 0;

	}

	return DefWindowProc(window, message, wideParameter, longParameter);
}

void gui::CreateHWindow(const char* draw_on_windows, const char* windowName) noexcept
{
	dow_hwnd = FindWindowA(NULL, draw_on_windows);
	if(!dow_hwnd)
		return;

	RECT rect;
	GetWindowRect(dow_hwnd, &rect);

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowProcess;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = reinterpret_cast<HINSTANCE>(GetWindowLongA(dow_hwnd, -6));
	windowClass.hIcon = 0;
	windowClass.hCursor = 0;
	windowClass.hbrBackground = WHITE_BRUSH;
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = "class001";
	windowClass.hIconSm = 0;

	RegisterClassEx(&windowClass);

	X = rect.left;
	Y = rect.top;
	WIDTH = rect.right - rect.left;
	HEIGHT = rect.bottom - rect.top;
	std::cout << X << " " << Y << " " << WIDTH << " " << HEIGHT << std::endl;
	window = CreateWindowEx(
		WS_EX_TRANSPARENT | WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW,
		"class001",
		windowName,
		WS_POPUP,
		X,
		Y,
		WIDTH,
		HEIGHT,
		0,
		0,
		windowClass.hInstance,
		0
	);

	SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	ShowWindow(window, SW_SHOWDEFAULT);
	UpdateWindow(window);
}

void gui::DestroyHWindow() noexcept
{
	DestroyWindow(window);
	UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
}

bool gui::CreateDevice() noexcept
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	if (!d3d)
		return false;

	ZeroMemory(&presentParameters, sizeof(presentParameters));

	presentParameters.Windowed = TRUE;
	presentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	presentParameters.EnableAutoDepthStencil = TRUE;
	presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	presentParameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	const auto result = d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		window,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&presentParameters,
		&device);
	if (result != D3D_OK)
	{
		return false;
	}

	return true;
}

void gui::ResetDevice() noexcept
{
	ImGui_ImplDX9_InvalidateDeviceObjects();

	const auto result = device->Reset(&presentParameters);

	if (result == D3DERR_INVALIDCALL)
		IM_ASSERT(0);

	ImGui_ImplDX9_CreateDeviceObjects();
}

void gui::DestroyDevice() noexcept
{
	if (device)
	{
		device->Release();
		device = nullptr;
	}

	if (d3d)
	{
		d3d->Release();
		d3d = nullptr;
	}
}

void gui::CreateImGui() noexcept
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ::ImGui::GetIO();

	io.IniFilename = NULL;

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX9_Init(device);
}

void gui::DestroyImGui() noexcept
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void gui::BeginRender() noexcept
{
	RECT rect;
	GetWindowRect(dow_hwnd, &rect);
	SetWindowPos(window, HWND_TOPMOST, rect.left, rect.top, 0, 0, SWP_NOSIZE);
	ShowWindow(window, SW_SHOWDEFAULT);
	UpdateWindow(window);

	MSG message;
	while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);

		if (message.message == WM_QUIT)
		{
			isRunning = !isRunning;
			return;
		}
	}

	// Start the Dear ImGui frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void gui::EndRender() noexcept
{
	ImGui::EndFrame();

	device->SetRenderState(D3DRS_ZENABLE, FALSE);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	device->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);

	device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(255, 255, 255, 0), 1.0f, 0);

	if (device->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		device->EndScene();
	}

	const auto result = device->Present(0, 0, 0, 0);

	// Handle loss of D3D9 device
	if (result == D3DERR_DEVICELOST && device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		ResetDevice();
}

std::tuple<float, float, float, bool> world_to_screen(float in_x, float in_y, float in_z, Urho3D::Matrix3x4* mtx)
{
	float _x = mtx->m00_ * in_x + mtx->m01_ * in_y + mtx->m02_ * in_z + mtx->m03_;
	float _y = mtx->m10_ * in_x + mtx->m11_ * in_y + mtx->m12_ * in_z + mtx->m13_;

	float w = mtx->m30_ * in_x + mtx->m31_ * in_y + mtx->m32_ * in_z + mtx->m33_;

	bool facing = false;
	if (w < 0.001f)
	{
		facing = false;
		_x *= 100000;
		_y *= 100000;
	}
	else
	{
		facing = true;
		float invw = 1.0f / w;
		_x *= invw;
		_y *= invw;
	}

	_x = 0.5f * (1.0f + _x) * gui::WIDTH;
	_y = 0.5f * (1.0f - _y) * gui::HEIGHT;

	auto visible{ (_x >= 0 && _x <= gui::WIDTH) &&
		_y >= 0 && _y <= gui::HEIGHT };
	if (!facing || !visible)
	{
		_x = -640;
		_y = -640;
		return {0,0,0,false};
	}

	return { _x, _y, w, true };
}

void gui::Render(SomeInfo some_info) noexcept
{
	ImGui::SetNextWindowPos({ 0, 0 });
	ImGui::SetNextWindowSize({ static_cast<float>(WIDTH), static_cast<float>(HEIGHT) });
	ImGui::Begin(
		"AAA",
		&isRunning,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoBackground |
		ImGuiWindowFlags_NoTitleBar
	);

	auto& local_player = *std::ranges::find_if(some_info.pawns, [&](auto& p)
	{
		return p.ex_controller->m_bIsLocalPlayerController;
	});

	for(auto& i : some_info.pawns)
	{
		struct GG
		{
			float x;
			float y;
			float z;
		};

		if(i.ex_controller->m_iTeamNum == local_player.ex_controller->m_iTeamNum)
			continue;

		if(i.ex_pawn->m_CBodyComponent == nullptr)
			continue;
		ex::var bc { i.ex_pawn->m_CBodyComponent, std::make_tuple(
			&source2sdk::client::CBodyComponent::m_pSceneNode
		) };

		if(bc->m_pSceneNode == nullptr)
			continue;
		ex::var scene_node { bc->m_pSceneNode, std::make_tuple(
			&source2sdk::client::CGameSceneNode::m_nodeToWorld
		) };

		if(i.ex_pawn->m_pEntity == nullptr)
			continue;
		ex::var pawn_entity { i.ex_pawn->m_pEntity, std::make_tuple(
			&source2sdk::entity2::CEntityIdentity::m_name
		) };

		ex::var<ex::str_t> pawn_name = EX_BYTES_TO_PTR(pawn_entity->m_name);

		float x = *((float*)scene_node->m_nodeToWorld);
		float y = *((float*)scene_node->m_nodeToWorld + 1);
		float z = *((float*)scene_node->m_nodeToWorld + 2);
		auto [a, b, c, is_ok] = world_to_screen(x, y, z, some_info.matrix.get());
		if(is_ok)
		{
			float viewingAngle = atanf(HEIGHT / ((some_info.view->fov / 43.805f) * c));
			float h = 160.f * tanf(viewingAngle);
			float w = h * 0.3f;

			float alpha = 200.f / h;

			ImGui::GetWindowDrawList()->AddRect(
				ImVec2{ a - w, b - h },
				ImVec2{ a + w, b},
				ImColor(255, 0, 0, 255),
				0,
				ImDrawFlags_None,
				1.f);

			if(c > 500.f)
			{
				ImGui::GetWindowDrawList()->AddText(
					ImVec2{ a + w + 10 / alpha, b - h },
					ImColor(255, 0, 0, 255),
					c_heroname_to_realname(pawn_name->str()).c_str());
			}

			/*
			ImGui::GetWindowDrawList()->AddRectFilled(
				ImVec2{ a + w + 5 / alpha, b },
				ImVec2{ a + w + 10 / alpha, b - h},
				ImColor(255, 0, 0, 255));

			ImGui::GetWindowDrawList()->AddRectFilled(
				ImVec2{ a + w + 5 / alpha, b - ((float)i.ex_pawn->m_iHealth / (float)i.ex_pawn->m_iMaxHealth) * h },
				ImVec2{ a + w + 10 / alpha, b },
				ImColor(0, 255, 0, 255));
				*/

			ImGui::GetWindowDrawList()->AddLine(
				ImVec2{ a - w, b - ((float)i.ex_pawn->m_iHealth / (float)i.ex_pawn->m_iMaxHealth) * h },
				ImVec2{ a - w, b },
				ImColor(0, 255, 0, 255),
				1.f);

			ImGui::GetWindowDrawList()->AddCircle(
				ImVec2{a, b},
				5,
				ImColor(0, 255, 0, 255));
		}
	}

	ImGui::End();
}

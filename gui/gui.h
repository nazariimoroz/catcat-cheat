#pragma once
#include <d3d9.h>
#include <type.h>

#include "matrix3x4.h"
#include "source2sdk/client/C_CitadelPlayerPawn.hpp"

struct SomeInfo
{
	Type<Urho3D::Matrix3x4> matrix;
	std::vector<player_t> pawns;
	Type<ViewRender> view;
};

namespace gui
{
	// constant window size
	inline int X = 500;
	inline int Y = 300;

	inline int WIDTH = 500;
	inline int HEIGHT = 300;

	// when this changes, exit threads
	// and close menu :)
	inline bool isRunning = true;

	// winapi window vars
	inline HWND window = nullptr;
	inline HWND dow_hwnd = nullptr;
	inline WNDCLASSEX windowClass = { };

	// points for window movement
	inline POINTS position = { };

	// direct x state vars
	inline PDIRECT3D9 d3d = nullptr;
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline D3DPRESENT_PARAMETERS presentParameters = { };

	// handle window creation & destruction
	void CreateHWindow(const char* draw_on_windows, const char* windowName) noexcept;
	void DestroyHWindow() noexcept;

	// handle device creation & destruction
	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	// handle ImGui creation & destruction
	void CreateImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;
	void Render(SomeInfo some_info) noexcept;
}

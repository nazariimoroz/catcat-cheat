#pragma once
#include <d3d9.h>
#include <type.h>

#include <vector>

#include "matrix3x4.h"
#include "source2sdk/client/C_CitadelPlayerPawn.hpp"

struct SomeInfo
{
	ex::var<Urho3D::Matrix3x4> matrix;

	ex::var<ViewRender> view;
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

	inline bool show_menu = false;

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

	bool is_dd_activated();

	// handle window creation & destruction
	bool FindDowWindow(const char* dow_name);
	void CreateHWindow(const char* windowName) noexcept;
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
	void Render(std::vector<player_t>& players_list, player_t& local_player) noexcept;

	std::tuple<xyz_t, bool> world_to_screen(xyz_t pos, Urho3D::Matrix3x4* mtx);
}

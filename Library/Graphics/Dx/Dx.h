#pragma once
#include <d3d9.h>
class Dx
{
public:
	
private:
	IDirect3D9* g_direct3D = nullptr;// Direct3D9オブジェクトのポインタを保持する
	IDirect3DDevice9* g_device = nullptr;// Direct3D9デバイスのポインタを保持する
	D3DPRESENT_PARAMETERS g_params = {};

};
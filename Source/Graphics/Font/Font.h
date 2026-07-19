#pragma once
//#include <d3d9.h>
#include <d3dx9.h>  

class Font
{
public:
    bool Init(IDirect3DDevice9* device);
    void Draw(const char* text, int x, int y);
    void Release();

private:
    ID3DXFont* font = nullptr;
};
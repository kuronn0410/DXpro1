#include "Font.h"   

bool Font::Init(IDirect3DDevice9* device)
{
    HRESULT result = D3DXCreateFontA(
        device,
        32,                 // 文字の高さ
        0,                  // 文字幅。0で自動
        FW_NORMAL,          // 太さ
        1,                  // ミップマップ数
        FALSE,              // 斜体にするか
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        "Arial",            // フォント名
        &font
    );

    return SUCCEEDED(result);
}

void Font::Draw(const char* text, int x, int y)
{
    if (font == nullptr || text == nullptr)
    {
        return;
    }

    RECT rect = {
        x,
        y,
        x + 500,
        y + 100
    };

    font->DrawTextA(
        nullptr,
        text,
        -1,
        &rect,
        DT_LEFT | DT_TOP | DT_NOCLIP,
        D3DCOLOR_ARGB(255, 255, 255, 255)
    );
}


void Font::Release()
{
	if (font)
	{
		font->Release();
		font = nullptr;
	}
}
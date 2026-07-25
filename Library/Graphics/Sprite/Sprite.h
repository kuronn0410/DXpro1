#pragma once
#include <d3dx9.h>

namespace Library
{
	namespace Graphics
	{
		class Sprite
		{
		public:
			bool Init(IDirect3DDevice9* g_device, const char* filePath);
			void Draw(float posX, float posY, float scaleX, float scaleY);
			void Release();
			const D3DSURFACE_DESC& GetImageInfo() const;
			float scaleX = 0.0f;
			float scaleY = 0.0f;

			/*float centerX = 0.0f;
			float centerY = 0.0f;*/
		private:
			D3DSURFACE_DESC imageInfo = {};
			IDirect3DTexture9* texture = nullptr;
			//スプライトのアドレスを保持する変数
			ID3DXSprite* sprite = nullptr;


		};
	}
}


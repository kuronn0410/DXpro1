//main.h
#pragma once
#include "Scene/SceneManager.h"

int APIENTRY WinMain(HINSTANCE hWnd, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);//ウィンドウ用メイン関数
void Update(SceneManager& sceneManager);//更新関数
void Draw(SceneManager& sceneManager);//描画関数
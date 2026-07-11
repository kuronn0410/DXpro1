#include "Input.h"
#include <Windows.h>

//SHORT GetAsyncKeyState(int vKey);
//キーの状態を保持する配列
//bool型の要素を256個持つ配列
bool nowKey[256];
bool oldKey[256];

void InputUpdate()
{
	for (int i = 0; i < 256; i++)
	{
		//前のキーの状態を保存
		oldKey[i] = nowKey[i];
		//// 現在のキーの状態を取得してboolで保存
		nowKey[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
	}
}

bool GetKey(int key)
{
	//キーが押されているかどうかを返す
	return nowKey[key];
}
bool GetKeyDown(int key)
{
	//前のキーがなくて、今のキーがある場合にtrueを返す
	return nowKey[key] && !oldKey[key];
}
bool GetKeyUp(int key)
{
	//前のキーがあって、今のキーがない場合にtrueを返す
	return  !nowKey[key] && oldKey[key];
}
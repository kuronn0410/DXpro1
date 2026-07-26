#pragma once
#include <cstdio>

namespace Library
{
	namespace DebugTools
	{
		void DebugLog(const char* message)
		{
			// デバッグメッセージを出力する処理を実装
			// ここでは標準出力に出力する例を示す
			printf("[DEBUG] %s\n", message);
		}
	}
}
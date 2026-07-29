#include "Debug.h"
#include <Windows.h>
#include <cstdio>


namespace Library
{
	namespace DebugTools
	{
		void DebugLog(const char* message)
		{
			char buffer[512];

			sprintf_s(
				buffer,
				"[DEBUG] %s\n",
				message
			);

			OutputDebugStringA(buffer);
		}
	}
}

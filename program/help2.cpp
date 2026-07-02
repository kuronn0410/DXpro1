#pragma region ヘッダ
#include "help1.h"
#pragma endregion

#pragma region デバッグ用関数定義
//真（0以外）ならば停止
bool break_point_true(bool b)
{
	if (b)
		return true;//ここにブレイクポイントをつける
	return false;
}


//偽（0）ならば停止
bool break_point_false(bool b)
{
	if (!b)
		return false;//ここにブレイクポイントをつける
	return true;
}
#pragma endregion

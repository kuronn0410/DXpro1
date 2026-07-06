#pragma once

class Timer
{
    public:
		//タイマーを開始する関数
        void Start(float seconds);
		//タイマーを更新する関数UPdateされてる関数内で呼び出す必要がある
        void Update(float deltaTime);
		//タイマーが終了したかどうかを返す関数
        bool IsFinished() const;

    private:
        float currentTime = 0.0f;
        float endTime = 0.0f;
};
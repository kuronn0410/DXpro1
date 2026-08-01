#pragma once
#include "Game/Enemy/Data/StageEnemyData.h"
#include "Game/Enemy/Data/StageEnemyEntry.h"	
#include "Game/StartPos.h"
#include <unordered_map>
class StageEnemyData
{
public:
	bool Initialize();
	void CreateStageEnemyData();
	/*const StageEnemyEntry* SearchStageEnemy(int stage, int enemyType) const;*/
	const std::unordered_map<int, StageEnemyEntry>* GetStageEnemyMap(int stage) const;


private :
	std::unordered_map<int, StageEnemyEntry> stage1EnemyMap;
	std::unordered_map<int, StageEnemyEntry> stage2EnemyMap;

	StageEnemyEntry stage1EnemyData[3] = {
		{	 
			EnemyType::VoidKnight, 
			1.0f, 
			1.0f, 
			1.0f, 
			{
				{  40.0f,  20.0f },
				{ 240.0f, 160.0f },
			}
		},
		{ 
			EnemyType::JadeDrake, 
			1.2f, 
			1.1f, 
			1.3f, 
			{
				{ 240.0f,  20.0f },
				{ 440.0f,  20.0f },
				{  40.0f, 160.0f },
			
			}	
		},
		{ 
			EnemyType::Scavenger, 
			0.8f, 
			0.9f, 
			0.7f, 
			{	
				{ 440.0f, 160.0f },
			}
		}
	};

	StageEnemyEntry stage2EnemyData[3] = {
		{ 
			EnemyType::VoidKnight, 
			1.0f, 
			1.0f, 
			1.0f, 
			{
				{   0.0f,  20.0f },
				{ 160.0f,  20.0f },
				{ 320.0f,  20.0f },
				{ 480.0f,  20.0f },
				{   0.0f, 160.0f },
			}
			
		},
		{ 
			EnemyType::JadeDrake, 
			1.2f, 
			1.1f, 
			1.3f, 
			{
				{ 160.0f, 160.0f },
				{ 480.0f, 160.0f }
			}
		},
		{ 
			EnemyType::Scavenger, 
			0.8f, 
			0.9f, 
			0.7f, 
			{
				{ 300.0f, 200.0f }
			}
		}
	};

};
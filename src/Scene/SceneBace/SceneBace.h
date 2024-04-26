#pragma once

constexpr char DISTANCE_SAVE_DATA[] = { "data/SaveData/AdvancedDistance.txt" };
constexpr char MAX_DISTANCE_SAVE_DATA[] = { "data/SaveData/MaxAdvancedDistance.txt" };

class SceneBace
{
public:
	virtual void Init() = 0;
	virtual void Step() = 0;
	virtual void Draw() = 0;
};
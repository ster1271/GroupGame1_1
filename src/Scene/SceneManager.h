#pragma once
#include "SceneTitle/SceneTitle.h"
#include "ScenePlay/ScenePlay.h"
#include "SceneResult/SceneResult.h"

class SceneManager
{
private:
	SceneBace* scene;

public:
	SceneManager();

	void Main();
};
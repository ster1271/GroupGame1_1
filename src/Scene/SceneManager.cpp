#include "DxLib.h"
#include "SceneManager.h"
#include "../Common.h"

SceneManager::SceneManager()
{
	scene = nullptr;
}

void SceneManager::Main()
{
	switch (g_current_scene_ID) {
	case Title: {
		if (scene != nullptr) {
			delete scene;
		}
		scene = new SceneTitle;
		scene->Init();
		g_current_scene_ID = LOOP;
		break;
	}
	case Play: {
		if (scene != nullptr) {
			delete scene;
		}
		scene = new ScenePlay;
		scene->Init();
		g_current_scene_ID = LOOP;
		break;
	}
	case Result: {
		if (scene != nullptr) {
			delete scene;
		}
		scene = new SceneResult;
		scene->Init();
		g_current_scene_ID = LOOP;
		break;
	}
	default: {
		scene->Step();
		scene->Draw();

		break;
	}
	}
}
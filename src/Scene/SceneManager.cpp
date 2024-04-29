#include "DxLib.h"
#include "SceneManager.h"
#include "../Common.h"
#include "../Sound/Sound.h"

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
		Sound::StopBGM(Result_BGM);
		Sound::PlayBGM(Title_BGM);
		g_current_scene_ID = LOOP;
		break;
	}
	case Play: {
		if (scene != nullptr) {
			delete scene;
		}
		scene = new ScenePlay;
		scene->Init();
		Sound::StopBGM(Title_BGM);
		Sound::PlayBGM(Play_BGM);
		g_current_scene_ID = LOOP;
		break;
	}
	case Result: {
		if (scene != nullptr) {
			delete scene;
		}
		scene = new SceneResult;
		scene->Init();
		Sound::StopBGM(Play_BGM);
		Sound::PlayBGM(Result_BGM);
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
#pragma once
#include <string>

using namespace std;

#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720		// Y�����̉�ʃT�C�Y���w��

void InitGame();
void FinGame();

enum SceneID
{
	Title,
	Play,
	Result,

	LOOP
};

extern SceneID g_current_scene_ID;
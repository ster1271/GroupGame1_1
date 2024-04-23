#pragma once

//�ݒ�t���[�����[�g�i60FPS�j
#define FRAME_RATE (60)

//�P�t���[���̎��ԁi�~���b�j
#define FRAME_TIME (1000/FRAME_RATE)

// FPS�̕\��
#define DRAW_FPS "FPS[%.2f]"

//�t���[�����[�g���
struct FrameRateInfo
{
	int currentTime;	//���݂̎���
	int LastFrameTime;	//�O��̃t���[�����s���̎���
	int count;			//�t���[���J�E���g�p
	int calcFpsTime;	//FPS���v�Z��������
	float fps;			//�v������FPS�i�\���p�j
};

//�t���[�����[�g���ϐ�
extern FrameRateInfo frameRateInfo;

//FPS�v�Z
void CalcFPS();

//FPS�\���i�f�o�b�N�p�j
void DrawFPS();
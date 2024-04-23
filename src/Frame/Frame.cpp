#include "DxLib.h"
#include "../Common.h"
#include "Frame.h"

//���C�����[�v�̍ŏ��ɂ���
/*
//=====================================================================
Sleep(1);	//�V�X�e���ɏ�����Ԃ�

//���݂̎��Ԃ��擾
frameRateInfo.currentTime = GetNowCount();

//�ŏ��̃��[�v�Ȃ�A
//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
if (frameRateInfo.calcFpsTime == 0.0f)
{
	frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	frameRateInfo.fps = (float)FRAME_RATE;
}

// ���݂̎��Ԃ��A�O��̃t���[�������
// 100/60�~���b�i1/60�b�j�ȏ�o�߂��Ă����珈�������s����
if (frameRateInfo.currentTime - frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.LastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;
//=====================================================================
*/

//�t���b�v�֐��̏�ɂ���
/*
//FPS�v�Z
CalcFPS();

//FPS�\��
DrawFPS();
*/

FrameRateInfo frameRateInfo;

void CalcFPS()
{
	//�O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//�O���FPS���v�Z�������Ԃ���
	//�P�b�ȏ�o�߂��Ă�����FPS���v�Z����
	if (difTime > 1000)
	{
		//�t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�������̂�float�ɃL���X�g
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPS�����߂�
		//���z�̐��l�� 60000 / 1000 �� 60 �ƂȂ�
		frameRateInfo.fps = frameCount / difTime;

		//�t���[�����[�g�J�E���g���N���A
		frameRateInfo.count = 0;

		//FPS���v�Z�������Ԃ��X�V
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

void DrawFPS()
{
	DrawFormatString(0, SCREEN_SIZE_Y - 15, GetColor(255,255,255), DRAW_FPS, frameRateInfo.fps);
}
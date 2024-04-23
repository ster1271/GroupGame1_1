#include "DxLib.h"
#include "Input.h"

char Input::currentKeyBuf[];
char Input::preKeyBuf[];

// �}�E�X�֘A�ϐ�

int Input::currentMouseBuf[];
int Input::preMouseBuf[];

void Input::InitInput()
{
	for (int i=0; i < KEY_BUF_LEN; i++)
	{
		currentKeyBuf[i] = '\0';
		preKeyBuf[i] = '\0';
	}
	for (int i = 0; i < MOUSE_BUF_LEN; i++)
	{
		currentMouseBuf[i] = 0;
		preMouseBuf[i] = 0;
	}
}

void Input::StepInput()
{
	for (int i = 0; i < KEY_BUF_LEN; i++)
		preKeyBuf[i] = currentKeyBuf[i];

	for (int i = 0; i < MOUSE_BUF_LEN; i++)
		preMouseBuf[i] = currentMouseBuf[i];

	GetHitKeyStateAll(currentKeyBuf);

	currentMouseBuf[0] = CheckMouse(MOUSE_INPUT_LEFT);
	currentMouseBuf[1] = CheckMouse(MOUSE_INPUT_RIGHT);
	currentMouseBuf[2] = CheckMouse(MOUSE_INPUT_MIDDLE);
}

//�������ꂽ
bool Input::IsKeyPush(int key_code)
{
	//�O�t���ŉ�����ĂȂ� ���� ���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1)
		return true;

	//������ĂȂ��̂� false
	return false;
}

//�����ꑱ���Ă���
bool Input::IsKeyKeep(int key_code)
{
	//�O�t���ł�����Ă��� ���� ���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

//�����ꂽ
bool Input::IsKeyRelease(int key_code)
{
	//�O�t���ŉ�����Ă��� ���� ���t���ŉ�����Ă��Ȃ�
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0)
		return true;

	return false;
}

//�P���ɉ�����Ă��邩
bool Input::IsKeyDown(int key_code)
{
	//���t���ŉ�����Ă���i�O�t���̏�Ԃ͊֌W�Ȃ��j
	if (currentKeyBuf[key_code] == 1)
		return true;

	return false;
}

int Input::CheckMouse(int mouse_code)
{
	if ((GetMouseInput() & mouse_code) != 0){
		return 1;
	}
	else {
		return 0;
	}
}

int Input::ChangeMouseCode(int mouse_code)
{
	if (mouse_code == MOUSE_INPUT_LEFT)
		return 0;
	if (mouse_code == MOUSE_INPUT_RIGHT)
		return 1;
	if (mouse_code == MOUSE_INPUT_MIDDLE)
		return 2;

	return 3;
}

//�������ꂽ
bool Input::IsMousePush(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//�O�t���ŉ�����ĂȂ� ���� ���t���ŉ�����Ă���
	if (preMouseBuf[mouse_code] == 0 && currentMouseBuf[mouse_code] == 1)
		return true;

	//������ĂȂ��̂� false
	return false;
}

//�����ꑱ���Ă���
bool Input::IsMouseKeep(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//�O�t���ł�����Ă��� ���� ���t���ŉ�����Ă���
	if (preMouseBuf[mouse_code] == 1 && currentMouseBuf[mouse_code] == 1)
		return true;

	return false;
}

//�����ꂽ
bool Input::IsMouseRelease(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//�O�t���ŉ�����Ă��� ���� ���t���ŉ�����Ă��Ȃ�
	if (preMouseBuf[mouse_code] == 1 && currentMouseBuf[mouse_code] == 0)
		return true;

	return false;
}

//�P���ɉ�����Ă��邩
bool Input::IsMouseDown(int mouse_code)
{
	mouse_code = ChangeMouseCode(mouse_code);

	if (mouse_code == 3)
		return false;

	//���t���ŉ�����Ă���i�O�t���̏�Ԃ͊֌W�Ȃ��j
	if (currentMouseBuf[mouse_code] == 1)
		return true;

	return false;
}
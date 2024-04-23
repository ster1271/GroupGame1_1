#include "DxLib.h"
#include "MyMath.h"
#include <math.h>

//�����̍���Ԃ�
float GetDefLen_f(float pos_A, float pos_B) { return fabsf(pos_A - pos_B); }

// ��
bool NearyEqual(float num1, float num2, float error_num)
{
	if (fabsf(num1 - num2) < error_num)
		return true;

	return false;
}

//������Ԃ�
int GetNumLen(int num)
{
	int len = 0;
	if (num == 0)
		return 1;
	else
		while (num != 0){
			num /= 10;
			len++;
		}

	return len;
}

//���ݒn����ړI�n�܂Ŏw��̑����œ����x�N�g��
VECTOR GetVector(VECTOR vec_here, VECTOR vec_dis, float speed)
{
	//���ݒn����ړI�n�̃x�N�g��
	VECTOR sub_vec = VSub(vec_dis, vec_here);

	//���K��
	VECTOR nor_vec = VNorm(sub_vec);

	//�擾����x�N�g���̑傫��
	VECTOR mul_vec = VScale(nor_vec, speed);

	return mul_vec;
}

//�O��
float VCross2D(VECTOR vec1, VECTOR vec2)
{
	return (vec1.x * vec2.y - vec1.y * vec2.x);
}

//�x�N�g���̂Ȃ��p
float AngleOf2Vector(VECTOR vec1, VECTOR vec2,bool degree_switch)
{
	//�x�N�g���̒���
	double len1 = VSize(vec1);
	double len2 = VSize(vec2);

	//cos��
	double cos_sita = VDot(vec1, vec2) / (len1 * len2);

	//��
	double sita = acos(cos_sita);

	//�p�x
	if (degree_switch)
		sita = sita * 180.0 / DX_PI;

	return (float)sita;
}
#pragma once
#include "DxLib.h"

//�����̍���Ԃ�
float GetDefLen_f(float pos_A, float pos_B);
//��
bool NearyEqual(float num1, float num2, float error_num = 1.0f);

//������Ԃ�
int GetNumLen(int num);

//----------------------------------------------------------------------------------------------------------
//�x�N�g��
/*
VAdd( VECTOR vec1, VECTOR vec2 );		���Z
VSub( VECTOR vec1, VECTOR vec2 );		���Z
VScale( VECTOR vec, float Scale );		�萔�{
VSize( VECTOR vec );					�T�C�Y�擾
VNorm( VECTOR vec );					���K��
VDot( VECTOR vec1, VECTOR vec2 );		����
VCross( VECTOR vec1, VECTOR vec2 );		�O��3D
*/

//�O��2D
float VCross2D(VECTOR vec1, VECTOR vec2);

//���ݒn����ړI�n�܂Ŏw��̑����œ����x�N�g��
VECTOR GetVector(VECTOR vec_here, VECTOR vec_dis, float speed = 1.0f);

//�x�N�g���̂Ȃ��p
float AngleOf2Vector(VECTOR vec1, VECTOR vec2, bool degree_switch = false);
//----------------------------------------------------------------------------------------------------------
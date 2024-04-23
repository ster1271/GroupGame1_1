#include "DxLib.h"
#include "Collision.h"
#include <math.h>
#include "../MyMath/MyMath.h"

//�������Ă���Ƃ��ǂ̕������瓖�����Ă��邩
//�O�C�P�C�Q�C�R�F�E�A���A���A��
int Collision::GetHitDirection2D(VECTOR objects, int size_x1, int size_y1,
								VECTOR use, int size_x2, int size_y2,
								float& overlap_x, float& overlap_y)
{
	int plas_x = 0;
	int plas_y = 0;

	if (objects.x < use.x) {
		overlap_x = objects.x + size_x1 - use.x;
		plas_x = 0;
	}
	else {
		overlap_x = use.x + size_x2 - objects.x;
		plas_x = 2;
	}

	if (objects.y < use.y) {
		overlap_y = objects.y + size_y1 - use.y;
		plas_y = 1;
	}
	else {
		overlap_y = use.y + size_y2 - objects.y;
		plas_y = 3;
	}
	
	if (overlap_x < overlap_y)
		return plas_x;
	else
		return plas_y;
}

//��`�̓����蔻��
bool Collision::IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
	if (x1<x2 + w2 &&
		x1 + w1>x2 &&
		y1<y2 + h2 &&
		y1 + h1>y2)
	{
		return true;
	}

	return false;
}

//�~�̓����蔻��
bool Collision::IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2)
{
	if ((r1 + r2) * (r1 + r2) > (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
	{
		return true;
	}

	return false;
}

//�~�Ƌ�`�̓����蔻��
bool Collision::IsHitCircleRect(float x1, float y1, float r1, float x2, float y2, float w2, float h2)
{
	//��`�� X���ɉ~�̔��a��������
	if (x1 > x2 &&
		x1<x2 + w2 &&
		y1>y2 - r1 &&
		y1 < y2 + h2 + r1)
		return true;

	//��`�� Y���ɉ~�̔��a��������
	if (x1 > x2 - r1 &&
		x1<x2 + w2 + r1 &&
		y1>y2 &&
		y1 < y2 + h2)
		return true;

	double X1 = (double)(x2 - x1);
	double X2 = (double)(x2 + w2 - x1);
	double Y1 = (double)(y2 - y1);
	double Y2 = (double)(y2 + h2 - y1);

	//�l�p
	if (X1 * X1 + Y1 * Y1 < r1 * r1)
		return true;

	if (X2 * X2 + Y1 * Y1 < r1 * r1)
		return true;

	if (X2 * X2 + Y2 * Y2 < r1 * r1)
		return true;

	if (X1 * X1 + Y2 * Y2 < r1 * r1)
		return true;

	return false;
}

// ��`�Ɠ_�̓����蔻��
bool Collision::IsHitRectPoint(float rect_x, float rect_y, float rect_w, float rect_h, float point_pos_x, float point_pos_y)
{
	if (point_pos_x > rect_x &&
		point_pos_x< rect_x + rect_w &&
		point_pos_y>rect_y &&
		point_pos_y < rect_y + rect_h) {
		return true;
	}

	return false;
}

//�~�Ɠ_�̓����蔻��
bool Collision::IsHitCirclePoint(float circcle_pos_x, float circcle_pos_y, float circle_len, float point_pos_x, float point_pos_y)
{
	//�_�Ɖ~�̃x�N�g��
	float vector_x = point_pos_x - circcle_pos_x;
	float vector_y = point_pos_y - circcle_pos_y;

	//�x�N�g���̒����Z�o
	float distance = (float)sqrt((double)((double)pow((double)vector_x, 2) + (double)pow((double)vector_y, 2)));

	if (distance < circle_len) {
		return true;
	}
	return false;
}

//�~�Ɛ��̓����蔻��
bool Collision::IsHitCircleLine(float circle_x, float circle_y, float circle_len,
	float line_start_x, float line_start_y, float line_end_x, float line_end_y)
{
	//�x�N�g���쐬
	//�n�_����~�̒��S
	float vector_start_circle_x = circle_x - line_start_x;
	float vector_start_circle_y = circle_y - line_start_y;
	//�I�_����~�̒��S
	float vector_end_circle_x = circle_x - line_end_x;
	float vector_end_circle_y = circle_y - line_end_y;
	//�n�_����I�_
	float vector_start_end_x = line_end_x - line_start_x;
	float vector_start_end_y = line_end_y - line_start_y;
	//�n�_����I�_�̃x�N�g���̑傫��
	float vector_start_end_size = (float)sqrt((double)pow(vector_start_end_x, 2) + (double)pow(vector_start_end_y, 2));
	//�n�_����I�_�̒P�ʃx�N�g��
	float normal_vector_start_end_x = vector_start_end_x / vector_start_end_size;
	float normal_vector_start_end_y = vector_start_end_y / vector_start_end_size;


	//�����Ɖ~�̒��S�̍ŒZ����
	float distance_projection = vector_start_circle_x * normal_vector_start_end_y -
		normal_vector_start_end_x * vector_start_circle_y;

	if (fabsf(distance_projection) < circle_len) {
		//�������Ă���\������

		//�n�_����I�_�Ǝn�_����~�̒��S�̓���
		float dot_start_circle = vector_start_circle_x * vector_start_end_x +
			vector_start_circle_y * vector_start_end_y;
		//�n�_����I�_�ƏI�_����~�̒��S�̓���
		float dot_end_circle = vector_end_circle_x * vector_start_end_x +
			vector_end_circle_y * vector_start_end_y;
		//��̓��ς̏�Z���O�ȉ��Ȃ瓖�����Ă���
		if (dot_start_circle * dot_end_circle <= 0)
			return true;


		//�n�_�܂��͏I�_���~�̒��Ȃ瓖�����Ă���
		if (IsHitCirclePoint(circle_x, circle_y, circle_len, line_start_x, line_start_y))
			return true;
		if (IsHitCirclePoint(circle_x, circle_y, circle_len, line_end_x, line_end_y))
			return true;

	}
	//�������Ă��Ȃ�
	return false;
}
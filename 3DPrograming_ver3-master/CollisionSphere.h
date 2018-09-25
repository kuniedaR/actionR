//���E����������Obj3D�N���X
#pragma once
#include "Collision.h"
#include "Obj3D.h"
#include "DebugSphere.h"

class CollisionSphere : public Obj3D
{
private:
	//�R���W�������
	Collision::Sphere m_collision;
	//�R���W�����\���I�u�W�F�N�g
	std::unique_ptr<DebugSphere> m_obj;

public:
	//�R���W�������̐ݒ�֐�
	void SetCollision(Collision::Sphere sphere);

	//�R���W�������̏����֐�
	Collision::Sphere GetCollision();

	//�f�o�b�N�p�R���W�����\���֐�
	void DrawCollision();

};

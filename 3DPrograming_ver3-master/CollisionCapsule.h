//�J�v�Z����������Obj3D�N���X
#pragma once
#include "Collision.h"
#include "Obj3D.h"
#include "DebugCapsule.h"

class CollisionCapsule : public Obj3D
{
private:
	//�R���W�������
	Collision::Capsule m_collision;
	//�R���W�����\���I�u�W�F�N�g
	std::unique_ptr<DebugCapsule> m_obj;

public:
	//�R���W�������̐ݒ�֐�
	void SetCollision(Collision::Capsule capsule);

	//�R���W�������̏����֐�
	Collision::Capsule GetCollision();

	//�f�o�b�N�p�R���W�����\���֐�
	void DrawCollision();

};


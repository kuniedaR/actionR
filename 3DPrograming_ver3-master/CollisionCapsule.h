//�J�v�Z����������Obj3D�N���X
#pragma once
#include "Collision.h"
#include "Obj3D.h"
#include "DebugCapsule.h"
#include "GameDefine.h"

class CollisionCapsule : public Obj3D
{
private:
	//�R���W�������
	Collision::Capsule m_collision;
	//�R���W�����\���I�u�W�F�N�g
	std::unique_ptr<DebugCapsule> m_obj;

public:
	//�R���X�g���N�^
	CollisionCapsule();

	//�R���W�������̐ݒ�֐�
	void SetCollision(Collision::Capsule capsule);

	//�R���W�������̏����֐�
	Collision::Capsule GetCollision();

	//�f�o�b�N�p�R���W�����\���֐�
	void DrawCollision();

	GameDefine::ColliderTag Gettag() { return m_tag; }

protected:
	//�^�O
	GameDefine::ColliderTag m_tag;
};


#pragma once
#include "pch.h"
#include "CollisionCapsule.h"

//�e�N���X
class Bullet : public CollisionCapsule
{
public:
	enum MOVE
	{
		STOP,		//��~
		STRAIGHT,	//���i
	};

private:
	//����
	float m_direction;

	//�ړ��t���O
	MOVE m_moveFlag;

	// �e�̑��x
	DirectX::SimpleMath::Vector3 m_v;

	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//���e�̈ʒu
	DirectX::SimpleMath::Vector3 m_bulletPosition;

public:
	//�R���X�g���N�^
	Bullet();

	//�X�V
	bool Update(float elapsedTime) override;

	//�`��
	void Render() override;

	// �ړ�����֐�
	void Move(MOVE move);

	//�e�̈ʒu������������֐�
	void SetPosition(DirectX::SimpleMath::Vector3 pos) { m_position = pos; }

	DirectX::SimpleMath::Vector3 GetPosition();

	float GetDirection();

	void SetDirection(float direction);

};

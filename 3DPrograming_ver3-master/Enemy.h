#pragma once
#include "CollisionCapsule.h"

//�G�N���X
class Enemy : public CollisionCapsule
{
public:
	enum MOVE
	{
		STOP,		//��~
		FORWARD,	//�O�i
		BACK,		//��i
		RIGHT_TURN, //�E��]
		LEFT_TURN,  //����]
	};

private:
	//����
	float m_direction;

	//�ړ��t���O
	MOVE m_moveFlag;

public:
	//�R���X�g���N�^
	Enemy();

	//�X�V
	bool Update(float elapsedTime) override;

	//�`��
	void Render() override;

	// �ړ�����֐�
	void Move(MOVE move);

	DirectX::SimpleMath::Vector3 GetPosition();

	float GetDirection();

};


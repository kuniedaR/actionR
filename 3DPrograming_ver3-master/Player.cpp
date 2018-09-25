#include "pch.h"
#include "Player.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player()
	: m_direction(0.0f), m_moveFlag(STOP)
{

}

bool Player::Update(float elapsedTime)
{
	//���x
	Vector3 v;

	switch (m_moveFlag)
	{
	case FORWARD:		//�O�i
		v.z = -0.1f;
		break;
	case BACK:			//��i
		v.z = 0.1f;
		break;
	case RIGHT_TURN:	//�E��]
		m_direction -= XMConvertToRadians(2.0f);
		break;
	case LEFT_TURN:		//����]
		m_direction += XMConvertToRadians(2.0f);
		break;
	default:
		break;
	}

	//�v���C���[���ړ�������
	m_rotation = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 5.0f, 0.0f), m_direction);
	v = Vector3::Transform(v, m_rotation);
	m_position += v;

	//�ړ��t���O�����Z�b�g����	
	m_moveFlag = STOP;

	//	���[���h�s��̍쐬
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);


	return true;
}

void Player::Render()
{
	if (m_game && m_models)
	{
		//���f����`��
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());

		//�f�o�b�N�p�R���W�����̕\��
		//DrawCollision();
	}
}

void Player::Move(MOVE move)
{
	m_moveFlag = move;
}

DirectX::SimpleMath::Vector3 Player::GetPosition()
{
	return m_position;
}

float Player::GetDirection()
{
	return m_direction;
}

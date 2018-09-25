#include "pch.h"
#include "BulletE.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

BulletE::BulletE()
	: m_direction(0.0f), m_moveFlag(STOP)
{
	m_v = Vector3(0, 0, 0.3f);
}

bool BulletE::Update(float elapsedTime)
{
	//���x
	Vector3 v = m_v;

	//�e���ړ�������
	m_rotation = Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), m_direction);
	v = Vector3::Transform(v, m_rotation);
	m_position += v;

	//	���[���h�s��̍쐬
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);

	return true;
}

void BulletE::Render()
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

void BulletE::Move(MOVE move)
{
	m_moveFlag = move;
}

DirectX::SimpleMath::Vector3 BulletE::GetPosition()
{
	return m_position;
}

float BulletE::GetDirection()
{
	return m_direction;
}

void BulletE::SetDirection(float direction)
{
	m_direction = direction;
}
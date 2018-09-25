#include "pch.h"
#include "CollisionCapsule.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

void CollisionCapsule::SetCollision(Collision::Capsule capsule)
{
	//�R���W�������̐ݒ�
	m_collision = capsule;

	if (m_game)
	{
		//�f�o�b�N�p�R���W�������f��
		m_obj = std::make_unique<DebugCapsule>(m_game->GetDevice()
			, m_collision.a // ���ԕ��̐����̊J�n�_
			, m_collision.b // ���ԕ��̐����̏I���_
			, m_collision.r //���a
			);
	}

}

Collision::Capsule CollisionCapsule::GetCollision()
{
	//	�R���W���������[���h�s��ɂ��ړ�����
	Collision::Capsule capsule;
	capsule.a = Vector3::Transform(m_collision.a, m_world);
	capsule.b = Vector3::Transform(m_collision.b, m_world);
	capsule.r = m_collision.r;

	return capsule;
}

void CollisionCapsule::DrawCollision()
{
	if (m_game)
	{
		//�f�o�b�N�p�R���W�����̕`��
		m_obj->Draw(m_game->GetContext(), *m_game->GetStates()
			, m_world, m_game->GetView(), m_game->GetProjection());
	}
}

#include "pch.h"
#include "CollisionSphere.h"
#include "Game.h"

void CollisionSphere::SetCollision(Collision::Sphere sphere)
{
	//�R���W�������̐ݒ�
	m_collision = sphere;

	if (m_game)
	{
		//�f�o�b�N�p�R���W�������f��
		m_obj = std::make_unique<DebugSphere>(m_game->GetDevice()
											  , m_collision.c //���E���̒��S
											  , m_collision.r //���a
											  );
	}

}

Collision::Sphere CollisionSphere::GetCollision()
{
	Collision::Sphere sphere;

	// ���E���̒��S���W�����[���h�s��ɂ����W�ϊ�����
	sphere.c = DirectX::SimpleMath::Vector3::Transform(m_collision.c, m_world);
	sphere.r = m_collision.r;

	return sphere;
}

void CollisionSphere::DrawCollision()
{
	if (m_game)
	{
		//�f�o�b�N�p�R���W�����̕`��
		m_obj->Draw(m_game->GetContext(), *m_game->GetStates()
			, m_world, m_game->GetView(), m_game->GetProjection());
	}

}

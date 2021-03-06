#include "pch.h"
#include "Bullet.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Bullet::Bullet()
	: m_direction(0.0f), m_moveFlag(STOP)
{
	m_v = Vector3(0, 0, -0.3f);
}

bool Bullet::Update(float elapsedTime)
{
	//速度
	Vector3 v = m_v;

	//弾を移動させる
	m_rotation = Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), m_direction);
	v = Vector3::Transform(v, m_rotation);
	m_position += v;

	//	ワールド行列の作成
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);

	return true;
}

void Bullet::Render()
{
	if (m_game && m_models)
	{
		//モデルを描画
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());
	}
}

void Bullet::Move(MOVE move)
{
	m_moveFlag = move;
}

DirectX::SimpleMath::Vector3 Bullet::GetPosition()
{
	return m_position;
}

float Bullet::GetDirection()
{
	return m_direction;
}

void Bullet::SetDirection(float direction)
{
	m_direction = direction;
}

// プレイヤーの位置を所得する関数
void Bullet::SetTarget(DirectX::SimpleMath::Vector3 pos)
{
	m_target = pos;
}

DirectX::SimpleMath::Matrix Bullet::GetView()
{
	Matrix b = Matrix::CreateLookAt(m_bulletPosition, m_target, Vector3(0.0f, 1.0f, 0.0f));

	return b;
}

#include "pch.h"
#include "CollisionCapsule.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

void CollisionCapsule::SetCollision(Collision::Capsule capsule)
{
	//コリジョン情報の設定
	m_collision = capsule;

	if (m_game)
	{
		//デバック用コリジョンモデル
		m_obj = std::make_unique<DebugCapsule>(m_game->GetDevice()
			, m_collision.a // 中間部の線分の開始点
			, m_collision.b // 中間部の線分の終了点
			, m_collision.r //半径
			);
	}

}

Collision::Capsule CollisionCapsule::GetCollision()
{
	//	コリジョンをワールド行列により移動する
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
		//デバック用コリジョンの描画
		m_obj->Draw(m_game->GetContext(), *m_game->GetStates()
			, m_world, m_game->GetView(), m_game->GetProjection());
	}
}

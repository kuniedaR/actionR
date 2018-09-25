#include "pch.h"
#include "CollisionSphere.h"
#include "Game.h"

void CollisionSphere::SetCollision(Collision::Sphere sphere)
{
	//コリジョン情報の設定
	m_collision = sphere;

	if (m_game)
	{
		//デバック用コリジョンモデル
		m_obj = std::make_unique<DebugSphere>(m_game->GetDevice()
											  , m_collision.c //境界球の中心
											  , m_collision.r //半径
											  );
	}

}

Collision::Sphere CollisionSphere::GetCollision()
{
	Collision::Sphere sphere;

	// 境界球の中心座標をワールド行列により座標変換する
	sphere.c = DirectX::SimpleMath::Vector3::Transform(m_collision.c, m_world);
	sphere.r = m_collision.r;

	return sphere;
}

void CollisionSphere::DrawCollision()
{
	if (m_game)
	{
		//デバック用コリジョンの描画
		m_obj->Draw(m_game->GetContext(), *m_game->GetStates()
			, m_world, m_game->GetView(), m_game->GetProjection());
	}

}

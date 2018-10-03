#include "pch.h"
#include "Saber.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Saber::Saber(GameDefine::ColliderTag tag)
	:m_parentTag(tag)
{
	
}

bool Saber::Update()
{

	//	ワールド行列の作成
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);


	return true;
}

void Saber::Render()
{
	if (m_game && m_models)
	{
		//モデルを描画
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());

		//デバック用コリジョンの表示
		//DrawCollision();
	}
}

DirectX::SimpleMath::Vector3 Saber::GetPosition()
{
	return m_position;
}

//プレイヤーの位置を所得する関数
void Saber::SetTarget(DirectX::SimpleMath::Vector3 pos)
{
	m_target = pos;
}
//サーベルのビュー行列
DirectX::SimpleMath::Matrix Saber::GetView()
{
	Matrix s = Matrix::CreateLookAt(m_saberPosition, m_target, Vector3(0.0f, 1.0f, 0.0f));

	return s;
}
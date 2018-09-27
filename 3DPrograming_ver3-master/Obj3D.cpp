#include "pch.h"
#include "Obj3D.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Obj3D::Obj3D()
	: m_game(nullptr), m_models(nullptr),m_active(true)
{
	
}

bool Obj3D::Update(float elapsedTime)
{
	if (m_active == false)
	{
		return false;
	}

	//ワールド行列の作成
	m_world = Matrix::CreateFromQuaternion(m_rotation)
		    * Matrix::CreateTranslation(m_position);
	return false;
}

void Obj3D::Render()
{
	if (m_active == false)
	{
		return;
	}
	if (m_models && m_game)
	{
		//モデルの描画
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());
	}
}

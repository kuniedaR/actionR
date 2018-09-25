#include "pch.h"
#include "Obj3D.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Obj3D::Obj3D()
	: m_game(nullptr), m_models(nullptr)
{

}

bool Obj3D::Update(float elapsedTime)
{
	//���[���h�s��̍쐬
	m_world = Matrix::CreateFromQuaternion(m_rotation)
		    * Matrix::CreateTranslation(m_position);
	return false;
}

void Obj3D::Render()
{
	if (m_models && m_game)
	{
		//���f���̕`��
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());
	}
}
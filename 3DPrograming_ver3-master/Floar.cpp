#include "pch.h"
#include "Floar.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


bool Floar::Update()
{

	//	���[���h�s��̍쐬
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);


	return true;
}

void Floar::Render()
{
	if (m_game && m_models)
	{
		//���f����`��
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());
	}
}

DirectX::SimpleMath::Vector3 Floar::GetPosition()
{
	return m_position;
}

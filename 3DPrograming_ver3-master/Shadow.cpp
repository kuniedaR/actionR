#include "pch.h"
#include "Shadow.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//�v���C���[�̈ʒu����������֐�
void Shadow::SetTarget(DirectX::SimpleMath::Vector3 pos)
{
	m_target = pos;
}

//�e�̈ʒu
void Shadow::SetShadowPosition(DirectX::SimpleMath::Vector3 pos)
{
	m_shadowPosition = pos;
}

void Shadow::Resources()
{
	ID3D11Device* device = m_deviceResources->GetD3DDevice();

	// �e���f�������[�h���ă��f���n���h�����擾���� 
	
}

//�e�̕`��
void Shadow::Render()
{
	
}


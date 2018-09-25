#pragma once
#include "pch.h"
#include <Model.h>
#include "DeviceResources.h"

class Shadow 
{
private:

	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//�e�̈ʒu
	DirectX::SimpleMath::Vector3 m_shadowPosition;

	// �e���f���n���h�� 
	DirectX::Model  *m_shadowmodel;


	DX::DeviceResources  *m_deviceResources;

public:

	//�v���C���[�̈ʒu����������֐�
	void SetTarget(DirectX::SimpleMath::Vector3 pos);

	//�e�̈ʒu����������֐�
	void SetShadowPosition(DirectX::SimpleMath::Vector3 pos);

	void Resources();

	void Render();

};

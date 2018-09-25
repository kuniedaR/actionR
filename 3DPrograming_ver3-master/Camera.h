#pragma once
#include "pch.h"

class Camera
{
public:
	//�v���C���[�̈ʒu����������֐�
	void SetTarget(DirectX::SimpleMath::Vector3 pos);
	//�J�����̈ʒu
	void SetCameraPosition(DirectX::SimpleMath::Vector3 pos);

	DirectX::SimpleMath::Matrix GetView();

private:
	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//�J�����̈ʒu
	DirectX::SimpleMath::Vector3 m_cameraPosition;
};

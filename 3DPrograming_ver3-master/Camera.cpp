#include "pch.h"
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//�v���C���[�̈ʒu����������֐�
void Camera::SetTarget(DirectX::SimpleMath::Vector3 pos)
{
	m_target = pos;
}

//�J�����̈ʒu
void Camera::SetCameraPosition(DirectX::SimpleMath::Vector3 pos)
{
	m_cameraPosition = pos;
}

DirectX::SimpleMath::Matrix Camera::GetView()
{
	Matrix m = Matrix::CreateLookAt(m_cameraPosition, m_target, Vector3(0.0f, 1.0f, 0.0f));

	return m;
}

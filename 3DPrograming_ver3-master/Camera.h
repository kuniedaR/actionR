#pragma once
#include "pch.h"

class Camera
{
public:
	//プレイヤーの位置を所得する関数
	void SetTarget(DirectX::SimpleMath::Vector3 pos);
	//カメラの位置
	void SetCameraPosition(DirectX::SimpleMath::Vector3 pos);

	DirectX::SimpleMath::Matrix GetView();

private:
	//注視点
	DirectX::SimpleMath::Vector3 m_target;
	//カメラの位置
	DirectX::SimpleMath::Vector3 m_cameraPosition;
};

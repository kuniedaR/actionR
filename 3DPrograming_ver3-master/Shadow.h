#pragma once
#include "pch.h"
#include <Model.h>
#include "DeviceResources.h"

class Shadow 
{
private:

	//注視点
	DirectX::SimpleMath::Vector3 m_target;
	//影の位置
	DirectX::SimpleMath::Vector3 m_shadowPosition;

	// 影モデルハンドル 
	DirectX::Model  *m_shadowmodel;


	DX::DeviceResources  *m_deviceResources;

public:

	//プレイヤーの位置を所得する関数
	void SetTarget(DirectX::SimpleMath::Vector3 pos);

	//影の位置を所得する関数
	void SetShadowPosition(DirectX::SimpleMath::Vector3 pos);

	void Resources();

	void Render();

};

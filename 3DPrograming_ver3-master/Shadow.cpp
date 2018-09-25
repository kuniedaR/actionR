#include "pch.h"
#include "Shadow.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//プレイヤーの位置を所得する関数
void Shadow::SetTarget(DirectX::SimpleMath::Vector3 pos)
{
	m_target = pos;
}

//影の位置
void Shadow::SetShadowPosition(DirectX::SimpleMath::Vector3 pos)
{
	m_shadowPosition = pos;
}

void Shadow::Resources()
{
	ID3D11Device* device = m_deviceResources->GetD3DDevice();

	// 影モデルをロードしてモデルハンドルを取得する 
	
}

//影の描画
void Shadow::Render()
{
	
}


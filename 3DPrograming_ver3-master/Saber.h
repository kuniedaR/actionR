#pragma once
#include "CollisionCapsule.h"

//床クラス
class Saber : public CollisionCapsule
{

public:
	//コンストラクタ
	Saber(GameDefine::ColliderTag tag = GameDefine::Bullet);

	//更新
	bool Update();

	//描画
	void Render() override;

	DirectX::SimpleMath::Matrix GetView();

	//プレイヤーの位置を所得する関数
	void SetTarget(DirectX::SimpleMath::Vector3 pos);

	DirectX::SimpleMath::Vector3 GetPosition();

	GameDefine::ColliderTag GetParentTag() {
		return m_parentTag;
	}
private:
	//注視点
	DirectX::SimpleMath::Vector3 m_target;
	//サーベルの位置
	DirectX::SimpleMath::Vector3 m_saberPosition;

	GameDefine::ColliderTag m_parentTag;
};
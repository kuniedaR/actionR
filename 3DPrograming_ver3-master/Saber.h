#pragma once
#include "CollisionCapsule.h"
#include "GameDefine.h"

//サーベルクラス
class Saber : public CollisionCapsule
{

public:
	//コンストラクタ
	Saber(GameDefine::ColliderTag tag = GameDefine::Bullet);

	//更新
	bool Update(float elapsedTime);

	//描画
	void Render() override;

	DirectX::SimpleMath::Matrix GetView();

	//プレイヤーの位置を所得する関数
	void SetTarget(DirectX::SimpleMath::Vector3 pos);

	//サーベルの位置
	void SetSaberPosition(DirectX::SimpleMath::Vector3 pos);

	GameDefine::ColliderTag GetParentTag() {
		return m_parentTag;
	}

	//DirectX::SimpleMath::Vector3 GetPosition();
private:
	//注視点
	DirectX::SimpleMath::Vector3 m_target;
	//サーベルの位置
	DirectX::SimpleMath::Vector3 m_saberPosition;
	//タグ
	GameDefine::ColliderTag m_parentTag;
};
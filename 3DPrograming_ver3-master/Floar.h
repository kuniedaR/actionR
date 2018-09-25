#pragma once
#include "CollisionCapsule.h"

//床クラス
class Floar : public CollisionCapsule
{

public:

	//更新
	bool Update();

	//描画
	void Render() override;

	DirectX::SimpleMath::Vector3 GetPosition();
};


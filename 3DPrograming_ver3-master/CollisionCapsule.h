//カプセルを持ったObj3Dクラス
#pragma once
#include "Collision.h"
#include "Obj3D.h"
#include "DebugCapsule.h"

class CollisionCapsule : public Obj3D
{
private:
	//コリジョン情報
	Collision::Capsule m_collision;
	//コリジョン表示オブジェクト
	std::unique_ptr<DebugCapsule> m_obj;

public:
	//コリジョン情報の設定関数
	void SetCollision(Collision::Capsule capsule);

	//コリジョン情報の所得関数
	Collision::Capsule GetCollision();

	//デバック用コリジョン表示関数
	void DrawCollision();

};


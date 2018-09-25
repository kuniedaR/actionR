//境界球を持ったObj3Dクラス
#pragma once
#include "Collision.h"
#include "Obj3D.h"
#include "DebugSphere.h"

class CollisionSphere : public Obj3D
{
private:
	//コリジョン情報
	Collision::Sphere m_collision;
	//コリジョン表示オブジェクト
	std::unique_ptr<DebugSphere> m_obj;

public:
	//コリジョン情報の設定関数
	void SetCollision(Collision::Sphere sphere);

	//コリジョン情報の所得関数
	Collision::Sphere GetCollision();

	//デバック用コリジョン表示関数
	void DrawCollision();

};

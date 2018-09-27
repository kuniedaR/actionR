#include "pch.h"
#include "BulletGenerator.h"
#include "CollisionCapsule.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

BulletGenerator::BulletGenerator()
{
}

BulletGenerator::~BulletGenerator()
{
}

Bullet* BulletGenerator::Create(ID3D11Device* device)
{
	// エフェクトファクトリー 
	EffectFactory fx(device);

	fx.SetDirectory(L"Resources\\Models");

	// 弾をロードしてモデルハンドルを取得する
	auto model = Model::CreateFromCMO(device, playerModelPath, fx);

	auto bullet = new Bullet(GameDefine::Player);
	bullet->SetModel(model.get());

	//カプセルの定義
	Collision::Capsule capsule;

	capsule.a = Vector3(0.0f, 0.0f, -0.3f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 0.0f, -0.1f);	//芯線の終了点
	capsule.r = 0.2f;		//半径

	bullet->SetCollision(capsule);

	return bullet;
}

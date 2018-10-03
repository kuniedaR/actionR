#include "pch.h"
#include "SaberGenerator.h"
#include "CollisionCapsule.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

SaberGenerator::SaberGenerator(ID3D11Device* device, EffectFactory& fx)
{
	// サーベルをロードしてモデルハンドルを取得する
	m_playerModel = Model::CreateFromCMO(device, playerModelPath, fx);
}

SaberGenerator::~SaberGenerator()
{

}

Saber* SaberGenerator::Create()
{
	auto saber = new Saber(GameDefine::Player);
	saber->SetModel(m_playerModel.get());

	//カプセルの定義
	Collision::Capsule capsule;

	capsule.a = Vector3(0.0f, 0.1f, -0.0f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 1.1f, -0.0f);	//芯線の終了点
	capsule.r = 0.05f;		//半径

	saber->SetCollision(capsule);

	return saber;
}
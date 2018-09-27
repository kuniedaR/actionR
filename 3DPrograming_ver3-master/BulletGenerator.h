#pragma once
#include <string>
#include "Bullet.h"
#include <Effects.h>

class BulletGenerator
{
public:
	BulletGenerator(ID3D11Device* device, DirectX::EffectFactory& fx);
	~BulletGenerator();

	//弾の作成
	Bullet* Create();

private:


	const wchar_t* playerModelPath = L"Resources\\Models\\Beem.cmo";

	//モデル
	std::unique_ptr<DirectX::Model> m_playerModel;
};

#pragma once
#include <string>
#include "Bullet.h"
#include <Effects.h>

class BulletGenerator
{
public:
	BulletGenerator(ID3D11Device* device, DirectX::EffectFactory& fx);
	~BulletGenerator();

	//íeÇÃçÏê¨
	Bullet* Create();

private:


	const wchar_t* playerModelPath = L"Resources\\Models\\Beem.cmo";

	//ÉÇÉfÉã
	std::unique_ptr<DirectX::Model> m_playerModel;
};

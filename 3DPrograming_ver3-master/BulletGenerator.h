#pragma once
#include <string>
#include "Bullet.h"
#include <Effects.h>

class BulletGenerator
{
public:
	BulletGenerator(ID3D11Device* device, DirectX::EffectFactory& fx);
	~BulletGenerator();

	//�e�̍쐬
	Bullet* Create();

private:


	const wchar_t* playerModelPath = L"Resources\\Models\\Beem.cmo";

	//���f��
	std::unique_ptr<DirectX::Model> m_playerModel;
};

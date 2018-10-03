#pragma once

#include <string>
#include "Saber.h"
#include <Effects.h>

class SaberGenerator
{
public:
	SaberGenerator(ID3D11Device* device, DirectX::EffectFactory& fx);
	~SaberGenerator();

	//弾の作成
	Saber* Create();

private:


	const wchar_t* playerModelPath = L"Resources\\Models\\Saber.cmo";

	//モデル
	std::unique_ptr<DirectX::Model> m_playerModel;
};
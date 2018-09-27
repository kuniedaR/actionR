#pragma once
#include <string>
#include "Bullet.h"

class BulletGenerator
{
public:
	BulletGenerator();
	~BulletGenerator();

	Bullet* Create(ID3D11Device* device);

private:

	const wchar_t* playerModelPath = L"Resources\\Models\\Beem.cmo";
};

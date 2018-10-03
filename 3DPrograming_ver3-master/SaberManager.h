#pragma once

#include <list>
#include "Saber.h"
#include "CollisionCapsule.h"
#include <time.h>
#include <iostream>

class SaberManager
{
private:
	//サーベルのリスト
	std::list<Saber*> m_saber;

public:
	//サーベルとの当たり判定
	Saber* HitCheck(CollisionCapsule& collision);
};

#pragma once
#include <list>
#include "Bullet.h"
#include "CollisionCapsule.h"

class BulletManager
{
private:
	//’e‚ÌƒŠƒXƒg
	std::list<Bullet*> m_bullets;

public:

	bool HitCheck(CollisionCapsule& collision);


};
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

	Bullet* HitCheck(CollisionCapsule& collision);

	void SetBullet(Bullet *setbullet);

	void Update(float elapsedTime);

	void Render();
};
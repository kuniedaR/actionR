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
	//’e‚Æ‚Ì“–‚½‚è”»’è
	Bullet* HitCheck(CollisionCapsule& collision);
	//’e‚ÌŠÇ—
	void SetBullet(Bullet *setbullet);
	//’e‚ÌXV
	void Update(float elapsedTime);
	//’e‚Ì•`‰æ
	void Render();
	//’e‚Ìíœ
	void DeleteBullet(Bullet *deletebullet);

};
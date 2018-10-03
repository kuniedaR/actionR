#pragma once
#include <list>
#include "Bullet.h"
#include "CollisionCapsule.h"
#include <time.h>
#include <iostream>

class BulletManager
{
private:
	//’e‚ÌƒŠƒXƒg
	std::list<Bullet*> m_bullets;
	//’e‚Ìƒ^ƒCƒ}[
	std::vector<int> m_bulletsTimer;

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
	//’e‚ÌŠÔ§ŒÀ
	void TimerBullet(Bullet *timerbullet);

};
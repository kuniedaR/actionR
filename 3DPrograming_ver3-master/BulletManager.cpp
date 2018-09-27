#include "pch.h"
#include "BulletManager.h"

Bullet* BulletManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto bullet in m_bullets)
	{
		if (bullet->GetParentTag() == collision.Gettag())
		{
			continue;
		}

		//“G‚ÆŽ©’e‚Ì“–‚½‚è”»’è
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), bullet->GetCollision()))
		{
			return bullet;
		}
	}
	return nullptr;
}
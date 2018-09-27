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

		//�G�Ǝ��e�̓����蔻��
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), bullet->GetCollision()))
		{
			return bullet;
		}
	}
	return nullptr;
}
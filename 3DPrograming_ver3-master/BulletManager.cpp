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

		//“G‚Æ©’e‚Ì“–‚½‚è”»’è
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), bullet->GetCollision()))
		{
			return bullet;
		}
	}
	return nullptr;
}

void BulletManager::SetBullet(Bullet *setbullet)
{
	auto ite = std::find(m_bullets.begin(), m_bullets.end(), setbullet);

	if (ite == m_bullets.end())
	{
		m_bullets.push_back(setbullet);
	}
}

void BulletManager::Update(float elapsedTime)
{
	for each (auto bullet in m_bullets)
	{
		bullet->Update(elapsedTime);
	}
}

void BulletManager::Render()
{
	for each (auto bullet in m_bullets)
	{
		bullet->Render();
	}
}
#include "pch.h"
#include "BulletManager.h"

//’e‚Æ‚Ì“–‚½‚è”»’è
Bullet* BulletManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto bullet in m_bullets)
	{
		if (bullet->GetParentTag() == collision.Gettag())continue;

		if (!bullet->GetActive()) continue;

		//“G‚ÆŽ©’e‚Ì“–‚½‚è”»’è
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), bullet->GetCollision()))
		{
			return bullet;
		}
	}
	return nullptr;
}
//ŠÇ—‚·‚é’e‚ð’Ç‰Á
void BulletManager::SetBullet(Bullet *setbullet)
{
	auto ite = std::find(m_bullets.begin(), m_bullets.end(), setbullet);

	if (ite == m_bullets.end())
	{
		m_bullets.push_back(setbullet);
	}
}
//’e‚ÌXV
void BulletManager::Update(float elapsedTime)
{
	for each (auto bullet in m_bullets)
	{
		bullet->Update(elapsedTime);
	}
}
//’e‚Ì•`‰æ
void BulletManager::Render()
{
	for each (auto bullet in m_bullets)
	{
		bullet->Render();
	}
}

void BulletManager::Delete(Bullet * deletebullet)
{
}

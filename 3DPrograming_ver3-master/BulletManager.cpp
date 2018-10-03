#include "pch.h"
#include "BulletManager.h"
#include <time.h>

//�e�Ƃ̓����蔻��
Bullet* BulletManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto bullet in m_bullets)
	{
		if (bullet->GetParentTag() == collision.Gettag())continue;

		if (!bullet->GetActive()) continue;

		//�G�Ǝ��e�̓����蔻��
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), bullet->GetCollision()))
		{
			return bullet;
		}
	}
	return nullptr;
}
//�Ǘ�����e��ǉ�
void BulletManager::SetBullet(Bullet *setbullet)
{
	auto ite = std::find(m_bullets.begin(), m_bullets.end(), setbullet);

	if (ite == m_bullets.end())
	{
		m_bullets.push_back(setbullet);
	}
}
//�e�̍X�V
void BulletManager::Update(float elapsedTime)
{
	for each (auto bullet in m_bullets)
	{
		bullet->Update(elapsedTime);
	}
}
//�e�̕`��
void BulletManager::Render()
{
	for each (auto bullet in m_bullets)
	{
		bullet->Render();
	}
}
//�e�̍폜
void BulletManager::DeleteBullet(Bullet *deletebullet)
{
	auto ite = std::find(m_bullets.begin(), m_bullets.end(), deletebullet);

	if (ite != m_bullets.end())
	{
		m_bullets.remove(deletebullet);
		delete deletebullet;
	}
}

//�e�̎��Ԑ���
void BulletManager::TimerBullet(Bullet *timerbullet)
{
	time_t t = time(NULL);



	delete timerbullet;
}
#include "pch.h"
#include "SaberManager.h"

//�T�[�x���Ƃ̓����蔻��
Saber* SaberManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto saber in m_saber)
	{
		if (saber->GetParentTag() == collision.Gettag())continue;

		if (!saber->GetActive()) continue;

		//�G�Ǝ��e�̓����蔻��
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), saber->GetCollision()))
		{
			return saber;
		}
	}
	return nullptr;
}
//�T�[�x���̍X�V
void SaberManager::Update(float elapsedTime)
{
	for each (auto saber in m_saber)
	{
		saber->Update(elapsedTime);
	}
}
//�T�[�x���̕`��
void SaberManager::Render()
{
	for each (auto bullet in m_saber)
	{
		bullet->Render();
	}
}
//�T�[�x���̐�������
void SaberManager::TimerBullet(Saber * timersaber)
{
	time_t t = time(NULL);



	delete timersaber;
}

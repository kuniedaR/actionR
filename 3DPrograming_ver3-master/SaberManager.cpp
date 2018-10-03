#include "pch.h"
#include "SaberManager.h"

//�T�[�x���Ƃ̓����蔻��
Saber* SaberManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto saber in m_saber)
	{
		if (saber->GetParentTag() == collision.Gettag())continue;

		if (!saber->GetActive()) continue;

		//�G�ƃT�[�x���̓����蔻��
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), saber->GetCollision()))
		{
			return saber;
		}
	}
	return nullptr;
}
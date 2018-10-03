#include "pch.h"
#include "SaberManager.h"

//サーベルとの当たり判定
Saber* SaberManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto saber in m_saber)
	{
		if (saber->GetParentTag() == collision.Gettag())continue;

		if (!saber->GetActive()) continue;

		//敵とサーベルの当たり判定
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), saber->GetCollision()))
		{
			return saber;
		}
	}
	return nullptr;
}
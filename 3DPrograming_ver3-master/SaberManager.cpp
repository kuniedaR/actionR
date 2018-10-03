#include "pch.h"
#include "SaberManager.h"

//サーベルとの当たり判定
Saber* SaberManager::HitCheck(CollisionCapsule& collision)
{
	for each (auto saber in m_saber)
	{
		if (saber->GetParentTag() == collision.Gettag())continue;

		if (!saber->GetActive()) continue;

		//敵と自弾の当たり判定
		if (Collision::HitCheck_Capsule2Capsule(collision.GetCollision(), saber->GetCollision()))
		{
			return saber;
		}
	}
	return nullptr;
}
//サーベルの更新
void SaberManager::Update(float elapsedTime)
{
	for each (auto saber in m_saber)
	{
		saber->Update(elapsedTime);
	}
}
//サーベルの描画
void SaberManager::Render()
{
	for each (auto bullet in m_saber)
	{
		bullet->Render();
	}
}
//サーベルの制限時間
void SaberManager::TimerBullet(Saber * timersaber)
{
	time_t t = time(NULL);



	delete timersaber;
}

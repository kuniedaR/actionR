#pragma once

#include <list>
#include "Saber.h"
#include "CollisionCapsule.h"
#include <time.h>
#include <iostream>

class SaberManager
{
private:
	//サーベルのリスト
	std::list<Saber*> m_saber;
	//弾のタイマー
	//std::vector<int> m_bulletsTimer;

public:
	//サーベルとの当たり判定
	Saber* HitCheck(CollisionCapsule& collision);
	//弾の更新
	void Update(float elapsedTime);
	//弾の描画
	void Render();
	//弾の時間制限
	void TimerBullet(Saber *timersaber);

};

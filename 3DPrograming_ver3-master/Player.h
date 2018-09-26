#pragma once
#include "CollisionCapsule.h"
#include <utility>
#include <list>

//プレイヤークラス
class Player : public CollisionCapsule
{
public:
	enum MOVE
	{
		STOP,		//停止
		FORWARD,	//前進
		BACK,		//後進
		RIGHT_TURN, //右回転
		LEFT_TURN,  //左回転
	};

private:
	//向き
	float m_direction;

	//移動フラグ
	MOVE m_moveFlag;

	std::list<std::pair<int,float>> test;
public:
	//コンストラクタ
	Player();

	//更新
	bool Update(float elapsedTime) override;

	//描画
	void Render() override;

	// 移動する関数
	void Move(MOVE move);

	DirectX::SimpleMath::Vector3 GetPosition();

	float GetDirection();

};

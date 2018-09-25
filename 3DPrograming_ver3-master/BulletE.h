#pragma once
#include "pch.h"
#include "CollisionCapsule.h"

//弾クラス
class BulletE : public CollisionCapsule
{
public:
	enum MOVE
	{
		STOP,		//停止
		STRAIGHT,	//直進
	};

private:
	//向き
	float m_direction;

	//移動フラグ
	MOVE m_moveFlag;

	// 弾の速度
	DirectX::SimpleMath::Vector3 m_v;

public:
	//コンストラクタ
	BulletE();

	//更新
	bool Update(float elapsedTime) override;

	//描画
	void Render() override;

	// 移動する関数
	void Move(MOVE move);

	//弾の位置を初期化する関数
	void SetPosition(DirectX::SimpleMath::Vector3 pos) { m_position = pos; }

	DirectX::SimpleMath::Vector3 GetPosition();

	float GetDirection();

	void SetDirection(float direction);

};


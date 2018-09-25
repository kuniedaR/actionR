#pragma once
#include "pch.h"

struct Collision
{


	// 球の構造体
	struct Sphere
	{
		DirectX::SimpleMath::Vector3 c; // 球の中心
		float r;   // 球の半径
	};

	//カプセルの構造体
	struct  Capsule
	{
		DirectX::SimpleMath::Vector3 a;  //中間部の線分の開始点
		DirectX::SimpleMath::Vector3 b;  //中間部の線分の終了点
		float r;   // 球の半径
	};

	// 球と球の衝突判定関数
	static bool HitCheck_Sphere2Sphere(Sphere sphere1, Sphere sphere2)
	{
		// 中心間の距離の平方を計算
		DirectX::SimpleMath::Vector3 d = sphere1.c - sphere2.c;
		float dist2 = d.Dot(d);
		// 平方した距離が平方した半径の合計よりも小さい場合に球は交差している
		float radiusSum = sphere1.r + sphere2.r;
		return dist2 <= radiusSum * radiusSum;
	}

	//球とカプセルの衝突判定関数
	static bool HitCheck_Sphere2Capsule(const Sphere& sphere, const Capsule& capsule)
	{
		// 球の中心とカプセルの中心の線分との距離の平方を計算
		float dist2 = SqDistPointSegment(capsule.a, capsule.b, sphere.c);
		float radiusSum = sphere.r + capsule.r;
		return dist2 <= radiusSum * radiusSum;
	}
	//点cと線分abの間の距離の平方を返す関数
	static float SqDistPointSegment(DirectX::SimpleMath::Vector3 a, DirectX::SimpleMath::Vector3 b, DirectX::SimpleMath::Vector3 c)
	{
		DirectX::SimpleMath::Vector3 ab = b - a;
		DirectX::SimpleMath::Vector3 ac = c - a;
		DirectX::SimpleMath::Vector3 bc = c - b;
		float e = ac.Dot(ab);	// e = ac * ab
		if (e < 0.0f)return ac.Dot(ac);
		float f = ac.Dot(ab);	// f = ab * ab
		return ac.Dot(ac) - e * e / f;
	}

};

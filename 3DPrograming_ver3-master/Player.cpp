#include "pch.h"
#include "Player.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player()
	: m_direction(0.0f), m_moveFlag(STOP)
{

}

bool Player::Update(float elapsedTime)
{
	//速度
	Vector3 v;

	switch (m_moveFlag)
	{
	case FORWARD:		//前進
		v.z = -0.1f;
		break;
	case BACK:			//後進
		v.z = 0.1f;
		break;
	case RIGHT_TURN:	//右回転
		m_direction -= XMConvertToRadians(2.0f);
		break;
	case LEFT_TURN:		//左回転
		m_direction += XMConvertToRadians(2.0f);
		break;
	default:
		break;
	}

	//プレイヤーを移動させる
	m_rotation = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 5.0f, 0.0f), m_direction);
	v = Vector3::Transform(v, m_rotation);
	m_position += v;

	//移動フラグをリセットする	
	m_moveFlag = STOP;

	//	ワールド行列の作成
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);


	return true;
}

void Player::Render()
{
	if (m_game && m_models)
	{
		//モデルを描画
		m_models->Draw(m_game->GetContext(), *m_game->GetStates(),
			m_world, m_game->GetView(), m_game->GetProjection());

		//デバック用コリジョンの表示
		//DrawCollision();
	}
}

void Player::Move(MOVE move)
{
	m_moveFlag = move;
}

DirectX::SimpleMath::Vector3 Player::GetPosition()
{
	return m_position;
}

float Player::GetDirection()
{
	return m_direction;
}

#include "pch.h"
#include "BulletGenerator.h"
#include "CollisionCapsule.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

BulletGenerator::BulletGenerator(ID3D11Device* device, EffectFactory& fx)
{
	// �e�����[�h���ă��f���n���h�����擾����
	m_playerModel = Model::CreateFromCMO(device, playerModelPath, fx);
}

BulletGenerator::~BulletGenerator()
{

}

Bullet* BulletGenerator::Create()
{
	auto bullet = new Bullet(GameDefine::Player);
	bullet->SetModel(m_playerModel.get());

	//�J�v�Z���̒�`
	Collision::Capsule capsule;

	capsule.a = Vector3(0.0f, 0.0f, -0.3f);	//�c���̊J�n�_
	capsule.b = Vector3(0.0f, 0.0f, -0.1f);	//�c���̏I���_
	capsule.r = 0.2f;		//���a

	bullet->SetCollision(capsule);

	return bullet;
}

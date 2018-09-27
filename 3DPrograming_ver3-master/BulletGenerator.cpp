#include "pch.h"
#include "BulletGenerator.h"
#include "CollisionCapsule.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

BulletGenerator::BulletGenerator()
{
}

BulletGenerator::~BulletGenerator()
{
}

Bullet* BulletGenerator::Create(ID3D11Device* device)
{
	// �G�t�F�N�g�t�@�N�g���[ 
	EffectFactory fx(device);

	fx.SetDirectory(L"Resources\\Models");

	// �e�����[�h���ă��f���n���h�����擾����
	auto model = Model::CreateFromCMO(device, playerModelPath, fx);

	auto bullet = new Bullet(GameDefine::Player);
	bullet->SetModel(model.get());

	//�J�v�Z���̒�`
	Collision::Capsule capsule;

	capsule.a = Vector3(0.0f, 0.0f, -0.3f);	//�c���̊J�n�_
	capsule.b = Vector3(0.0f, 0.0f, -0.1f);	//�c���̏I���_
	capsule.r = 0.2f;		//���a

	bullet->SetCollision(capsule);

	return bullet;
}

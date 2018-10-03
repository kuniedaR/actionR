#include "pch.h"
#include "SaberGenerator.h"
#include "CollisionCapsule.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

SaberGenerator::SaberGenerator(ID3D11Device* device, EffectFactory& fx)
{
	// �T�[�x�������[�h���ă��f���n���h�����擾����
	m_playerModel = Model::CreateFromCMO(device, playerModelPath, fx);
}

SaberGenerator::~SaberGenerator()
{

}

Saber* SaberGenerator::Create()
{
	auto saber = new Saber(GameDefine::Player);
	saber->SetModel(m_playerModel.get());

	//�J�v�Z���̒�`
	Collision::Capsule capsule;

	capsule.a = Vector3(0.0f, 0.1f, -0.0f);	//�c���̊J�n�_
	capsule.b = Vector3(0.0f, 1.1f, -0.0f);	//�c���̏I���_
	capsule.r = 0.05f;		//���a

	saber->SetCollision(capsule);

	return saber;
}
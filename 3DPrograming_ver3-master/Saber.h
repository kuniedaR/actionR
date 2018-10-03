#pragma once
#include "CollisionCapsule.h"
#include "GameDefine.h"

//�T�[�x���N���X
class Saber : public CollisionCapsule
{

public:
	//�R���X�g���N�^
	Saber(GameDefine::ColliderTag tag = GameDefine::Bullet);

	//�X�V
	bool Update(float elapsedTime);

	//�`��
	void Render() override;

	DirectX::SimpleMath::Matrix GetView();

	//�v���C���[�̈ʒu����������֐�
	void SetTarget(DirectX::SimpleMath::Vector3 pos);

	//�T�[�x���̈ʒu
	void SetSaberPosition(DirectX::SimpleMath::Vector3 pos);

	GameDefine::ColliderTag GetParentTag() {
		return m_parentTag;
	}

	//DirectX::SimpleMath::Vector3 GetPosition();
private:
	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//�T�[�x���̈ʒu
	DirectX::SimpleMath::Vector3 m_saberPosition;
	//�^�O
	GameDefine::ColliderTag m_parentTag;
};
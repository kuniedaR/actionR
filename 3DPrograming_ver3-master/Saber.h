#pragma once
#include "CollisionCapsule.h"

//���N���X
class Saber : public CollisionCapsule
{

public:
	//�R���X�g���N�^
	Saber(GameDefine::ColliderTag tag = GameDefine::Bullet);

	//�X�V
	bool Update();

	//�`��
	void Render() override;

	DirectX::SimpleMath::Matrix GetView();

	//�v���C���[�̈ʒu����������֐�
	void SetTarget(DirectX::SimpleMath::Vector3 pos);

	DirectX::SimpleMath::Vector3 GetPosition();

	GameDefine::ColliderTag GetParentTag() {
		return m_parentTag;
	}
private:
	//�����_
	DirectX::SimpleMath::Vector3 m_target;
	//�T�[�x���̈ʒu
	DirectX::SimpleMath::Vector3 m_saberPosition;

	GameDefine::ColliderTag m_parentTag;
};
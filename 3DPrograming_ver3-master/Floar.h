#pragma once
#include "CollisionCapsule.h"

//���N���X
class Floar : public CollisionCapsule
{

public:

	//�X�V
	bool Update();

	//�`��
	void Render() override;

	DirectX::SimpleMath::Vector3 GetPosition();
};


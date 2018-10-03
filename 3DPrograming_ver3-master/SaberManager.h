#pragma once

#include <list>
#include "Saber.h"
#include "CollisionCapsule.h"
#include <time.h>
#include <iostream>

class SaberManager
{
private:
	//�T�[�x���̃��X�g
	std::list<Saber*> m_saber;
	//�e�̃^�C�}�[
	//std::vector<int> m_bulletsTimer;

public:
	//�T�[�x���Ƃ̓����蔻��
	Saber* HitCheck(CollisionCapsule& collision);
	//�e�̍X�V
	void Update(float elapsedTime);
	//�e�̕`��
	void Render();
	//�e�̎��Ԑ���
	void TimerBullet(Saber *timersaber);

};

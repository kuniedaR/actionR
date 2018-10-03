#pragma once
#include <list>
#include "Bullet.h"
#include "CollisionCapsule.h"
#include <time.h>
#include <iostream>

class BulletManager
{
private:
	//�e�̃��X�g
	std::list<Bullet*> m_bullets;
	//�e�̃^�C�}�[
	std::vector<int> m_bulletsTimer;

public:
	//�e�Ƃ̓����蔻��
	Bullet* HitCheck(CollisionCapsule& collision);
	//�e�̊Ǘ�
	void SetBullet(Bullet *setbullet);
	//�e�̍X�V
	void Update(float elapsedTime);
	//�e�̕`��
	void Render();
	//�e�̍폜
	void DeleteBullet(Bullet *deletebullet);
	//�e�̎��Ԑ���
	void TimerBullet(Bullet *timerbullet);

};
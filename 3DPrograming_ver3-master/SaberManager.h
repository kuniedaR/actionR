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

public:
	//�T�[�x���Ƃ̓����蔻��
	Saber* HitCheck(CollisionCapsule& collision);
};

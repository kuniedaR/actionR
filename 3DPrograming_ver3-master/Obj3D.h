#pragma once

class Game;

class Obj3D
{
protected:

	// �Q�[���I�u�W�F�N�g�ւ̃|�C���^
	Game* m_game;

	//���f���n���h��
	DirectX::Model* m_models;

	//�ʒu
	DirectX::SimpleMath::Vector3 m_position;

	//��]
	DirectX::SimpleMath::Quaternion m_rotation;

	//���[���h�s��
	DirectX::SimpleMath::Matrix m_world;

	bool m_active;

public:
	//�R���X�g���N�^
	Obj3D();

	//�X�V
	virtual bool Update(float elapsedTime);

	//�`��
	virtual void Render();

	//�Q�[���I�u�W�F�N�g��ݒ肷��֐�
	void SetGame(Game* game) { m_game = game; }

	//���f���n���h����ݒ肷��֐� 
	void SetModel(DirectX::Model* model) { m_models = model; }

	//�ʒu��ݒ肷��֐�
	void SetPosition(DirectX::SimpleMath::Vector3 position) { m_position = position; }

	//��]��ݒ肷��֐�
	void SetRotation(DirectX::SimpleMath::Quaternion rotation) { m_rotation = rotation; }

	void SetActive(bool active) { m_active = active; }

	bool GetActive() { return m_active; }
};
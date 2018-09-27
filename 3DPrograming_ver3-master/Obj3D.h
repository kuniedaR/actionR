#pragma once

class Game;

class Obj3D
{
protected:

	// ゲームオブジェクトへのポインタ
	Game* m_game;

	//モデルハンドル
	DirectX::Model* m_models;

	//位置
	DirectX::SimpleMath::Vector3 m_position;

	//回転
	DirectX::SimpleMath::Quaternion m_rotation;

	//ワールド行列
	DirectX::SimpleMath::Matrix m_world;

	bool m_active;

public:
	//コンストラクタ
	Obj3D();

	//更新
	virtual bool Update(float elapsedTime);

	//描画
	virtual void Render();

	//ゲームオブジェクトを設定する関数
	void SetGame(Game* game) { m_game = game; }

	//モデルハンドルを設定する関数 
	void SetModel(DirectX::Model* model) { m_models = model; }

	//位置を設定する関数
	void SetPosition(DirectX::SimpleMath::Vector3 position) { m_position = position; }

	//回転を設定する関数
	void SetRotation(DirectX::SimpleMath::Quaternion rotation) { m_rotation = rotation; }

	void SetActive(bool active) { m_active = active; }

	bool GetActive() { return m_active; }
};
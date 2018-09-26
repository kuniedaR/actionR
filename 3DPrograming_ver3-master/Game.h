//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

#include "DebugCamera.h"
#include "GridFloor.h"

#include <Effects.h>
#include <Model.h> 

#include "Obj3D.h"
#include "CollisionSphere.h"

#include "Player.h"

#include "Camera.h"

#include "Shadow.h"

#include "Enemy.h"

#include "Bullet.h"

#include "BulletE.h"

#include "Floar.h"

#include "Saber.h"

#include "StepTimer.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

	//ゲッター//

	//デバイスを所得する関数
	ID3D11Device* GetDevice() { return m_deviceResources->GetD3DDevice(); }

	//コンテキストを所得する関数
	ID3D11DeviceContext* GetContext() { return m_deviceResources->GetD3DDeviceContext(); }

	//コモンステートを所得する関数
	DirectX::CommonStates* GetStates() { return m_states.get(); }

	//ビュー行列を所得する関数
	const DirectX::SimpleMath::Matrix GetView() { return m_view; }

	//射影行列を所得する関数
	const DirectX::SimpleMath::Matrix GetProjection() { return m_projection; }


private:

    void Update(DX::StepTimer const& timer);

    void Render();

    void Clear();

    void CreateDeviceDependentResources();

    void CreateWindowSizeDependentResources();

	//プレイヤーの入力処理
	void PlayerInput();

	////敵の入力処理
	//void EnemyInput();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	//自弾のキーボードトラッカー
	DirectX::Keyboard::KeyboardStateTracker m_tracker;

	//敵弾のキーボードトラッカー
	DirectX::Keyboard::KeyboardStateTracker m_trackerE;

	//サーベルのキーボードトラッカー
	DirectX::Keyboard::KeyboardStateTracker m_trackerS;

	// マウス
	std::unique_ptr<DirectX::Mouse> m_mouse;

	// コモンステート
	std::unique_ptr<DirectX::CommonStates> m_states;

	// スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	// スプライトフォント
	std::unique_ptr<DirectX::SpriteFont> m_font;

	// ビュー行列
	DirectX::SimpleMath::Matrix m_view;

	// 射影行列
	DirectX::SimpleMath::Matrix m_projection;

	// デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugCamera;

	// プレイヤーモデル 
	std::unique_ptr<DirectX::Model> m_playerModel;

	// プレイヤー
	std::unique_ptr<Player> m_player; 

	// 敵機モデル 
	std::unique_ptr<DirectX::Model> m_enemyModel;

	// 敵
	std::unique_ptr<Enemy> m_enemy;

	// 自段モデル 
	std::unique_ptr<DirectX::Model> m_bulletModel;

	// 自弾
	std::unique_ptr<Bullet> m_bullet;

	// 敵弾モデル 
	std::unique_ptr<DirectX::Model> m_bulletEModel;

	// 敵弾
	std::unique_ptr<BulletE> m_bulletE;

	// 床モデルハンドル 
	std::unique_ptr<DirectX::Model> m_floarModel;

	// 床
	std::unique_ptr<Floar> m_floar;

	//サーベルモデルハンドル
	std::unique_ptr<DirectX::Model> m_saberModel;

	//サーベル
	std::unique_ptr<Saber> m_saber;

	// 影モデルハンドル 
	std::unique_ptr<DirectX::Model> m_shadowModel;

	// スカイドームハンドル 
	std::unique_ptr<DirectX::Model> m_skyModel;

	// 体力ゲージハンドル
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_armor;

	//プレイヤーの座標
	DirectX::SimpleMath::Vector3 m_playerpos;

	//敵の座標
	DirectX::SimpleMath::Vector3 m_enemypos;

	//自弾の座標
	DirectX::SimpleMath::Vector3 m_bulletPpos;

	//攻撃判定フラグ
	bool m_hitFlag;

	//自弾のフラグ
	bool m_drawbulletFlag;

	//敵弾のフラグ
	bool m_drawbulletEFlag;

	//サーベルのフラグ
	bool m_drawsaberFlag;

	//カメラのメンバ変数
	Camera m_camera;

	//敵体力ゲージのメンバ変数
	int m_helsE;

	//プレイヤー体力ゲージのメンバ変数
	int m_hels;
};
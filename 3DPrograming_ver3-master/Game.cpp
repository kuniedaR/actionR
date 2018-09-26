//
// Game.cpp
//

#include "pch.h"
#include "Game.h"

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

extern void ExitGame();

using namespace DirectX;
using namespace DirectX::SimpleMath;

using Microsoft::WRL::ComPtr;

Game::Game()
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();
    m_deviceResources->RegisterDeviceNotify(this);
}

// Initialize the Direct3D resources required to run.
void Game::Initialize(HWND window, int width, int height)
{
	// キーボードの作成
	m_keyboard = std::make_unique<Keyboard>();

	// マウスの作成
	m_mouse = std::make_unique<Mouse>();
	m_mouse->SetWindow(window);

	// デバッグカメラの作成
	m_debugCamera = std::make_unique<DebugCamera>(width, height);

    m_deviceResources->SetWindow(window, width, height);

    m_deviceResources->CreateDeviceResources();
    CreateDeviceDependentResources();

    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */

	//プレイヤーの初期位置
	m_playerpos = Vector3(0.0f, 2.3f, 10.0f);

	//敵の初期位置
	m_enemypos = Vector3(0.0f, 0.0f, 0.0f);

	//敵の位置
	m_enemy->SetPosition(m_enemypos);

	//プレイヤーの位置
	m_player->SetPosition(m_playerpos);

	//敵体力ゲージの初期値
	m_helsE = 500;

	//プレイヤー体力ゲージの初期値
	m_hels = 500;
}

#pragma region Frame Update
// Executes the basic game loop.
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

	//プレイヤーの入力処理の関数読み込み
	this->PlayerInput(timer);
	//敵の入力処理の関数読み込み
	this->EnemyInput(timer);
	//プレイヤーの当たり判定の関数読み込み
	this->CollisionPlayer();
	//敵の当たり判定の関数読み込み
	this->CollisionEnemy();
	//カメラの関数読み込み
	this->CameraMove();
	//体力の関数読み込み
	this->Physical();
}



#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Game::Render()
{
	// Don't try to render anything before the first Update.
	if (m_timer.GetFrameCount() == 0)
	{
		return;
	}

	Clear();

	m_deviceResources->PIXBeginEvent(L"Render");
	auto context = m_deviceResources->GetD3DDeviceContext();

	// ここから描画処理を記述する

	Matrix world;

	// スカイモデルの描画 
	m_skyModel->Draw(context, *m_states.get(), world, m_view, m_projection);

	// 影モデルの描画 
	auto SetCustomShadowState = [&]()
	{
		//半透明ON
		context->OMSetBlendState(m_states->AlphaBlend(), nullptr, 0xFFFFFFFF);
		//震度バッファは使用せず必ず描画する設定
		context->OMSetDepthStencilState(m_states->DepthNone(), 0);
	};

	//単位行列
	world = Matrix::Identity;
	/*m_shadowmodel->Draw(context, *m_states.get(), m_playerworld, m_view, m_projection, false, SetCustomShadowState);
	m_shadowmodel->Draw(context, *m_states.get(), m_enemyworld, m_view, m_projection, false, SetCustomShadowState);*/

	m_skyModel->UpdateEffects([&](IEffect* effect)
	{
		IEffectLights* lights = dynamic_cast<IEffectLights*>(effect);

		if (lights)
		{
			lights->SetAmbientLightColor(Vector3(0.0f, 0.0f, 0.0f));    // アンビエント色を設定する
			lights->SetLightEnabled(0, false);
			lights->SetLightEnabled(1, false);
			lights->SetLightEnabled(2, false);
		}
		BasicEffect* basicEffect = dynamic_cast<BasicEffect*>(effect);
		if (basicEffect)
		{
			// エミッション色の設定
			basicEffect->SetEmissiveColor(Vector3(1.0f, 1.0f, 1.0f));
		}
	});

	//スカイドームの描画
	m_skyModel->Draw(context, *m_states.get(), world, m_view, m_projection);

	// プレイヤーの描画
	m_player->Render();

	// 敵機の描画
	m_enemy->Render();

	// 床モデルの描画 
	m_floar->Render();

	//サーベルの描画
	if (m_drawsaberFlag == true)
	{
		m_saber->Render();
	}
	//プレイヤー名の描画 
	m_sprites->Begin();
	m_font->DrawString(m_sprites.get(), L"Player1", Vector2(30, 530), Colors::Black);
	m_sprites->End();

	//敵名の描画
	m_sprites->Begin();
	m_font->DrawString(m_sprites.get(), L"Player2", Vector2(690, 530), Colors::Black);
	m_sprites->End();

	//自弾の描画
	if (m_drawbulletFlag == true)
	{
		m_bullet->Render();
	}

	//敵弾の描画
	if (m_drawbulletEFlag == true)
	{
		m_bulletE->Render();
	}

	//左体力ゲージの描画 
	m_sprites->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(m_armor.Get(), RECT{ 20, 530 - m_hels,120,530 });
	m_sprites->End();

	//敵体力ゲージの描画
	m_sprites->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());
	m_sprites->Draw(m_armor.Get(), RECT{ 680, 530 - m_helsE,780,530 });
	m_sprites->End();
	// ここまで

    m_deviceResources->PIXEndEvent();

    // Show the new frame.
    m_deviceResources->Present();
}

// Helper method to clear the back buffers.
void Game::Clear()
{
    m_deviceResources->PIXBeginEvent(L"Clear");

    // Clear the views.
    auto context = m_deviceResources->GetD3DDeviceContext();
    auto renderTarget = m_deviceResources->GetRenderTargetView();
    auto depthStencil = m_deviceResources->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, Colors::DarkBlue);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

    // Set the viewport.
    auto viewport = m_deviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    m_deviceResources->PIXEndEvent();
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    if (!m_deviceResources->WindowSizeChanged(width, height))
        return;

    CreateWindowSizeDependentResources();

    // TODO: Game window is being resized.
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}
#pragma endregion

#pragma region Direct3D Resources
// These are the resources that depend on the device.
void Game::CreateDeviceDependentResources()
{
    ID3D11Device* device = m_deviceResources->GetD3DDevice();
	ID3D11DeviceContext* context =  m_deviceResources->GetD3DDeviceContext();

	// コモンステートの作成
	m_states = std::make_unique<CommonStates>(device);

	// スプライトバッチの作成
	m_sprites = std::make_unique<SpriteBatch>(context);

	// スプライトフォントの作成
	m_font = std::make_unique<SpriteFont>(device, L"SegoeUI_18.spritefont");

	// エフェクトファクトリー 
	EffectFactory fx(device);

	fx.SetDirectory(L"Resources\\Models");

	// 体力ゲージを読み込む 
	CreateWICTextureFromFile(device, L"Resources\\Textures\\tairyokugej.png", nullptr, m_armor.GetAddressOf());

	// 床モデルをロードしてモデルハンドルを取得する
	m_floarModel = Model::CreateFromCMO(device, L"Resources\\Models\\floor.cmo", fx);

	// サーベルモデルをロードしてモデルハンドルを取得する
	m_saberModel = Model::CreateFromCMO(device, L"Resources\\Models\\Saber.cmo", fx);

	// 影モデルをロードしてモデルハンドルを取得する
	m_shadowModel = Model::CreateFromCMO(device, L"Resources\\Models\\shadow.cmo", fx);

	// スカイモデルをロードしてモデルハンドルを取得する
	m_skyModel = Model::CreateFromCMO(device, L"Resources\\Models\\Exsky.cmo", fx);

	// プレイヤーをロードしてモデルハンドルを取得する
	m_playerModel = Model::CreateFromCMO(device, L"Resources\\Models\\Player.cmo", fx); 

	// 敵機をロードしてモデルハンドルを取得する
	m_enemyModel = Model::CreateFromCMO(device, L"Resources\\Models\\RoboEnemy.cmo", fx);

	// 弾をロードしてモデルハンドルを取得する
	m_bulletModel = Model::CreateFromCMO(device, L"Resources\\Models\\Beem.cmo", fx);

	// 敵弾をロードしてモデルハンドルを取得する
	m_bulletEModel = Model::CreateFromCMO(device, L"Resources\\Models\\BeemE.cmo", fx);

	//カプセルの定義
	Collision::Capsule capsule;

	//プレイヤーの作成
	m_player = std::make_unique<Player>();
	m_player->SetGame(this);
	m_player->SetModel(m_playerModel.get());

	capsule.a = Vector3(0.0f, 0.5f, -0.25f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 2.0f, -0.25f);	//芯線の終了点
	capsule.r = 0.5f;		//半径
	m_player->SetCollision(capsule);

	//敵機の作成
	m_enemy = std::make_unique<Enemy>();
	m_enemy->SetGame(this);
	m_enemy->SetModel(m_enemyModel.get());

	capsule.a = Vector3(0.0f, 0.5f, -0.25f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 2.0f, -0.25f);	//芯線の終了点
	capsule.r = 0.5f;		//半径
	m_enemy->SetCollision(capsule);

	//弾の作成
	m_bullet = std::make_unique<Bullet>();
	m_bullet->SetGame(this);
	m_bullet->SetModel(m_bulletModel.get());

	capsule.a = Vector3(0.0f, 0.0f, -0.3f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 0.0f, -0.1f);	//芯線の終了点
	capsule.r = 0.2f;		//半径

	m_bullet->SetCollision(capsule);

	//敵弾の作成
	m_bulletE = std::make_unique<BulletE>();
	m_bulletE->SetGame(this);
	m_bulletE->SetModel(m_bulletEModel.get());

	capsule.a = Vector3(0.0f, 0.0f, -0.3f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 0.0f, -0.1f);	//芯線の終了点
	capsule.r = 0.2f;		//半径

	m_bulletE->SetCollision(capsule);

	//サーベルの作成
	m_saber = std::make_unique<Saber>();
	m_saber->SetGame(this);
	m_saber->SetModel(m_saberModel.get());

	capsule.a = Vector3(0.0f, 0.1f, -0.0f);	//芯線の開始点
	capsule.b = Vector3(0.0f, 1.1f, -0.0f);	//芯線の終了点
	capsule.r = 0.05f;		//半径

	m_saber->SetCollision(capsule);

	//床の作成
	m_floar = std::make_unique<Floar>();
	m_floar->SetGame(this);
	m_floar->SetModel(m_floarModel.get());
}

// Allocate all memory resources that change on a window SizeChanged event.
void Game::CreateWindowSizeDependentResources()
{
    // TODO: Initialize windows-size dependent objects here.

	// ウインドウサイズからアスペクト比を算出する
	RECT size = m_deviceResources->GetOutputSize();
	float aspectRatio = float(size.right) / float(size.bottom);

	// 画角を設定
	float fovAngleY = XMConvertToRadians(45.0f);

	// 射影行列を作成する
	m_projection = Matrix::CreatePerspectiveFieldOfView
	(
		fovAngleY,
		aspectRatio,
		0.01f,
		300.0f
	);

	// デバッグカメラにウインドウのサイズ変更を伝える
	m_debugCamera->SetWindowSize(size.right, size.bottom);
}

void Game::OnDeviceLost()
{
    // TODO: Add Direct3D resource cleanup here.

	// コモンステートの解放
	m_states.reset();

	// スプライトバッチの解放
	m_sprites.reset();

	// スプライトフォントの解放
	m_font.reset();

}

void Game::OnDeviceRestored()
{
    CreateDeviceDependentResources();

    CreateWindowSizeDependentResources();
}

// プレイヤーの入力処理
void Game::PlayerInput(DX::StepTimer const& timer)
{
	float elapsedTime = float(timer.GetElapsedSeconds());

	//プレイヤーの更新
	m_player->Update(elapsedTime);

	//弾の更新
	m_bullet->Update(elapsedTime);

	//サーベルの更新
	m_saber->Update();

	//プレイヤーの操作
	//キー入力
	auto playerkb = Keyboard::Get().GetState();
	//	上キーが押された
	if (playerkb.Up)
	{
		//前に移動
		m_player->Move(Player::FORWARD);
	}
	//下キーが押された
	if (playerkb.Down)
	{
		//後ろに移動
		m_player->Move(Player::BACK);
	}
	//右キーが押された
	if (playerkb.Right)
	{
		//右に曲がる
		m_player->Move(Player::RIGHT_TURN);
	}
	//左キーが押された
	if (playerkb.Left)
	{
		//左に曲がる
		m_player->Move(Player::LEFT_TURN);
	}

	//サーベルキートリガーの宣言
	Keyboard::State saberkb = m_keyboard->GetState();
	//サーベルキートリガーの更新
	m_trackerS.Update(saberkb);
	if (m_trackerS.pressed.Enter)
	{
		//フラグが立ったたらサーベル描画
		m_drawsaberFlag = true;

		//サーベルがプレイヤーの位置を所得
		m_saber->SetTarget(m_player->GetPosition());

		//プレイヤーの左腕の位置にサーベル描画
		Vector3 sa(-0.45f, -0.55f, -0.1f);

		float dirs = m_player->GetDirection();
		//サーベルの回転
		Quaternion qu = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), dirs);
		sa = Vector3::Transform(sa, qu);

		//サーベルがプレイヤーの位置を追いかける
		m_saber->SetPosition(sa + m_player->GetPosition());

		m_view = m_saber->GetView();
	}

	//自弾キートリガーの宣言
	Keyboard::State bulletkb = m_keyboard->GetState();
	//自弾キートリガーの更新
	m_tracker.Update(bulletkb);
	//エンターキー押したら自弾の発射
	if (m_tracker.pressed.Space)
	{
		//フラグが立ったたら自弾描画
		m_drawbulletFlag = true;
		//プレイヤーの右腕の位置に自弾描画
		Vector3 sa(0.45f, -0.4f, -0.1f);
		m_bullet->SetPosition(sa + m_player->GetPosition());
		//プレイヤーの向いてる方向に撃つ
		m_bullet->SetDirection(m_player->GetDirection());
		//自弾直進
		m_bullet->Move(Bullet::STRAIGHT);
	}
}

//敵の入力処理
void Game::EnemyInput(DX::StepTimer const& timer)
{
	float elapsedTime = float(timer.GetElapsedSeconds());

	//敵機の更新
	m_enemy->Update(elapsedTime);

	//敵弾の更新
	m_bulletE->Update(elapsedTime);

	//敵の操作
	//キー入力
	auto enemykb = Keyboard::Get().GetState();
	//	Wキーが押された
	if (enemykb.W)
	{
		//前に移動
		m_enemy->Move(Enemy::FORWARD);
	}
	//Sキーが押された
	if (enemykb.S)
	{
		//後ろに移動
		m_enemy->Move(Enemy::BACK);
	}
	//Dキーが押された
	if (enemykb.D)
	{
		//右に曲がる
		m_enemy->Move(Enemy::RIGHT_TURN);
	}
	//Aキーが押された
	if (enemykb.A)
	{
		//左に曲がる
		m_enemy->Move(Enemy::LEFT_TURN);
	}

	//敵弾キートリガーの宣言
	Keyboard::State bulletEkb = m_keyboard->GetState();
	//敵弾キートリガーの更新
	m_trackerE.Update(bulletEkb);
	//スペースキー押したら弾の発射
	if (m_trackerE.pressed.R)
	{
		//フラグが立ったたら敵弾描画
		m_drawbulletEFlag = true;
		//敵の位置に敵弾描画
		Vector3 enemyPos = m_enemy->GetPosition();
		enemyPos.y = 1.8f;
		m_bulletE->SetPosition(enemyPos);
		//敵の向いてる方向に撃つ
		m_bulletE->SetDirection(m_enemy->GetDirection());
		//敵弾直進
		m_bulletE->Move(BulletE::STRAIGHT);
	}
}

//プレイヤーと敵弾の当たり判定
void Game::CollisionPlayer()
{
	//プレイヤーと敵弾の当たり判定
	m_hitFlag = false;
	if (m_drawbulletEFlag == true)
	{
		if (Collision::HitCheck_Capsule2Capsule(m_player->GetCollision(), m_bulletE->GetCollision()) == true)
		{
			//体力を無くす
			m_hels -= 30;
			//敵弾の移動を止める
			m_bulletE->Move(BulletE::STOP);
			//敵弾の描画を消す
			m_drawbulletEFlag = false;
		}
	}
}

//敵とプレイヤーの弾の当たり判定
void Game::CollisionEnemy()
{
	//敵と自弾の当たり判定
	m_hitFlag = false;
	if (m_drawbulletFlag == true)
	{
		if (Collision::HitCheck_Capsule2Capsule(m_enemy->GetCollision(), m_bullet->GetCollision()) == true)
		{
			//体力を無くす
			m_helsE -= 30;
			//自弾の移動を止める
			m_bullet->Move(Bullet::STOP);
			//自弾の描画を消す
			m_drawbulletFlag = false;
		}
	}
}

//カメラの処理
void Game::CameraMove()
{
	//カメラがプレイヤーの位置を所得
	m_camera.SetTarget(m_player->GetPosition());

	//カメラの位置
	Vector3 a(0.0f, 0.5f, 1.5f);

	float dir = m_player->GetDirection();
	//カメラの回転
	Quaternion q = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), dir);
	a = Vector3::Transform(a, q);

	//カメラがプレイヤーの位置を追いかける
	m_camera.SetCameraPosition(a + m_player->GetPosition());

	m_view = m_camera.GetView();
}

//体力の処理
void Game::Physical()
{
	//敵体力ゲージが0のになったら敵を消す
	if (m_helsE < 0)
	{
		exit(0);
	}

	//プレイヤー体力ゲージが0のになったら敵を消す
	if (m_hels < 0)
	{
		exit(0);
	}
}
#pragma endregion

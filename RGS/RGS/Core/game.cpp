//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：Gameの基本処理
//-------------------------------------------------------
#include <Core\game.h>

using namespace Core;

//初期化処理
void Game::Initialize()
{
	m_end_flag = false;
	m_motion_index = 0;

	m_projector_angle = 0;
	m_dest_angle = 0;
	m_zoom_rate = 100;

	m_renderer = m_game_device->GetRenderer();

	m_phase_manager = std::make_shared<BattleSystem::PhaseManager>();
	m_phase_manager->Initialize();

	m_rate = 0;
}

//ロードコンテンツ
void Game::Load()
{
	m_game_device->GetContent()->LoadTexture("load", ".png");
	m_game_device->GetContent()->LoadTexture("test", ".png");
	m_game_device->GetContent()->LoadTexture("mask", ".png");
	m_game_device->GetContent()->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	//m_content_manager->LoadFont("MS UI Gothic", 50, 3);			//WordでFont名を見る

	m_game_device->GetContent()->LoadModel("test", ".mv1");

	m_game_device->GetContent()->LoadShaderPixel("cut_in", ".pso");

	m_cutin_effect = std::make_shared<Shader::CutinEffect>();
	m_cutin_effect->Initialize(Math::Vector2(100, 100), "test", "mask");
}

//コンテンツ解放
void Game::Unload()
{
}

//更新処理
void Game::Update()
{
	if (m_input_state->IsKeyTrigger(DIK_ESCAPE))
		m_end_flag = true;

	m_motion_index++;
	if (m_motion_index > 5)
		m_motion_index = 0;

	if (m_input_state->IsKeyTrigger(DIK_E)) 
	{
		m_dest_angle += 90;
	}

	if (m_input_state->IsKeyTrigger(DIK_Q))
	{
		m_dest_angle -= 90;
	}

	if (m_projector_angle > m_dest_angle) 
	{
		m_projector_angle-=3;
		m_game_device->GetProjector()->Rotate(m_projector_angle * 3.14159f / 180.0f);
	}

	if (m_projector_angle < m_dest_angle)
	{
		m_projector_angle+=3;
		m_game_device->GetProjector()->Rotate(m_projector_angle * 3.14159f / 180.0f);
	}

	if (m_input_state->IsKeyDown(DIK_I)) 
	{
		m_zoom_rate -= 1;
		m_game_device->GetProjector()->Zoom(m_zoom_rate);
	}

	if (m_input_state->IsKeyDown(DIK_O))
	{
		m_zoom_rate += 1;
		m_game_device->GetProjector()->Zoom(m_zoom_rate);
	}

	if (m_input_state->IsKeyDown(DIK_P))
	{
		m_rate += 0.07f;
		m_rate = m_rate > 1.0f ? 1.0f : m_rate;
	}
	if (m_input_state->IsKeyDown(DIK_M))
	{
		m_rate -= 0.07f;
		m_rate = m_rate < 0.0f ? 0.0f: m_rate;
	}

	m_phase_manager->Update();
}

//描画処理
void Game::Draw()
{
	m_renderer->Clear(50, 50, 100);

	m_renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159f / 180,
		Color(1.0f, 0.1f, 0.1f, 1.0f));
	//m_renderer->DrawTexture("load", Math::Vector2(0, 0), 0.1f);

	m_renderer->DrawMotion("test", m_motion_index, Math::Vector2(0, 100));

	m_renderer->DrawString("Hello World 漢字", "MS UI Gothic", Math::Vector2(0, 600), Color(120, 120, 50));
	m_renderer->DrawString("こんにちは。世界", "MS UI Gothic", Math::Vector2(600, 300), Color(120, 120, 50));

	/*for (int i = 0; i < 16; i++) 
	{
		DrawSphere3D(VGet(i % 4 * 10, 0.0f, i / 4 * 10), 5.0f, 36, GetColor(255, 255, 255), GetColor(255, 255, 255), TRUE);
	}*/

	/*m_renderer->DrawMotion3D("test", m_motion_index, Math::Vector3(0, 0, 0), 64);
	m_renderer->DrawTexture3D("test", Math::Vector3(0, 0, 0), 500, 2, Color(1.0f, 1.0f, 1.0f, 1.0f));
	m_renderer->DrawTexture3D("test", Math::Vector3(-5, 0, -3), 500);*/

	/*m_renderer->GetDepthSort()->AddTransparentObj(Device::TransparentObj("test", -1, Math::Vector3(2, 0, 0), 500, 2, Color(1.0f, 1.0f, 1.0f, 1.0f)));
	m_renderer->GetDepthSort()->AddTransparentObj(Device::TransparentObj("test", -1, Math::Vector3(0, 0, 0), 500, 2, Color(1.0f, 1.0f, 1.0f, 1.0f)));
	m_renderer->GetDepthSort()->Sort(m_game_device->GetProjector()->Position());
	m_renderer->DrawTransparentObj();*/

	for (int i = 0; i < 25; i++) 
	{
		m_renderer->DrawModel("test", Math::Vector3(i % 5 * 10, 0,  i / 5 * 10), Math::Vector3(10, 10, 10), Math::Vector3(0, 0, 0));
	}

	m_phase_manager->Draw();

	m_cutin_effect->Draw(m_rate);

	m_renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_end_flag;
}
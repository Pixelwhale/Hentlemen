//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FGame�̊�{����
//-------------------------------------------------------
#include <Core\game.h>

using namespace Core;

//����������
void Game::Initialize()
{
	m_end_flag = false;
	m_motion_index = 0;

	m_game_device = std::make_shared<Device::GameDevice>(
		m_input_state,
		m_renderer,
		m_content_manager);

	m_projector_angle = 0;
	m_dest_angle = 0;
	m_zoom_rate = 100;
}

//���[�h�R���e���c
void Game::Load()
{
	m_content_manager->LoadTexture("load", ".png");
	m_content_manager->LoadTexture("test", ".png");
	m_content_manager->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	m_content_manager->LoadFont("MS UI Gothic", 50, 3);			//Word��Font��������

	m_content_manager->LoadModel("test", ".mv1");
}

//�R���e���c���
void Game::Unload()
{
}

//�X�V����
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
}

//�`�揈��
void Game::Draw()
{
	m_renderer->Clear(50, 50, 100);

	m_renderer->DrawTexture("load", Math::Vector2(800, 500), Math::Vector2(0, 0),
		Math::Vector2(1.0f, 1.0f), 30 * 3.14159f / 180,
		Color(1.0f, 0.1f, 0.1f, 1.0f));
	m_renderer->DrawTexture("load", Math::Vector2(0, 0), 0.1f);

	m_renderer->DrawMotion("test", m_motion_index, Math::Vector2(0, 100));

	m_renderer->DrawString("Hello World ����", "MS UI Gothic", Math::Vector2(0, 600), Color(120, 120, 50));
	m_renderer->DrawString("����ɂ��́B���E", "MS UI Gothic", Math::Vector2(600, 300), Color(120, 120, 50));

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


	m_renderer->Swap();
}

//�I����Ă��邩
bool Game::IsEnd()
{
	return m_end_flag;
}
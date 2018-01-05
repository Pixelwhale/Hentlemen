//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FGame�̊�{����
//-------------------------------------------------------
#pragma once
#include <Core\application.h>
#include <Device\game_device.h>
#include <BattleSystem\phase_manager.h>
#include <Shader\cutin_effect.h>
#include <Scene\scene_manager.h>
#include <Map\battle_map.h>
#include <Map\map_loader.h>

namespace Core
{
	class Game : public Application
	{
	public:
		Game() {}						//�R���X�g���N�^
		~Game() {}						//�f�X�g���N�^�[

	protected:
		virtual void Initialize();		//������
		virtual void Load();			//���\�[�X�ǂݍ���
		virtual void Unload();			//���\�[�X���
		virtual void Update();			//�Q�[���X�V
		virtual void Draw();			//�`��
		virtual bool IsEnd();			//�I���m�F���郁�\�b�h

	private:
		bool m_end_flag;					//�Q�[���I���̃t���O

		int m_motion_index;				//Test�p
		float m_dest_angle;				//Test�p
		float m_projector_angle;		//Test�p
		float m_zoom_rate;				//Test�p

		std::shared_ptr<BattleSystem::PhaseManager> m_phase_manager;
		std::shared_ptr<Device::Renderer> m_renderer;

		std::shared_ptr<Shader::CutinEffect> m_cutin_effect;
		float m_rate;					//Test�p
		float m_alpha;					//Test�p
		std::shared_ptr<Scene::SceneManager> m_scene_manager;

		Map::BattleMap m_map;
		Map::MapLoader m_map_loader;

		ss::Player* m_ss_player;
	};
}
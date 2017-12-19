//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FDevice�n���܂Ƃ߂��N���X
//-------------------------------------------------------
#pragma once
#include <memory>
#include <Core\input_state.h>
#include <Device\renderer.h>
#include <Device\projector.h>
#include <Device\content_manager.h>
#include <Device\random.h>

namespace Device
{
	static class GameDevice
	{
	public:
		~GameDevice();
		///<summary>�C���X�^���X���擾</summary>
		static std::shared_ptr<GameDevice> GetInstance() 
		{
			static std::shared_ptr<GameDevice> instance(new GameDevice);
			return instance;
		}

		///<summary>������</summary>
		bool Initialize(HINSTANCE h_instance, HWND hwnd);
		///<summary>�������</summary>
		void ShutDown();

		///<summary>���͑��u</summary>
		std::shared_ptr<Core::InputState>	GetInput();
		///<summary>�����_���[</summary>
		std::shared_ptr<Renderer>			GetRenderer();
		///<summary>�J����</summary>
		std::shared_ptr<Projector>			GetProjector();
		///<summary>�R���e���g�}�l�[�W���[</summary>
		std::shared_ptr<ContentManager>		GetContent();
		///<summary>�����_��</summary>
		Random*								GetRandom();

	private:
		GameDevice();
		GameDevice(const GameDevice&);

	private:
		std::shared_ptr<Core::InputState>	m_input;			//���͑��u
		std::shared_ptr<Renderer>			m_renderer;			//�����_���[
		std::shared_ptr<Projector>			m_projector;		//�J����
		std::shared_ptr<ContentManager>		m_content;			//�R���e���c
		Random								m_rand;				//�����_��
	};
}

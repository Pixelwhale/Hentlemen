#pragma once
#include <string>
#include <Device\game_device.h>
#include <Math\vector2.h>
#include <DX\DXLib\DxLib.h>

namespace Shader 
{
	class CutinEffect 
	{
	public:
		CutinEffect();
		CutinEffect(const CutinEffect&);
		~CutinEffect();

		void Initialize(Math::Vector2 position,
			std::string source_name,
			std::string mask_name);

		void Draw();

	private:
		void SetPosition(Math::Vector2 position);
		void SourceTexture(std::string source_name);
		void MaskTexture(std::string source_name);

	private:
		std::shared_ptr<Device::ContentManager> m_content;

		VERTEX2DSHADER m_vertice[4];
		Math::Vector2 m_position;

		int m_shader_handle;

		int m_source_handle;
		int m_mask_handle;
	};
}
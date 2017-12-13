//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.12
// ���e�@�F�����̂���e�N�X�`���̓\�[�g���ĕ`�悷��K�v��
//			����̂ŁA���̂��߂̃N���X
//-------------------------------------------------------
#pragma once
#include <vector>
#include <Color\color.h>
#include <Math\vector3.h>
#include <DX\DXLib\DxLib.h>

namespace Device 
{
	class DepthSort 
	{
	public:
		struct TransparentObj
		{
		public:
			TransparentObj(std::string textureName, int index, 
				Math::Vector3 position,
				float scale, float angle, Color color) 
				:m_textureName(textureName), m_index(index), 
				m_position(VGet(position.x, position.y, position.z)), 
				m_scale(scale), m_angle(angle), m_color(color)
			{
			}

			std::string		m_textureName;
			int				m_index;
			VECTOR			m_position;
			float			m_scale;
			float			m_angle;
			Color			m_color;
		};

	public:
		DepthSort();
		DepthSort(const DepthSort&);
		~DepthSort();

		void AddTransparentObj(TransparentObj obj);
		void Clear();

		void Sort(Math::Vector3 projectorPos);
		void Draw();

	private:
		std::vector<TransparentObj>			m_drawList;
		
	};
}
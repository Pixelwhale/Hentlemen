//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.28
// ���e�@�F��}�X�̃u���b�N��ۑ�����\����
//-------------------------------------------------------
#pragma once
#include <vector>

namespace Map
{
	struct Grid
	{
		///<summary>��}�X�̃u���b�N��ۑ�����\����</summary>
		///<param name="height">�u���b�N���܂Ƃ߂��z��</param>
		Grid(std::vector<int> height)
		{
			blocks = height;
		}

		///<summary>�ςݏグ�����̐�</summary>
		int Height() { return blocks.size(); }

		std::vector<int> blocks;					//��}�X�̃u���b�N
	};
}
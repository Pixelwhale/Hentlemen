//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.14
// 内容　：キャラクターの移動について処理
//-------------------------------------------------------
#pragma once

namespace Actor
{
	class CharacterMove
	{
	public:
		CharacterMove(int move);
		~CharacterMove();

	private:
		int Move();			//AP-=5000/Move;
		int m_base_move;
	};
}
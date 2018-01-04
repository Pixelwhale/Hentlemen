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
		CharacterMove(int move, int jump);
		~CharacterMove();

	private:
		int m_move;		//移動力。高くなると移動する時かかる
		int m_jump;
	};
}
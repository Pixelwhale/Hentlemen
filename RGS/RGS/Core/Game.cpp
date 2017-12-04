//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：Gameの基本処理
//-------------------------------------------------------
#include <Core\Game.h>

using namespace Core;

void Game::Initialize() 
{
	m_endFlag = false;
}
void Game::Load() 
{
}
void Game::Unload() 
{
}
void Game::Update() 
{
}
void Game::Draw() 
{
}
bool Game::IsEnd() 
{
	return m_endFlag;
}
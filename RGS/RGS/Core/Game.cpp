//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FGame�̊�{����
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
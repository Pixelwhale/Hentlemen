//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FWindowAPI���g����Application�̋N��
//-------------------------------------------------------
#include <Core\Game.h>

//WindowsAPI
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	Core::Application* game;				//�Q�[���N���X

	game = new Core::Game;					//���̂���������
	if (game == NULL)						//���s����ꍇ�v���O�������I��
		return 0;
	if (!game->InitWindow(hInstance))		//Window���J���A���s����ꍇ�v���O�������I��
		return 0;

	game->Run();							//�Q�[���A�v�����N��

	delete game;							//Pointer�����
	game = 0;

	return 0;								//Application���I��
}
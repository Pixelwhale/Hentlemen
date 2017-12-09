//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FWindowAPI���g����Application�̋N��
//-------------------------------------------------------
#include <Core\Game.h>
#include <memory>

//WindowsAPI
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	std::shared_ptr<Core::Application> game;	//�Q�[���N���X

	game = std::make_shared<Core::Game>();		//���̂���������
	if (game == NULL)							//���s����ꍇ�v���O�������I��
		return 0;

	if (!game->InitWindow())					//Window���J���A���s����ꍇ�v���O�������I��
		return 0;

	game->Run();								//�Q�[���A�v�����N��

	return 0;									//Application���I��
}
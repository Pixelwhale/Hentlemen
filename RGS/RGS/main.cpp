//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：WindowAPIを使ってApplicationの起動
//-------------------------------------------------------
#include <Core\Game.h>

//WindowsAPI
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	Core::Application* game;				//ゲームクラス

	game = new Core::Game;					//実体を持たせる
	if (game == NULL)						//失敗する場合プログラムを終了
		return 0;
	if (!game->InitWindow(hInstance))		//Windowを開く、失敗する場合プログラムを終了
		return 0;

	game->Run();							//ゲームアプリを起動

	delete game;							//Pointerを解放
	game = 0;

	return 0;								//Applicationを終了
}
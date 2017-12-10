//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Contentを読み込むクラス
//-------------------------------------------------------
#pragma once
#include <map>

namespace Device 
{
	class ContentManager 
	{
	public:
		ContentManager();
		ContentManager(const ContentManager&);
		~ContentManager();

		///<summary>初期化処理</summary>
		void Initialize();
		///<summary>Memory上のTextureを解放</summary>
		void Release();

		///<summary>Textureを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="path">パス</param>
		void LoadTexture(std::string filename, std::string fileExtention, std::string path = "./Content/Texture/");

		///<summary>Textureを読み込む</summary>
		///<param name="fileName">Asset名</param>
		///<param name="fileExtention">拡張子</param>
		///<param name="total">総枚数</param>
		///<param name="xAmount">横の枚数</param>
		///<param name="yAmount">縦の枚数</param>
		///<param name="xSize">横サイズ</param>
		///<param name="ySize">縦サイズ</param>
		///<param name="path">パス</param>
		void LoadTexture(
			std::string filename, std::string fileExtention, 
			int total, int xAmount, int yAmount, int xSize, int ySize,
			std::string path = "./Content/Texture/");

		///<summary>Textureのハンドルを取得</summary>
		///<param name="textureName">Textureの名前</param>
		///<returns>Texture Handle</returns>
		int TextureHandle(std::string textureName);

		///<summary>Textureのハンドルを取得</summary>
		///<param name="textureName">Asset名</param>
		///<param name="motionIndex">何枚目</param>
		int MotionHandle(std::string textureName, int motionIndex);

	private:
		std::map<std::string, int> m_textures;			//テクスチャのハンドル
		std::map<std::string, int*> m_motion;			//Animated Texture
	};
}
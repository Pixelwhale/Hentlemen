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
		void LoadTexture(std::string filename, std::string fileExtention, std::string path);

		///<summary>Textureのハンドルを取得</summary>
		///<param name="textureName">Textureの名前</param>
		///<returns>Texture Handle</returns>
		int TextureHandle(std::string textureName);

	private:
		std::map<std::string, int> m_textures;			//テクスチャのハンドル
	};
}
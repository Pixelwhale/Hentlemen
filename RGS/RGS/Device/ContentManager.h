//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FContent��ǂݍ��ރN���X
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

		///<summary>����������</summary>
		void Initialize();
		///<summary>Memory���Texture�����</summary>
		void Release();

		///<summary>Texture��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadTexture(std::string filename, std::string fileExtention, std::string path);

		///<summary>Texture�̃n���h�����擾</summary>
		///<param name="textureName">Texture�̖��O</param>
		///<returns>Texture Handle</returns>
		int TextureHandle(std::string textureName);

	private:
		std::map<std::string, int> m_textures;			//�e�N�X�`���̃n���h��
	};
}
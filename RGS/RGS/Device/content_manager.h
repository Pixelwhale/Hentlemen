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

#pragma region Texture�֘A

		///<summary>Texture��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="path">�p�X</param>
		void LoadTexture(std::string filename, std::string fileExtention, std::string path = "./Content/Texture/");

		///<summary>Texture��ǂݍ���</summary>
		///<param name="fileName">Asset��</param>
		///<param name="fileExtention">�g���q</param>
		///<param name="total">������</param>
		///<param name="xAmount">���̖���</param>
		///<param name="yAmount">�c�̖���</param>
		///<param name="xSize">���T�C�Y</param>
		///<param name="ySize">�c�T�C�Y</param>
		///<param name="path">�p�X</param>
		void LoadTexture(
			std::string filename, std::string fileExtention,
			int total, int xAmount, int yAmount, int xSize, int ySize,
			std::string path = "./Content/Texture/");

		///<summary>Texture�̃n���h�����擾</summary>
		///<param name="textureName">Texture�̖��O</param>
		///<returns>Texture Handle</returns>
		int TextureHandle(std::string textureName);

		///<summary>Texture�̃n���h�����擾</summary>
		///<param name="textureName">Asset��</param>
		///<param name="motionIndex">������</param>
		int MotionHandle(std::string textureName, int motionIndex);

#pragma endregion

#pragma region Font�֘A

		///<summary>Font��ǂݍ���</summary>
		///<param name="fontName">Font�̖��O</param>
		///<param name="size">�傫��</param>
		///<param name="thickness">�����i0�`9�j</param>
		void LoadFont(std::string fontName, int size, int thickness);

		///<summary>Font�̃n���h�����擾</summary>
		///<param name="fontName">Font�̖��O</param>
		int FontHandle(std::string fontName);

#pragma endregion


	private:
		std::map<std::string, int> m_textures;			//�e�N�X�`���̃n���h��
		std::map<std::string, int*> m_motion;			//Animated Texture
		std::map<std::string, int> m_font;				//Font
	};
}
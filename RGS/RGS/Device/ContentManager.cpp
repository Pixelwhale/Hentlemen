//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FContent��ǂݍ��ރN���X
//-------------------------------------------------------
#include <Device\ContentManager.h>
#include <DX\DXLib\DxLib.h>

using namespace Device;

ContentManager::ContentManager()
{
}

ContentManager::ContentManager(const ContentManager&)
{
}

ContentManager::~ContentManager()
{
}

void ContentManager::Initialize()
{
	DxLib::InitGraph();			//Memory��̃e�N�X�`�������폜
	m_textures.clear();			//Texture��Handle���폜
}

void ContentManager::Release()
{
	DxLib::InitGraph();			//Memory��̃e�N�X�`�������폜
	m_textures.clear();			//Texture��Handle���폜
}

void ContentManager::LoadTexture(
	std::string filename, 
	std::string fileExtention, 
	std::string path = "./Content/Texture/")
{
	int handle = LoadGraph((path + filename + fileExtention).c_str());		//Texture��ǂݍ���
	m_textures[filename] = handle;											//Handle��Map�ɒǉ�
}

int  ContentManager::TextureHandle(std::string textureName) 
{
	return m_textures[textureName];
}
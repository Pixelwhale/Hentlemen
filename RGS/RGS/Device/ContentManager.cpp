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

	for (auto& map : m_motion)	//MotionHandle��Delete
	{
		delete[] map.second;
	}
	m_motion.clear();			//Motion��Handle���폜
}

void ContentManager::Release()
{
	DxLib::InitGraph();			//Memory��̃e�N�X�`�������폜
	m_textures.clear();			//Texture��Handle���폜

	for (auto& map : m_motion)	//MotionHandle��Delete
	{
		delete[] map.second;
	}
	m_motion.clear();			//Motion��Handle���폜
}

void ContentManager::LoadTexture(
	std::string filename, 
	std::string fileExtention, 
	std::string path)
{
	int handle = LoadGraph((path + filename + fileExtention).c_str());		//Texture��ǂݍ���
	m_textures[filename] = handle;											//Handle��Map�ɒǉ�
}

void  ContentManager::LoadTexture(
	std::string filename, std::string fileExtention,
	int total, int xAmount, int yAmount, int xSize, int ySize,
	std::string path)
{
	int* handle = new int[total];
	int error;
	error = LoadDivGraph((path + filename + fileExtention).c_str(),
		total, xAmount, yAmount, xSize, ySize, handle);						//Texture�𕪊����ēǂݍ���
	m_motion[filename] = handle;											//Handle��Map�ɒǉ�
}

int  ContentManager::TextureHandle(std::string textureName) 
{
	return m_textures[textureName];
}

int ContentManager::MotionHandle(std::string textureName, int motionIndex)
{
	return (m_motion[textureName])[motionIndex];
}
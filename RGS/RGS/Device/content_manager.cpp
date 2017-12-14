//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FContent��ǂݍ��ރN���X
//-------------------------------------------------------
#include <Device\content_manager.h>
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

	InitFontToHandle();			//Font��Handle���폜
	m_font.clear();

	LoadFont("Arial", -1, -1);
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

	InitFontToHandle();			//Font��Handle���폜
	m_font.clear();
}

#pragma region Texture�֘A

void ContentManager::LoadTexture(
	std::string file_name,
	std::string file_extention,
	std::string path)
{
	int handle = LoadGraph((path + file_name + file_extention).c_str());		//Texture��ǂݍ���
	m_textures[file_name] = handle;												//Handle��Map�ɒǉ�
}

void  ContentManager::LoadTexture(
	std::string file_name, std::string file_extention,
	int total, int x_count, int y_count, int x_size, int y_size,
	std::string path)
{
	int* handle = new int[total];
	int error;
	error = LoadDivGraph((path + file_name + file_extention).c_str(),
		total, x_count, y_count, x_size, y_size, handle);						//Texture�𕪊����ēǂݍ���
	m_motion[file_name] = handle;												//Handle��Map�ɒǉ�
}

int  ContentManager::TextureHandle(std::string texture_name)
{
	return m_textures[texture_name];
}

int ContentManager::MotionHandle(std::string texture_name, int motion_index)
{
	return (m_motion[texture_name])[motion_index];
}

#pragma endregion


#pragma region Font�֘A

void ContentManager::LoadFont(std::string font_name, int size, int thickness) 
{
	int handle;
	handle = CreateFontToHandle(font_name.c_str(), size, thickness);
	if (handle == -1)						//Error�΍�
		return;
	m_font[font_name] = handle;
}

int ContentManager::FontHandle(std::string font_name) 
{
	return m_font[font_name];
}

#pragma endregion

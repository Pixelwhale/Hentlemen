//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Contentを読み込むクラス
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
	DxLib::InitGraph();			//Memory上のテクスチャ情報を削除
	m_textures.clear();			//TextureのHandleを削除

	for (auto& map : m_motion)	//MotionHandleをDelete
	{
		delete[] map.second;
	}
	m_motion.clear();			//MotionのHandleを削除
}

void ContentManager::Release()
{
	DxLib::InitGraph();			//Memory上のテクスチャ情報を削除
	m_textures.clear();			//TextureのHandleを削除

	for (auto& map : m_motion)	//MotionHandleをDelete
	{
		delete[] map.second;
	}
	m_motion.clear();			//MotionのHandleを削除
}

void ContentManager::LoadTexture(
	std::string filename, 
	std::string fileExtention, 
	std::string path)
{
	int handle = LoadGraph((path + filename + fileExtention).c_str());		//Textureを読み込み
	m_textures[filename] = handle;											//HandleをMapに追加
}

void  ContentManager::LoadTexture(
	std::string filename, std::string fileExtention,
	int total, int xAmount, int yAmount, int xSize, int ySize,
	std::string path)
{
	int* handle = new int[total];
	int error;
	error = LoadDivGraph((path + filename + fileExtention).c_str(),
		total, xAmount, yAmount, xSize, ySize, handle);						//Textureを分割して読み込む
	m_motion[filename] = handle;											//HandleをMapに追加
}

int  ContentManager::TextureHandle(std::string textureName) 
{
	return m_textures[textureName];
}

int ContentManager::MotionHandle(std::string textureName, int motionIndex)
{
	return (m_motion[textureName])[motionIndex];
}
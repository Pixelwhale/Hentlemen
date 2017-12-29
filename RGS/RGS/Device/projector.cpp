//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.11
// 内容　：Projector
//-------------------------------------------------------
#include <Device\projector.h>
#include <Def\window_def.h>

using namespace Device;

Projector::Projector()
{
}

Projector::Projector(const Projector&)
{
}

Projector::~Projector()
{
}

void Projector::Initialize()
{
	SetCameraNearFar(1.0f, 1000.0f);								//Near 1.0 Far 1000.0
	SetupCamera_Ortho(100);											//Orthographic Zoom out 100

	SetTarget(Math::Vector3(0.0f, 0.0f, 0.0f));						//目標：原点
	SetRelativePosition(Math::Vector3(100.0f, 100.0f, -100.0f));	//相対位置設定(左手系座標なのでZは-)
}

void Projector::SetRelativePosition(Math::Vector3 relative_position)
{
	m_relative_position.x = relative_position.x;
	m_relative_position.y = relative_position.y;
	m_relative_position.z = relative_position.z;
	VectorAdd(&m_position, &m_relative_position, &m_target);		//位置設定
	UpdateView();
}

void Projector::SetTarget(Math::Vector3 target) 
{
	m_target.x = target.x;
	m_target.y = target.y;
	m_target.z = target.z;
	VectorAdd(&m_position, &m_relative_position, &m_target);		//位置設定
	UpdateView();
}

void Projector::Rotate(float angle) 
{
	VectorRotationY(&m_position, &m_relative_position, angle);		//Localに対して回転
	VectorAdd(&m_position, &m_position, &m_target);					//ターゲットへ移動
	UpdateView();
}

void Projector::Zoom(float rate) 
{
	SetupCamera_Ortho(rate);
}

void Projector::UpdateView() 
{
	SetCameraPositionAndTarget_UpVecY(m_position, m_target);
}

Math::Vector3 Projector::Position() 
{
	return  Math::Vector3(m_position.x, m_position.y, m_position.z);
}

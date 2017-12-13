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
	SetCameraNearFar(1.0f, 1000.0f);						//Near 1.0 Far 1000.0
	SetupCamera_Ortho(100);				//Orthographic Zoom out 100
}

void Projector::SetPosition(Math::Vector3 position)
{
	m_position.x = position.x;
	m_position.y = position.y;
	m_position.z = position.z;
	UpdateView();
}

void Projector::SetTarget(Math::Vector3 target) 
{
	m_target.x = target.x;
	m_target.y = target.y;
	m_target.z = target.z;
	UpdateView();
}

void Projector::UpdateView() 
{
	SetCameraPositionAndTarget_UpVecY(m_position, m_target);
}

//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.11
// ���e�@�FProjector
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
	Zoom(100);														//Orthographic Zoom out 100

	m_rotation = 0;
	SetTarget(Math::Vector3(0.0f, 0.0f, 0.0f));						//�ڕW�F���_
	SetRelativePosition(Math::Vector3(100.0f, 100.0f, -100.0f));	//���Έʒu�ݒ�(����n���W�Ȃ̂�Z��-)
}

void Device::Projector::SpriteMode()
{
	m_stock_target = m_target;										//�ݒ���L�^
	m_stock_rerelative_position = m_relative_position;

	SetupCamera_Ortho(WindowDef::kScreenHeight);					//�k��
	//��ʂ̍��������_
	SetTarget(Math::Vector3(WindowDef::kScreenWidth / 2, WindowDef::kScreenHeight / 2, 0.0f));
	SetRelativePosition(Math::Vector3(0, 0, -1));
}

void Device::Projector::PopSetting()
{
	m_target = m_stock_target;										//�ݒ��߂�
	m_relative_position = m_stock_rerelative_position;
	
	Rotate(m_rotation);												//��]�ʒu�֖߂�
	Zoom(m_zoom_rate);												//���̑傫���ɖ߂�
}

void Projector::SetRelativePosition(Math::Vector3 relative_position)
{
	m_relative_position.x = relative_position.x;
	m_relative_position.y = relative_position.y;
	m_relative_position.z = relative_position.z;
	VectorAdd(&m_position, &m_relative_position, &m_target);		//�ʒu�ݒ�
	UpdateView();
}

void Projector::SetTarget(Math::Vector3 target) 
{
	m_target.x = target.x;
	m_target.y = target.y;
	m_target.z = target.z;
	VectorAdd(&m_position, &m_relative_position, &m_target);		//�ʒu�ݒ�
	UpdateView();
}

void Projector::Rotate(float angle) 
{
	m_rotation = angle;												//��]�p�x���L�^
	VectorRotationY(&m_position, &m_relative_position, angle);		//Local�ɑ΂��ĉ�]
	VectorAdd(&m_position, &m_position, &m_target);					//�^�[�Q�b�g�ֈړ�
	UpdateView();
}

void Projector::Zoom(float rate) 
{
	m_zoom_rate = rate;					//�g��k������ۑ�
	SetupCamera_Ortho(rate);			//�g��k��
}

void Projector::UpdateView() 
{
	SetCameraPositionAndTarget_UpVecY(m_position, m_target);		//View���X�V
}

Math::Vector3 Projector::Position() 
{
	return  Math::Vector3(m_position.x, m_position.y, m_position.z);
}

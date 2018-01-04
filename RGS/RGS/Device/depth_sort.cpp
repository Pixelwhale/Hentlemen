//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.12
// ���e�@�F�����̂���e�N�X�`���̓\�[�g���ĕ`�悷��K�v��
//			����̂ŁA���̂��߂̃N���X
//-------------------------------------------------------
#include <Device\depth_sort.h>
#include <algorithm>

using namespace Device;

DepthSort::DepthSort(){}
DepthSort::DepthSort(const DepthSort&){}
DepthSort::~DepthSort(){}

void DepthSort::AddTransparentObj(TransparentObj obj)
{
	m_draw_list.push_back(obj);
}

void DepthSort::Clear()
{
	m_draw_list.clear();
}

void DepthSort::Sort(Math::Vector3 projector_pos)
{
	for (auto& obj:m_draw_list)		//�J�����Ƃ̋������v�Z
	{
		obj.projection_dis = (projector_pos - obj.position).lengthSqrt();
	}

	std::sort(m_draw_list.begin(), m_draw_list.end(), [](const TransparentObj& first, const TransparentObj& second)
	{
		return first.projection_dis > second.projection_dis;		//Sort
	});
}

std::vector<TransparentObj>& DepthSort::DrawList()
{
	return m_draw_list;
}
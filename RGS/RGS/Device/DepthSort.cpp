//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.12
// 内容　：透明のあるテクスチャはソートして描画する必要が
//			あるので、そのためのクラス
//-------------------------------------------------------
#include <Device\DepthSort.h>

using namespace Device;

DepthSort::DepthSort(){}
DepthSort::DepthSort(const DepthSort&){}
DepthSort::~DepthSort(){}

void DepthSort::AddTransparentObj(TransparentObj obj){}
void DepthSort::Clear(){}

void DepthSort::Sort(Math::Vector3 projectorPos){}
void DepthSort::Draw(){}
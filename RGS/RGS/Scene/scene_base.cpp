//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.18
// 内容　：シーンのベースクラス
//-------------------------------------------------------
#include <Scene\scene_base.h>

using namespace Scene;
using namespace Device;

Scene::SceneBase()
{
	m_renderer = GameDevice::GetInstance()->GetRenderer();
	m_input = GameDevice::GetInstance()->GetInput();
}
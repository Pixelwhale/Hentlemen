//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.11
// 内容　：Projector
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Math\Vector3.h>

namespace Device 
{
	class Projector 
	{
	public:
		Projector();
		Projector(const Projector&);
		~Projector();
		///<summary>初期化処理</summary>
		void Initialize();

		///<summary>カメラ位置を設定</summary>
		///<param name="position">位置</param>
		void SetPosition(Math::Vector3 position);
		///<summary>注目点を設定</summary>
		///<param name="target">注目目標</param>
		void SetTarget(Math::Vector3 target);

	private:
		///<summary>Viewを更新（移動などがある場合）</summary>
		void UpdateView();

	private:
		VECTOR m_position;		//Projectorの位置
		VECTOR m_target;		//注目点
	};
}
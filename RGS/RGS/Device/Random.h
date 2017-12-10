//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F�̍�������̂��N���X�����Ď����Ă���
// ���e�@�FRandom
//-------------------------------------------------------
#pragma once

namespace Device 
{
	class Random 
	{
	public:
		Random();
		Random(const Random&);
		~Random();

		///<summary>0�ȏ�̐�����Ԃ�</summary>
		int Next();
		///<summary>0�ȏ�max�����̐�����Ԃ�</summary>
		///<param name="max">�ő�l</param>
		int Next(int max);
		///<summary>min�ȏ�max�����̐�����Ԃ�</summary>
		///<param name="min">�ŏ��l</param>
		///<param name="max">�ő�l</param>
		int Next(int min, int max);

		///<summary>0����1��Double��Ԃ�</summary>
		double NextDouble();
	};
}
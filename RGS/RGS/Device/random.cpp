//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F�̍�������̂��N���X�����Ď����Ă���
// ���e�@�FRandom
//-------------------------------------------------------
#include <Device\random.h>
#include <random>
#include <ctime>

using namespace Device;

Random::Random()
{
	srand((int)time(NULL));	//�����_�������̃^�C���ŏ�����
}

Random::Random(const Random&)
{
}

Random::~Random()
{
}

int Random::Next()
{
	return rand();
}

int Random::Next(int max)
{
	int random = rand() % max;	//�ő�l���܂܂Ȃ� 0 �ȏ�̐�
	return random;
}

int Random::Next(int min, int max)
{
	int count = max - min;		//�͈͓��̐�
	int random_min = 0 - min;	//�ŏ��l
								//�]��Ŕ͈͂�����A�S�̂��ŏ��l�ŕ��s�ړ�
	int random = rand() % count - random_min;
	return random;
}

double Random::NextDouble()
{
	//		int		 int �ő�l
	return (rand() / (RAND_MAX * 1.0));
}
//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.10
// ���e�@�FColor
//-------------------------------------------------------
#pragma once
#include <Math\Vector3.h>

struct Color
{
public:
	Color(Math::Vector3 vector);
	Color(Math::Vector3 vector, int a);
	Color(int r, int g, int b);
	Color(float r, float g, float b);
	Color(int r, int g, int b, int a);
	Color(float r, float g, float b, float a);
	Color(const Color&);
	~Color();

	///<summary>Lerp</summary>
	Color Lerp(Color color1, Color color2, float amount);
	///<summary>�|���Z</summary>
	Color Multiply(Color color, float scale);

	///<summary>�����F�̏ꍇ��True</summary>
	bool Equals(Color other);

	///<summary>Red�i0.0f�`1.0f�j</summary>
	float R();
	///<summary>Green�i0.0f�`1.0f�j</summary>
	float G();
	///<summary>Blue�i0.0f�`1.0f�j</summary>
	float B();
	///<summary>Alpha�i0.0f�`1.0f�j</summary>
	float A();

	friend static Color operator *(Color value, float scale)
	{
		value.r = (int)(value.r * scale);
		value.g = (int)(value.g * scale);
		value.b = (int)(value.b * scale);
		value.a = (int)(value.a * scale);
		value.Clamp();
		return value;
	}

	friend static Color operator *(float scale, Color value)
	{
		value.r = (int)(value.r * scale);
		value.g = (int)(value.g * scale);
		value.b = (int)(value.b * scale);
		value.a = (int)(value.a * scale);
		value.Clamp();
		return value;
	}

	friend static bool operator ==(Color a, Color b)
	{
		return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
	}

	friend static bool operator !=(Color a, Color b)
	{
		return !(a == b);
	}

private:
	void Clamp();		//�i0�`255�j�ɂ���

public:
	int r;		//Red�i0�`255�j
	int g;		//Green�i0�`255�j
	int b;		//Blue�i0�`255�j
	int a;		//Alpha�i0�`255�j
};
//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F�̍�������̂����̂܂܎����Ă���
// ���e�@�FVector3
//-------------------------------------------------------
#pragma once

namespace Math
{
	struct Vector3
	{
	public:   
		Vector3();    
		Vector3(float X, float Y, float Z );
		Vector3(const Vector3& other);

		float    length() const;                       
		Vector3& normalize();                          
		float    dot( const Vector3& v ) const;     
		Vector3  cross( const Vector3& v ) const;   
		Vector3  operator + () const;    
		Vector3  operator - () const;

		Vector3&  operator += ( const Vector3& v );    
		Vector3&  operator -= ( const Vector3& v );    
		Vector3&  operator *= ( float s );    
		Vector3&  operator /= ( float s );

		Vector3 Clamp(const Vector3& v, const Vector3& min, const Vector3& max);

		friend const Vector3 operator + ( const Vector3& v1, const Vector3& v2 )
		{
			return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		}
		friend const Vector3 operator - ( const Vector3& v1, const Vector3& v2 )
		{
			return Vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		}
		friend const Vector3 operator * ( const Vector3& v, float s )
		{
			return Vector3(v.x * s, v.y * s, v.z * s);
		}
		friend const Vector3 operator * ( float s, const Vector3& v )
		{
			return Vector3(v.x * s, v.y * s, v.z * s);
		}
		friend const Vector3 operator / (const Vector3& v, float s) 
		{
			return Vector3(v.x / s, v.y / s, v.z / s);
		}

	public:
		float x;
		float y;
		float z;
	};
}
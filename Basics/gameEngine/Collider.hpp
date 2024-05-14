// Collider.h
#ifndef COLLIDER_H
#define COLLIDER_H
#include <iostream>
class Collider
{
public:
	Vector3();
	Vector3(float coords[3]);
	Vector3(float x, float y, float z);
	bool equals(const Vector3& rhs);

	Vector3 add(const Vector3& rhs);
	Vector3 operator+(const Vector3& rhs);

	Vector3 sub(const Vector3& rhs);
	Vector3 operator-(const Vector3& rhs);

	Vector3 mul(float scalar);
	Vector3 operator*(float scalar);

	float length();
	void normalize();

	float dot(const Vector3& rhs);
	float operator*(const Vector3& rhs);

	float* toFloatArray();
	operator float* ();

	void print();
	void input();
	float mX;
	float mY;
	float mZ;
};

std::istream& operator>>(std::istream& is, Vector3& v);
std::ostream& operator<<(std::ostream& os, const Vector3& v);


#endif // COLLIDER_H

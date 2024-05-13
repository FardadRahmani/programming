//Vector3.cpp
#include "Vector3.hpp"
using namespace std;

Vector3::Vector3()
{
	mX = 0.0f;
	mY = 0.0f;
	mZ = 0.0f;
}
Vector3::Vector3(float coords[3])
{
	mX = coords[0];
	mY = coords[1];
	mZ = coords[2];
}
Vector3::Vector3(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}
bool Vector3::equals(const Vector3& rhs)
{
	// Return true if the corresponding components are equal.
	return
		mX == rhs.mX &&
		mY == rhs.mY &&
		mZ == rhs.mZ;
}

//ADD
Vector3 Vector3::add(const Vector3& rhs)
{
	Vector3 sum;
	sum.mX = mX + rhs.mX;
	sum.mY = mY + rhs.mY;
	sum.mZ = mZ + rhs.mZ;
	return sum;
}
Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 sum;
	sum.mX = mX + rhs.mX;
	sum.mY = mY + rhs.mY;
	sum.mZ = mZ + rhs.mZ;
	return sum;
}

//Subtract
Vector3 Vector3::sub(const Vector3& rhs)
{
	Vector3 dif;
	dif.mX = mX - rhs.mX;
	dif.mY = mY - rhs.mY;
	dif.mZ = mZ - rhs.mZ;
	return dif;
}
Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 dif;
	dif.mX = mX - rhs.mX;
	dif.mY = mY - rhs.mY;
	dif.mZ = mZ - rhs.mZ;
	return dif;
}

//Scalar Product
Vector3 Vector3::mul(float scalar)
{
	Vector3 p;
	p.mX = mX * scalar;
	p.mY = mY * scalar;
	p.mZ = mZ * scalar;
	return p;
}
Vector3 Vector3::operator*(float scalar)
{
	Vector3 p;
	p.mX = mX * scalar;
	p.mY = mY * scalar;
	p.mZ = mZ * scalar;
	return p;
}

//Dot Product
float Vector3::dot(const Vector3& rhs)
{
	float dotP = mX * rhs.mX + mY * rhs.mY + mZ * rhs.mZ;
	return dotP;
}
float Vector3::operator*(const Vector3& rhs)
{
	float dotP = mX * rhs.mX + mY * rhs.mY + mZ * rhs.mZ;
	return dotP;
}


float Vector3::length()
{
	return sqrtf(mX * mX + mY * mY + mZ * mZ);
}
void Vector3::normalize()
{
	// Get 'this' vector's length.
	float len = length();
	// Divide each component by the length.
	mX /= len;
	mY /= len;
	mZ /= len;
}

//Conversion to float Array
float* Vector3::toFloatArray()
{
	return &mX;		//returns adress of first element of Vector3 object
}
Vector3::operator float* ()
{
	return &mX;
}



/*
float mX;
float mY;
float mZ;
The memory of mY comes directly after mX, and the memory for mZ comes directly after mY.:

Vector3 w(-5.0f, 2.0f, 0.0f);
float* wArray = w.toFloatArray();
// wArray[0] == w.x == -5.0f
// wArray[1] == w.y == 2.0f
// wArray[2] == w.z == 0.0f

*/

void Vector3::print()
{
	cout << "<" << mX << ", " << mY << ", " << mZ << "> \n";
}

void Vector3::input()
{
	cout << "Enter x: ";
	cin >> mX;
	cout << "Enter y: ";
	cin >> mY;
	cout << "Enter z: ";
	cin >> mZ;
}


std::istream& operator>>(std::istream& is, Vector3& v)
{
	cout << "Enter x: ";
	cin >> v.mX;
	cout << "Enter y: ";
	cin >> v.mY;
	cout << "Enter z: ";
	cin >> v.mZ;
	return is;
}
std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	cout << "<" << v.mX << ", " << v.mY << ", " << v.mZ << "> \n";
	return os;
}
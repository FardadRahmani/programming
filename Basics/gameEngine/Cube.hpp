// Cube.hpp
#ifndef Cube_H
#define Cube_H
#include <iostream>
#include <string>
#include "Shape.hpp"
#include "Vector3.hpp"

using namespace std;

class Cube: public Shape
{
public:
	Cube(float posX, float posY, float posZ, float w, float l, float h): Shape(posX, posY, posZ), mWidth(w), mLength(l), mHeight(h) { }
	string type() { return "Cube"; };
	float volume() { return mWidth * mLength * mHeight; }
	void resetSize(float w, float l, float h) { mWidth = w; mLength = l; mHeight = h; }


private: 
	float mWidth;
	float mLength;
	float mHeight;


};


#endif // VECTOR3_H


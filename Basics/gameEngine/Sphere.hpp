// Sphere.hpp
#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include <string>
#include "Shape.hpp"
#include "Vector3.hpp"

using namespace std;
const float PI = 3.14;
class Sphere : public Shape
{
public:
	Sphere(float posX, float posY, float posZ, float rad) : Shape(posX, posY, posZ), mRadius(rad) {}
	string type() { return "Sphere"; };
	float volume() { return (4/3)*PI* mRadius* mRadius* mRadius; }
	void setSize(float r) { mRadius = r; }



private:
	float mRadius;
	

};


#endif // SPHERE_H


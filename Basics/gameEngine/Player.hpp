// Sphere.hpp
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Shape.hpp"
#include "Vector3.hpp"

using namespace std;

class Player : public Shape
{
public:
	Player(float posX, float posY, float posZ, bool npc, string name) : Shape(posX, posY, posZ), mNpc(npc), mName(name) {}
	string type() { return "Player"; };
	



private:
	
	bool mNpc;	//0= Player; 1= NPC
	string mName


};


#endif // PLAYER_H


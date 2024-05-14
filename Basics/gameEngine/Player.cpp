
#include "Player.hpp"



//class Player : public Shape
//{
//public:
//	Player(float posX, float posY, float posZ, bool npc, string name) : Shape(posX, posY, posZ), mNpc(npc), mName(name) {}
//	string type() { return "Player"; }
//	string getname() const { return mName; }
//	void move();
//
//
//
//private:
//
//	bool mNpc;	//0= Player; 1= NPC
//	string mName;
//
//
//};

void Player::move()
{
	cout << "======================Player Position:===========================" << endl;
	cout << "======================";
	cout << "<" << this->mPosition.mX << ", " << this->mPosition.mY << ", " << this->mPosition.mZ << ">";
	cout << "======================" << endl;
	cout << "=================================================================" << endl;
	cout << "Move   (N)orth   (E)ast   (S)outh   (W)est   (F)ly   (D)escend   (Q)uit Movement?" << endl;
	char dir; cin >> dir;
	while (dir != 'q' || dir != 'Q')
	{
		switch (dir)
		{
		case 'n':
		case 'N':
			this->mPosition.mY++;
			break;
		case 'e':
		case 'E':
			this->mPosition.mX++;
			break;
		case 's':
		case 'S':
			this->mPosition.mY--;
			break;
		case 'w':
		case 'W':
			this->mPosition.mX--;
			break;
		case 'f':
		case 'F':
			this->mPosition.mZ++;
			break;
		case 'd':
		case 'D':
			this->mPosition.mZ--;
			break;
		case 'q':
		case 'Q':
			dir = 'q';
			break;



		}//switch
	}//while

}



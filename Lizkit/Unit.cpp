#include "pch.h"
#include "Unit.h"


namespace Lizkit {
	Unit::Unit(const std::string& picFile, int hp) : mPicture(picFile), mHP(hp) {
	
	}

	Unit::Unit(const std::string& picFile, int hp, int x, int y) : mPicture(picFile), mHP(hp), mXcoord(x), mYcoord(y) {

	}

	Unit::Unit(std::string&& picFile, int hp) : mPicture(picFile), mHP(hp) {
	
	}

	Picture& Unit::GetPicture(){
		return mPicture;
	}

	void Unit::SetCoord(int x, int y, int z) {
		mXcoord = x;
		mYcoord = y;
		mZcoord = z;
	}

	int Unit::ChangeX(int xDiff) {
		mXcoord += xDiff;
		return mXcoord;
	}

	int Unit::ChangeY(int yDiff) {
		mYcoord += yDiff;
		return mYcoord;
	}

	int Unit::ChangeZ(int zDiff) {
		mZcoord += zDiff;
		return mZcoord;
	}


	void Unit::SetX(int x){
		mXcoord = x;
	}
	void Unit::SetY(int y){
		mYcoord = y;
	}

	int Unit::GetX() const {
		return mXcoord;
	}
	int Unit::GetY() const {
		return mYcoord;
	}
	int Unit::GetZ() const {
		return mZcoord;
	}

	int Unit::ChangeHP(int hpDiff) {
		mHP += hpDiff;
		return mHP;
	}

	void Unit::SetHP(int hp){
		mHP = hp;
	}

	int Unit::GetHP() const {
		return mHP;
	}

	bool Unit::OverlapsWith(const Unit& other) const {
		int oneLeft{ GetX() };
		int oneRight{ GetX() + mPicture.GetWidth() };
		int anotherLeft{ other.GetX() };
		int anotherRight{ other.GetX() + other.mPicture.GetWidth()};

		int oneBottom{ GetY()};
		int oneTop{ GetY() + mPicture.GetHeight() };
		int anotherBottom{ other.GetY() };
		int anotherTop{ other.GetY() + other.mPicture.GetHeight() };

		bool collideX{ false };
		if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) || (anotherLeft <= oneLeft && oneLeft <= anotherRight))
			collideX = true;

		bool collideY{ false };
		if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) || (anotherBottom <= oneBottom && oneBottom <= anotherTop))
			collideY = true;
	
		return collideX && collideY;
	}
}
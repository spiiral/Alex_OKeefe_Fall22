#pragma once

#include "LizkitUtil.h"
#include "Picture.h"

namespace Lizkit{
	class LIZKIT_API Unit {
	public: 
		Unit(const std::string& picFile, int hp);
		Unit(const std::string& picFile, int hp, int x, int y);
		Unit(std::string&& picFile, int hp);

		void SetCoord(int x, int y, int z);

		Picture& GetPicture();

		int ChangeX(int xDiff);
		int ChangeY(int yDiff);
		int ChangeZ(int zDiff);

		void SetX(int x);

		void SetY(int y);

		int GetX() const;
		int GetY() const;
		int GetZ() const;

		int ChangeHP(int hpDiff);
		int GetHP() const;

		bool OverlapsWith(const Unit& other) const;
	private:
		Picture mPicture;
		int mHP;
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };

		friend class Renderer;
	};

}
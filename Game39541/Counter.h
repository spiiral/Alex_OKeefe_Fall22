#pragma once
#include "Renderer.h"

class Counter {
public:
	void DrawCounter(int num) {

		int xCoord{ 960 };

		if (num == 0) {
			Lizkit::Renderer::Draw(m_Digits[num], xCoord - 55, 720, 1);
		}
		while (num > 0) {
			int index = num % 10;
			xCoord -= 55;
			Lizkit::Renderer::Draw(m_Digits[index], xCoord, 720, 1);
			num = num / 10;
		}
	}
private:
	std::vector<Lizkit::Picture> m_Digits{
		Lizkit::Picture("Assets/Textures/0.png"),
		Lizkit::Picture("Assets/Textures/1.png"),
		Lizkit::Picture("Assets/Textures/2.png"),
		Lizkit::Picture("Assets/Textures/3.png"),
		Lizkit::Picture("Assets/Textures/4.png"),
		Lizkit::Picture("Assets/Textures/5.png"),
		Lizkit::Picture("Assets/Textures/6.png"),
		Lizkit::Picture("Assets/Textures/7.png"),
		Lizkit::Picture("Assets/Textures/8.png"),
		Lizkit::Picture("Assets/Textures/9.png"),
	};
};

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Block : public RectangleShape
{
	vector<RectangleShape*> shadow;
public:
	Block(float x, float y) : RectangleShape({ 1,1 }) {
		setPosition({ x,y });
		setFillColor(Color::Yellow);
	}
	void makeShadow(float lightX, float lightY);
	void drawShadow(RenderWindow& window);
	void updateShadow(float lightX, float lightY);
};


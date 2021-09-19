#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Pixel : public RectangleShape
{
	
public:
	Pixel(Vector2f a) : RectangleShape(a) {
		
	}
	int getDistance(int x, int y);
	Color& getShade(int dis, float a);
	
	void addColor(int r, int g, int b);
};


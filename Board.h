#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Pixel.h"
using namespace std;
using namespace sf;
class Board
{
	vector<vector<Pixel*>> pixels;
public:
	int pixCount;
	Board(int dim) {
		pixCount = dim;
		for (int i = 0; i < pixCount; ++i) {
			vector<Pixel*> tem;
			for (int j = 0; j < pixCount; ++j) {
				float a = 1000 / pixCount;
				
				Vector2f b = { a,a };
				Pixel* ptr = new Pixel(b);
				ptr->setPosition(i * a, j * a);
				ptr->setFillColor(ptr->getShade(ptr->getDistance(500,500),0));
				tem.push_back(ptr);
			}
			pixels.push_back(tem);
		}
	}
	void drawAllPixels(RenderWindow& window);
	void updateShades(int x, int y, float a);
	void addAllColor(int r, int g, int b);
};


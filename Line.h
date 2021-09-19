#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Line
{
private:
	vector<RectangleShape> pixels;
	vector<int> direction;
public:
	Line(int x, int y) {
		direction.push_back(x);
		direction.push_back(y);
	}
	

};


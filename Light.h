#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Light : public CircleShape
{
public:
	Light() : CircleShape(5) {
		setFillColor(Color::White);
		setPosition(500, 500);
	}
};


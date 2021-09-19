#include "Block.h"
#include <iostream>
using namespace sf;
using namespace std;
void Block::makeShadow(float lightX, float lightY) {
	
	float xDir = getPosition().x - lightX;
	float yDir = getPosition().y - lightY;
	
	float x = getPosition().x;
	float y = getPosition().y;
	for (int i = 0; i < 1000; ++i) {
		
		RectangleShape* temp = new RectangleShape({ 1,1 });
		temp->setFillColor(Color::Black);
		temp->setPosition({ x,y });
		x += xDir/100;
		y += yDir/100;
		shadow.push_back(temp);
	}

}
void Block::updateShadow(float lightX, float lightY) {
	float xDir = getPosition().x - lightX;
	float yDir = getPosition().y - lightY;

	float x = getPosition().x;
	float y = getPosition().y;
	for (int i = 0; i < 1000; ++i) {

		shadow.at(i)->setPosition({x,y});
		
		x += xDir / 100;
		y += yDir / 100;
		
	}
}
void Block::drawShadow(RenderWindow& window) {
	for (int i = 0; i < shadow.size(); ++i) {
		window.draw(*shadow.at(i));
	}
}
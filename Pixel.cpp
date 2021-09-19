#include "Pixel.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace sf;
using namespace std;
int Pixel::getDistance(int x, int y) {
	
	return sqrt(pow(x - getPosition().x, 2) + pow(y - getPosition().y, 2));
}
Color& Pixel::getShade(int dis, float a) { // wtf!! //
	bool coolMode = true;
	float intensity = .05; // if change > 1 weird shit // // lower = higher 
	if (coolMode) {
		intensity =  0 + a;
	}
	int val = 255 - (dis * 1000 / 255 * intensity);
	if (!coolMode &&  val < 0) {
		val = 1;
	}
	Color temp(val,val,val);
	return temp;
}
void Pixel::addColor(int r, int g, int b) {
	Color temp(getFillColor().r - r, getFillColor().g -g, getFillColor().b - b);
	setFillColor(temp);
}
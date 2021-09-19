#include "Board.h"
using namespace std;
using namespace sf;
void Board::drawAllPixels(RenderWindow& window) {
	for (int i = 0; i < pixCount; ++i) {
		for (int j = 0; j < pixCount; ++j) {
			window.draw(*pixels.at(i).at(j));
		}
	}
}
void Board::updateShades(int x, int y, float a) {
	for (int i = 0; i < pixCount; ++i) {
		for (int j = 0; j < pixCount; ++j) {
			
			Pixel* ptr = pixels.at(i).at(j);
			
			ptr->setFillColor(ptr->getShade(ptr->getDistance(x, y),a));
		}
	}
	
}
void Board::addAllColor(int r, int g, int b) {
	for (int i = 0; i < pixCount; ++i) {
		for (int j = 0; j < pixCount; ++j) {
			pixels.at(i).at(j)->addColor(r, g, b);
		}
	}
}
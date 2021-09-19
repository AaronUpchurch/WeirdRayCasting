#include "BigBlock.h"
using namespace std;
using namespace sf;
void BigBlock::drawAllBlocks(RenderWindow& window) {
	for (int i = 0; i < blocks.size(); ++i) {
		for (int j = 0; j < blocks.at(0).size(); ++j) {
			blocks.at(i).at(j).drawShadow(window);
		}
	}
}
void BigBlock::updateAllShadows(float& x, float& y) {
	for (int i = 0; i < blocks.size(); ++i) {
		for (int j = 0; j < blocks.at(i).size(); ++j) {
			blocks.at(i).at(j).makeShadow(x,y);
		}
	}
}
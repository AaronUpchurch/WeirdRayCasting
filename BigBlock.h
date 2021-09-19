#pragma once
#include "Block.h"
#include <vector>
using namespace std;
using namespace sf;
class BigBlock
{
	vector<vector<Block>> blocks;
public:
	BigBlock(float x, float y, int length, int height) {
		int x_ = x;
		vector<Block> tempVec;
		for (int i = 0; i < length; ++i) {
			tempVec.clear();
			x = x_;
			for (int j = 0; j < length; ++j) {
				Block temp(x, y);
				tempVec.push_back(temp);
				++x;
			}
			blocks.push_back(tempVec);
			++y;
		}
	}
	void drawAllBlocks(RenderWindow& window);
	void updateAllShadows(float& x, float& y);
};


#include "block.h"
#include <cmath>
#include <iostream>

int Block::Height() const {
    return data.size();
}

int Block::Width() const {
    return data[0].size();

}

void Block::Render(PNG &im, int x) const {
	for (int i = 0; i< Width(); i++) {
        for(int j = 0; j < Height(); j++) {
            RGBAPixel *pixel = im.getPixel(x + i, j);
            *pixel = data[i][j];
        }
    }

}

void Block::Build(PNG &im, int x, int width) {
}

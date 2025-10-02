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
	/* your code here */

}

void Block::Build(PNG &im, int x, int width) {
	for (int i = 0; i < 10; i++) {
        for(int j = x; j <= width; j++) {
            // save da pixel
        }
    }
}

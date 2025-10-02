#include "block.h"
#include <cmath>
#include <iostream>

int Block::Height() const {
    if (!data.empty()) 
    {
        return data[0].size(); 
    } 
    else 
    {
        return 0;
    }
	
}

int Block::Width() const {
	return data.size(); 
}

// draws the current block into im
void Block::Render(PNG& im, int x) const
{
    if (im.width() == 0 || im.height() == 0) {
        return;
    }
    
    for (int i = 0; i < Width(); i++)
    {
        for (int j = 0; j < Height(); j++)
        {
            RGBAPixel *pixel = im.getPixel(x + i, j);
            *pixel = data[i][j];
        }
    }
}

void Block::Build(PNG &im, int x, int width)
{
    data.clear();
    data.resize(width);

    for (int i = 0; i < width; i++)
    {
        data[i].resize(im.height());
        for (int j = 0; j < im.height(); j++)
        {
            RGBAPixel *pixel = im.getPixel(x + i, j);
            data[i][j] = *pixel;
        }
    }
}

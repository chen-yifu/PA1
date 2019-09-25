#include "block.h"


/**
 * Returns the width of the block.
 */
int Block::width() const{/*your code here*/
    return data[0].size();
}

/**
 * Returns the height of the block.
 */
int Block::height() const{/*your code here*/
    return data.size();
}

/**
 * Default Block constructor.
 */
Block::Block() {/* nothing */}

/**
 * Useful Block constructor.
 * Makes a block from the rectangle of width by height pixels in im
 * whose upper-left corner is at position (x,y).
 */
Block::Block(PNG & im, int x, int y, int width, int height) {/*your code here*/
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++ ) {
            data[i][j] = im.getPixel(x+j,y+i);
        }
    }
}

/**
 * Draws the block at position (x,y) in the image im
 */
void Block::render(PNG & im, int x, int y) const {/*your code here*/
    for (int i = 0; i < height(); j++) {
        for (int j = 0; j < width(); i++ ) {
            im.getPixel(x+j,y+i)->h = data[i][j].h;
            im.getPixel(x+j,y+i)->s = data[i][j].s;
            im.getPixel(x+j,y+i)->l = data[i][j].l;
            im.getPixel(x+j,y+i)->a = data[i][j].a;
        }
    }
}

/**
 * Changes the saturation of every pixel in the block to 0,
 * which removes the color, leaving grey.
 */
void Block::greyscale() {/*your code here*/
    for (int i = 0; i < height(); j++) {
        for (int j = 0; j < width(); i++ ) {
            data[i][j].s = 0;
        }
    }
}


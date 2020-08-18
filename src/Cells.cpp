//
// Created by ash on 14/08/2020.
//

#include "Cells.h"
#include <iostream>
#include <cstring>
#include "time.h"

Cells::Cells(unsigned int width_, unsigned int height_)
        : width{width_}, height{height_} {
    length = width * height;
    cells = new unsigned char[length];
    memset(cells, 0, length);
};

Cells::~Cells() {
    delete[] cells;
    delete[] temp;
}

void Cells::initRandom(int seed) {
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (double (rand())/RAND_MAX < 0.2)
                setCell(i, j);
        }
    }
}

bool Cells::isActive(int y, int x) {
    unsigned char *cell;
    cell = cells + (y * width) + x;
    return *cell & 0x01;
}

void Cells::setCell(unsigned int y, unsigned int x) {
    int left, right, top, bot;
    unsigned char *cell = cells + (y * width) + x;

    if (x == 0)
        left = width - 1;
    else
        left = -1;
    if (y == 0)
        top = length - width;
    else
        top = -width;
    if (x == (width - 1))
        right = -(width - 1);
    else
        right = 1;
    if (y == (height - 1))
        bot = -(length - width);
    else
        bot = width;

    *(cell) |= 0x01;
    *(cell + top + left) += 2;
    *(cell + top) += 2;
    *(cell + top + right) += 2;
    *(cell + left) += 2;
    *(cell + right) += 2;
    *(cell + bot + left) += 2;
    *(cell + bot) += 2;
    *(cell + bot + right) += 2;
}

void Cells::clearCell(unsigned int y, unsigned int x) {
    int left, right, top, bot;
    unsigned char *cell = cells + (y * width) + x;

    if (x == 0)
        left = width - 1;
    else
        left = -1;
    if (y == 0)
        top = length - width;
    else
        top = -width;
    if (x == (width - 1))
        right = -(width - 1);
    else
        right = 1;
    if (y == (height - 1))
        bot = -(length - width);
    else
        bot = width;

    *(cell) &= ~0x01;
    *(cell + top + left) -= 2;
    *(cell + top) -= 2;
    *(cell + top + right) -= 2;
    *(cell + left) -= 2;
    *(cell + right) -= 2;
    *(cell + bot + left) -= 2;
    *(cell + bot) -= 2;
    *(cell + bot + right) -= 2;
}

void Cells::switchCell(int y, int x) {
    isActive(y, x) ? clearCell(y, x) : setCell(y, x);
}

void Cells::prepareNext() {
    unsigned int x, y, count;
    unsigned char *cell, *row_cell;

    memcpy(temp, cells, length);

    cell = temp;// Pointer to temp cells
    for (y = 0; y < height; y++) {
        x = 0;
        do {
            //Skips through dead cells (Not on, no activate neighbors)
            while (*cell == 0) {
                cell++;
                if (++x >= width) goto NextRow;
            }
            //Cell is on or has on neighbors
            count = *cell >> 1; //Count neigbours
            if (*cell & 0x01) {
                if ((count != 2) && (count != 3)) {
                    clearCell(y, x);
                }
            } else {
                if (count == 3) {
                    setCell(y, x);
                }
            }
            cell++;
        } while (++x < width);
        NextRow:;
    }
}

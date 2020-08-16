//
// Created by ash on 14/08/2020.
//

#include "Cells.h"
#include <iostream>
#include <time.h>

Cells::Cells(int width_, int height_)
        : width{width_}, height{height_} {
    srand(time(NULL));
    std::vector<std::vector<bool>> cell(height, std::vector<bool>(width, false));
    cells = cell;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cells[i][j] = (double(rand()) / RAND_MAX < 0.1);
        }
    }
};

Cells::~Cells() {
}

bool Cells::isActive(int y, int x) {
    return cells[y][x];
}

void Cells::switchCell(int y, int x) {
    cells[y][x] = !cells[y][x];
}

void Cells::prepareNext() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cells[i][j] = cells[i][j];
        }
    }
}

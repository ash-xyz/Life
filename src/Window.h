//
// Created by ash on 13/08/2020.
//

#ifndef LIFE_WINDOW_H
#define LIFE_WINDOW_H

#include <SFML/Graphics.hpp>

class Window {
public:
    void drawBoard();

private:
    int height;
    int width;
    int squareSize;
};


#endif //LIFE_WINDOW_H

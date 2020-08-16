//
// Created by ash on 11/08/2020.
//
#include <SFML/Graphics.hpp>
#include "Cells.h"

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)

int main() {
    const int CELL_SIZE = 30;
    const sf::Vector2f CELL_VECTOR(CELL_SIZE, CELL_SIZE);
    const int GRID_WIDTH = 30;
    const int GRID_HEIGHT = 20;

    Cells cells(GRID_WIDTH, GRID_HEIGHT);

    int delay = 100;
    bool isPlaying = true;

    sf::Font font;
    font.loadFromFile(".././fonts/roboto.ttf");

    sf::Text textPause("Press 'space' to pause.", font);
    textPause.setCharacterSize(15);
    textPause.setPosition(10, CELL_SIZE * GRID_HEIGHT + 5);
    textPause.setFillColor(BLACK);

    sf::Text textPlay("Press 'space' to play.", font);
    textPlay.setCharacterSize(15);
    textPlay.setPosition(10, CELL_SIZE * GRID_HEIGHT + 5);
    textPlay.setFillColor(BLACK);

    sf::Text textToggle("Click on cell to toggle live/dead cell.", font);
    textToggle.setCharacterSize(15);
    textToggle.setPosition(10, CELL_SIZE * GRID_HEIGHT + 25);
    textToggle.setFillColor(BLACK);

    sf::Text textSpeed("Use left/right arrow keys to change speed.", font);
    textSpeed.setCharacterSize(15);
    textSpeed.setPosition(300, CELL_SIZE * GRID_HEIGHT + 5);
    textSpeed.setFillColor(BLACK);

    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * GRID_WIDTH, CELL_SIZE * GRID_HEIGHT + 50), "Game of Life");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent((event))) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space)
                        isPlaying = !isPlaying;
                    else if (event.key.code == sf::Keyboard::Right)
                        delay = std::max(delay - 50, 0);
                    else if (event.key.code == sf::Keyboard::Left)
                        delay += 50;
                    break;
                case sf::Event::MouseButtonPressed:
                    if (!isPlaying && event.mouseButton.button == sf::Mouse::Left) {
                        int x = double(event.mouseButton.x) / CELL_SIZE;
                        int y = double(event.mouseButton.y) / CELL_SIZE;
                        if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
                            cells.switchCell(y, x);
                    }
                    break;
            }
        }

        window.clear(WHITE);
        for (int x = 0; x < GRID_WIDTH; x++) {
            for (int y = 0; y < GRID_HEIGHT; y++) {
                // draw cell
                sf::RectangleShape cell;
                cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                cell.setSize(CELL_VECTOR);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(GRAY);
                if (cells.isActive(y,x))
                    cell.setFillColor(BLACK);
                else
                    cell.setFillColor(WHITE);
                window.draw(cell);
            }
        }
        if(isPlaying)
        {
            cells.prepareNext();
        }
        window.draw(textSpeed);
        if (isPlaying)
            window.draw(textPause);
        else
        {
            window.draw(textPlay);
            window.draw(textToggle);
        }

        window.display();
        sf::sleep(sf::milliseconds(delay));
    }
}
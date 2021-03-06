//
// Created by ash on 14/08/2020.
//

#ifndef LIFE_CELLS_H
#define LIFE_CELLS_H

class Cells {
private:
    unsigned char *cells;
    unsigned char *temp;
    unsigned int width;
    unsigned int height;
    unsigned int length;

    /**
     * Switches Cell on
     *
     * @param y: location along y axis
     * @param x: location along x axis
     */
    void setCell(unsigned int y, unsigned int x);

    /**
     * Switches Cell off
     *
     * @param y: location along y axis
     * @param x: location along x axis
     */
    void clearCell(unsigned int y, unsigned int x);

public:
    /**
     * Constructor for the cells
     *
     * @param width: width of the cells
     * @param height: height of the cells
     */
    Cells(unsigned int width, unsigned int height);

    /**
     * Destructor for the cells
     */
    ~Cells();

    /**
     * Outputs whether a cell is Active or Not
     *
     * @param y: location along the y axis
     * @param x: location along the x axis
     * @return : True if the cell is the active, False otherwise
     */
    bool isActive(int y, int x);

    /**
     * Prepares the next board
     */
    void prepareNext();

    /**
     * Switches the cell's activity to the opposite activity; on->off, off->on
     *
     * @param y: location along the y axis
     * @param x: location along the x axis
     */
    void switchCell(int y, int x);

    /**
     * Initializes the cells
     *
     * @param seed: seed for the randomizer, 0 for random initialization
     * @param epsilon: Expect number of activations
     */
    void initRandom(int seed = 0, double epsilon = 0.2);
};


#endif //LIFE_CELLS_H

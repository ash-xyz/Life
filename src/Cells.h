//
// Created by ash on 14/08/2020.
//

#ifndef LIFE_CELLS_H
#define LIFE_CELLS_H


class Cells {
public:
    Cells(int x, int y);

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
    void switchCell(int m, int n);
};


#endif //LIFE_CELLS_H

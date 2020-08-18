//
// Created by ash on 18/08/2020.
//

#include "catch.hpp"
#include "../src/life/Cells.h"
#include <vector>

/*
TEST_CASE("Test isActive and switchCell") {
    Cells cells(1, 1);
    CHECK(cells.isActive(0, 0) == false);
    cells.switchCell(0, 0);
    CHECK(cells.isActive(0, 0) == true);
    cells.switchCell(0, 0);
    CHECK(cells.isActive(0, 0) == false);
}*/

TEST_CASE("Test initRandom & prepareNext") {
    /*
    cells.initRandom(2, 0.2);

    SECTION("Test Init") {
        std::vector<std::vector<int>> init_0 = {{0, 0, 1, 1},
                                                {0, 0, 0, 1},
                                                {0, 0, 0, 0},
                                                {0, 1, 0, 0}};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                REQUIRE(int(cells.isActive(i, j)) == init_0[i][j]);
            }
        }
    }
    SECTION("Test Next Iteration") {
        std::vector<std::vector<int>> init_1 = {{1, 0, 1, 1},
                                                {0, 0, 1, 1},
                                                {0, 0, 0, 0},
                                                {0, 0, 1, 0}};
        cells.prepareNext();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                REQUIRE(int(cells.isActive(i, j)) == init_1[i][j]);

            }
        }
    }
    */
}
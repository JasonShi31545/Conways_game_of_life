#include "life.hpp"
#include <unistd.h>
#include <ctime>

// #define p make_pair

int main(int argc, const char *argv[]) {

    /*
    vector<pair<int, int>> coordinates = {
        make_pair(10, 10),
        make_pair(10, 11),
        make_pair(11, 10),
        make_pair(12, 13),
        make_pair(13, 13),
        make_pair(13, 12)
    };
    // Beacon
    //
    */
    /*
    vector<pair<int, int>> coordinates = {
        make_pair(10, 10),
        make_pair(11, 10),
        make_pair(12, 10)
    };
    // Blinker
    */
    /*
    vector<pair<int, int>> coordinates = {
        make_pair(10, 10),
        make_pair(11, 10),
        make_pair(12, 10),
        make_pair(9, 11),
        make_pair(10, 11),
        make_pair(11, 11)
    };
    // Toad
    */
    /*

    vector<pair<int, int>> coordinates = {
        make_pair(3, 3),
        make_pair(3, 4),
        make_pair(3, 5),
        make_pair(2, 5),
        make_pair(1, 4)
    };
    */

    // Glider
    /*
    vector<pair<int, int>> coordinates = {
        make_pair(10, 10),
        make_pair(9, 10),
        make_pair(9, 11),
        make_pair(11, 11),
        make_pair(10, 12)
    };
    // Boat
    */
    /*
    vector<pair<int, int>> coordinates = {
        make_pair(9, 10),
        make_pair(10, 10),
        make_pair(11, 10),

        make_pair(10, 11),
        make_pair(10, 12),

        make_pair(9, 13),
        make_pair(10, 13),
        make_pair(11, 13),

        make_pair(9, 15),
        make_pair(10, 15),
        make_pair(11, 15),


        make_pair(9, 16),
        make_pair(10, 16),
        make_pair(11, 16),

        make_pair(9, 18),
        make_pair(10, 18),
        make_pair(11, 18),

        make_pair(10, 19),
        make_pair(10, 20),

        make_pair(10, 21),
        make_pair(9, 21),
        make_pair(11, 21)
    };
    // Penta-decathlon
    */
    const int p = 32;
    vector<pair<int, int>> coordinates = {
        
        // left block
        make_pair(5, 15), // the top left block
        make_pair(6, 15),
        make_pair(5, 16), 
        make_pair(6, 16),

        // right block
        make_pair(6+33, 13),
        make_pair(7+33, 13),
        make_pair(6+33, 14),
        make_pair(7+33, 14),

        // right machine
        make_pair(6+19, 15), // major bottom left
        make_pair(6+20, 15),
        make_pair(6+19, 14),
        make_pair(6+20, 14),
        make_pair(6+19, 13),
        make_pair(6+20, 13),

        make_pair(6+21, 12),
        make_pair(6+21, 16),

        make_pair(6+23, 12),
        make_pair(6+23, 11),

        make_pair(6+23, 16),
        make_pair(6+23, 17),

        // left machine
        make_pair(6+16, 16), // tip
        make_pair(6+15, 16),
        make_pair(6+13, 16),
        make_pair(6+9, 16),

        make_pair(6+15, 15), // upper
        make_pair(6+9, 15),
        make_pair(6+14, 14),
        make_pair(6+10, 14),
        make_pair(6+11, 13),
        make_pair(6+12, 13),

        make_pair(6+15, 17), // lower
        make_pair(6+9, 17),
        make_pair(6+14, 18),
        make_pair(6+10, 18),
        make_pair(6+11, 19),
        make_pair(6+12, 19),

        // eater
        make_pair(6+p, 30),
        make_pair(6+p+1, 30),
        make_pair(6+p, 31),
        make_pair(6+p+2, 31),
        make_pair(6+p+2, 32),
        make_pair(6+p+2, 33),
        make_pair(6+p+3, 33),


        make_pair(50-1, 50),
        make_pair(50-1, 51),
 make_pair       (50-1, 54),
 make_pair       (51-1, 50),
 make_pair       (51-1, 53),
 make_pair       (52-1, 50),
 make_pair       (52-1, 53),
 make_pair       (52-1, 54),
 make_pair       (53-1, 52),
 make_pair       (54-1, 50),
 make_pair       (54-1, 52),
 make_pair       (54-1, 53),
 make_pair       (54-1, 54),

         make_pair(9, 10),
        make_pair(10, 10),
        make_pair(11, 10),

        make_pair(10, 11),
        make_pair(10, 12),

        make_pair(9, 13),
        make_pair(10, 13),
        make_pair(11, 13),

        make_pair(9, 15),
        make_pair(10, 15),
        make_pair(11, 15),

        make_pair(50, 50),
 make_pair       (51, 50),
 make_pair       (51, 51),
 make_pair       (56, 49),
 make_pair       (56, 51),
 make_pair       (55, 51),
 make_pair       (57, 51)
    };
    // Gosper glider gun & eater
    /*
    vector<pair<int, int>> coordinates = {
        make_pair(10, 10),
        make_pair(10, 10),
        make_pair(10, 10),
        make_pair(10, 10),
        make_pair(10, 10),
        make_pair(10, 10),
        make_pair(10, 10),
        make_pair(9, 11),
        make_pair(11, 11),
        make_pair(10, 12)
    }; 
    */
    /*
    vector<pair<int, int>> coordinates = {
        p(50, 50),
        p(51, 50),
        p(49, 51),
        p(50, 51),
        p(50, 52)
    };
    */
    // The R-pentomino
    /*
    vector<pair<int, int>> coordinates = {
        p(50, 50),
        p(51, 50),
        p(51, 51),
        p(56, 49),
        p(56, 51),
        p(55, 51),
        p(57, 51)
    };
    // Diehard
    */
    /*
    vector<pair<int, int>> coordinates = {
        p(50, 50),
        p(50, 51),
        p(50, 54),
        p(51, 50),
        p(51, 53),
        p(52, 50),
        p(52, 53),
        p(52, 54),
        p(53, 52),
        p(54, 50),
        p(54, 52),
        p(54, 53),
        p(54, 54)
    };
    */
    const int SECOND_USLEEP_CONSTANT = 1000*1000;

    int evolution = 20;
    cout << "Evolution times: ";
    cin >> evolution;
    if (evolution > 0 && evolution < 1000) {
    } else {
        return -1;
    }

    double delay_time = 0.2;
    Life::initialize_game(85, 70);
    for (auto cp: coordinates) {
        int x = cp.first;
        int y = cp.second;
        Life::cell_of_cells[y][x].alive = true;
    }
    Life::print_current_timestamp();

    Life::update_cells();
    int i = 1;
    while (i <= evolution) {
        Life::step();
        Life::print_current_timestamp();
        usleep(delay_time * SECOND_USLEEP_CONSTANT);
        i++;
    }

    return 0;
}

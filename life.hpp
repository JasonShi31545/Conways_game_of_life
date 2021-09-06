#ifndef LIFE_HPP
#define LIFE_HPP

#include <bits/stdc++.h>
/* Conway life */

using namespace std;

namespace Life {


const int shifts_count = 8;

const int neighbor_x_index_shifts[] = {
    -1, 0, 0, 1         ,        -1, 1, -1, 1
};
const int neighbor_y_index_shifts[] = {
    0, 1, -1, 0         ,        -1, -1, 1, 1
};

typedef struct _cell {
    int neighbor_count;
    // vector<bool> neighbors(8); // true is alive; false is dead
    /*
     * +---+---+---+
     * | 0 | 1 | 2 |
     * +---+---+---+
     * | 3 | C | 4 |
     * +---+---+---+
     * | 5 | 6 | 7 |
     * +---+---+---+
    */
    bool alive;
} Cell;

// vector<vector<Cell>> cell_of_cells(20)(20);
vector<vector<Cell>> cell_of_cells;//(20, vector<Cell> (20, {0,false}));

/*
int n;

void initialize_game(const int _n) {
    n = _n;
    cell_of_cells.resize(n);
    for (int i = 0; i < n ; i++) {
        cell_of_cells[i].resize(n);
        for (int j = 0; j < n; j++) {
            cell_of_cells[i][j] = {0, false};
        }
    }
}
*/

int rows, columns;

void initialize_game(const int _rows, const int _columns) {
    rows = _rows;
    columns = _columns;
    cell_of_cells.resize(rows);
    for (int i = 0; i < rows; i++) {
        cell_of_cells[i].resize(columns);
        for (int j = 0; j < columns; j++) {
            cell_of_cells[i][j] = {0, false};
        }
    }
}

void print_current_timestamp() {
    for (int i = 0; i < cell_of_cells.size(); i++) {
        for (int j = 0; j < cell_of_cells[i].size(); j++) {
            if (cell_of_cells[i][j].alive) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/*
void initialize_cells() {
    for (int i = 0 ; i < cell_of_cells.size(); i++) {
        for (int j = 0; j < cell_of_cells[i].size(); j++) {
            cell_of_cells[i][j] = {
                0, // neighbor_count
                false // alive
            };
        }
    }
}
*/

void update_cells() {
    for (int i = 0; i < cell_of_cells.size(); i++) {
        for (int j = 0; j < cell_of_cells[i].size(); j++) {
            Cell &cell = cell_of_cells[i][j];
            int temp = 0;
            for (int shift_id = 0; shift_id < shifts_count; shift_id++) {
                if (i+neighbor_y_index_shifts[shift_id] >= rows || i+neighbor_y_index_shifts[shift_id] < 0) continue;
                if (j+neighbor_x_index_shifts[shift_id] >= columns || j+neighbor_x_index_shifts[shift_id] < 0) continue;
                if (cell_of_cells
                        [i+neighbor_y_index_shifts[shift_id]]
                        [j+neighbor_x_index_shifts[shift_id]].alive) {
                    temp++;
                }
            }
            cell.neighbor_count = temp;
        }
    }
}

void update_neighbor(int i, int j, int plus) {
    for (int k = 0; k < 8; k++) {
        int x_offset = neighbor_x_index_shifts[k];
        int y_offset = neighbor_y_index_shifts[k];
        const int shift_id = k;
        if (i+neighbor_y_index_shifts[shift_id] >= rows || i+neighbor_y_index_shifts[shift_id] < 0) continue;
        if (j+neighbor_x_index_shifts[shift_id] >= columns || j+neighbor_x_index_shifts[shift_id] < 0) continue;
        
        Cell &neighbor = cell_of_cells[i + y_offset][j + x_offset];
        if (neighbor.alive) {
            if (plus) {
                neighbor.neighbor_count++;
            } else {
                neighbor.neighbor_count--;
            }
        }
    }
}
void step() {
//    update_cells();
    vector<pair<Cell *, bool>> coordinate_mark;
    for (int i = 0; i < cell_of_cells.size(); i++) {
        for (int j = 0; j < cell_of_cells[i].size(); j++) {
            Cell &cell = cell_of_cells[i][j];
            if (!cell.alive) { // dead cell
                if (cell.neighbor_count == 3) {
//                    cell.alive = true;
                    coordinate_mark.push_back(make_pair(&cell, true));
//                    update_cells();
                }
            } else { // alive
                if (!(cell.neighbor_count == 2 || cell.neighbor_count == 3)) { // if neighbors are not 2 or 3, die and remove
    //                cell.alive = false;
                    coordinate_mark.push_back(make_pair(&cell, false));
    //                update_cells();
                }
            }
        }
    }
    for (auto info : coordinate_mark) {
        if (info.second) { // come alive
            (*info.first).alive = true;
        } else { // go die
            (*info.first).alive = false;
        }
    }
    update_cells();

}

};

#endif // LIFE_HPP

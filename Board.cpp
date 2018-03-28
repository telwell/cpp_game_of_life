//
// Created by TElwell on 3/28/18.
//

#include <iostream>
#include "Board.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

void init_board(bool grid [grid_size+1][grid_size+1]){
    int n, x, y;
    cout << "How many cells would you like to set?" << endl;
    cin >> n;
    cout << "Enter X Y coordinates of where you'd like to change" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Update " << i << endl;
        cin >> x >> y;
        grid[y][x] = true;
    }
}

void print_grid(bool grid [grid_size+1][grid_size+1]){
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            cout << (grid[i][j]? " O " : " . ");
        }
        cout << endl;
    }
}

bool valid_board(bool grid [grid_size+1][grid_size+1]){
    bool ret = false;
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            if(grid[i][j]){
                ret = true;
                break;
            }
        }
    }
    return ret;
}

// This is bad... hoping for a better way to do this.
void clear_screen(){
    cout << string( 100, '\n' );
}

void next_scene(bool grid [grid_size+1][grid_size+1], bool next_grid [grid_size+1][grid_size+1]){
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            // Get our neighbors
            int neigh = 0;
            for (int r = -1; r < 2; ++r) {
                for (int c = -1; c < 2; ++c) {
                    if (!(c == 0 && r == 0)){
                        int row = i+r, col = j+c;
                        // Make sure we're never going to look out of bounds.
                        if (row > grid_size || col > grid_size || row < 0 || col < 0)
                            continue;
                        if (grid[row][col]){
                            neigh += 1;
                        }
                    }
                }
            }
            if(grid[i][j]){
                if (neigh < 2){
                    // Dies
                    next_grid[i][j] = false;
                } else if ( neigh == 2 || neigh == 3){
                    // Stays alive
                    next_grid[i][j] = true;
                } else {
                    // Dies
                    next_grid[i][j] = false;
                }
            } else {
                if (neigh == 3) {
                    // Lives
                    next_grid[i][j] = true;
                } else {
                    next_grid[i][j] = false;
                }
            }
        }
    }
}
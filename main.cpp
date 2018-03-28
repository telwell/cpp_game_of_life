/* Written by Trevor Elwell
 * 3/27/2018 */

#include <iostream>
#include <thread>
#include "Board.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    bool grid[grid_size+1][grid_size+1] = {};
    bool next_grid[grid_size+1][grid_size+1] = {};

    init_board(grid);
    print_grid(grid);

    bool game_over = false;

    while (!game_over){
        // Pause...
        std::chrono::milliseconds dura(500);
        std::this_thread::sleep_for(dura);

        if(!valid_board(grid)) {
            game_over = true;
            cout << "Sorry, your game of life has ended..." << endl;
        } else {
            clear_screen();
            next_scene(grid, next_grid);
            std::swap(grid, next_grid);
            print_grid(grid);
        }
    }

    return 0;
}

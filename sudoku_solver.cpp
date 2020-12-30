#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

void
print_board(vector<vector<int>> board) {
    int i, j;
    for (i = 0; i < board.size(); i++) {
        if (i % 3 == 0) cout << "-------------------------" << endl;
        for (j = 0; j < board[0].size(); j++) {
            if (j % 3 == 0) cout << "| ";
            cout << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------------------" << endl;
}

pair<int, int>
find_empty(vector<vector<int>> board) {
    int i, j;
    pair<int, int> pos(-1, -1);

    for (i = 0; i < board.size(); i++) {
        for (j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                pos.first = i;
                pos.second = j;
                goto out;
            }
        }
    }

out:
    return pos;
}

bool
valid(vector<vector<int>> board, int num, pair<int,int> pos) {
    int i, j;
    int grid_x, grid_y;

    // check row
    for (i = 0; i < board[0].size(); i++) {
        if (board[pos.first][i] == num && pos.second != i) {
            return false;
        }
    }

    // check col
    for (i = 0; i < board.size(); i++) {
        if (board[i][pos.second] == num && pos.first != i) {
            return false;
        }
    }

    // check 3x3 grid
    grid_x = pos.first / 3;
    grid_y = pos.second / 3;

    for (i = grid_x*3; i < grid_x*3 + 3; i++) {
        for (j = grid_y*3; j < grid_y*3 + 3; j++) {
            if (board[i][j] == num && i != pos.first && j != pos.second)
                return false;
        }
    }

    return true;
}

bool
solve(vector<vector<int>> &board) {
    pair<int, int> pos = find_empty(board);
    int i = 0;

    if(pos.first == -1) {
        return true;
    }

    for (i = 1; i <= 9; i++) {
        if (valid(board, i, pos)) {
            board[pos.first][pos.second] = i;

            if (solve(board)) {
                return true;
            }

            board[pos.first][pos.second] = 0;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> board{
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 3},
        {0, 7, 4, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 2},
        {0, 8, 0, 0, 4, 0, 0, 1, 0},
        {6, 0, 0, 5, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 7, 8, 0},
        {5, 0, 0, 0, 0, 9, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0},
    };

    // vector<vector<int>> board{
    //     {0, 0, 0, 2, 6, 0, 7, 0, 1},
    //     {6, 8, 0, 0, 7, 0, 0, 9, 0},
    //     {1, 9, 0, 0, 0, 4, 5, 0, 0},
    //     {8, 2, 0, 1, 0, 0, 0, 4, 0},
    //     {0, 0, 4, 6, 0, 2, 9, 0, 0},
    //     {0, 5, 0, 0, 0, 3, 0, 2, 8},
    //     {0, 0, 9, 3, 0, 0, 0, 7, 4},
    //     {0, 4, 0, 0, 5, 0, 0, 3, 6},
    //     {7, 0, 3, 0, 1, 8, 0, 0, 0},
    // };

    // vector<vector<int>> board{
    //     { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    //     { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //     { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //     { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //     { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //     { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //     { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //     { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //     { 0, 0, 5, 2, 0, 6, 3, 0, 0 },
    // };

    vector<vector<int>> copy_board = board;

    print_board(board);
    if (!solve(copy_board)) {
        cout << "This puzzle cannot be solved" << endl;
    } else{
        cout << "solution :" << endl;
        print_board(copy_board);
    }

    return 0;
}

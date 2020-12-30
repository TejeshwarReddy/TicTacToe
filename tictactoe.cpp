#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 0 - o
// 1 - x

void printGrid(vector<vector<int>> *v) {
    for (size_t i = 0; i < v->size(); i++) {
        for (size_t j = 0; j < v->at(i).size(); j++)
        {
            char c = '\0';
            if (v->at(i).at(j) == -1) {
                c = '-';
            } else if (v->at(i).at(j) == 0) {
                c = 'O';
            } else {
                c = 'X';
            }

            cout << c << " ";
        }
        cout << endl;
    }
}

bool gotWinner(int winner) {
    if (winner != -1) {
        cout << ((winner == 1) ? 'X' : 'O') << " is the winner !!!" << endl;
        return true;
    }
    return false;
}

bool checkWinner(vector<vector<int>> *v) {
    int winner = -1;
    // horizontal lines
    for (size_t i = 0; i < v->size(); i++)
    {
        if (v->at(i).at(0) == v->at(i).at(1) && v->at(i).at(1) ==  v->at(i).at(2))
            winner = v->at(i).at(1);
    }

    if (gotWinner(winner)) {
        return true;
    }

    // vertical lines
    for (size_t i = 0; i < v->size(); i++)
    {
        if (v->at(0).at(i) == v->at(1).at(i) && v->at(1).at(i) ==  v->at(2).at(i))
            winner = v->at(1).at(i);
    }

    if (gotWinner(winner)) {
        return true;
    }

    // diagonals
    if (v->at(0).at(0) == v->at(1).at(1) && v->at(1).at(1) == v->at(2).at(2)) {
        winner = v->at(1).at(1);
    }
    
    if (gotWinner(winner)) {
        return true;
    }

    if (v->at(2).at(0) == v->at(1).at(1) && v->at(1).at(1) == v->at(0).at(2)) {
        winner = v->at(1).at(1);
    }

    if (gotWinner(winner)) {
        return true;
    }
    
    return false;

}

void play(vector<vector<int>> *v) {
    int i = 0;
    int row, col;
    int start = rand();
    cout << ((start%2 == 0) ? 'O' : 'X') << " starts the game" << endl;
    int inputCount = 0;
    while (inputCount < 9) {
        printGrid(v);
        if (start%2) {
            cout << "X's turn" << endl;
        } else {
            cout << "O's turn" << endl;
        }
        cout << "Enter space separated row and col indices : " << endl;
        cin >> row;
        cin >> col;
        assert(row < 3);
        assert(col < 3);
        if (v->at(row).at(col) == -1) {
            v->at(row).at(col) = (start%2 == 0) ? 0 : 1;
            if (checkWinner(v)) {
                break;
            }
            start++;
            inputCount++;
        } else {
            cout << "Invalid inputs!! \n Please re-enter" << endl;
        }
    }

    if (inputCount == 9) {
        cout << "It's a draw!!" << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v
    {
        {-1,-1,-1},
        {-1,-1,-1},
        {-1,-1,-1}
    };

    play(&v);

    return 0;
}

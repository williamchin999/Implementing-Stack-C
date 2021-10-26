//Copyright 2021 William Chin
//Email: wchin1@sfsu.edu
//This file is apart of CSC340 -Assignment 3

//Functions for tic tac toe to initilize board, print board, check game status, and add move to board,

//TODO: I think its pretty good possibly improve efficiency

#include "TicTacToe.h"
#include<iostream>

using namespace std;

TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::printBoard() const {

    cout << endl << endl;
    cout << "\t\t0\t\t1\t\t2\t" << endl << endl;
    cout << "\t0\t" << board[0][0] << "\t|\t" << board[0][1] << "\t|\t" << board[0][2] << endl;
    cout << "\t\t- \t\t- \t\t-" << endl;
    cout << "\t1\t" << board[1][0] << "\t|\t" << board[1][1] << "\t|\t" << board[1][2] << endl;
    cout << "\t\t- \t\t- \t\t-" << endl;
    cout << "\t2\t" << board[2][0] << "\t|\t" << board[2][1] << "\t|\t" << board[2][2] << endl;
}
bool TicTacToe::validMove(int a, int b) const{
    if (board[a][b] == ' ' && a < 3 && b < 3)
        return true;
    else
        return false;
}
bool TicTacToe::xoMove(char a) {
    int row;
    int col;
    do {
        cout << "\nPlayer " << a << " enter a move:";
        cin >> row >> col;
        
        while (cin.fail()) {
            cout << "Enter Integers" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\nPlayer " << a << " enter a move:";
            cin >> row >> col;
        }
        if (validMove(row, col) == true) {
            board[row][col] = a;
            break;
        }
        else
            cout << "enter a valid move" << endl;

        printBoard();
    } while (validMove(row, col) == false);
    
    return true;
}
TicTacToe::Status TicTacToe::gameStatus() const {
    //row check
    for (int i = 0; i <= 2; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return WIN;
    }
    // col check
    for (int i = 0; i <= 2; i++){
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return WIN;
    }

    // 1st diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return WIN;

    // 2nd diagonal
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return WIN;
    else {
        int count = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (board[i][j] == ' ') {
                    return CONTINUE;
                }
                else if (board[i][j] == 'X' || board[i][j] == 'O') {
                    count++;
                    //cout << count << endl;
                    if (count == 8)
                        return DRAW;
                }
            }
        }

    }


}
void TicTacToe::makeMove() {
   printBoard();
   Status status = CONTINUE;
   while (status == CONTINUE) {
      if (xoMove('X')) {
          printBoard();
          //cout << status << endl;
          status = gameStatus();
          //cout << status << endl;
          if (status == WIN) {
              cout << "Player X won" <<endl;
              break;
          }
          else if (status == DRAW) {
              cout << "Draw" << endl;
              break;
          }
      }
      if (xoMove('O')) {
          printBoard();
          //cout << status << endl;
          status = gameStatus();
          //cout << status << endl;
          if (status == WIN) {
              cout << "Player O won" << endl;
              break;
          }
          else if (status == DRAW) {
              cout << "Draw" << endl;
              break;
          }
      }

   } 
} 

//Copyright 2021 William Chin
//Email: wchin1@sfsu.edu
//This file is apart of CSC340 -Assignment 3

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <array>
#include <string>

class TicTacToe {

private:
   enum Status {WIN, DRAW, CONTINUE};
   std::array<std::array<char, 3>, 3> board;

public:
   TicTacToe();
   void makeMove();
   void printBoard() const;
   bool validMove(int, int) const;
   bool xoMove(char); // x o move
   Status gameStatus() const;

};

#endif

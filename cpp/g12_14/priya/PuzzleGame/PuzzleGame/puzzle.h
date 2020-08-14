#pragma once
#include<iostream>
class puzzle
{
    int board[3][3];
public:
    puzzle();
    void initializeBoard();
    void show();
    void move(int num);
    bool isWon();
    void turn();
};

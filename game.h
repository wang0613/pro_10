//
// Created by wang on 2022/8/7.
//
#include <stdlib.h> //rand()函数；
#include <time.h> //time()函数；

#ifndef PRO_10_GAME_H
#define PRO_10_GAME_H

#endif //PRO_10_GAME_H

// 定义棋盘行和列
#define ROW 3
#define COL 3

//初始化棋盘
void init_board(char board[ROW][COL],int row,int col);

//展示棋盘
void display_board(char board[ROW][COL], int row, int col);

//玩家下棋
void player_move(char board[ROW][COL], int row, int col);
//电脑下棋
void computer_move(char board[ROW][COL], int row, int col);

//玩家赢 ‘*’
//电脑赢 ‘#’
//平局 ‘Q’
//继续 ‘C’
char isWin(char board[ROW][COL],int row, int col);

//1： 棋盘满了   0没满

int isFull(char board[ROW][COL],int row, int col);
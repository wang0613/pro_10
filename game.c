//
// Created by wang on 2022/8/7.
//
#include "game.h"
#include <stdio.h>

/*
 *          . * .
 *          . . .
 *          . . .
 */
//打印棋盘
/*
 *      ___|___|____
 *      ___|___|___
 *         |   |
 */
/*void display_board(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++) {
        //1：打印一行数据
        printf(" %c | %c | %c   \n",board[i][0],board[i][1],board[i][2]);
        //2:打印一行分隔符
        if(i < row-1)
        {

            printf("---|---|--- \n");
        }

    }

}*/
void display_board(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < row; i++) {
        int j = 0;
        for (j = 0; j < col; j++) {
            //1：打印一行数据
//        printf(" %c | %c | %c   \n",board[i][0],board[i][1],board[i][2]);
            printf(" %c ", board[i][j]);
            //最后一个数据不打印 |
            if (j < col - 1) {
                printf("|");
            }
        }
        printf("\n");
        //2:打印一行分隔符
        if (i < row - 1) {
            for (j = 0; j < col; j++) {
                printf("---");
                if (j < col - 1) {
                    printf("|");
                }
            }
            printf("\n");
        }


    }

}

//初始化棋盘 -为空格
void init_board(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}


//玩家下棋
void player_move(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("玩家走 >\n");
    int flag = 1; //结束当前一轮的标志
    while (flag) {

        printf("请输入坐标");
        scanf("%d%d", &x, &y);
        //1:判断坐标的合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col) {

            //2:判断当前坐标是否下过
            if (board[x - 1][y - 1] == ' ') {
                //没有下，用户棋子为*
                board[x - 1][y - 1] = '*';
                flag = 0;  //玩家下过棋，该电脑下棋
            } else {
                //下过了
                printf("该坐标被占用！\n");
            }


        } else {
            printf("非法坐标 请重新输入！\n");
        }
    }
}

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col) {
    //生成0-2范围内的随机坐标
    int x = 0;
    int y = 0;
    printf("电脑走 >\n");
    int flag = 1;
    while (flag) {
        x = rand() % row;  //生成 0-2的数据
        y = rand() % col;
        if (board[x][y] == ' ') {
            board[x][y] = '#';
            flag = 0;
        }
    }

}

//1： 棋盘满了   0没满
int isFull(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if(board[i][j] == ' '){
                return 0;//没满
            }
        }
    }
    return 1; //满了
}


//玩家赢 ‘*’
//电脑赢 ‘#’
//平局 ‘Q’
//继续 ‘C’
char isWin(char board[ROW][COL], int row, int col) {

    int i = 0;
    for (i = 0; i < row; i++) {
        //横着的一行
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][1] != ' ') {
            //返回任意一个
            return board[i][1];
        }
    }
    for (i = 0; i < col; i++) {
        //竖着的一列
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[1][i] != ' ') {
            //返回任意一个
            return board[1][i];
        }
    }
    //对角线  00   11  22
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ') {
        //返回任意一个
        return board[1][1];
    }
    //对角线  02   11  20
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[1][1] != ' ') {
        //返回任意一个
        return board[1][1];
    }
    //判断是否平局  棋盘满了
    if (isFull(board, row, col) == 1) {
        return 'Q'; //平局
    }

    //否则继续
    return 'C';

}



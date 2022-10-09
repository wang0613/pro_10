#include <stdio.h>

#include "game.h"
//c语言实现三子棋
void menu() {
    printf("**********************");
    printf("***1.play   0.exit****");
    printf("**********************");
}
//算法实现
void game() {
    //数组-存放棋盘信息
    char board[ROW][COL] = {' '};
    //初始化棋盘
    init_board(board, ROW, COL);
    //显示棋盘
    display_board(board, ROW, COL);
    char ret;
    //下棋
    int flag = 1;
    while (flag) {
        //玩家下棋
        player_move(board, ROW, COL);
        display_board(board, ROW, COL);

        /*
         * //玩家赢 ‘*’
        //电脑赢 ‘#’
        //平局 ‘Q’
        //继续 ‘C’
         */
        //判断玩家是否赢了
        ret = isWin(board,ROW, COL);
        if (ret != 'C') {
           flag = 0;
        }
        computer_move(board, ROW, COL);
        display_board(board, ROW, COL);
        if (ret != 'C') {
            flag = 0;
        }

    }
    if(ret == '*')
    {
        printf("玩家赢了\n");
    }else if(ret == '#'){
        printf("电脑赢了\n");

    }else{
        printf("平局\n");
    }

}
void test() {

    int input = 0;
    srand((unsigned int) time(NULL)); //以当前时间为时间戳
    do {
        menu(); //菜单
        printf("请选择：\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入有误\n");
                break;

        }
    } while (input == 1);
}


int main() {
    test();

    return 0;
}

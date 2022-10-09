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
//��ӡ����
/*
 *      ___|___|____
 *      ___|___|___
 *         |   |
 */
/*void display_board(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++) {
        //1����ӡһ������
        printf(" %c | %c | %c   \n",board[i][0],board[i][1],board[i][2]);
        //2:��ӡһ�зָ���
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
            //1����ӡһ������
//        printf(" %c | %c | %c   \n",board[i][0],board[i][1],board[i][2]);
            printf(" %c ", board[i][j]);
            //���һ�����ݲ���ӡ |
            if (j < col - 1) {
                printf("|");
            }
        }
        printf("\n");
        //2:��ӡһ�зָ���
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

//��ʼ������ -Ϊ�ո�
void init_board(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}


//�������
void player_move(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("����� >\n");
    int flag = 1; //������ǰһ�ֵı�־
    while (flag) {

        printf("����������");
        scanf("%d%d", &x, &y);
        //1:�ж�����ĺϷ���
        if (x >= 1 && x <= row && y >= 1 && y <= col) {

            //2:�жϵ�ǰ�����Ƿ��¹�
            if (board[x - 1][y - 1] == ' ') {
                //û���£��û�����Ϊ*
                board[x - 1][y - 1] = '*';
                flag = 0;  //����¹��壬�õ�������
            } else {
                //�¹���
                printf("�����걻ռ�ã�\n");
            }


        } else {
            printf("�Ƿ����� ���������룡\n");
        }
    }
}

//��������
void computer_move(char board[ROW][COL], int row, int col) {
    //����0-2��Χ�ڵ��������
    int x = 0;
    int y = 0;
    printf("������ >\n");
    int flag = 1;
    while (flag) {
        x = rand() % row;  //���� 0-2������
        y = rand() % col;
        if (board[x][y] == ' ') {
            board[x][y] = '#';
            flag = 0;
        }
    }

}

//1�� ��������   0û��
int isFull(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if(board[i][j] == ' '){
                return 0;//û��
            }
        }
    }
    return 1; //����
}


//���Ӯ ��*��
//����Ӯ ��#��
//ƽ�� ��Q��
//���� ��C��
char isWin(char board[ROW][COL], int row, int col) {

    int i = 0;
    for (i = 0; i < row; i++) {
        //���ŵ�һ��
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][1] != ' ') {
            //��������һ��
            return board[i][1];
        }
    }
    for (i = 0; i < col; i++) {
        //���ŵ�һ��
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[1][i] != ' ') {
            //��������һ��
            return board[1][i];
        }
    }
    //�Խ���  00   11  22
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ') {
        //��������һ��
        return board[1][1];
    }
    //�Խ���  02   11  20
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[1][1] != ' ') {
        //��������һ��
        return board[1][1];
    }
    //�ж��Ƿ�ƽ��  ��������
    if (isFull(board, row, col) == 1) {
        return 'Q'; //ƽ��
    }

    //�������
    return 'C';

}



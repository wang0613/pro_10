#include <stdio.h>

#include "game.h"
//c����ʵ��������
void menu() {
    printf("**********************");
    printf("***1.play   0.exit****");
    printf("**********************");
}
//�㷨ʵ��
void game() {
    //����-���������Ϣ
    char board[ROW][COL] = {' '};
    //��ʼ������
    init_board(board, ROW, COL);
    //��ʾ����
    display_board(board, ROW, COL);
    char ret;
    //����
    int flag = 1;
    while (flag) {
        //�������
        player_move(board, ROW, COL);
        display_board(board, ROW, COL);

        /*
         * //���Ӯ ��*��
        //����Ӯ ��#��
        //ƽ�� ��Q��
        //���� ��C��
         */
        //�ж�����Ƿ�Ӯ��
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
        printf("���Ӯ��\n");
    }else if(ret == '#'){
        printf("����Ӯ��\n");

    }else{
        printf("ƽ��\n");
    }

}
void test() {

    int input = 0;
    srand((unsigned int) time(NULL)); //�Ե�ǰʱ��Ϊʱ���
    do {
        menu(); //�˵�
        printf("��ѡ��\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("�˳���Ϸ\n");
                break;
            default:
                printf("��������\n");
                break;

        }
    } while (input == 1);
}


int main() {
    test();

    return 0;
}

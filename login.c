#include "login.h"

void PrintLogin() {
    printf("[로그인 메뉴]\n");
    printf("1. 관리자 로그인\n");
    printf("2. 트레이너 로그인\n");
    printf("0. 종료\n");
    printf("선택하세요(숫자만 입력) : ");
}

int InputLogin() {
    int num=0, mode=0;
    scanf("%d", &mode);

    while((mode!=0)&&(mode!=1)&&(mode!=2)) {
        printf(MENU_INPUT_ERROR_MESSAGE);
        printf("선택하세요(숫자만 입력) : ");
        scanf("%d", &mode);
    }
    num = mode;

    return num; 
}

void PrintAdminLogin() {
    printf("[관리자 로그인]\n");
    printf("비밀번호 : ");
}

char* InputAdminPW() {
    char pw[16];
    scanf("%s", pw);

    return pw;
}

void PrintTrainerLogin() {
    printf("[트레이너 로그인]\n");
    printf("이름 : ");
}

char* InputTrainerName() {
    char name[21];
    scanf("%s", name);

    return name;
}

#include "trainer.h"

//트레이너 로그인시 첫 화면 보여주는 함수
void TrainerPrompt(char* trainer_name) { 
    int input; //사용자 입력 저장 변수
    char* t_name; //트레이너 이름 저장할 변수

    t_name = &trainer_name; //인자로 받은 트레이너 이름값 저장

    while(1){
        printf("[트레이너 메뉴]\n1. 담당회원\n2. 로그아웃\n0. 종료\n선택하세요(숫자만 입력) : ");
        scanf("%d", &input);

        if(input == 1){ //담당회원목록 출력
         //printf("담당회원 출력 ㄱ ㄱ \n");
         PrintMemberList(t_name); //담당회원 출력 함수

        }else if(input ==2){  //로그아웃 진행
            //printf("프로그램 첫 화면으로 ㄱㄱ \n");
            //PrintLogin(); //앱 첫 실행시 보여주는 관리자or트레이너 로그인 화면 
            break; 

        }else if(input==0){  //프로그램 종료
            return;
        }else{
            printf("올바른 메뉴만을 입력해 주세요.\n");
        }        
    }
}

//담당회원 출력해주는 함수
void PrintMemberList(char* trainer_name) {
    printf("PrintMemberList실행\n");
    

}
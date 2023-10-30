#include "trainer.h"
#include <string.h>

//트레이너 로그인시 첫 화면 보여주는 함수
void TrainerPrompt(char* trainer_name) { 
    int input; //사용자 입력 저장 변수
    char* t_name; //인자로 받은 트레이너 이름을 저장
    t_name = trainer_name;

    while(1){
        printf(TRAINER_PROMPT); //트레이너 프롬프트 매크로상수 출력
        scanf("%d", &input);

        if(input == 1){ //담당회원목록 출력
         //printf("담당회원 출력 ㄱㄱ \n");
         PrintMemberList(t_name); //담당회원 출력 함수

        }else if(input ==2){  //로그아웃 진행
            //printf("프로그램 첫 화면으로 ㄱㄱ \n");
            PrintLogin();  //앱 첫 실행시 보여주는 관리자or트레이너 로그인 화면 실행 함수
            break; 

        }else if(input==0){  //프로그램 종료
            return;
        }else{
            printf("올바른 메뉴만을 입력해 주세요.\n\n");
        }        
    }
}


//담당회원 출력해주는 함수
void PrintMemberList(char* trainer_name) {
    char* t_name = trainer_name;  //인자로 받은 트레이너 이름 저장 
    char buffer[MAX_LINE];  //파일에서 읽을 바이트
    char *readByte;  //회원정보 한줄씩 저장할 변수
    FILE* file; 
    file = fopen(MEMBER_DATA_FILE_PATH, "r"); //회원목록파일을 읽기 권한으로 열기 

    //파일이 존재X일경우
    if(file == NULL){
        printf("member_data.txt파일을 열 수 없습니다.");
        return;
    }

    printf(ASSIGNED_MEMBER_LIST_MESSAGE);  //회원리스트 보여줄때 쓰는 매크로 상수 출력

    //회원파일 불러와서 한줄씩 읽으며 담당트레이너 필드가 t_name과 동일하면 해당 줄 출력 
    while (feof(file) == 0) { //파일의 끝이면 1, 끝이 아니면 0을 반환
        
        //한줄읽기
        readByte = fgets(buffer, MAX_LINE, file);
        
        //복사를 위한 임시 문자열
        char *tempStr = malloc(sizeof(char) * 1024);
        
        //읽은 한줄을 복사 =>  tempStr
        strcpy(tempStr , readByte);
        
        //읽은 한 줄을 " " 기준으로 하나씩 자르기
        char *ptr = strtok(buffer, " ");
        
        while (ptr != NULL) {
            //printf("자른 문자열 출력 : %s \n" , ptr);

            //두 문자열이 같은지 비교. 같으면  0
            int ret = strcmp(t_name , ptr);
            
            //두 문자열이 같다면 해당 한 줄 출력(회원정보 하나 출력)
            if (ret == 0) {
                printf("%s \n\n",  tempStr);
                break;
            }
            ptr = strtok(NULL, " "); //다음 문자열을 잘라서 포인터를 반환
        }
        //위에서 할당한 포인터 문자열 해제
        free(tempStr);
    }
    fclose(file);
}

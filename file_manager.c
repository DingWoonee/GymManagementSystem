#include "file_manager.h"
#include "prompt_macro.h"
#include "regex.h"
#include <stdbool.h>
#include <stdio.h>

int CreateTrainerFile() {
    const char* file_name;
    const char* admin_data;
    FILE* file = fopen("trainer_data.txt", "r");

    if (file == NULL) {
        file = fopen("trainer_data.txt", "w");
        fprintf(file, ADMIN_INFO); //관리자 데이터 입력
        fclose(file);
        if (file == NULL) {
            perror("트레이너 파일 생성 실패");
            return -1;
        }
        printf("트레이너 파일 새로 생성, 관리자 데이터 입력됨"); //나중에 지울 부분
        return 0;
    }
    else {
        fclose(file);
        printf("기존 트레이너 파일이 존재함"); //나중에 지울 부분
        return 1;
    }
}

bool ValidateTrainerDataFile(const char* file_path, const char* admin_pattern, const char* trainer_pattern) {
    char buffer[MAX_LINE];
    bool is_first_line = true;
    FILE* file = fopen(file_path, "r");
    
    if (file_path == NULL) return false;
    if (admin_pattern == NULL) return false;
    if (trainer_pattern == NULL) return false;
    
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        if (is_first_line == true) { //첫번째 줄 데이터 검사
            if (IsMatch(admin_pattern, buffer)) {
                 is_first_line = false;
            }
            else {
                fclose(file);
                printf("admin data is invalid");
                return false;
            }
        }
        else { //첫번쨰 줄 이후 데이터 검사
            if (IsMatch(trainer_pattern, buffer)) {
            }
            else {
                fclose(file);
                printf("trainer data is invalid");
                return false;
            }
        }
    }
    fclose(file);
    printf("trainer data file is valid"); //지울 부분
    return true;

}

int CreateMemberFile() {
    const char* file_name;
    const char* admin_data;
    FILE* file = fopen("member_data.txt", "r");

    if (file == NULL) {
        file = fopen("trainer_data.txt", "a");
        fclose(file);
        printf("멤버 파일 새로 생성"); //나중에 지울 부분
        return 0;
        if (file == NULL) {
            perror("멤버 파일 생성 실패");
            return -1;
        }
    }
    else {
        fclose(file);
        printf("기존 멤버 파일이 존재함"); //나중에 지울 부분
        return 1;
    }
}

bool ValidateMemberDataFile(const char* file_path, const char* member_pattern) {
    char buffer[MAX_LINE];
    FILE* file = fopen(file_path, "r");
    
    if (file_path == NULL) return false;
    if (member_pattern == NULL) return false;
    
    while(fgets(buffer, sizeof(buffer), file) != NULL) {
        if (!IsMatch(member_pattern, buffer)) {
            fclose(file);
            printf("member file is invalid");
            return false;
        }
    }
    fclose(file);
    printf("member data file is valid"); //지울 부분
    return true;

}

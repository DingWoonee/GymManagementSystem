#include "admin.h"

//정보 수정이나 삭제 시에 고유 번호 입력받는 함수
int InputId(const char* file_path) {
    int input;
    int current_id;
    FILE* file = fopen(file_path, "r");

    //입력값이 정수가 아닐 경우
    if (scanf("%d", &input) != 1) {
        printf(INPUT_INFO_ERROR_MESSAGE);
        fclose(file);
        return -1;
    }
    //파일 탐색
    while (fscanf(file, "%d", &current_id) != EOF) {
        if (current_id == input) {
            fclose(file);
            return input;
        }
        //다음 줄로
        char ch;
        while ((ch = fgetc(file)) != '\n' && ch != EOF);
    }
    //해당 번호 존재 안함
    printf(INPUT_ID_ERROR_MESSAGE);
    fclose(file);
    return -1;
}

void AdminPrompt() {
    while (1) {
        int input;
        printf(ADMIN_PROMPT);
        //메뉴 번호 입력
        while (scanf("%d", &input) != 1 || (input <= MaxMenuNum && input >= 0)) {
            printf(MENU_INPUT_ERROR_MESSAGE);
            //입력 버퍼 초기화
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }

        switch (input) {
            case 0: //종료
                exit(0);
            case MaxMenuNum: //로그아웃
                return;
            case 1: //트레이너 신규 등록
                AddTrainerInfo();
                break;
            case 2: //트레이너 재입사
                RejoinTrainer(TRAINER_DATA_FILE_PATH);
                break;
            case 3: //트레이너 수정
                UpdateInfo(TRAINER_DATA_FILE_PATH, TRAINER_INFO_PATTERN);
                break;
            case 4: //트레이너 퇴사
                ResignTrainer(TRAINER_DATA_FILE_PATH, MEMBER_DATA_FILE_PATH);
                break;
            case 5: //트레이너 삭제
                DelTrainerInfo(TRAINER_DATA_FILE_PATH);
                break;
            case 6: //회원 등록
                AddMemberInfo();
                break;
            case 7: //회원 수정
                UpdateInfo(MEMBER_DATA_FILE_PATH, MEMBER_INFO_PATTERN);
                break;
            case 8: //회원 삭제
                DelTrainerInfo(MEMBER_DATA_FILE_PATH);
                break;
            case 9: //트레이너가 배정되지 않은 회원 조회
                PrintNoTrainerMemberList();
                break;
        }
    }
}

void AddTrainerInfo() {

}

void ResignTrainer(const char* file_path, const char* file_path2) {

}

void RejoinTrainer(const char* file_path) {

}

void UpdateInfo(const char* file_path, const char* input_pattern) {

}

void DelInfo(const char* file_path) {
    int id;
    if ((id = InputId(file_path)) == -1) {
        return;
    }
    int cur_id;
    char line[MAX_LINE];
    FILE* file = fopen(MEMBER_DATA_FILE_PATH, "r");
    FILE* temp_file = fopen("temp_data.txt", "w");

    //파일 열기 실패 처리 해야함

    while (fgets(line, MAX_LINE, file) != NULL) {
        sscanf(line, "%d", &cur_id);
        if (id != cur_id) {
            fprintf(file, "%s", line);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(file_path);
    rename("temp_data.txt", file_path);
}

void AddMemberInfo() {

}

void PrintNoTrainerMemberList() {
    char buffer[MAX_LINE];
    FILE* file = fopen(MEMBER_DATA_FILE_PATH, "r");

    //파일 열기 실패 처리 해야함

    while (feof(file) != 1) {
        if (fgets(buffer, MAX_LINE, file) == NULL) {
            break;
        }

        int field_count = 0;
        char* string_split_ptr = strtok(buffer, " ");

        while (string_split_ptr != NULL) {
            field_count++;
            if (field_count == 9 && strcmp(string_split_ptr, "X") == 0) {
                printf("%s", buffer);
            }
            string_split_ptr = strtok(NULL, " ");
        }
    }
    fclose(file);
}
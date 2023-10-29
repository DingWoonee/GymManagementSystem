#include "admin.h"

//���� �����̳� ���� �ÿ� ���� ��ȣ �Է¹޴� �Լ�
int InputId(const char* file_path) {
    int input;
    int current_id;
    FILE* file = fopen(file_path, "r");

    //�Է°��� ������ �ƴ� ���
    if (scanf("%d", &input) != 1) {
        printf(INPUT_INFO_ERROR_MESSAGE);
        fclose(file);
        return -1;
    }
    //���� Ž��
    while (fscanf(file, "%d", &current_id) != EOF) {
        if (current_id == input) {
            fclose(file);
            return input;
        }
        //���� �ٷ�
        char ch;
        while ((ch = fgetc(file)) != '\n' && ch != EOF);
    }
    //�ش� ��ȣ ���� ����
    printf(INPUT_ID_ERROR_MESSAGE);
    fclose(file);
    return -1;
}

void AdminPrompt() {
    while (1) {
        int input;
        printf(ADMIN_PROMPT);
        //�޴� ��ȣ �Է�
        while (scanf("%d", &input) != 1 || (input <= MaxMenuNum && input >= 0)) {
            printf(MENU_INPUT_ERROR_MESSAGE);
            //�Է� ���� �ʱ�ȭ
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }

        switch (input) {
            case 0: //����
                exit(0);
            case MaxMenuNum: //�α׾ƿ�
                return;
            case 1: //Ʈ���̳� �ű� ���
                AddTrainerInfo();
                break;
            case 2: //Ʈ���̳� ���Ի�
                RejoinTrainer(TRAINER_DATA_FILE_PATH);
                break;
            case 3: //Ʈ���̳� ����
                UpdateInfo(TRAINER_DATA_FILE_PATH, TRAINER_INFO_PATTERN);
                break;
            case 4: //Ʈ���̳� ���
                ResignTrainer(TRAINER_DATA_FILE_PATH, MEMBER_DATA_FILE_PATH);
                break;
            case 5: //Ʈ���̳� ����
                DelTrainerInfo(TRAINER_DATA_FILE_PATH);
                break;
            case 6: //ȸ�� ���
                AddMemberInfo();
                break;
            case 7: //ȸ�� ����
                UpdateInfo(MEMBER_DATA_FILE_PATH, MEMBER_INFO_PATTERN);
                break;
            case 8: //ȸ�� ����
                DelTrainerInfo(MEMBER_DATA_FILE_PATH);
                break;
            case 9: //Ʈ���̳ʰ� �������� ���� ȸ�� ��ȸ
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

    //���� ���� ���� ó�� �ؾ���

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

    //���� ���� ���� ó�� �ؾ���

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
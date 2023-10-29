#include "prompt_macro.h"
#include "regex.h"
#include "file_manager.h"
#include "login.h"
#include "trainer.h"
#include "admin.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	//Ʈ���̳� ������ ���� ����
	if (CreateTrainerFile() == 1) { // ������ ������ ���� ���
		//������ ��ȿ�� �˻�
		if (!ValidateTrainerDataFile(TRAINER_DATA_FILE_PATH, ADMIN_INFO_PATTERN, TRAINER_INFO_PATTERN)) {
			printf("���� ���� ����");
			exit(1);
		}
	}
	//ȸ�� ������ ���� ����
	if (CreateMemberFile() == 1) { // ������ ������ ���� ���
		if (!ValidateMemberDataFile(MEMBER_DATA_FILE_PATH, MEMBER_INFO_PATTERN)) {
			printf("���� ���� ����");
			exit(1);
		}
	}

	//������Ʈ ����
	while (1) {
		printf(INITIAL);

		PrintLogin();
		InputLogin();
	}

	return 0;
}
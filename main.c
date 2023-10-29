#include "prompt_macro.h"
#include "regex.h"
#include "file_manager.h"
#include "login.h"
#include "trainer.h"
#include "admin.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	//트레이너 데이터 파일 생성
	if (CreateTrainerFile() == 1) { // 기존에 파일이 있을 경우
		//데이터 유효성 검사
		if (!ValidateTrainerDataFile(TRAINER_DATA_FILE_PATH, ADMIN_INFO_PATTERN, TRAINER_INFO_PATTERN)) {
			printf("파일 내용 결함");
			exit(1);
		}
	}
	//회원 데이터 파일 생성
	if (CreateMemberFile() == 1) { // 기존에 파일이 있을 경우
		if (!ValidateMemberDataFile(MEMBER_DATA_FILE_PATH, MEMBER_INFO_PATTERN)) {
			printf("파일 내용 결함");
			exit(1);
		}
	}

	//프롬프트 시작
	while (1) {
		printf(INITIAL);

		PrintLogin();
		InputLogin();
	}

	return 0;
}
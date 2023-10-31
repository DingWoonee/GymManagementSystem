#pragma once
//프롬프트 문구
#define INITIAL "\
###############################################\n\
##                                           ##\n\
##           GYM MANAGEMENT SYSTEM           ##\n\
##                                           ##\n\
###############################################\n"
#define MENU_INPUT_ERROR_MESSAGE "원하는 메뉴의 숫자만을 입력해 주세요.\n선택하세요(숫자만 입력) : "
#define ADMIN_LOGIN_ERROR_MESSAGE "비밀번호가 틀립니다.\n"
#define TRAINER_LOGIN_ERROR_MESSAGE "존재하지 않는 이름입니다.\n"
#define INPUT_INFO_ERROR_MESSAGE "입력 데이터가 올바르지 않습니다."
#define INPUT_ID_ERROR_MESSAGE "없는 번호입니다."
#define ADMIN_PROMPT "[관리자 메뉴]\n1. 트레이너 등록\n2. 트레이너 수정\n3. 트레이너 삭제\n4. 회원 등록\n5. 회원 수정\n6. 회원 삭제\n7. 로그아웃\n0. 종료\n선택하세요(숫자만 입력) : "
#define TRAINER_REGISTRATION_PROMPT1 "[트레이너 등록]\n이름, 생년월일, 연락처를 입력해 주세요.\n(입력예시: 홍길동 19991225 01067003261)\n입력 : "
#define TRAINER_REGISTRATION_PROMPT2 "입사일을 입력해 주세요.\n(입력예시: 20221229)\n입력 : "
#define TRAINER_UPDATE_PROMPT "[트레이너 수정]\n고유번호를 입력해 주세요.\n(입력예시: 13)\n입력 : "
#define UPDATE_COMPLETE_MESSAGE "수정이 완료되었습니다."
#define TRAINER_DELETION_PROMPT "[트레이너 삭제]\n고유번호를 입력해 주세요.\n(입력예시: 13)\n입력 : "
#define CONFIRM_DELETION_PROMPT "정말 삭제하시겠습니까? (“삭제”라고 입력 시 삭제)\n(입력예시 : 삭제)\n입력 : "
#define DELETION_COMPLETE_MESSAGE "삭제가 완료되었습니다."
#define MEMBER_REGISTRATION_PROMPT1 "[회원 등록]\n이름, 생년월일, 연락처를 입력해 주세요.\n(입력예시: 홍길동 19991225 01067003261)\n입력 : "
#define MEMBER_REGISTRATION_PROMPT2 "등록일, 담당 트레이너, PT반, PT횟수를 입력해 주세요.\n(입력예시: 20221229 김길동 오전반 30)\n입력 : "
#define MEMBER_UPDATE_PROMPT "[회원 수정]\n회원 번호를 입력해 주세요.\n(입력예시: 13)\n입력 : "
#define UPDATE_COMPLETE_MESSAGE "수정이 완료되었습니다."
#define MEMBER_DELETION_PROMPT "[회원 삭제]\n회원 번호를 입력해 주세요.\n(입력예시: 13)\n입력 : "
#define TRAINER_PROMPT "[트레이너 메뉴]\n1. 담당회원\n2. 로그아웃\n0. 종료\n선택하세요(숫자만 입력) : "
#define ASSIGNED_MEMBER_LIST_MESSAGE "[담당 회원 리스트]\n회원번호\t이름\t번호\tPT반\tPT횟수\n\n"

//기타
#define TRAINER_DATA_FILE_PATH "trainer_data.txt"
#define MEMBER_DATA_FILE_PATH "member_data.txt"
#define ADMIN_INFO "관리자 1111"
#define MAX_LINE 1024

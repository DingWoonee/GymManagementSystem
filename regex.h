#pragma once
#include <stdbool.h>

#define NAME_PATTERN "^[��-�R]+$"
#define DATE_PATTERN "^\\d{8}$"
#define CONTACT_PATTERN "^010\\d{8}$|^00000000000$"
#define TRAINER_LIST_PATTERN "^[��-�R]+(?: [��-�R]+)*$"
#define PT_CLASS_PATTERN "^(������|���Ĺ�)$"
#define PT_REMAIN_PATTERN "^\\d+$"
#define PASSWORD_PATTERN "^[A-Za-z0-9]{6,15}$"
#define NAME_DATE_CONTACT_PATTERN "^[��-�R]+ \\d{8} (010\\d{8}|00000000000)$"
#define TRAINER_INFO_PATTERN "^[가-힣]+ \\d{8} (010\\d{8}|00000000000)$ \\d{8}"
#define DATE_NAME_PT_CLASS_PT_REMAIN "^\\d{8} [��-�R]+ (������|���Ĺ�) \\d+$"
#define MEMBER_INFO_PATTERN "^[��-�R]+ \\d{8} (010\\d{8}|00000000000) \\d{8} [��-�R]+(?: [��-�R]+)* (������|���Ĺ�) \\d+$"
#define ADMIN_INFO_PATTERN "^������ [A-Za-z0-9]{6,15}$"

bool IsMatch(const char* pattern, const char* input);
#pragma once
#include <stdbool.h>

#define NAME_PATTERN "^[°¡-ÆR]+$"
#define DATE_PATTERN "^\\d{8}$"
#define CONTACT_PATTERN "^010\\d{8}$|^00000000000$"
#define TRAINER_LIST_PATTERN "^[°¡-ÆR]+(?: [°¡-ÆR]+)*$"
#define PT_CLASS_PATTERN "^(¿ÀÀü¹Ý|¿ÀÈÄ¹Ý)$"
#define PT_REMAIN_PATTERN "^\\d+$"
#define PASSWORD_PATTERN "^[A-Za-z0-9]{6,15}$"
#define NAME_DATE_CONTACT_PATTERN "^[°¡-ÆR]+ \\d{8} (010\\d{8}|00000000000)$"
#define TRAINER_INFO_PATTERN "^[°¡-ÆR]+ \\d{8} (010\\d{8}|00000000000)$ \\d{8}"
#define DATE_NAME_PT_CLASS_PT_REMAIN "^\\d{8} [°¡-ÆR]+ (¿ÀÀü¹Ý|¿ÀÈÄ¹Ý) \\d+$"
#define MEMBER_INFO_PATTERN "^[°¡-ÆR]+ \\d{8} (010\\d{8}|00000000000) \\d{8} [°¡-ÆR]+(?: [°¡-ÆR]+)* (¿ÀÀü¹Ý|¿ÀÈÄ¹Ý) \\d+$"
#define ADMIN_INFO_PATTERN "^°ü¸®ÀÚ [A-Za-z0-9]{6,15}$"

bool IsMatch(char* pattern, char* input);
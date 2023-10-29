#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "regex.h"
#include "prompt_macro.h"

#define MaxMenuNum 10

int InputId(const char* file_path);

void AdminPrompt();

void AddTrainerInfo();

void ResignTrainer(const char* file_path, const char* file_path2);

void RejoinTrainer(const char* file_path);

void UpdateInfo(const char* file_path, const char* input_pattern);

void DelInfo(const char* file_path);

void AddMemberInfo();

void PrintNoTrainerMemberList();
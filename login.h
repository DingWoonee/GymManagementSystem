#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prompt_macro.h"
#include "regex.h"

void PrintLogin();

int InputLogin();

void PrintAdminLogin();

char* InputAdminPW();

void PrintTrainerLogin();

char* InputTrainerName();

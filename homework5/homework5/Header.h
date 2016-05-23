#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char decimal(char first, char last);
void decode(char *input, char *output);
void enorde(char source[], char destination[], char argv);
char hexadecimal(int asc, int locate);
void encode(char *enter, char *output);
void write(FILE *fPtr, char content[]);
FILE* open(char fileName[], char type[]);
#ifndef FILE_H
#define FILE_H

#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define BUFFER 4096
#define TRUE 1
#define FALSE 0

FILE* OpenFile(const char*, const char*);

// Read file
int  ReadFileNumber(const char*, const char*, int*);
void ReadFile(const char*);
void ReadFile4KB(const char*);

// Get size of file
int GetSizeFile(const char*);
#if defined(__linux)
#pragma messeage("you are using linux distro")
#include"sys/stat.h"
int GetSizeFileLinux(const char*);
#endif

// Write file
void WriteFile(const char*, const char*);
void WriteMethod(const char*);
int WriteContent(char*);

// Copy file
int CopyFile(const char*, const char*);

// File handle
int DeleteFile(const char*);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HASH_SIZE 1024
#define MAX_WORD_LENGTH 16

typedef struct __ENTRY
{
    struct __ENTRY *pNext;
    char name[MAX_WORD_LENGTH];
} entry;

entry *findByName(char [], entry *[]);
void hTblappend(char [], entry *[]);

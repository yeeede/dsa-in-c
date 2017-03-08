#include "hash.h"

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; //131
    unsigned int hash = 0;
    while(*str)
    {
        hash = hash * seed + (*str++);
    }
    return hash;
}

void hTblappend(char name[], entry *h[])
{
    unsigned int hVal = BKDRHash(name) % HASH_SIZE;
    strcpy(h[hVal]->name, name);
    h[hVal]->pNext = (entry *) malloc(sizeof(entry));
    h[hVal] = h[hVal]->pNext;
    h[hVal]->pNext = NULL;
}


entry *findByName(char name[], entry *pHead[])
{
    entry *ptr[MAX_WORD_LENGTH];
    int i;
    for(i = 0; i < MAX_WORD_LENGTH; i++)
        ptr[i] = pHead[i];

    unsigned int hVal = BKDRHash(name) % HASH_SIZE;
    while(ptr[hVal])
    {
        if(strcasecmp(name, ptr[hVal]->name)) return ptr[hVal];
        ptr[hVal] = ptr[hVal]->pNext;
    }
    return NULL;
}

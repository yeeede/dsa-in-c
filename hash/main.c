#include <stdio.h>
#include <string.h>
#include <assert.h>

#include IMPL

void help()
{
    printf("/*\n");
    printf("  USAGE: $ ./hash <input> <output>\n");
    printf("  input should be words per line\n");
    printf("  Each words is at most MAX_WORD_SIZE\n");
    printf("  output file will shuffle the words in order\n");
    printf("*/\n");
}

int main(int argc, char *argv[])
{

    if(argc != 3)
    {
        help();
        return -1;
    }

    /* read file */
    FILE *fInput;
    fInput = fopen(argv[1], "r");
    if (fInput == NULL)
    {
        printf("cannot open the file \n");
        return -1;
    }

    /* build entry */
    char line[MAX_WORD_LENGTH];
    entry *hTbl[HASH_SIZE];
    entry *pHead[HASH_SIZE];

    int i = 0;
    for(i = 0; i < HASH_SIZE; i++)
    {
        entry *tEntry = (entry *) malloc(sizeof(entry));
        pHead[i] = hTbl[i] = tEntry;
    }

    int j = 0;
    while (fgets(line, sizeof(line), fInput))
    {
        while (line[j] != '\0')
            j++;
        line[j - 1] = '\0';
        j = 0;
        hTblappend(line, hTbl);
    }

    fclose(fInput);

    /* write file */
    /*
    FILE *fOutput = fopen(argv[2], "w");
    for(i=0; i<HASH_SIZE; i++)
    {
        fprintf(fOutput, "%d\n", i); //index = hash number
        entry *tPrint = (entry *) malloc(sizeof(entry));
        tPrint->pNext = pHead[i]->pNext;
        strcpy(tPrint->name, pHead[i]->name);
        while(tPrint->pNext != NULL)
        {
            fprintf(fOutput, "%s\n", tPrint->name);
            tPrint = tPrint->pNext;
        }
        fprintf(fOutput, "\n");
        free(tPrint);
    }
    fclose(fOutput);
    */

    char input[MAX_WORD_LENGTH] = "zyxel";
    if(findByName(input, pHead)) 
        printf("found\n");

    /* free memory */
    for(i = 0; i < HASH_SIZE; i++)
    {
        entry *tFree;
        if(pHead[i])
        {
            tFree = pHead[i];
            pHead[i] = pHead[i]->pNext;
            free(tFree);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead,unsigned char *indexOut)
{
    /* TODO: implement */
    *indexOut = 0;
    while (pHead != NULL) {
        if((*indexOut) < (pHead ->index)) {
            if (strcasecmp(lastname, pHead->lastName[(*indexOut)++]) == 0) {
                return pHead;
            }
        } else {
            pHead = pHead->pNext;
            *indexOut =0;
        }
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    if(e->index ==0 ) {
        e->pNext = (entry *) malloc(sizeof(entry));
        e = e->pNext;
        e->index =0;
        e->pNext = NULL;
    }
    //struct is full
    else if(e->index == entrySize) {
        e->pNext = (entry *) malloc(sizeof(entry));
        e = e->pNext;
        e->pNext = NULL;
        e->index =0;
        strcpy(e->lastName[e->index++], lastName);
        return e;
    }
    strcpy(e->lastName[e->index++], lastName);
    return e;
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

void append_elements(char elements[16],char *info)
{
    info = (char*)malloc(16*sizeof(char));
    strcpy(info, elements);
    return;
}
void freeList(entry *head)
{
    entry *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->pNext;
        free(tmp);
    }

}

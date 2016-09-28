#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
//#define OPT_HASH 1
//#define OPT 1
#define SIZE 1024
#define entrySize 128
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[entrySize][MAX_LAST_NAME_SIZE];
    unsigned char index;
    struct __PHONE_BOOK_ENTRY *pNext;
    struct __PHONE_BOOK_EXTRA_ENTRY *infoNext;
} entry;

typedef struct __PHONE_BOOK_EXTRA_ENTRY {
    char *firstName_ptr;
    char *email_ptr;
    char *phone_ptr;
    char *cell_ptr;
    char *addr1_ptr;
    char *addr2_ptr;
    char *city_ptr;
    char *state_ptr;
    char *zip_ptr;

} info;

unsigned int BKDRHash(char *str);
entry *findName(char lastname[], entry *pHead,unsigned char *index_out);
entry *append(char lastName[], entry *e);
void append_elements(char elements[16],char *info);
void freeList(entry *head);
#endif

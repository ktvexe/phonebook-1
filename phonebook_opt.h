#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char *firstName_ptr;
    char *email_ptr;
    char *phone_ptr;
    char *cell_ptr;
    char *addr1_ptr;
    char *addr2_ptr;
    char *city_ptr;
    char *state_ptr;
    char *zip_ptr;
    struct __PHONE_BOOK_ENTRY *pNext;

} entry;

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif

#ifndef ___iLab_List__my_list__
#define ___iLab_List__my_list__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {ERREXIST = 1, ERRNOMEM, ERRALLOC, ERRNOELEM};

struct elem{
    int data;
    int count;
    struct elem* next;
    struct elem* prev;
};

typedef struct elem list_elem;

typedef struct{
    list_elem* first;
    int (*cmp)(int, int);
}my_list;

my_list* list_new(int data, int (*cmp)(int, int));
int list_delete(my_list* list);

int insert_elem(my_list* list, int data);
int delete_elem(my_list* list, int data);
int find_elem(my_list* list, int data);

int find_or_delete(my_list* list, int data, short delOrNdel);

void list_dump(my_list* list);



#endif /* defined(___iLab_List__my_list__) */

#include "my_list.h"

my_list* list_new(int data, int (*cmp)(int, int)){
    my_list* list = (my_list*)calloc(1, sizeof(*list));
    if (list == NULL) {
        return NULL;
    }
    
    list->cmp = cmp;
    list->first = (list_elem*)calloc(1, sizeof(*list->first));
    if (list->first == NULL) {
        free(list);
        return NULL;
    }
    
    list->first->data = data;
    
    list->first->prev = NULL;
    list->first->next = NULL;
    
    return list;
}

int list_delete(my_list* list){
    
    if (list == NULL) {
        return ERREXIST;
    }
    list_elem* tmp_elem_1 = list->first, *tmp_elem_2 = NULL;
    while (tmp_elem_1 != NULL) {
        tmp_elem_2 = tmp_elem_1;
        tmp_elem_2->next = NULL;
        tmp_elem_2->prev = NULL;
        free(tmp_elem_2);
        
        tmp_elem_1 = tmp_elem_1->next;
    }
    
    list->first = NULL;
    list->cmp = NULL;
    
    free(list);
    
    return 0;
}

int insert_elem(my_list* list, int data){
    list_elem* tmp_elem = list->first;

    if (list->first == NULL) {
        list_elem* new_elem = (list_elem*)calloc(1, sizeof(*new_elem));
        if (new_elem == NULL) {
            return ERRALLOC;
        }
        new_elem->data = data;
        list->first = new_elem;
        return 0;
    }
    
    if (list->cmp(list->first->data, data) >= 0) {
        if (list->cmp(list->first->data, data) == 0) {
            list->first->count++;
        }else{
            list_elem* new_elem = (list_elem*)calloc(1, sizeof(*new_elem));
            if (new_elem == NULL) {
                return ERRALLOC;
            }
            new_elem->data = data;
            new_elem->prev = NULL;
            new_elem->next = list->first;
            list->first->prev = new_elem;
            list->first = new_elem;
        }
        return 0;
    }
    
    while (1) {
        if ((tmp_elem->next == NULL)||(list->cmp(tmp_elem->next->data, data) >= 0)) {
            break;
        }
        tmp_elem = tmp_elem->next;
    }
    if ((tmp_elem->next != NULL)&&(list->cmp(tmp_elem->next->data, data) == 0)) {
        tmp_elem->next->count++;
    }else{
        list_elem* new_elem = (list_elem*)calloc(1, sizeof(*new_elem));
    if (new_elem == NULL) {
            return ERRALLOC;
        }
    
        new_elem->data = data;

        new_elem->next = tmp_elem->next;
        new_elem->prev = tmp_elem;
    
        if (tmp_elem->next != NULL) {
            tmp_elem->next->prev = new_elem;
        }
    
    
        tmp_elem->next = new_elem;
    }
    return 0;
}

int find_or_delete(my_list* list, int data, short delOrnDel){
    list_elem* tmp_elem = list->first;
    while (1) {
        if (list->cmp(list->first->data, data) == 0) {
            if(delOrnDel == 1){
                if (tmp_elem->prev != NULL) {
                    tmp_elem->prev->next = tmp_elem->next;
                }
                if (tmp_elem->next != NULL) {
                    tmp_elem->next->prev = tmp_elem->prev;
                    list->first = tmp_elem->next;
                }else{
                    list->first = NULL;
                }
                
                free(tmp_elem);
                return 0;
            }else{
                return 0;
            }
        }
        if (tmp_elem->next == NULL) {
            if (list->cmp(tmp_elem->data, data) == 0) {
                if(delOrnDel == 1){
                    if (tmp_elem->prev != NULL) {
                        tmp_elem->prev->next = tmp_elem->next;
                    }
                    if (tmp_elem->next != NULL) {
                        tmp_elem->next->prev = tmp_elem->prev;
                    }
                    free(tmp_elem);
                    return 0;
                }else{
                    return 0;
                }
            }
            break;
        }
        
        if (list->cmp(tmp_elem->next->data, data) > 0) {
            if (list->cmp(tmp_elem->data, data) == 0) {
                if(delOrnDel == 1){
                    if (tmp_elem->prev != NULL) {
                        tmp_elem->prev->next = tmp_elem->next;
                    }
                    if (tmp_elem->next != NULL) {
                        tmp_elem->next->prev = tmp_elem->prev;
                    }
                    free(tmp_elem);
                    return 0;
                }else{
                    return 0;
                }
            }
        }
        
        tmp_elem = tmp_elem->next;
    }
    
    return ERRNOELEM;
}

int delete_elem(my_list* list, int data){
    if (find_or_delete(list, data, 1)) {
        printf("Elem \"%d\" not found\n", data);
        return 0;
    }
    return ERRNOELEM;
}

int find_elem(my_list* list, int data){
    if (find_or_delete(list, data, 0)) {
        printf("Elem \"%d\" not found", data);
        return 0;
    }
    return ERRNOELEM;
}

void list_dump(my_list* list){
    list_elem* tmp_elem = list->first;
    while (1) {
        if (tmp_elem == NULL) {
            break;
        }
        printf("%d %d\n", tmp_elem->data, tmp_elem->count+1);
        tmp_elem = tmp_elem->next;
        
    }
}

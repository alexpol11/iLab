#include "my_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

//
// функций swap и dump нет, тк не понял что они делают
//
//

void killUncorrectStack(my_stack_double* stack, char* progPath){
    if (stack == NULL){
        printf("%s ERROR: Stack doesn't exist!\n", progPath);
        exit(1);
    }
    if (stack->stack_pointer == NULL){
        printf("%s ERROR: NULL stack pointer!\n", progPath);
        exit(2);
    }
    if (stack->size == 0){
        printf("%s ERROR: NULL stack size!\n", progPath);
        exit(3);
    }
    if (stack->data == NULL){
        printf("%s ERROR: Data points on NULL adress!\n", progPath);
        exit(4);
    }
}

int my_stack_double_empty(my_stack_double* stack){
    if (stack->stack_pointer == stack->data) {
        return 1;
    }
    return 0;
}

size_t my_stack_double_size(my_stack_double* stack){
    return stack->size;
}

my_stack_double* my_stack_double_new(size_t size){
    if (size == 0) {
        printf("CONSTRUCTOR ERROR: You can't create NULL size stack!\n");
        exit(5);
    }
    my_stack_double* stack = (my_stack_double*)calloc(1, sizeof(stack));
    if (stack == NULL){
        printf("CONSTRUCTOR ERROR: Stack create failed!\n");
        exit(6);
    }

    stack->size = size;
    stack->data = (double*)calloc(stack->size, sizeof(*stack->data));
    stack->stack_pointer = stack->data;

    if (stack->data == NULL) {
        printf("CONSTRUCTOR ERROR: Stack create failed!\n");
        exit(7);
    }
    return stack;
}

int my_stack_double_push(my_stack_double* stack, double data){
    killUncorrectStack(stack, "PUSH");
    if (stack->stack_pointer == &stack->data[stack->size - 1] + 1) {
        printf("PUSH ERROR: Stack overflow!\n");
        exit(1);
    }
    *stack->stack_pointer = data;
    stack->stack_pointer++;
    if (my_stack_double_empty(stack)){
        printf("PUSH ERROR: Push result: empty stack!\n");
        exit(8);
    }
    return 0;
}

double my_stack_double_pop(my_stack_double* stack){
    killUncorrectStack(stack, "POP");
    double element = 0;

    if (my_stack_double_empty(stack)) {
        printf("POP ERROR: Empty stack!\n");
        exit(9);
    }

    stack->stack_pointer--;
    element = *stack->stack_pointer;
    *stack->stack_pointer = 0;

    return element;
}

int my_stack_double_delete(my_stack_double* stack){
    if (stack == NULL){
        printf("DESTRUCTOR ERROR: Stack doesn't exist!\n");
    }
    stack->stack_pointer = NULL;
    free(stack->data);
    free(stack);
    return 0;
}

double my_stack_double_top(my_stack_double* stack){
    killUncorrectStack(stack, "TOP");
    double element = 0;

    if (my_stack_double_empty(stack)) {
        printf("TOP ERROR: Empty stack!\n");
        exit(10);
    }

    element = *(stack->stack_pointer - 1);

    return element;
}

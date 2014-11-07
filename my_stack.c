#include "my_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void EXIT(my_stack_double* stack, int errCode){
    my_stack_double_delete(stack);
    exit(errCode);
}

void my_stack_double_dump(my_stack_double* stack){
    int i = 0;
    while(&stack->data[i] != stack->stack_pointer){
        printf("data[%d] = %0.2f\n", i, stack->data[i]);
        i++;
    }
}

void killUncorrectStack(my_stack_double* stack, char* progPath){
    if (stack == NULL){
        printf("%s ERROR: Stack doesn't exist!\n", progPath);
        EXIT(stack, 1);
    }
    if (stack->stack_pointer == NULL){
        printf("%s ERROR: NULL stack pointer!\n", progPath);
        EXIT(stack, 2);
    }
    if (stack->data == NULL){
        printf("%s ERROR: Data points on NULL adress!\n", progPath);
        EXIT(stack, 4);
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
        return my_stack_double_new(1);
    }
    my_stack_double* stack = (my_stack_double*)calloc(1, sizeof(*stack));
    if (stack == NULL){
        perror("CONSTRUCTOR ERROR: Stack create failed!\n");
        exit(6);
    }
    
    stack->size = size;
    stack->data = (double*)calloc(stack->size, sizeof(*stack->data));
    stack->stack_pointer = stack->data;

    if (stack->data == NULL) {
        perror("CONSTRUCTOR ERROR: Stack create failed!\n");
        EXIT(stack, 7);
    }
    return stack;
}

int my_stack_double_push(my_stack_double* stack, double data){
    killUncorrectStack(stack, "PUSH");
    
    if (stack->stack_pointer == &stack->data[stack->size - 1] + 1) {
        double* tmpData = (double*)malloc((stack->size+1)*sizeof(*tmpData));
        
        if (stack->data == NULL){
            perror("PUSH ERROR: Stack data allocation failed!\n");
            exit(8);
        }
        
        int i = 0;
        while (i != stack->size) {
            tmpData[i] = stack->data[i];
            i++;
        }
        free(stack->data);
        stack->data = tmpData;
        stack->stack_pointer = &stack->data[stack->size];
        stack->size++;
    }
    *stack->stack_pointer = data;
    stack->stack_pointer++;
    if (my_stack_double_empty(stack)){
        printf("PUSH ERROR: Push result: empty stack!\n");
        EXIT(stack, 9);
    }
    return 0;
}

double my_stack_double_pop(my_stack_double* stack){
    killUncorrectStack(stack, "POP");
    double element = 0;

    if (my_stack_double_empty(stack)) {
        printf("POP ERROR: Empty stack!\n");
        EXIT(stack, 10);
    }

    stack->stack_pointer--;
    element = *stack->stack_pointer;
    *stack->stack_pointer = 0;

    return element;
}

int my_stack_double_delete(my_stack_double* stack){
    if (stack == NULL){
        printf("DESTRUCTOR ERROR: Stack doesn't exist!\n");
        return -1;
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
        EXIT(stack, 11);
    }

    element = *(stack->stack_pointer - 1);

    return element;
}

void swap(my_stack_double* stack){
    double num1 = 0, num2 = 0;
    num1 = my_stack_double_pop(stack);
    num2 = my_stack_double_pop(stack);
    my_stack_double_push(stack, num2);
    my_stack_double_push(stack, num1);
}

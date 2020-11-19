#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


void push(struct stack* this, int x){
    if(this->num_of_elements >0){
        struct linking_list * link_t = malloc(sizeof(struct linking_list));
        link_t->next_p = this->list;
        link_t->value = x;
        this->list = link_t;
    }
    else{
        struct linking_list * link_t = malloc(sizeof(struct linking_list));
        link_t->next_p = NULL;
        link_t->value = x;
        this->list = link_t;
    }
    this->num_of_elements += 1;
}

int pop(struct stack* this){
    if(this->num_of_elements >0){
        int pop_value;
        struct linking_list * pop_list;
        pop_value = this->list->value;
        pop_list = this->list;
        this->list = pop_list->next_p;
        free(pop_list);
        this->num_of_elements -= 1;
        return pop_value;
    }
    else{
        return -1;
    }
}

struct stack* new_stack(){
    struct stack * stack_t = malloc(sizeof(struct stack));
    stack_t->list = NULL;
    stack_t->num_of_elements = 0;
}

void delete_stack(struct stack* stk){
    while(stk->list != NULL){
        struct linking_list * pop_list;
        pop_list = stk->list;
        stk->list = pop_list->next_p;
        free(pop_list);
    }
    free(stk);
}
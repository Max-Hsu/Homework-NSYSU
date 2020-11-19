#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

struct linking_list{
    int value;
    struct linking_list * next_p;
};
struct stack {
    int num_of_elements;
    struct linking_list * list;
};

extern void push(struct stack* this, int x);
extern int pop(struct stack* this);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);

#endif
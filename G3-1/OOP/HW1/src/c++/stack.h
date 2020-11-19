#ifndef __STACK_H__
#define __STACK_H__
struct linking_list{
    int value;
    struct linking_list * next_p;
};
class Stack {
    enum { STACK_SIZE = 100 };

    int num_of_elements;
    struct linking_list * list;

    public:
        Stack();
        void push(int x);
        int pop();
        ~Stack();
};

#endif
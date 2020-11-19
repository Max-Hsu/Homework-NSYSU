#include "stack.h"

Stack::Stack(){
    num_of_elements = 0;
    list = nullptr;
}
void Stack::push(int x){
    if(num_of_elements > 0){
        struct linking_list * link_t = new(struct linking_list);
        link_t->next_p = this->list;
        link_t->value = x;
        this->list = link_t;
    }
    else{
        struct linking_list * link_t = new(struct linking_list);
        link_t->next_p = nullptr;
        link_t->value = x;
        this->list = link_t;
    }
    num_of_elements += 1;
}
int Stack::pop(){
    if(this->num_of_elements >0){
        int pop_value;
        struct linking_list * pop_list;
        pop_value = this->list->value;
        pop_list = this->list;
        this->list = pop_list->next_p;
        delete(pop_list);
        this->num_of_elements -= 1;
        return pop_value;
    }
    else{
        return -1;
    }
}

Stack::~Stack(){
    while(this->list != nullptr){
        struct linking_list * pop_list;
        pop_list = this->list;
        this->list = pop_list->next_p;
        delete(pop_list);
    }
}
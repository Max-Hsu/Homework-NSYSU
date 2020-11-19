#include <stdio.h>
#include "stack.h"

const int NUM_ITEMS = 200;

int main()
{
struct stack* stk1 = new_stack();
struct stack* stk2 = new_stack();

int i;

for (i = 0; i < NUM_ITEMS; i++) {
push(stk1, 200+i);
push(stk2, 700+i);
}

printf("Dump of stack 1:\n");
for (i = 0; i < NUM_ITEMS; i++)
printf("%d\n", pop(stk1));

printf("Dump of stack 2:\n");
for (i = 0; i < NUM_ITEMS; i++)
printf("%d\n", pop(stk2));

delete_stack(stk1);
delete_stack(stk2);

return 0;
}
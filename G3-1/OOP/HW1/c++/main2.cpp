#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;

const int NUM_ITEMS = 200;

int main()
{
    Stack stk1;
    Stack stk2;

for (int i = 0; i < NUM_ITEMS; i++) {
    stk1.push(200+i);
    stk2.push(700+i);
}

cout << "Dump of stack 1:" << endl;
for (int i = 0; i < NUM_ITEMS; i++)
    cout << stk1.pop() << endl;

cout << "Dump of stack 2:" << endl;
for (int i = 0; i < NUM_ITEMS; i++)
    cout << stk2.pop() << endl;

return 0;
}
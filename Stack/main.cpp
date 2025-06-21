#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    
    stack.Pop();
    stack.Pop();
    stack.Pop();
    
    stack.PrintStack();
    
    stack.IsTop();
    
    cout << "Stack Size: " << stack.GetLength() << "\n";
    
    return 0;
}

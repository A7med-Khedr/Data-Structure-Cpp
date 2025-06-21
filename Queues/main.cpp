#include <iostream>
using namespace std;
#include "Queue.h"

int main()
{
    Queue<int> My_Queue;

    My_Queue.EnQueue(4);
    My_Queue.EnQueue(5);
    My_Queue.EnQueue(7);
    My_Queue.EnQueue(9);

    My_Queue.DeQueue();
    My_Queue.DeQueue();
    My_Queue.DeQueue();

    My_Queue.Print();

    cout << My_Queue.GetLength();

    return 0;
}

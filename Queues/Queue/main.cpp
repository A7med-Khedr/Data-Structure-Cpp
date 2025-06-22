#include <iostream>
using namespace std;
#include "queue.h"

int main()
{
    Queue<int> queue;

    queue.EnQueue(4);
    queue.EnQueue(5);
    queue.EnQueue(7);
    queue.EnQueue(9);

    queue.DeQueue();
    queue.DeQueue();
    queue.DeQueue();

    queue.PrintQueue();

    cout << queue.GetLength();

    return 0;
}

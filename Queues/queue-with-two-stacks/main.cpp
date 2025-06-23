#include <iostream>
#include "queue_with_two_stack.h"
using namespace std;

int main() {
	QueueCloned<int> q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);

	q.Print(); // Output: 1 2 3

	q.DeQueue(); // Removes 1

	q.Print(); // Output: 2 3

	q.Clear();
}

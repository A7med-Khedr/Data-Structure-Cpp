#include <iostream>
using namespace std;
#include "linked_list.h"

int main()
{
    Linked_List<int> list;

    cout << "Test Linked List\n";
    list.insertNodeAtBeginning(3);
    list.insertNodeAtBeginning(2);
    list.insertNodeAtBeginning(1);
    list.insertNodeAtEnd(4);
    list.insertNodeAtEnd(8);

    list.insertAtPosition(5, 4);
    list.insertAtPosition(6, 5);
    list.insertAtPosition(10, 6);

    list.printList();
    cout << "Length: " << list.getLength() << "\n";
    cout << "Middel Element  is: " << list.middleElement() << "\n";

    cout << "===================\n";

    list.removeNode(8);
    list.removeNode(1);
    list.removeNode(4);
    list.removeNode(5);

    list.printList();

    cout << "Length: " << list.getLength() << "\n";
    cout << "Middel Element  is: " << list.middleElement() << "\n";
    cout << "===================\n";

    list.insertNodeAtBeginning(1);
    list.insertNodeAtEnd(4);

    list.printList();
    cout << "Middel Element  is: " << list.middleElement() << "\n";
    cout << "===================\n";

    return 0;
}

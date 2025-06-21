#include <iostream>
using namespace std;
#include "linked_list.h"

int main()
{
    Linked_List<int> list;

    cout << "Test Linked List\n";
    list.INSERT_NODE_AT_BEGINNING(3);
    list.INSERT_NODE_AT_BEGINNING(2);
    list.INSERT_NODE_AT_BEGINNING(1);
    list.INSERT_NODE_AT_END(4);
    list.INSERT_NODE_AT_END(8);

    list.INSERT_NODE_AT_POSITION(5, 4);
    list.INSERT_NODE_AT_POSITION(6, 5);
    list.INSERT_NODE_AT_POSITION(10, 6);

    list.PRINT_LINKED_LIST();
    cout << "Length: " << list.GET_LENGTH() << "\n";
    cout << "Middel Element  is: " << list.MIDDEL_ELEMENT() << "\n";

    cout << "===================\n";

    list.REMOVE_NODE(8);
    list.REMOVE_NODE(1);
    list.REMOVE_NODE(4);
    list.REMOVE_NODE(5);

    list.PRINT_LINKED_LIST();

    cout << "Length: " << list.GET_LENGTH() << "\n";
    cout << "Middel Element  is: " << list.MIDDEL_ELEMENT() << "\n";
    cout << "===================\n";

    list.INSERT_NODE_AT_BEGINNING(1);
    list.INSERT_NODE_AT_END(4);

    list.PRINT_LINKED_LIST();
    cout << "Middel Element  is: " << list.MIDDEL_ELEMENT() << "\n";
    cout << "===================\n";

    return 0;
}

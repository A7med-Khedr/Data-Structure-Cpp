#include "./Double_Linked_List.h"

int main() {
	Double_Linked_List<int> double_list;

    double_list.INSERT_NODE_AT_BEGINNING(3);
    double_list.INSERT_NODE_AT_BEGINNING(2);
    double_list.INSERT_NODE_AT_BEGINNING(1);
    double_list.INSERT_NODE_AT_END(4);
    double_list.INSERT_NODE_AT_POSITION(5, 4);

    double_list.PRINT_LINKED_LIST();
    cout << "Length: " << double_list.GET_LENGTH() << "\n";
    cout << "===================\n";

    double_list.REMOVE_NODE(1);
    double_list.REMOVE_NODE(2);
    double_list.REMOVE_NODE(3);
    double_list.REMOVE_NODE(4);

    double_list.PRINT_LINKED_LIST();
    cout << "Length: " << double_list.GET_LENGTH() << "\n";

    cout << "End\n";

	return 0;
}

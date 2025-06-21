#include "./Double_Linked_List.h"

int main() {
	Double_Linked_List<int> double_list;

    double_list.Insert_Node_At_Beginning(3);
    double_list.Insert_Node_At_Beginning(2);
    double_list.Insert_Node_At_Beginning(1);
    double_list.Insert_Node_At_End(4);
    double_list.Insert_At_Position(5, 4);

    double_list.Print_List();
    cout << "Length: " << double_list.Get_Length() << "\n";
    cout << "===================\n";

    double_list.Remove_Node(1);
    double_list.Remove_Node(2);
    double_list.Remove_Node(3);
    double_list.Remove_Node(4);

    double_list.Print_List();
    cout << "Length: " << double_list.Get_Length() << "\n";

    cout << "End\n";

	return 0;
}

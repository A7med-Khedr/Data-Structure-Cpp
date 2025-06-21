#include <iostream>
using namespace std;

template <class D> // To Create D Data Type
// And Create List With Any Data Type But The Same List Contain The Same Data Type
class Double_Linked_List
{
    class Double_Node
    {
    public:
        D data;            // Data Initial By User With D Data Type
        Double_Node *next; // Pointer To Reference Next Node
        Double_Node *prev; // Pointer To Reference Pervious Node

        Double_Node(D data) : data(data), next(nullptr), prev(nullptr)
        { // Constructor To Assign Value In Function For Data In Double_Node Equal This But Last Is Faster
          // this->data = value;   // Assign Value In Function For Data In Class
          // this->next = nullptr; // Assign First Value Is nullptr
          // this->prev = nullptr; // Assign First Value Is nullptr
        }
    };

private:
    Double_Node *head = nullptr; // Head pointer To Reference Always In First Element In Double Linked List
    Double_Node *tail = nullptr; // Tail pointer To Reference Always In Last Element In Double Linked List
    // ==========================

    bool isEmpty() // Check List Empty Or No We Need It In Print Function
    {
        return head == nullptr; // This Line => head == nullptr ? True ( 1 ) : False ( 0 )
    }

public:
    void Insert_Node_At_Beginning(D value) // Function To Add Element In First
    {
        Double_Node *New_Node = new Double_Node(value); // Create New Node And Assign Value For Data
        if (head == nullptr)                            // Check If List Empty Or No
        {                                               // If Yes
            head = New_Node;                            // Head Pointer Reference To New_Node
            tail = New_Node;                            // Tail Pointer Reference To New_Node
            return;
        }
        else // If There Many Element
        {
            head->prev = New_Node; // Pointer Before Head Refer New Node To Put It First
            New_Node->next = head; // Pointer To New Node Refer Head
            head = New_Node;       // Head Move New Node Because New Node Is First
        }
    }

    void Insert_Node_At_End(D value)
    {                                                   // Function To Add Data In Last
        Double_Node *New_Node = new Double_Node(value); // Create New Node And Assign Value For Data
        if (this->head == nullptr)                      // Check If List Empty Or No
        {                                               // If Yes
            head = New_Node;                            // Head Pointer Reference To New_Node
            tail = New_Node;                            // Tail Pointer Reference To New_Node
            // Because list Is Empty
            return;
        }
        else // If There Many Element
        {
            tail->next = New_Node; // After Last Element ( Tail Refer It ) Equal New Node
            New_Node->prev = tail; // Pointer Before New Node Refer To Tail
            tail = New_Node;       // Tail Move To New Node Because New Node Is Last Element
        }
    }

    void Insert_At_Position(D value, int pos)
    { // Function To INsert Node In Any Place In Double Linked List
        if (pos < 0)
        { // If User Input Number Less 0 print This
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 0, head == nullptr)
        {                                    // If We Need Add Element In First
            Insert_Node_At_Beginning(value); // Call This Function And Get Value As A Parameter
            return;
        }

        Double_Node *New_Node = new Double_Node(value); // Create New Node And Assign Value To Data In Class
        Double_Node *current = head;                    // Create Current Pointer To Loop In Linked List
        int current_position = 0;                       // Use This To Check Current Pointer Not Exceeds Specific Position

        while (current->next != nullptr && current_position < pos - 1)
        {                            // Check Current Not Arrive Last Element And current_position Is Valid
            current = current->next; // Increment Loop
            current_position++;      // Increment current_position Plus 1 Each Loop Is True
        }

        if (current->next == nullptr && current_position < pos - 1)
        { // If Input By User Exceed Length For Double Linked List Print This
            cout << "Position: " << pos << " Exceeds The Size Of The Linked List\n";
            cout << "Size of Linked List Is: " << this->Get_Length() << "\n";
            delete New_Node; // And Delete New Node To Free Memory
            return;
        }

        New_Node->next = current->next; // Next Pointer To New Node Refer To Next To Current
        New_Node->prev = current;       // Perv Pointer To New  NOde Refer To Current Because Current Element Before New Node
        current->next = New_Node;       // Next Pointer To current Assign to New Node

        if (New_Node->next == nullptr)
        {                    // Check If Insert Element In Tail
            tail = New_Node; // Update Tail Pointer To New NOde
        }
        else
        {
            New_Node->next->prev = New_Node; // Element After New Node Prev Pointer Have It Pointer To New Node
                                             // Because To New Node Is Element Before This
        }
    }

    void Remove_Node(D value)
    {                        // Function To Remove Node
        if (head == nullptr) // Check If List Is Empty Or No
        {
            return; // If yes Out Function
        }

        Double_Node *current = head;     // Create Pointer To Iterate List
        Double_Node *pervious = nullptr; // Create Pointer To Refer Before Current
        while (current != nullptr)       // Break When Current Arrive Last Element
        {
            if (current->data == value) // If Current Equal Value You Need Remove It
            {
                break; // Element You Need Delete It Equal Current
            }
            pervious = current;      // Pervious Pointer Refer Element Before Current Because Break When Find Element
            current = current->next; // Increment While Loop
        }

        if (current == nullptr) // If Not Found Element You Delete It
        {
            cout << "Value Not Found In The List\n"; // Print This
            return;
        }

        if (current == head) // If Current Equal First Element
        {
            head = head->next;   // Update Head T o Next Element
            if (head != nullptr) // If Head Equal Element
            {
                head->prev = nullptr; // Make Perv Pointer To nullptr
            }
            else // Head Equal nullptr And List Became Empty
            {
                tail = nullptr; // Tail Pointer Equal nullptr Because Delete Alone Element And List Is Empty
            }
        }
        else if (current == tail) // if Current Equal Last Element
        {
            tail = tail->prev;   // Update Tail To Before Element
            if (tail != nullptr) // If Tail Equal Element
            {
                tail->next = nullptr; // Make Next Pointer Equal nullptr
            }
            else // Tail Equal nullptr
            {
                head = nullptr; // Head Pointer Equal nullptr Because Delete Alone Element And List Is Empty
            }
        }
        else // If Current Not Equal First Or Last Element
        {
            if (pervious != nullptr && current->next != nullptr) // Pervious Equal Element After Element To Current Equal Element
            {
                pervious->next = current->next; // Pointer To After pervious ( Before Current ) Skip Element And Pointer To Element After Current
                current->next->prev = pervious; // Element To After Current The Prev Pointer Skip Current And Equal Pervious
            }
            else // Not Fount Node
            {
                cout << "Invalid node pointer provided\n"; // Print This
                return;
            }
        }
        delete current; // Delete Current
    }

    void Print_List() // Method To Print Linked List
    {
        if (this->isEmpty()) // Check List Is Empty Or No
        {
            cout << "Linked List Is Empty\n"; // If Yes Print This
        }
        else // If No Print List
        {
            Double_Node *current = head; // Create Element To Move In List
            while (current != nullptr)   // Until Arrive Last Element
            {
                cout << current->data << "\n"; // Print Element
                current = current->next;       // Increment loop
            }
        }
    }

    int Get_Length() // Function To Get Length Of List
    {
        Double_Node *current = head; // Create Node To Move In List
        int count = 0;               // Create Counter To Get Final Length
        while (current != nullptr)   // Break When Current Arrive Last Element
        {
            count++;                 // Increment Count Plus 1
            current = current->next; // Increment For This Loop
        }
        return count; // Return Final Length
    }
};

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

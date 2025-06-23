#ifndef _LINKED_LIST_CPP // any name as you like ( help compiler to provide include this file )
#define _LINKED_LIST_CPP // and defined it

#include "./linked_list.h" // and incluse header file for linked list to implement list operations

template <typename T> // To Create T Data Type
// And Create List With Any Data Type But The Same List Contain The Same Data Type
Linked_List<T>::Linked_List() : head(nullptr), tail(nullptr) {} // Constructor

template <typename T>
bool Linked_List<T>::IS_EMPTY() const
{
    return head == nullptr;
}

template <typename T> // To Create T Data Type
void Linked_List<T>::INSERT_NODE_AT_BEGINNING(T value)
{
    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data
    if (head == nullptr)              // Check Head Equal Null ? Mean Value Is First Element In List : There Is Many Element
    {
        head = New_Node; // Assign Head Pointer To Reference The Data
        tail = New_Node; // And Assign Tail Pointer To Reference The Data
        // Because The Data Is The Alone Element In Linked List
        return;
    }
    else
    {                          // Mean The Linked List Is Not Null
        New_Node->next = head; // Next Pointer To New Node Assign Head ( Because The Head Reference To First Element )
        head = New_Node;       // Move Head Pointer In The New Node Because Head Pointer Always Reference First Element
    }
}

template <typename T>
void Linked_List<T>::INSERT_NODE_AT_END(T value)
{
    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data
    if (head == nullptr)              // Check Head Equal Null ? Mean Value Is First Element In List : There Is Many Element
    {
        head = New_Node; // Assign Head Pointer To Reference The Data
        tail = New_Node; // And Assign Tail Pointer To Reference The Data
        // Because The Data Is The Alone Element In Linked List
        return;
    }
    else
    {                          // Mean The Linked List Is Not Null
        tail->next = New_Node; // tail->next = Null In DeFault | Assign New Node To tail->next When Need Put Node In End
        tail = New_Node;       // Move Tail Pointer In The New Node Because Tail Pointer Always Reference Last Element
    } 
}

template <typename T>
void Linked_List<T>::INSERT_NODE_AT_POSITION(T value, int pos) 
    { // Function To Insert Node In Any Position In Linked List
        if (pos < 0)
        { // If User Input Number Less 0 print This
            cout << "Invalid Position\n";
        }

        if (pos == 0 || head == nullptr)
        {                                    // Check If You Need Add Element At Beginning Linked List
            INSERT_NODE_AT_BEGINNING(value); // Call This Function And Get Value As A Parameter
            return;
        }

        Node *New_Node = new Node(value); // Create New Node To Store Element
        Node *current = head;             // Create Pointer To Loop In Linked List
        int current_position = 0;         // Use This To Check Current Pointer Not Exceeds Specific Position

        while (current->next != nullptr && current_position < pos - 1)
        {                            // Check Current Not Arrive Last Element And current_position Is Valid
            current = current->next; // Increment Loop
            current_position++;      // Increment current_position Plus 1 Each Loop Is True
        }

        if (current->next == nullptr && current_position < pos - 1)
        { // If Input By User Exceed Length For Linked List Print This
            cout << "Position: " << pos << " Exceeds The Size Of The Linked List\n";
            cout << "Size of Linked List Is: " << this->GET_LENGTH() << "\n";
            delete New_Node; // Delete New Node To Free Memory
            return;
        }
        // If Valid Position
        New_Node->next = current->next; // Next Pointer To New Node Refer To Next To Current
        current->next = New_Node;       // Next Pointer To Current Refer To New Node

        if (New_Node->next == nullptr)
        {                    // Check If Insert Node At End
            tail = New_Node; // Update Tail To New Node
        }
    }

template <typename T>
void Linked_List<T>::REMOVE_NODE(T value)
{
    if (head == nullptr) // Check List Is Empty Or No
    {
        return; // list Is Empty
    }

    if (value == head->data) // Check If value Equal First Element
    {
        head = head->next;   // Move Head To Next Element
        if (head == nullptr) // If Next Element Equal nullptr Mean We Deleted Alone Element
        {
            tail = nullptr; // Update Tail pointer To nullptr Because List Became Empty
        }
        return;
    }

    Node *current = head;      // Create Pointer To Move In List
    Node *perv = nullptr;      // Pointer Refer Before Node To Remove It
    while (current != nullptr) // Stop When Current Arrive Last Element
    {
        if (current->data == value) // If found Node To Need Delete It
        {
            break; // Element You Need Delete It Equal Current
        }
        perv = current;          // Perv Pointer Refer Element Before Current Because Break When Find Element
        current = current->next; // Increment While Loop
    }

    if (current == nullptr) // Check If Current Arrive Last Element And To Find Element To Delete
    {
        cout << "Value Not Found In The List\n";
        return;
    }

    if (current == tail) // Current Equal Last Element
    {
        perv->next = nullptr; // Element Before Tail Pointer To Null Because It Became Last Element
        tail = perv;          // Move Tail To Last Element
    }
    else
    {
        perv->next = current->next; // Mean Element Deleted Not Equal Last Element & Make Pointer After perv Skip Element Deleted
    } // And Pinter To After Element
    delete current;
}

template <typename T>
void Linked_List<T>::PRINT_LINKED_LIST()
{
    if (this->IS_EMPTY()) // Check List Is Empty Or No
    {
        cout << "Linked List Is Empty\n"; // If Yes Print This
    }
    else // If No Print List
    {
        Node *current = head;      // Create Element To Move In List
        while (current != nullptr) // Until Arrive Last Element
        {
            cout << current->data << "\n"; // Print Element
            current = current->next;       // Increment loop
        }
    }
}

template <typename T>
int Linked_List<T>::GET_LENGTH()
{
    Node *current = head;      // Create Node To Move In List
    int count = 0;             // Create Counter To Get Final Length
    while (current != nullptr) // Break When Current Arrive Last Element
    {
        count++;                 // Increment Count Plus 1
        current = current->next; // Increment For This Loop
    }
    return count; // Return Final Length
}

template <typename T>
T Linked_List<T>::MIDDEL_ELEMENT()
{
    Node *slow = head; // Create Slow Pointer In Head To Move one Step
    Node *fast = head; // Create Fast Pointer In Head To Move Two Step

    while(fast != nullptr && slow->next != nullptr) {
        fast = fast->next->next;
        // fast iterator move two steps when fast arrive in last element is mean linked list is odd and fast will be nullptr list is even
        slow = slow->next;// and slow iterator is move one step when fast arrive in last element slow is in meddle element
    }

    return slow->data; // and return middle element
}

#endif

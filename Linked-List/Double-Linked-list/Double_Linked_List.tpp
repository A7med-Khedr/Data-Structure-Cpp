#ifndef _DOUBLE_LINKED_LIST_CPP
#define _DOUBLE_LINKED_LIST_CPP

#include "Double_Linked_List.h"

template <typename T>
bool Double_Linked_List<T>::IS_EMPTY()
{
    return head == nullptr; // This Line => head == nullptr ? True ( 1 ) : False ( 0 )
}

template <typename T>
void Double_Linked_List<T>::INSERT_NODE_AT_BEGINNING(T value)
{
    Node *New_Node = new Node(value); // Create New Node And Assign Value For Data
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

template <typename T>
void Double_Linked_List<T>::INSERT_NODE_AT_END(T value)
{                                                   
    Node *New_Node = new Node(value); // Create New Node And Assign Value For Data
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

template <typename T>
void Double_Linked_List<T>::INSERT_NODE_AT_POSITION(T value, int pos)
{ 
    if (pos < 0)
    { // If User Input Number Less 0 print This
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 0 || head == nullptr)
    {                                    // If We Need Add Element In First
        INSERT_NODE_AT_BEGINNING(value); // Call This Function And Get Value As A Parameter
        return;
    }

    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data In Class
    Node *current = head;                    // Create Current Pointer To Loop In Linked List
    int current_position = 0;                       // Use This To Check Current Pointer Not Exceeds Specific Position

    while (current->next != nullptr && current_position < pos - 1)
    {                            // Check Current Not Arrive Last Element And current_position Is Valid
        current = current->next; // Increment Loop
        current_position++;      // Increment current_position Plus 1 Each Loop Is True
    }

    if (current->next == nullptr && current_position < pos - 1)
    { // If Input By User Exceed Length For Double Linked List Print This
        cout << "Position: " << pos << " Exceeds The Size Of The Linked List\n";
        cout << "Size of Linked List Is: " << this->GET_LENGTH() << "\n";
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

template <typename T>
void Double_Linked_List<T>::REMOVE_NODE(T value)
{                        
    if (head == nullptr) // Check If List Is Empty Or No
    {
        return; // If yes Out Function
    }

    Node *current = head;     // Create Pointer To Iterate List
    Node *pervious = nullptr; // Create Pointer To Refer Before Current
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

template <typename T>
void Double_Linked_List<T>::PRINT_LINKED_LIST()
{
    if (this->IS_EMPTY()) // Check List Is Empty Or No
    {
        cout << "Linked List Is Empty\n"; // If Yes Print This
    }
    else // If No Print List
    {
        Node *current = head; // Create Element To Move In List
        while (current != nullptr)   // Until Arrive Last Element
        {
            cout << current->data << "\n"; // Print Element
            current = current->next;       // Increment loop
        }
    }
}

template <typename T>
int Double_Linked_List<T>::GET_LENGTH()
{
    Node *current = head; // Create Node To Move In List
    int count = 0;               // Create Counter To Get Final Length
    while (current != nullptr)   // Break When Current Arrive Last Element
    {
        count++;                 // Increment Count Plus 1
        current = current->next; // Increment For This Loop
    }
    return count; // Return Final Length
}

#endif

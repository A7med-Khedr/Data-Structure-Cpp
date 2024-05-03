#include <iostream>
#include <cstdlib> // To Use malloc Function
using namespace std;

template <class T>
class Linked_List
{
  class Node
  {
  public:
    T data;
    Node *next; // Pointer To Reference The Next Data In Linked List
    Node(T data)
    {
      this->data = data;    // To Assign Value In Function To Data In Node
      this->next = nullptr; // To Assign Next Data Equal null Always
    }
  };

private:                // Because Head And Tail Must Not Access By User
  Node *head = nullptr; // Head pointer To Reference Always In First Element In Linked List
  Node *tail = nullptr; // Tail Pointer To Reference Always In Last Element In Linked List

  bool isEmpty() // Check List Empty Or No We Need It In Print Function
  {
    return head == nullptr; // This Line => head == nullptr ? True ( 1 ) : False ( 0 )
  }

public:
  void Insert_Node_At_Beginning(T value)
  {                                   // Method To Add Element In First
    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data
    if (head == nullptr)              // Check Head Equal Null ? Mean Value Is First Element In List : There Is Many Element
    {
      head = New_Node; // Assign Head Pointer To Reference The Data
      tail = New_Node; // And Assign Tail Pointer To Reference The Data
      // Because The Data Is The Alone Element In Linked List
      return;
    }
    else
    {                        // Mean The Linked List Is Not Null
      New_Node->next = head; // Next Pointer To New Node Assign Head ( Because The Head Reference To First Element )
      head = New_Node;       // Move Head Pointer In The New Node Because Head Pointer Always Reference First Element
    }
  }

  // ===================================================

  void Insert_Node_At_End(T value)
  {                                   // Method To Add Element In End
    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data
    if (head == nullptr)              // Check Head Equal Null ? Mean Value Is First Element In List : There Is Many Element
    {
      head = New_Node; // Assign Head Pointer To Reference The Data
      tail = New_Node; // And Assign Tail Pointer To Reference The Data
      // Because The Data Is The Alone Element In Linked List
      return;
    }
    else
    {                        // Mean The Linked List Is Not Null
      tail->next = New_Node; // tail->next = Null In DeFault | Assign New Node To tail->next When Need Put Node In End
      tail = New_Node;       // Move Tail Pointer In The New Node Because Tail Pointer Always Reference Last Element
    }
  }

  // ===================================================

  void Insert_At_Position(T value, int pos)
  { // Function To Insert Node In Any Position In Linked List
    if (pos < 0)
    { // If User Input Number Less 0 print This
      cout << "Invalid Position\n";
    }

    if (pos == 0 || head == nullptr)
    {                                  // Check If You Need Add Element At Beginning Linked List
      Insert_Node_At_Beginning(value); // Call This Function And Get Value As A Parameter
      return;
    }

    Node *New_Node = new Node(value); // Create New Node To Store Element
    Node *current = head;             // Create Pointer To Loop In Linked List
    int current_position = 0;         // Use This To Check Current Pointer Not Exceeds Specific Position

    while (current->next != nullptr && current_position < pos - 1)
    {                          // Check Current Not Arrive Last Element And current_position Is Valid
      current = current->next; // Increment Loop
      current_position++;      // Increment current_position Plus 1 Each Loop Is True
    }

    if (current->next == nullptr && current_position < pos - 1)
    { // If Input By User Exceed Length For Linked List Print This
      cout << "Position: " << pos << " Exceeds The Size Of The Linked List\n";
      cout << "Size of Linked List Is: " << this->Get_Length() << "\n";
      delete New_Node; // Delete New Node To Free Memory
      return;
    }
    // If Valid Position
    New_Node->next = current->next; // Next Pointer To New Node Refer To Next To Current
    current->next = New_Node;       // Next Pointer To Current Refer To New Node

    if (New_Node->next == nullptr)
    {                  // Check If Insert Node At End
      tail = New_Node; // Update Tail To New Node
    }
  }

  // ===================================================

  void Remove_Node(T value) // Function To Remove Node
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
    }                             // And Pinter To After Element
    delete current;
  }

  // ===================================================

  void Print_List() // Method To Print Linked List
  {
    if (this->isEmpty()) // Check List Is Empty Or No
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

  // ===================================================

  int Get_Length() // Function To Get Length Of List
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

  // ===================================================
};

template <class D>
class Double_Linked_List
{
  class Double_Node
  {
  public:
    D data;            // Data Initial By User
    Double_Node *next; // Pointer To Reference Next Node
    Double_Node *prev; // Pointer To Reference Pervious Node

    Double_Node(D value)
    {                       // Constructor To Assign Value In Function  For Data In Double_Node
      this->data = value;   // Assign Value In Function For Data In Class
      this->next = nullptr; // Assign First Value Is nullptr
      this->prev = nullptr; // Assign First Value Is nullptr
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
  void Insert_Node_At_Beginning(D value) // Function To Add Data In First
  {
    Double_Node *New_Node = new Double_Node(value); // Create New Node And Assign Value For Data
    if (head == nullptr)                            // Check If List Empty Or No
    {                                               // If Yes
      head = New_Node;                              // Head Pointer Reference To New_Node
      tail = New_Node;                              // Tail Pointer Reference To New_Node
      return;
    }
    else // If There Many Element
    {
      head->prev = New_Node; // Pointer Before Head Refer New Node To Put It First
      New_Node->next = head; // Pointer To New Node Refer Head
      head = New_Node;       // Head Move New Node Because New Node Is First
    }
  }

  // ====================================

  void Insert_Node_At_End(D value)
  {                                                 // Function To Add Data In Last
    Double_Node *New_Node = new Double_Node(value); // Create New Node And Assign Value For Data
    if (this->head == nullptr)                      // Check If List Empty Or No
    {                                               // If Yes
      head = New_Node;                              // Head Pointer Reference To New_Node
      tail = New_Node;                              // Tail Pointer Reference To New_Node
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

  // ====================================

  void Remove_Node(D value)
  {                      // Function To Remove Node
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

  // ====================================

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

  // ====================================

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

int main()
{
  Linked_List<int> My_List;
  cout << "Start\n";

  My_List.Insert_Node_At_Beginning(3);
  My_List.Insert_Node_At_Beginning(2);
  My_List.Insert_Node_At_Beginning(1);
  My_List.Insert_Node_At_End(4);
  My_List.Insert_Node_At_End(8);

  My_List.Insert_At_Position(5, 4);
  My_List.Insert_At_Position(6, 5);
  My_List.Insert_At_Position(10, 6);

  My_List.Print_List();
  cout << "Length: " << My_List.Get_Length() << "\n";

  cout << "===================\n";

  My_List.Remove_Node(8);
  My_List.Remove_Node(1);
  My_List.Remove_Node(4);
  My_List.Remove_Node(5);

  My_List.Print_List();

  cout << "Length: " << My_List.Get_Length() << "\n";
  cout << "===================\n";

  // My_List.Print_List();
  cout << "===================\n";

  Double_Linked_List<int> New_List;

  New_List.Insert_Node_At_Beginning(3);
  New_List.Insert_Node_At_Beginning(2);
  New_List.Insert_Node_At_Beginning(1);
  New_List.Insert_Node_At_End(4);

  New_List.Print_List();
  cout << "Length: " << New_List.Get_Length() << "\n";
  cout << "===================\n";

  New_List.Remove_Node(1);
  New_List.Remove_Node(2);
  New_List.Remove_Node(3);
  New_List.Remove_Node(4);

  New_List.Print_List();
  cout << "Length: " << New_List.Get_Length() << "\n";

  cout << "End\n";
  return 0;
}

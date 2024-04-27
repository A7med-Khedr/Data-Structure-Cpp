#include <iostream>
#include <stdexcept> // Library In C++ Allow Me Print Massage As Error
// throw std::out_of_range("Stack Is Empty")
using namespace std;

template <class T>
class Queue
{ // Create Queue Class
public:
  class Node
  { // Create Node Class
  public:
    T data;     // Create Data Input From User
    Node *next; // And Create Next POinter Tp Refer Nullptr If User Not Change This
    Node(double value) : data(value), next(nullptr) {}
    // Constructor To Assign value To Data From User And Assign Next Nullptr
  };

private:
  Node *head = nullptr; // Head Pointer Always Reference In First Element In Queue
  Node *tail = nullptr; // Tail Pointer Always Reference In Last Element In Queue
  int count = 0;        // Attribute To Count Number Of Data In Queue

  bool IsEmpty()
  {                         // Function To Check Queue Is Empty Or No
    return head == nullptr; // Line => Head == Nullptr ? True : False
  }

public:
  void EnQueue(T value)
  {                                   // Function To Add Element In Last
    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data In Class
    if (tail == nullptr)
    {                  // If Queue Is Empty
      head = New_Node; // Assign head Pointer To New_Node And Tail Already Nullptr
    }
    else
    {                        // If There Many Element
      tail->next = New_Node; // Next Pointer Assign To New Node
    }
    tail = New_Node; // And Update tail Pointer To New Node Because Tail Refer Last Element
    count++;         // Increment Count Plus 1 To Get Final Length
  }

  T DeQueue()
  { // Function To Remove Element In First
    if (IsEmpty())
    {
      throw out_of_range("Queue Is Empty"); // Throw Massage Error ( Queue Is Empty )
    }
    else
    {
      T value = head->data; // Create Value With Any Data Type And Assign This In data Of Head
      head = head->next;    // And Update Head Pointer To Next Element
      if (head == nullptr)
      {                 // After Update Head If Refer Nullptr Mean Queue Became Empty
        tail = nullptr; // Assign tail Equal Nullptr Because Queue Became Empty
      }
      count--; // Decrement Count Minus 1 To Get Final length
      return value;
    }
  }

  void Print()
  { // Function To Print Element In Queue
    if (IsEmpty())
    {                             // Check If Queue Is Empty Or No
      cout << "Queue Is Empty\n"; // If Empty Print This
    }
    else
    {                       // If Not Empty
      Node *current = head; // Create Current Pointer To Move In Queue
      while (current != nullptr)
      {                                // Until Arrive Last Element
        cout << current->data << "\n"; // Print Element
        current = current->next;       // Increment loop
      }
    }
  }

  int GetLength()
  {               // Function To Return Length To Queue
    return count; // Return Final Count
  }
};

int main()
{

  Queue<int> My_Queue;

  My_Queue.EnQueue(4);
  My_Queue.EnQueue(5);
  My_Queue.EnQueue(7);
  My_Queue.EnQueue(9);

  My_Queue.DeQueue();
  My_Queue.DeQueue();
  My_Queue.DeQueue();

  My_Queue.Print();

  cout << My_Queue.GetLength();

  return 0;
}

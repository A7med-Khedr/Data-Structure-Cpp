#include <iostream>
#include <stdexcept> // Library In C++ Allow Me Print Massage As Error
                     //throw std::out_of_range("Stack Is Empty")
using namespace std;

template <typename T> // Template In C++ Allow Me Declare Any Data Type With T Parameter
class Stack           // Last In First Out ( LIFO )
{
public:
    class Node // Node Class To Create Node
    {
    public:
        T data;              // data Attribute I Can Call It With Any Data Type Because T Parameter
        Node *next;          // Pointer To Next Data In Stack
        Node(const T &value) // Constructor To Assign Value In Data And Create Next Pointer
        {
            this->data = value;   // Assign Value In Function To Data In Class
            this->next = nullptr; // Assign Next Pointer To nullptr Always If Not Redeclare It
                                  // Node(const T& data) : data(data), next(nullptr) {} // Faster Constructor
        }
    };

private:
    Node *top;    // Create Top Pointer To Refer In The First Element Always And Element In Top Refer Element Down
    int size = 0; // To Get Size Of Stack
public:
    Stack() : top(nullptr) {} // Constructor To Assign Top To nullptr If Stack Is Empty

    ~Stack() // Destructor
    {
        while (!isEmpty()) // Work Is User Delete Node ( Optional ) But
        {                  // For Each Element Popped From The Stack, Its Memory is Deallocated By The pop() function
            pop();
        }
    }

    void Push(const T &value) // Function To Push Element In End
    {
        Node *New_Node = new Node(value); // Create New Node And Assign Value To Data And Make nullptr
        New_Node->next = top;             // Pointer After New Node Assign To Top Because Top Refer To First Element
        top = New_Node;                   // And Update Top Pointer To New Node Because New Node Is First Element
        size++;                           // Increment Size By 1 When Push Element
    }

    // ===================================================

    Node pop() // To Remove First Element
    {
        if (isEmpty()) // If Stack Is Empty
        {
            throw std::out_of_range("Stack Is Empty"); // Throw Massage Error ( Stack Is Empty )
        }
        T data = top->data; // Assign Value To Data
        Node *temp = top;   // Make Node And Delete It
        top = top->next;    // Update Top Pointer To Next Element
        delete temp;        // To Delete Element
        size--;             // Decrement Size By 1 If pop Element
        return data;        // Why Return Data If Remove It? Here Data Delete In Stack
                            // But Return It Because Make Any Action To It If User Need Data In Another Place Or Stack
    }

    // ===================================================

    bool isEmpty() // Function To Check Stack Is Empty Or No
    {
        return top == nullptr; // This Line Equal => top == nullptr ? True : False ( Ternary Conditional )
    }

    // ===================================================

    void Display() const
    {                              // Function To Print ELement In Stack
        if (this->Get_Size() == 0) // Check Stack Is Empty Or No
        {
            cout << "Stack Is Empty\n"; // If Yes Print This
        }
        else
        {
            Node *current = top; // pointer To Iterate Stack And Print Element
            cout << "Stack Element: \n";
            while (current != nullptr)
            {                                  // Break If Current Arrive Last Element
                cout << current->data << "\n"; // Print Data
                current = current->next;       // Increment Current To while Loop
            }
        }
    }

    // ===================================================

    void Print_Top()
    {                  // Function To Print Top Element
        if (isEmpty()) // Check Stack Is Empty Or No
        {
            cout << "Stack Is Empty\n"; // IF Is Empty Print This
        }
        else
        {
            cout << "Top Element: " << top->data << "\n"; // If No Print Top
        }
    }

    // ===================================================

    int Get_Size() const
    {                // Function To Get Length
        return size; // After Increment Or Decrement In Push Or pop
    }

    // ===================================================
};

int main()
{
    Stack<int> My_Stack;
    My_Stack.Push(1);
    My_Stack.Push(2);
    My_Stack.Push(3);
    My_Stack.Push(4);

    My_Stack.pop();
    My_Stack.pop();
    My_Stack.pop();

    My_Stack.Display();

    My_Stack.Print_Top();

    cout << "Stack Size: " << My_Stack.Get_Size() << "\n";

    return 0;
}
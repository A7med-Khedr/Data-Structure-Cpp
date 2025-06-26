#include <iostream>
#include "tree.h"
using namespace std;


int main() {
    Tree<int> myTree;

    myTree.Insert(10);
    myTree.Insert(5);
    myTree.Insert(15);
    myTree.Insert(2);
    myTree.Insert(8);
    myTree.Insert(12);
    myTree.Insert(20);

    cout << "Search 8: " << (myTree.searchNode(8) ? "Found" : "Not Found") << endl;
    cout << "Search 13: " << (myTree.searchNode(13) ? "Found" : "Not Found") << endl;

    return 0;
}

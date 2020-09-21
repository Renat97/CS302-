/// CS 302 Project 7
/// Created by Renat Norderhaug on 5/7/18.
///

#include <iostream>
#include "RBTree.h"
#include <ctime>

using namespace std;


int main() {
    RBTree obj;

/// insert 1000 unique objects of values 1- 10000

    //// TESTING to store the random Unique numbers ///

    const int COUNT = 1000; ///amount of unique nodes that need to be generated for Red black tree
    const int MAX_VALUE = 10000; ///maximum value that can be generated

    srand((unsigned)time(NULL)); /// randomizing numbers

///generate random numbers:

    for (int i=0;i<COUNT;i++)
    {
        int n=rand()%MAX_VALUE;
        cout << " inserting " << n << endl;
        obj.insertValue(n);
    }

    cout << COUNT << " nodes Inserted." << endl;

    cout << "Tree height: " << obj.getHeight() << endl;

    cout << "Tree sum: " <<obj.getSum() << endl;

    obj.deleteTree();

    cout << "Tree was successfully deleted." << endl;

    return 0;
}

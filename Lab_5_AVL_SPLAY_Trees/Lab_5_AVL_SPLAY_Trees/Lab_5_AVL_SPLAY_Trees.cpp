//
//  
// Lab_4 AVL-SPLAY Tree
// Sample implementation of AVL & Splay tree is provided
// 
// Assignmnet:
// Run the supplied code in your visual studio IDE
// Modify the startup program to perform random operations on AVL & Splay Trees (insert the same generated values into both trees), i.e.:
// 1- Count the total number of rotations performed over the sequence. (you can use any random number generation method in C++ used in previus labs)
// 2- How does the running time compare to SPLAY tree?
//
// For Question 2, you can keep track of how many nodes were visited in order to search for a specific key.
// So the analysis will be based on Number of rotations in Splay Tree Vs. How many nodes will be visited in AVL
// Inserting/searching operations will be in the range of 10,000,000 and above, run time may take up to 20 seconds
//
// 3- Create a report highlighting the above research topic featurieng your run data.
//
//
// You might be able to prove that AVL will be in the range of (log(n)), where Splay will be less, based on the timing analysis.
//


#include <iostream>
#include "AvlTree.h"
#include "SplayTree.h"


using namespace std;

// Startup program
int main()
{
    AvlTree<int>   AVL_Tree;
    SplayTree<int> Splay_Tree;

    int arr[10000] = {};

    cout << "AVL Tree Checking... " << endl;

    for (int i = 0; i < 10000; i++) {
        int v1 = rand() % 10000;
        AVL_Tree.insert(v1);
        Splay_Tree.insert(v1);
        arr[i] = v1;
    }
    //remove
    for (int i = 0; i < 5; i++) {
        int v2 = rand() % 10;
        AVL_Tree.remove(arr[v2]);
        Splay_Tree.remove(arr[v2]);


    }

    // Only print if elements are few
    cout << endl << "AVL Tree Elemenets:" << endl;

    AVL_Tree.printTree();

    cout << "Finsh: ";
    cout << endl;
    cout << "Total Rotation: " << AVL_Tree.r << endl;
    cout << "is 9 there?(0 for false and 1 for true) " << bool(AVL_Tree.contains(9))<<endl;

    cout << "Max:" << AVL_Tree.findMax() << endl;
    cout << "Min:" << AVL_Tree.findMin() << endl;

    cout << "End of AVL test..." << endl;





    //////////////////////////////

    // Only print if elements are few
    cout << endl << "Splay Tree Elemenets:" << endl;
    Splay_Tree.printTree();
    cout << "Finsh";
    cout << endl;
    cout << "Total Rotation" << Splay_Tree.r << endl;
    cout <<"is 5 there?(0 for false and 1 for true) "<< bool(Splay_Tree.contains(5)) << endl;
    

    cout << "Max: " << Splay_Tree.findMax() << endl;
    cout << "Min: " << Splay_Tree.findMin() << endl;


    

    cout << "End of Splay test..." << endl;
    if (AVL_Tree.r > Splay_Tree.r) { cout << "Splay Tree is better in this situation."<<endl; }
    else { cout << "Avl tree is better in this situation." << endl; }




    return 0;
}

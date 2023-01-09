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
   



    int NUMS = 100;
    const int GAP = 7; // 37;
    int i;

    cout << "AVL Tree Checking... " << endl;

    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
    {
        cout << i << " ";
        AVL_Tree.insert(i);
    }


    for (i = 1; i < NUMS; i += 2)
        AVL_Tree.remove(i);

    // Only print if elements are few
    cout << endl << "AVL Tree Elemenets:" << endl;
    AVL_Tree.printTree();



    if (NUMS < 40)
        AVL_Tree.printTree();
    if (AVL_Tree.findMin() != 2 || AVL_Tree.findMax() != NUMS - 2)
        cout << "FindMin or FindMax error!" << endl;

    for (i = 2; i < NUMS; i += 2)
        if (!AVL_Tree.contains(i))
            cout << "Find error1!" << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (AVL_Tree.contains(i))
            cout << "Find error2!" << endl;
    }


    cout << "End of AVL test..." << endl;

  
    
    
    
    //////////////////////////////
  
    cout << endl << "Splay Tree: Checking... " << endl;

    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
    {
        cout << i << " ";
        Splay_Tree.insert(i);
    }


    for (i = 1; i < NUMS; i += 2)
        Splay_Tree.remove(i);


    // Only print if elements are few
    cout << endl << "Splay Tree Elemenets:" << endl;
    Splay_Tree.printTree();


    if (NUMS < 40)
        Splay_Tree.printTree();
    if (Splay_Tree.findMin() != 2 || Splay_Tree.findMax() != NUMS - 2)
        cout << "FindMin or FindMax error!" << endl;

    for (i = 2; i < NUMS; i += 2)
        if (!Splay_Tree.contains(i))
            cout << "Find error1!" << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (Splay_Tree.contains(i))
            cout << "Find error2!" << endl;
    }

    cout << "End of Splay test..." << endl;





    return 0;
}

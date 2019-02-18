#### CS 240 - Spring 2018
# Lab 5 - Binary Search Tree
## Due Date: 5:00 p.m., March 21st, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab5.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
```shell
    TEST #1: Create an empty tree
    ========================PASS========================
    TEST #2: Insert values into the Tree
    ========================PASS========================
    TEST #3: Cannot insert duplicate values into the Tree
    ========================PASS========================
    TEST #4: Insert 1000 Values into the Tree
    ========================PASS========================
    TEST #5: Find values in the tree
    ========================PASS========================
    TEST #6: Find doesn't segfault on empty tree
    ========================PASS========================
    TEST #7: Cannot remove node that is not in the tree
     [1]  [2]  [3]  [5]  [6]  [7]  [8]  [9]  [10]  [11]  [12]  [13]
    ========================PASS========================
    TEST #8: Remove a leaf node
     [2]  [3]  [5]  [6]  [7]  [8]  [9]  [10]  [11]  [12]  [13]
    ========================PASS========================
    TEST #9: Remove single branch using the Short Circuit algorithm
     [2]  [3]  [5]  [6]  [8]  [9]  [10]  [11]  [12]  [13]
    ========================PASS========================
    Test #10: Remove two branch node promoting a leaf node
     [2]  [3]  [5]  [6]  [8]  [9]  [11]  [12]  [13]
    ========================PASS========================
    TEST #11: Remove two branch node promoting a 1 branch node using Short Circuit
     [2]  [3]  [5]  [6]  [8]  [9]  [12]  [13]
    ========================PASS========================
    TEST #12: Remove root with two branches
     [2]  [3]  [6]  [8]  [9]  [12]  [13]
    ========================PASS========================
    TEST #13: Remove root with one branch
     [8]  [9]  [12]  [13]
    ========================PASS========================
    TEST #14: Remove root as leaf
    ========================PASS========================
    TEST #15: Deep copy for a tree of 100 random values
    ========================PASS========================
    TEST #16: Test deletion and Destructor
    ========================PASS========================
    TEST #17: Test Balancing Tree
    ========================PASS========================
    All Tests Passed.
    Don\'t forget to run with Valgrind and submit to Blackboard!
```
### Grading Rubric
**_TOTAL: 25 points_**
* **Part A: 12 points**
    * Header and Implementation split into .h and .cpp (1 point)
    * Node is an internal class (2 points)
    * Test #1 - Create an empty tree (1 point)
    * Test #2 - Insert values into the Tree (2 points)
    * Test #3 - Cannot insert duplicate values into the Tree (1 point)
    * Test #4 - Insert 1000 Values into the Tree (2 points)
    * Test #5 - Find values in the tree (2 points)
    * Test #6 - Find doesn't segfault on empty tree (1 point)
* **Part B: 13 points**
    * Test #7 - Cannot remove node that is not in the tree (1 point)
    * Test #8 - Remove a leaf node (1 point)
    * Test #9 - Remove single branch using the Short Circuit algorithm (2 points)
    * Test #10 - Remove two branch node promoting a leaf node (1 point)
    * Test #11 - Remove two branch node promoting a 1 branch node using Short Circuit (1 point)
    * Test #12 - Remove root with two branches (1 point)
    * Test #13 - Remove root with one branch (1 point)
    * Test #14 - Remove root as leaf (1 point)
    * Test #15 - Deep copy for a tree of 100 random values (2 points)
    * Test #16 - Test deletion and Destructor (2 points)
* **Part C - EXTRA CREDIT: 5 points**
    * Test #17 - Test Balancing Tree (5 points)
* **Part D:**
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure, makefile, and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

The goal of Lab 5 is to build a Binary Search Tree, work with STL containers, and develop tree based algorithms such as traversal and balancing.

#### (Parts A must be completed in lab)

## Part A: Creating a BST Class

Write your own simple Binary Search Tree (BST) C++ class that includes the insert(), find(). We’ll save remove for later in the lab. Your BST must have the following public interface:
* BSTree()
* bool empty()
    * true if the tree is empty
    * false if it is not
* bool insert(int val)
    * Returns true if the value was inserted
    * false if the value was already in the tree
        * INSERT ALGORITHM: To insert a new node, start at the root and move down left or right, following the appropriate pointers, until you get to the appropriate place at the bottom. Then create a new BSTree::Node and set the appropriate pointer to the new node.
* bool find(int val)
    * true if the value is in the tree
    * false if the value is not in the tree
        * FIND ALGORITHM: Find works the same as insert, except you do not create a new node. Instead you return a boolean value when you find the value or a null branch.
* Use one class for the entire BST, which contains a single pointer to a Node, which is the root of the tree.
You'll also have a nested helper C++ class, Node, which contains an integer data member to store the data item, and three pointers to other Nodes, one for the left subtree, one for the right subtree, and one for the parent.
* You are going to create the Node class as an internal class to the Tree. This MUST be the first thing in your BSTree class. You declare it just like a normal class, except it is kept as a private data member:

```
class BSTree{
      private:
            class Node{
                    public:
                            …
```

* You can only access the node class within your BSTree class if it is private.
    * More info about [nested classes](http://www.oopweb.com/CPP/Documents/CPPAnnotations/Volume/cplusplus16.html)
* You must complete your header file and implementations of your insert and find in lab. Make sure everything compiles before moving on.

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Implementing Remove
Now we are going to extend the BST with remove and traversal. Your BST must have the following public interface:
* __BSTree()__
* __BSTree(const BSTree &old_tree)__
    * Performs a deep copy of a BSTree object using preorder traversal
* __~BSTree()__
    * Removes all allocated memory in a BSTree using postorder traversal
* __bool empty()__
    * true if the tree is empty
    * false if it is not
* __bool insert(int val)__
    * Returns true if the value was inserted
    * false if the value was already in the tree
* __bool find(int val)__
    * true if the value is in the tree
    * false if the value is not in the tree
* __void sortedArray(vector<int> &list)__
    * Takes a vector reference, and fills the vector with the tree values in sorted order
* __bool remove(int num)__
    * Takes a value and removes that value from the tree if found
    * Returns true is the value was removed, false if the value is not in the tree.

You will need to implement the following algorithms. I recommend implementing them as separate private methods that you call in each of the associated public methods.

* InOrder Traversal for sortedArray
* PostOrder Traversal for tree deletion
* PreOrder Traversal for tree deep copy

## Part C - EXTRA CREDIT: Balancing Your Tree

There are many different ways to balance a binary tree. The simplest method (but not necessarily the most efficient) is to sort the tree into a sorted list, then delete all values from the tree and remake the tree by recursively dividing the array in half, and inserting the center value back into the tree. Here is the basic algorithm:
1) Get the middle of the array and make it root.
2) Recursively do same for left half and right half.
      * Get the middle of left half and make it left child of the root
          created in step 1.
      * Get the middle of right half and make it right child of the
          root created in step 1.

etc...

For part C you must have a method that balances your tree object. You may use another algorithm if you choose. The only requirement for your balance method is that it must have this interface:
```c++
    void balance();
```

In order to test your tree, you will need to have an additional method, height, which returns the height of your tree. Add the following method to your BSTree class:

```c++
    int BSTree::height(){
        return findHeight(this->root);
    }
    int BSTree::findHeight(Node* node){
       // base case tree is empty
       if(node == NULL)
           return 0;

       // If tree is not empty then height = 1 + max of left height and right heights
        lh = height(node->left);
        rh = height(node->right)
        max = (lh >= rh) ? lh : rh;
        return 1 + max;
    }
```

You may have to make some modifications to work with your tree, but you should not change the basic algorithm.

__You must add a blank file to your repo called EXTRA in order for the TA's to give you credit for the extra credit__
__Use the command `touch EXTRA` to create this file__


## Part D: Code Organization and Submission
* Required code organization:
    * lab5.cpp (driver code - You must include this file in your submission)
    * BSTree.h/.cpp
    * makefile
        * executable should be called: lab5
        * You should have all the same labels in your makefile from the previous lab with minor updates
    * EXTRA (optional)

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

*These commands all presume that your current working directory is within the directory tracked by `git`.*

```git
git add Anthill.h
git add Anthill.cpp
git commit -a -m "first commit"
git push
```
Lastly we are going to make our final commit. You will need to do this when your submission is ready for grading.

```shell
git commit --allow-empty -m "final commit"
git push
```

:warning: Remember, you __MUST__ make a submission with the comment "final commit" before the deadline to be considered on time.

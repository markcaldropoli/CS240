#### CS 240 - Spring 2018
# Lab 4 - Templates
## Due Date: 5:00 p.m., March 2nd, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab4.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
        ```shell
        TEST #1: Test create a integer List
        ========================PASS========================
        TEST #2: Test create a double List
        ========================PASS========================
        TEST #3: Test delete elements from Linked List
        ========================PASS========================
        TEST #4: Test add 1 element to a Queue
        ========================PASS========================
        TEST #5: Test create a Queue
        ========================PASS========================
        TEST #6: Test Queue Order
        ========================PASS========================
        TEST #7: Test Queue Interface
        ========================PASS========================
        Don\'t forget to run with Valgrind and commit to Github!
        ```

### Grading Rubric
**_TOTAL: 20 points_**
* **Part A:**
    * TEST #1: Test create a integer List (3 points)
    * TEST #2: Test create a double List (3 points)
    * TEST #3: Test delete elements from Linked List (3 points)
* **Part B:**
    * TEST #4: Test add 1 element to a Queue (2 points)
    * TEST #5: Test create a Queue (3 points)
    * TEST #6: Test Queue Order (3 points)
    * TEST #7: Test Queue interface (3 points)
* **Part C:**
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure, makefile, and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

The goal of Lab 4 is to get you to Templatize your code, and use your expanding library for another ADT. You are going to expand and refine your existing library by templatizing your Linked List using C++ templates. Once you have successfully templated your code, you will use your fancy new template list library to implement a Queue data structure.

:bulb: You do not have to keep your LinkList the same as the project. You can start fresh if you like.

#### (Parts A must be completed in lab)

## Part A: Creating a Template Class

As you are templatizing your Linked List, be sure to remember the following:
* All of your code must be moved into the header file. You will need to eliminate the .cpp file completely.
* Your linked list will also need the following public interface:
   * LinkedList()
   * LinkedList(const LinkedList<type> & sll)
   * void insert(<type> data);
      * inserts a copy of the data into the list
   * <type>& read();
      * returns a reference to the next item in the list and advances an internal iterator to the next element
   * bool empty();
      * returns true the the list is empty
   * bool remove(<type> &data);
      * removes the comparable value (operator==) from the list
        * Dont worry if there are multiple items of the same value. Juts remove the first one you come across.
   * You may add any additional methods you require. This means you can use your existing methods to implement the above interface if you want to.
* :bulb: Every instance of ‘Ant’ from your previous code needs to become a type variable, and no specific calls to Ant methods should remain.
* Here is a resource that gives a brief overview of templates if you need a syntax reminder
   * https://www.tutorialspoint.com/cplusplus/cpp_templates.htm

## Part B: Using your Linked List Library for a Queue

Once you have completed your templated linked list, you will use it to create Queue template data structure. Your Queue should be in separate file (Queue.h), and should use your Linked List as an internal data structure. This means you need to have the following methods:
* enqueue(<type> data)
   * Adds a data object onto the queue and returns a boolean if successful
* dequeue()
   * removes a data object from the queue and returns it
* peek()
   * returns a copy (not a reference) of the data object but does not remove it from the list
* empty()
   * returns a boolean, true if the queue is empty, false if it contains 1 or more elements
* clear()
   * deletes all items from the queue
HINT: It can make things much easier is you make Queue a friend class of your LinkedList, but don’t forget that Queue is a template.

## Part C : Code Organization and Submission
* Required code organization:
    * lab4.cpp (driver code - You must include this file in your submission)
    * LinkedList.h
    * Queue.h
    * makefile
        * executable should be called: lab4
        * You should have all the same labels in your makefile from the previous assignments

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

*These commands all presume that your current working directory is within the directory tracked by `git`.*

```git
git add LinkedList.h
git commit -a -m "first commit"
git push
```
Lastly we are going to make our final commit. You will need to do this when your submission is ready for grading.

```shell
git commit --allow-empty -m "final commit"
git push
```

:warning: Remember, you __MUST__ make a submission with the comment "final commit" before the deadline to be considered on time.

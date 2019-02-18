#### CS 240 - Spring 2018
# Lab 6 - More Templates and STL
## Due Date: 5:00 p.m., March 28th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab6.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
```shell
    TEST #1: Card does not allow invalid values
    ========================PASS========================
    TEST #2: Overloaded equal operator
    ========================PASS========================
    TEST #3: Uses STL deque
    ========================PASS========================
    TEST #4: Create Deck
    ========================PASS========================
    TEST #5: Shuffle
    ========================PASS========================
    All Tests Passed.
    Don\'t forget to run with Valgrind and commit to Github!
```

### Grading Rubric
**_TOTAL: 15 points_**
* **Part A: 10 points**
    * Test #1  [5 pts]
        * Card class does not have a default constructor, sets invalid values to default
        * Card value and suit are private variables
        * Card class only has getters for value and suit
    * Test #2  [3 pts]
        * Card class has overloaded == operator
    * Test #3  [3 pts]
        * Deck uses STL deque as the internal data structure [3 pts]
    * Test #4  [6 pts]
        * Deck class initializes deck of 52 cards
        * Creates unique cards
* **Part B: 5 points**
    * Test #5  [5 pts]
        * Shuffles the deck to produce a random order
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

The goal of Lab 6 is to get more familiar with the STL and building data structures.

#### (Parts A must be completed in lab)

## Part A: Creating a Deck of Cards

You are going to create a Deck of Cards that uses your Queue. The following classes must be developed:

### Card Class

The Card class must have the following attributes and behaviors:
* The instance variables of a card are value and suit. Both must be private instance variables.
    * You should only have a value constructor. No default constructor.
        * The constructor should take suit, then value
            * Card(int suit, int value)
                * The value of the Card that returns the numerical value of the card ranges from 2-14
                    * Ace will be considered high or low; however, it is helpful to set its default value to high.
                * the suit of the card ranges from 1 - 4
            * If either of the given values are out of range, set the Card to the default, suit: 1, value: 2
* You should have the following public interface:
    * int getValue();
    * int getSuit();
    * bool operator==(const Card &other)
* :bulb: Other operations may be added to this class as determined by your design

### Deck Class

Once your Card class is working, you are going to create a Deck for the cards. The constructor for the Deck class should create 52 cards __on the heap__ (2-14 for each suit), and store them internally in the STL [deque](http://www.cplusplus.com/reference/deque/deque/) container.
* Your Deck class should have the following methods:
    * Deck()
    * Card draw()
        * Returns and removes the top Card object from the Deck
    * bool empty()
        * returns true if the deck is empty, otherwise false
    * std::deque<Card \*> & getInternal()
       * returns a reference internal deque

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Shuffle
Add a method to your Deck class:
* void shuffle();
    * The shuffle method should (*surprise*) shuffle your deck. You must only use your deque methods to do this.
* You can use an additional methods or anything else you find useful in your algorithm, as long as you are not violating encapsulation principles (i.e. changing the value of a card instead of moving the objects around).

## Part C: Code Organization and Submission
* Required code organization:
    * lab6.cpp (driver code - You must include the provided file in your submission)
    * Deck.cpp/.h
    * Card.cpp/.h
    * makefile
        * executable should be called: lab6
        * You should have all the same labels in your makefile from the previous lab with minor updates

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

*These commands all presume that your current working directory is within the directory tracked by `git`.*

```git
git add Deck.h
git add Card.cpp
git commit -a -m "first commit"
git push
```
Lastly we are going to make our final commit. You will need to do this when your submission is ready for grading.

```shell
git commit --allow-empty -m "final commit"
git push
```

:warning: Remember, you __MUST__ make a submission with the comment "final commit" before the deadline to be considered on time.

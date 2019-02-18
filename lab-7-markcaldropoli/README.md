#### CS 240 - Spring 2018
# Lab 7 - Hash Tables
## Due Date: 5:00 p.m., April 25th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab7.cpp
    * password.txt
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
```shell
    TEST #1: Create a hash of the correct size
    ========================PASS========================
    TEST #2: Insert values into the Hash
    ========   Hash Table   ========
    Index:0		Key:		Value:
    Index:1		Key:sam		Value:captain.america
    Index:2		Key:		Value:
    Index:3		Key:		Value:
    Index:4		Key:peter		Value:spiderman
    Index:5		Key:jane		Value:thor
    Index:6		Key:vision		Value:vision
    Index:7		Key:natasha		Value:blackwidow
    Index:8		Key:clint		Value:hawkeye
    Index:9		Key:logan		Value:wolverine
    ========================PASS========================
    TEST #3: Verify invalid password doesn't work
    ========================PASS========================
    TEST #4: Verify valid passwords are retrievable
    ========   Hash Table   ========
    Index:0		Key:		Value:
    Index:1		Key:sam		Value:captain.america
    Index:2		Key:		Value:
    Index:3		Key:		Value:
    Index:4		Key:peter		Value:spiderman
    Index:5		Key:jane		Value:thor
    Index:6		Key:vision		Value:vision
    Index:7		Key:natasha		Value:blackwidow
    Index:8		Key:clint		Value:hawkeye
    Index:9		Key:logan		Value:wolverine
    ========================PASS========================
    TEST #5: Remove entries from the hash
    ========================PASS========================
    All Tests Passed.
    Don\'t forget to run with Valgrind and commit to Github!
```

### Grading Rubric
**_TOTAL: 20 points_**
* **Part A: 15 points**
   * Hash class doesn’t use STL containers other than vector and pair (2 points)
   * Test 1 - create empty hash (1 point)
   * Test 2 - insert into a hash (5 points)
      * must use open addressing to address collisions
   * Test 3 - invalid password is not retrieved (2 points)
   * Test 4 - verify passwords are retrievable (5 points)
* **Part B: 5 points**
    * Test 5 - entries are removeable (5 points)
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

The goal of Lab 7 is to implement a hash table for retrieving passwords. You must use open addressing for collision resolution.

#### (Parts A must be completed in lab)

## Part A: Hash Table

For Part A you are going to implement a Hash class that will store a key string (username) and value string (password) and uses open addressing for collision resolution. Open addressing sacrifices insertion and lookup performance to save memory by placing the data in the next open space when there is a collision:

### Hash Class

* class Hash
   * Public Methods
      * Hash(unsigned int size)
         * Should initialize an array to some static size. You can use a vector for this, but it should still have a static size (meaning you will need to initialize the vector to some start size).
      * bool insert(string key, string value)
         * returns false is the hash is full
      * bool remove(string key)
         * removes the entry from the hash
         * returns false if the key was not found
      * string find(string key)
         * returns the correct value based on the key parameter
         * If the key is not found, returns an empty string
      * bool empty()
         * returns true of the hash is empty
      * int size()
         * returns to max size of the hash (not the current number of items)
      * void printHash()
         * prints out the index, key, and value of each element in the hash
      * int hasher(string key)
         * hash function that determines an index based on the key parameter
         * You can develop whatever hash function you want, but should try to limit collisions

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Password retrieval
Your hash should correctly store and retrieve passwords along with the key. Some rules your hash must follow are:
1. You must use open addressing for collision resolution
2. You may use a vector as your internal collection, and a pair as your storage object, but you may not use any other STL collections.
3. Your hash table must not change size. Empty ‘slots’ are represented with empty strings.

## Part C: Code Organization and Submission
* Required code organization:
    * lab7.cpp  (driver code - You must include this file in your submission)
    * password.txt - (sample text file - You must include this file in your submission)
    * Hash.h/.cpp
    * makefile
        * executable should be called: lab7
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

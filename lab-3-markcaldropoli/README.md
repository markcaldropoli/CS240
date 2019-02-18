#### CS 240 - Spring 2018
# Lab 3 - Creating Larger Programs
## Due Date: 5:00 p.m., February 7th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab3.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
        ```shell
        ./lab3
        TEST #1: Test Ant Hill Creation with 0 ants
        ========================PASS========================
        TEST #2: Test Add 1 Ant         ========================PASS========================
        TEST #3: Add Many Ants
        ========================PASS========================
        TEST #4: Delete Ants
        ========================PASS========================
        TEST #5: Move Ants Still Works
        ========================PASS========================
        TEST #6: Print Hill Information and Free Memory
        =================================        
        This hill currently has 480 ants:
        Ant #10 [22,5]
        Ant #11 [0,-5]
        …
        Ant #498 [8,12]
        Ant #499 [3,14]
        ========================PASS========================
        TEST #7: Fighting Ants
        Ant #0 wins with 2 experience
        Ant #0 wins the fight!
        ...
        Ant #13 wins the fight!
        Ant #13 wins with 20 experience
        Ant #13 wins the fight!

        ========================PASS========================

        All Tests Passed.
        Don’t forget to run with Valgrind and submit to Blackboard!
        ```

### Grading Rubric
**_TOTAL: 20 points_**
* **Part A: 2 points**
    * Has separate Ant and AntHill implementation and header files [2 points]
* **Part B: 18 points**
    * Passes test #1 [1 point]
    * Passes test #2 [2 points]
        * Must allocate memory for ants with ‘new’
    * Passes test #3 [3 points]
        * Must allocate memory for ants with new
    * Passes test #4 [3 points]
        * Must deallocate memory for ants with delete
    * Passes test #5 [1 point]
    * Passes test #5 [2 points]
    * Passes test #6 [3 points]
    * Passes test #7 [3 points]
        * It is possible for either Ant to win
        * The Ant’s experience is a factor
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

The goal of Lab 3 is to extend your previous lab by refactoring your previous code and adding a few new features. In particular: you will move most of your memory usage to the heap rather than the stack, add the ability to randomly delete an ant from the hill, enable a battle system, and further break your code out into separate files.

#### (Parts A must be completed in lab)

## Part A: Refactoring the Ant Hill Program

Refactor your C++ program to take advantage of dynamic memory (the heap). You should make the following changes to your AntHill and Ant classes:

Break your AntHill and Ant classes into two different files. This means you will need to alter your makefile to compile AntHill.cpp and Ant.cpp into separate object files.

### Ant
The Ant class will now only need one constructor that takes an ID as a value. You should still initialize x and y coordinates to (0,0). Your ant class should already have the following public interface:
* public methods:
    * Ant(int);
        * A value constructor that sets the Ant’s id to a unique value and its x,y coordinates to 0
    * void move();
        * No change from the previous lab

Alter the 3 getter methods below to be inline methods. Recall from class that an inline method is defined within the class, but should be limited to very short methods such as getters and setters. This means that in your Ant.cpp should only have the value constructor and the move method after these changes.

* int getID();
* int getX();
* int getY();

Next, you must add an additional instance variable to the Ant object. The additional variable will function as experience points for the Ant, and must have some initial starting value. You will also need to implement a method in the Ant class which allows two ants to fight one another. The winner of the fight gains all the loser’s experience. The algorithm for the fight is up to you, but there are two rules you must follow:
* The algorithm should factor in the Ant’s experience for its chances of winning
* No matter what the experience level of both ants, it should be possible for either Ant to win (even if unlikely)

The method interface should be as follows:
* Ant * fight(Ant \*);
    * takes another ant as an opponent
    * uses some internal experience mechanism **and** randomness to determine the winner
    * returns a pointer to the __losing__ ant

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Container Classes

### AntHill
_Please read the description below describing how to refactor and add to your AntHIll class. I will only describe the changes that should be made to your class. Anything not mentioned does not change._
* private:
   * int max_ants;
      * The max_ants variable is no longer needed and should be removed.
   * Ant ** ants;
      * You array of ants should become an array of Ant pointers. This means you will need to declare it as a double pointer, and initialize it to NULL in the constructor.
* public:
   * AntHill(int);
      * The constructor no longer needs an initializing value. It should set the current number of ants to 0 and the ants array pointer to NULL.
   * ~AntHill()
      * You must add a destructor to deallocate any remaining ants when the AntHill is deleted.
   * int addAnt();
      * The method to add an ant should now return the ID of the newly created Ant. The ant must be created with new (on the heap), and the resulting pointer stored in the Ant array.
      * This means that each time you add an Ant to the AntHill, you will have to:
         * allocate a new array of size 1 + the current number of Ants
         * copy all the pointers over to the new array
         * Create a new Ant object
         * Put the resulting Ant object pointer in the new array
         * update the current number of Ants
         * free the old array
         * Point the ant array to the new array
   * bool removeAnt(int)
      * Takes an Ant’s ID as a parameter, and removes an Ant from the AntHill, completely freeing the Ant’s memory. You must return true upon successful deletion and false on failure.
      * You must also shrink the size of the Ant array storing the AntHill’s Ants. This means you will have to:
         * allocate a new array of size 1 - the current number of Ants
         * copy all the pointers over to the new array except the pointer with the ID that matches the Ant to be deleted.
         * delete the Ant object with the matching ID
         * update the current number of Ants
         * free the old array
         * Point the ant array to the new array
   * Ant * getAnt(int)
      * Takes an Ant’s ID (not index as before), and returns a pointer to the ant. If the ant is not found, it returns NULL.
   * void move();
      * Although the move method does not change much, you will have to alter it to use pointers.
   * bool changeMax(int)
      * _This method is no longer needed and may be removed._
   * void printHillInfo()
      * Although the move method does not change much, you will have to alter it to use pointers.
   * int getCurrentNumAnts()
      * Alter this method to make it an inline method.

## Part C : Code Organization and Submission
* Required code organization:
    * lab3.cpp (driver code - You must include this file in your submission)
    * AntHill.h/.cpp
    * Ant.h/.cpp
    * makefile
        * executable should be called: lab3
        * You should have all the same labels in your makefile from the previous lab with minor updates

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

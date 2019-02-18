#### CS 240 - Spring 2018
# Lab 2 - Standard I/O, Separate Compilation, and Pass By Reference
## Due Date: 5:00 p.m., January 31st, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab2.cpp
    * Anthill.h
    * Anthill.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
        ```shell
        ./lab2
        TEST #1: Test Ant Hill Creation with 0 ants
        ========================PASS========================
        TEST #2: Test Change Max
        ========================PASS========================
        TEST #3: Add Ants
        ========================PASS========================
        TEST #4: Move Ants
        ========================PASS========================
        TEST #5: Print Hill Information
        Ant #0 [-1,3]
        Ant #1 [1,-1]
        Ant #2 [-1,1]
        Ant #3 [-1,3]
        Ant #4 [-2,1]
        ========================PASS========================
        All Tests Passed.
        Don’t forget to run with Valgrind and submit to Blackboard!
        ```

### Grading Rubric
**_TOTAL: 15 points_**
* **Part A: 2 points**
    * Has separate Ant and AntHill classes [2 points]
* **Part B: 13 points**
    * Passes test #1 [1 point]
    * Passes test #2 [2 points]
    * Passes test #3 [2 points]
    * Passes test #4 [2 points]
    * Passes test #5 [1 point]
    * Makefile contains an 'all' target that _only_ compiles the code [1 point]
    * Makefile contains an 'run' target that executes and only compiles if necessary [1 point]
    * Makefile contains an 'checkmem' target that executes with valgrind [1 point]
    * Makefile contains an 'clean' target that removes object files and the executable [1 point]
    * Makefile contains variables as described [1 point]
* **Part C:**
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk)
        * such as containing global variables [-3 points]

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

The goal of Lab 2 is to familiarize you with the few basic C++ features and aspects that we have discussed in the first weeks of class. In particular, you will implement multiple classes with various methods; you will use iostream to produce formatted output; you will do just a bit more separate compilation by building two separate object (i.e. _.o_) files, and then separately link them into a single executable; finally, you will test your code with valgrind.

## Part A: Ant Program

You should implement two classes, AntHill and Ant. Both these classes are defined in an AntHill.h file and should be implemented in the AntHill.cpp file. The TA will give a brief overview of separate header and implementation files. We will discuss it in more detail in class. All methods must be external (don’t worry if you don’t know what that means).

### Ant
The Ant class has two constructors. One that creates an Ant and initializes the id to -1, and another that takes an #id number as a parameter. Both should initialize x and y coordinates to (0,0). Your ant class should have the following interface:
* private instance variables:
   * int id;
      * A unique id assigned by the AntHill
   * int x;
      * The X coordinate of the ant
   * int y;
      * The Y coordinate of the ant
* public methods:
   * Ant(); //already implemented for you
      * A default constructor so you can allocate memory for an empty array. This is for utility purposes only, and should be considered an invalid object.
   * Ant(int); //already implemented for you
      * A value constructor that sets the Ant’s id to a unique value and its x,y coordinates to 0
   * void move();
      * Moves the ant 1 unit in a random direction (up, down, left, or right). No diagonal movement. This means that either the x or y coordinate will be incremented/decremented by 1.
      * Please take a look at the documentation for rand() for generating a random value. I have already included a random seed (srand()) in  the driver code. Do not call srand() in your code.
   * int getID(); //already implemented for you
      * returns the Ant’s ID number
   * int getX();
      * returns the Ant’s x coordinate
   * int getY();
      * returns the Ant’s y coordinate

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

### Anthill
The Anthill class will have a constructor that takes the maximum number of ants it is allowed to hold as a parameter, up to the buffer max. You will also need an array of Ant objects. For now, you should allocate the Ant array to a constant buffer size of 100. Below is the expected interface for your Anthill class.
* _private_:
   * int max_ants;
      * The maximum number of Ants the AntHill can support
   * int current_ants;
      * The current number of Ants in the AntHill
   * Ant ants[100];
      * An array of Ants. We will make this more dynamic in a later lab.
   * int next_id;
      * [Optional] A mechanism for keeping track of the next ID to assign an ant. There are many way to accomplish this. You are free to come up with your own solution as long as the ID’s are unique and integers.
* _public_:
    * AntHill(int);
        * A constructor that takes the maximum number of Ants as a parameter
    * bool addAnt();
        * Adds a new Ant to the AntHill. Return true on success and false on failure.
    * Ant getAnt(int);
        * Returns a copy of an Ant with the specified id.
    * void move();
        * Commands all of the Ants in the AntHill to move 1 random unit.
    * bool changeMax(int);
        * Allows you to change the maximum number of Ants.
        * If the number is greater than 100, you should ignore the change, and leave the max as is
    * void printHillInfo();
        * Prints the Hill information. (See sample output below)
    * int getCurrentNumAnts()
        * returns the current number of  ants
    * int getMaxAnts()
        * returns the maximum number of ants




## Part B: Testing and Running Your Code
### Make
You are going to be using separate compilation to build your program. This means you will need to create two object files. One from the provided lab2.cpp file, and one from your AntHill.cpp file. The header file, or .h file,  contains your class declarations. You never compile header files. They are always included in other files that get compiled, and should be dependencies for a target, never a target themselves. Often, they will be included in multiple files.

For this class we are going to be using ‘make’ and makefiles to compile our code. Write a makefile that compiles lab2.cpp and AntHill.cpp to separate object files. Then link them as shown in class. Your makefile will need to have the following targets (in addition to the compile and linking targets).
* __all__
   * This will compile your code to an executable, and should have your executable target as a dependancy
* __run__
   * This target has ‘all’ as a dependency, then runs your executable
* __checkmem__
   * Also has ‘all’ as a dependency, but runs your code with valgrind (explanation below)
* __clean__
   * removes object files and the executable. Be careful not to delete your source code.

[Click here for more information on makefiles](http://mrbook.org/blog/tutorials/make/)

You must use variables in your makefile to accomplish the following:
* A compiler flag variable that will easily allow you to switch compiler flags
   * example compiler flags I recommend:
      * `-Wall -Wextra -DDEBUG -g -pedantic -std=c++14`
* A project name variable that you can use throughout your makefile
### Valgrind
You will also need to run your code with Valgrind to ensure you do not have any memory leaks or memory errors. Valgrind is a unix tool that allows you to run many different kinds of memory tests on your code. For this class we will be concerned with two things
* __Memory Leaks__
    * you should not have any memory leaks in this lab, but valgrind catches, and if you compile with the `-g` flag, tells you where the memory leaks are (usually).
* __Memory Errors__
    * If you are using uninitialized memory or you are overflowing a buffer, valgrind will catch it.

Below is a sample of how to run valgrind, and the output you should see:
```shell
        valgrind ./lab2
        … #your code runs
        ==18210== HEAP SUMMARY:
        ==18210==     in use at exit: 0 bytes in 0 blocks
        ==18210==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
        ==18210==
        ==18210== All heap blocks were freed -- no leaks are possible
        ==18210==
        ==18210== For counts of detected and suppressed errors, rerun with: -v
        ==18210== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

__For every subsequent lab you must have 0 leaks and 0 errors or you will lose points.__

### Constraints

The above public methods for your classes are the minimum interface requirements. You may add additional methods or instance variables to your classes if you feel they are needed. For full credit, please adhere to the following constraints, in addition to what is described above:
* You may not use any __global variables__. The only exception to this is constant values, and they should be declared in all uppercase.        
* Your lab must build from 2 different C++ source files (See expected structure below).
    * Your ‘AntHill’ /’Ant’ classes should be defined in a header file, and implemented in a separate implementation (.cpp) file.
    * The C++ file that contains the main() is provided below. You must use the provided driver code, as it will contain tests you must pass.
    * _lab2.cpp_ and _AntHill.cpp_ should build into .o files called _lab2.o_ and _AntHill.o_, respectively, and should then link into an executable called _lab2_. Therefore, after building your program with make, we should be able to type `./lab2` to run it.

## Part C : Code Organization and Submission
* Required code organization:
   * lab2.cpp (driver code - You must include this file in your submission)
   * AntHill.h
   * AntHill.cpp
   * makefile
      * executable should be called: lab2
         * _do not add a .exe extension_

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

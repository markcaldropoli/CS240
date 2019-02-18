#### CS 240 - Spring 2018
# Program 2 - Highcard Tournament
## Due Date: 5:00 p.m., April 18th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * Driver
       * program2.cpp
    * Test players files
       * players.txt
       * players2.txt
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
```shell
    TEST #0: Missing file handled
    ========================PASS========================
    TEST #1: Create Players and store them in a heap
    ========================PASS========================
    TEST #2: Players stored in correct order when removed from the heap
    ========================PASS========================
    TEST #3: Heap is empty
    ========================PASS========================
    TEST #4: Can add individual players to the heap
    ========================PASS========================
    TEST #5: Play 1 round of highcard
    ========================PASS========================
    TEST #6: Play highcard tournament
    ====James Bond\'s Hand====
    K (Diamond)
    =========================
    James Bond wins in round 5179
    ========================PASS========================
    TEST #7: Play highcard tournament with equal starting budgets
    ====Tyler Durden\'s Hand====
    3 (Diamond)
    =========================
    Tyler Durden wins in round 780
    ========================PASS========================
    TEST #8: Play highcard tournament with random starting budgets
    ====Player5\'s Hand====
    6 (Spade)
    =========================
    Player5 wins in round 12486
    ========================PASS========================
```

### Grading Rubric
__Total: 65 points__
* __Part A__
    * Passes test 0 [2 points]
        * Handles empty file case without crashing or memory leak
    * Passes test 1 [5 points]
        * Creates a heap from players file
    * Passes test 2 [5 points]
        * Players are removed from the heap in correct order
    * Passes test 3 [3 points]
        * Heap is empty without memory leaks after all players removed
* __Part B__
    * Passes test 4 [10 points]
        * Players can be added individually maintaining the heap
    * Passes test 5 [10 points]
        * Plays a single round of highcard
    * Passes test 6 [10 points]
        * Plays through entire tournament
    * Passes test 7 [5 points]
        * Plays tournament with equal budgets
    * Passes test 8 [5 points]
        * Plays tournament with randomized budgets
* __Part C__
    * Passes 2 additional tests written by the student [5 points each]
        * Each test is significant and has a comment noting what is being tested
* __Part D__
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure, makefile, and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

Welcome to the high stakes world of backroom high card, where the best of the best walk away with it all, and only the richest players get to play. For this assignment, you are to implement a High Card tournament by putting all players into a max-heap sorted by their budgets. The losers of each round are placed back into the heap, and the next 4 richest players from the heap are added back to the game. This could be the same players as the previous round or new players who have deeper pockets and lady luck on their side.

## Part A: Setting up the Tournament

For Part A you will read in a text document containing players and their budget (from 1-200). As you read in the players, you must store them in a binary max-heap ADT that you have written. The heap is prioritized by the player’s current budget and must be an array based heap. You may not use the STL library for the heap itself, but you can use a vector (or other STL container) for the internal array.

Below is the the class interface for the players and the heap.
* class Player
    * Public Instance Variables
        * `Card hand`;
    * Public Methods
        * `Player(String name, int budget)`
        * `string getName()`
        * `int getBudget()`
        * `bool bet(int amount)`
            * Removes a specified amount of money from the player’s budget
        * `void collectWinnings(int amount)`
            * Adds a specified amount of money to the player’s budget
* class Heap
    * Public Methods
        * `Heap()`
            * default constructor initializes an empty array
        * `Heap(string filename)`
            * Takes a filename and reads the player’s name and budget
                * (see file linked below for format)
         * `Heap(const Heap &copy)`
         * `void addPlayer(Player newPlayer)`
         * `Player getPlayer()`
             * Removes the priority player (the player with the highest budget) from the heap. This should remove the player from the heap entirely.
             * Remember that after removing the player, your heap still needs to be a heap
         * `vector<Player> getArray()`
         * `bool empty()`
         * `unsigned int size()`

__Show your TA your working Part A code by the end of lab on April 12th.__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Making Your High Card game
### Playing the Game
In the game of high card the following actions occur.
1. The 52 cards in the deck are shuffled (randomized).
2. Each player ante’s (puts in a minimum bet)
3. Then each player is given one card from the top of the deck.
4. Now each player’s card is evaluated and the winner is determined.
    * You can handle value ties however you like, but the standard suit rank is diamonds (lowest), followed by clubs, hearts, and spades (highest). There should only be 1 winner per round.
5. The losers that still have enough money in their budget to cover an ante are placed back into the heap, and the next group of players sit at the table.

 Below is the class you will need to run the game:

* Class Table
    * Public Methods
         * `Table(int num_seats, int ante)`
         * `bool emptySeat()`
         * `vector<Player> playRound()`
             * Returns a vector of the losers of the round
             * The winner stays for the next round while the losers leave
             * The players in this vector will be put back into the heap if they have enough money to cover the ante
         * `void addPlayer(Player p)`
         * `void printWinner()`

Once you have you `Player` and `Table` set up and are passing the first 5 tests in the driver code, you should then start on the actual high card game itself. You can use your Deck class and Card class from your previous lab to implement the highcard game. You may need to change or add additional methods to those classes (verify that shuffle is actually random).

## Part C: Testing your code

Once you are passing all of my tests, you must come up with two more tests for your code on your own. State explicitly in a comment preceding the test:
* what you are testing
* what is the expected outcome.

Whether you use an assert() or some other mechanism, the tests must end your program abnormally if it fails.
* Example of ending your program abnormally:
    * failing an assert
    * calling exit(-1)

## Part D: Code Organization and Submission
* Required code organization:
    * program2.cpp
    * Player.h/.cpp
    * Table.h/.cpp
    * Heap.h/.cpp
    * Deck.h/.cpp
    * Card.h/.cpp
    * makefile
        * You must have ‘checkmem’ and ‘run’ targets
        * Your makefile must include c++14 extensions

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

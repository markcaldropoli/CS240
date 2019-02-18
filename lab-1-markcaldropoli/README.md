#### CS 240 - Spring 2018
# Lab 1 - Setting Up Your Environment
## Due Date: 5:00 p.m., January 24th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab1.cpp
    * makefile
* _Expected Command > Output_
    * make ; ./lab1
        * Hello World! <br>
        C++ Data Structures!

### Grading Rubric
**_TOTAL: 5 points_**
* **Part A: 1 point**
    * Compiles and outputs hello world when run (1 points)
* **Part B: 1 point**
    * Compiles with makefile (1 point)
* **Part C: 3 points**
    * Follows requested project structure and submission format
    * Clean submission does not include .o files or binary
    * Follows [formatting guidelines](https://docs.google.com/document/d/1RU9bHsJhc4wecOXelXF5uUjcNTce4f2I0-09kJKvRvk/edit?usp=sharing)

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

_In this lab, you will learn to:_

* Use the command line to issue commands to the operating system
* Write, compile, and execute a simple C++ program in a command-line environment
* Use `git` to manage your projects and submit your work for grading.

## Part A: Learning the Environment

Part A must be completed in lab. Each lab during the semester will have a Part A that you must attempt to complete in lab. As soon as you complete Part A, you may show the TA and leave. If you cannot complete Part A by the end of lab, speak with the TA at the end of lab.

If you miss your lab time without prior arrangements with me or the TA, you cannot make up or complete part A outside of lab. In this case, you will not receive credit for Part A, even if completed (_many labs will require you to complete Part A in order to complete the lab_).

There will usually be additional parts to the lab that may be completed outside of lab on your own time.

### Using Linux Commands
First, you will begin running and using some Linux commands to set up your work environment for the semester.  This will ensure everyone has access to their accounts and all of the tools needed for the course.

Log into a machine using your CS Department userid and password (If you're reading this online in the lab, you've probably succeeded in doing this already). Locate and launch a "terminal". We will call this, interchangeably, a terminal, shell, or command line. The shell will accept and execute Linux commands, of which there are hundreds. If you are not familiar with the Linux terminal, a good introduction can be found [here](https://code.tutsplus.com/tutorials/command-line-basics-and-useful-tricks-with-the-terminal--cms-29356).

In particular, complete the following steps:
* Create a directory named cs240. On the command line, you can do this with the following command:
   * `mkdir cs240`
* Change your "present working directory" to be the cs240 directory. To do this, execute the following command:
   * `cd cs240`
* Confirm that you are in fact in the cs240 directory by typing the command:
   * `pwd`
      * this stands for ‘present working directory’

### Working with Git and Github
The next thing we are going to do is initialize our folder to work with github. First, let's set up our git credentials. Enter the following two commands in the terminal:

`git config --global user.name "Firstname Lastname"`
`git config --global user.email "email@binghamton.edu"`

You should be in your cs240 directory. If you are not, go back to the previous section and try to figure out how to get there. If you need help, ask a TA.

In this directory, you are going to clone this repository to get a copy of the source code onto your account. To do this, you will first need to have signed up for a Github account if you didn't already have one.

:bulb: If you don't have an account, ask the TA to help you.

Look at the Github landing page for your fork of this project. You should see a green button that says "Clone or download". Press it and you should see a URL like https://github.com/binghamtonuniversity-cs240/lab-1-username.git. Copy that text somewhere you can access it, then go back to the terminal.

Next, be sure you are still in the cs240 directory and execute the following command in the terminal:

`git clone URL`

:bulb: *where URL is the copied text ending in ".git".*

We will explore git workflows in-depth later in this lab.

### Compiling a C++ Program
Next we will write a 'Hello World' program in C++. Change your directory to the cloned repository. So far, you have not done any "programming" or even dealt with any C++ code. You have run a few simple linux commands to create and navigate directories. In the next few sections, you will edit, compile, and run a C++ program within linux.

To create a file, you will need to use a unix file editor. Unix systems generally have several editors from which to choose. Two of the more popular and classic Unix editors are called “vi” (or “vim”) and “emacs”. Another popular editor is "nano". You may use any editor you prefer, but if you are learning one for this class, I don't recommend vi or emacs. Nano is slightly simpler, but still not the best choice....

If you are not already very familiar with a linux editor, please use gedit, which has several nice features for C++ code development. You can use gedit to open a file by typing, for example, the following into a linux command shell:
`gedit lab1.cpp &`

If there is no file in the current folder named *lab1.cpp*, then gedit will create a new empty one for you (remember, you can check your current folder location with `pwd`). If the file does exist, it will edit the existing file.

:bulb: The ampersand (&) at the end of the command says to run this application in the background. This will allow you to write some code, save it, then run it in the shell without quitting gedit.

After making changes to a file, you can save it by clicking "Save" at the top of the gedit window, or with the hot key command `<ctrl-s>`. Note that if you have made changes to an open file, and those changes have not been saved, the file name across the top of the window will be preceded by an asterisk (for example, "\*lab1.cpp"). To exit from gedit, make sure your modifications are saved, and then type `<ctrl-q>` in the gedit window, or simply close the gedit window by clicking the “x” in the upper right hand corner.

The only problem with gedit is that it will not work if you are trying to program remotely, from a machine other than the ones in Q22 or G7. To work remotely, you can use an editor (such as vi or nano) that works within a shell, or you can edit the file on another machine and transfer it to the CS file server separately. See the resources page on piazza for more information about working remotely.

You should be able to learn enough about text editing and working remotely on your own, or from a classmate, for this class. Please let us know if you need help.

Now we are going to write a program in C++:
* Open the file named lab1.cpp within the lab1 directory.
* Write a simple hello world program by doing the following to print out ‘Hello World’:
    * At the very top of your file you will need to add the following line: `#include <iostream>`
        * This will include the required libraries for input and output. In C++ we call input and output ‘streams’, which is why it is called iostream.
    * All C++ programs must have a main function. The main lets the OS know where to start executing the program. Although in newer versions of C++ (>=C++11) you can return void from the main, it is a best practice to return an int. So your next line of code should be: <br>
    `int main(){`
    * To print output to the console, you should use the following line: <br>
    `std::cout << “Hello World!” << std::endl;`
        * std::cout is an object in C++ that encapsulates output.
        * std::endl flushes the output stream and adds a new line to the output.
    * End your program with a closing the brace.<br>
        `}`
        * You may also add `return 0` at the end of main before the closing brace, which lets the operating system know that everything executed properly; however, the C++ specification states that if no return statement is present at the end of main, the process automatically returns 0.
    * Save and exit.

__Show your TA your code.__<br>
__--END OF IN LAB REQUIRED WORK--__ <br>
__You may continue to work on the remainder of the lab on your own time or in lab__


## Part B: Compiling and Executing
Like you did in Part A, navigate to your lab 1 folder in the shell:
* Type in `ls` to list the directory's files. Ensure that 'lab1.cpp' is in the directory.
* To compile, we will be using the program called 'make'. Do not confuse this with the 'makefile' which we will be creating later. 'make' is the program that reads makefiles.
    * We will be discussing makefiles at length later in class.
* A starter makefile is included in the cloned repository.  We will use it to compile your lab1.cpp source code to an executable called ‘lab1’.
* To compile the C++ source file, enter the following command in the terminal:
    * `make`
        * This command produces an executable file named “lab1” by executing the g++ command found within the contents of the makefile. In particular, the “make” command looks for a file named “makefile” in the present working directory, and finds within that file the rule for “all” by default. This rule indicates that “all” should follow the rule for "lab1", contained below it. The lab1 rule, in turn, contains the following two lines:
        ```shell
        lab1: lab1.cpp
            g++ -g lab1.cpp -o lab1
        ```
        * You could also target specific rules
            * `make lab1`
        * The source should compile to an executable.

Importantly, there is a [tab] character (not a single space) before the g++. These two lines indicate that the lab1 target depends on the lab1.cpp file. So if lab1.cpp has been updated recently (i.e. since the time that the lab1 executable was created), then the make utility will re-run the command that follows (in this case `g++ -g lab1.cpp -o lab1`). This line (`g++ -g lab1.cpp -o lab1`) is a linux command, and could be executed from a shell prompt. In our case, it is being executed by make, to compile the C++ code contained in lab1.cpp. The command's output is a file named "lab1", which contains object code for the Hello program that is linked with the C++ libraries into an executable file. g++ does this linking for you. In the next lab, we will learn how to compile and link in separate steps.

To repeat (in an attempt to be as clear as we can), g++ is the compiler and the linker... it's doing all the work of building your C++ program into object code and an executable that can be run on linux. The makefile is not strictly necessary for building C++ programs; it just makes things more convenient. The makefile contains rules for the linux make utility to invoke g++ so that it can do its thing. This way of building programs is intended to give you control over the build process, to set it up however you want, without requiring you to type in a bunch of detailed commands every time you compile your code. (That is, once everything is set up properly, you just type “make”, instead of all the different commands that are contained in the makefile.)

To verify that the new file (lab1) was created, run the following command:
* `ls`
    * _As you know, "ls" lists the files in the current working directory._

The final thing to make sure you have in the makefile is a rule for "make clean," which should run the following command:
* `rm lab1`

This `rm` command removes the file "lab1". Run `make clean` and then `ls`, and observe that the file that make (via g++) had created earlier is now gone:
* `make clean; ls`

To rebuild your program and get the executable back, run make again
* `make`

Object files and the executable are not rebuilt if the files that they depend on have not been changed. Try running make one more time.
* `make`

You should see a message that says, "make: Nothing to be done for 'all'.". That's because the output (lab1) exists and has a timestamp that is newer than the lab1.cpp file, which means it is up to date. Again, we will go into further details regarding makefiles in class.
### Running and Updating a C++ Program
So far, you have compiled and linked a C++ program, but you have not run it yet. To run the program, type the following at the shell prompt:
* `./lab1`
    * In linux, “.” is a shortcut name for the current working directory, and “..” is a shortcut name for the directory just “above” it.

Observe the output of the program, and then look in the lab1.cpp file to see the program that produced it. To look in the lab1.cpp file, you can edit it (with an editor described above), or you can use ‘cat’, ‘less’, or ‘more’ (all linux commands).
### Altering and Recompiling a C++ Program
Now, let's change the C++ code, recompile, and rerun it. Open the lab1.cpp file and add another line to the code to have it print “C++ Data Structures!”. Immediately upon doing so, save the file and try running the program again:
* `./lab1`

Notice that your new message is not printed. This is because you only updated the C++ file, not the executable file (lab1). To rebuild the executable, run make again. Now run lab1 and observe that it prints your new message.

## Part C : Submission
* Required code naming and organization:
    * lab1.cpp
    * makefile

:no_entry_sign: Every lab will have required submission guidelines. Please read submission requirements carefully. Any deviations from specifications on future labs or projects will result in point deductions or incomplete grades.
### Git
In this and future assignments, we will use Github Classroom repositories. You have already [forked](https://help.github.com/articles/fork-a-repo/) this repository when you accepted the emailed link. That makes a copy of the repository, free for you to make changes. Then you cloned your forked repository to get a working copy onto this machine.

Now that we have made local changes to our working copy, let's [commit](https://git-scm.com/docs/git-commit) those changes to the repository:

:warning: *These commands all presume that your current working directory is within the directory tracked by `git`.*

```shell
git commit -a -m "first commit"
```

The `-a` says that git should add all tracked files with changes to your commit, and the `-m` says the next string contains the commit message.

What about _untracked files_? Run the following commands:

```shell
echo $(whoami)@$(hostname):$(pwd) > information.txt
git status
```

You'll notice that `git` tells us that `information.txt` is an _untracked file_. That means it's not being tracked by the repository. Let's fix that by [adding](https://git-scm.com/docs/git-add) it.

```shell
git add information.txt
git commit -m "Added an informational file"
```

Once we've made the commits for a given coding session, we need to add those to the repository by performing a [push](https://git-scm.com/docs/git-push):

```shell
git push
```

Now, let's say we don't want `information.txt` in the repository anymore. How can we remove it?

```shell
git rm information.txt
git commit -m "Removed an informational file"
git push
```

Lastly, the next time we begin a coding session, we will need to [pull](https://git-scm.com/docs/git-pull) to get an updated working copy.

```shell
git pull
```

This will allow you to keep your code in the lab and on your own computer synchronized.

Lastly we are going to make our final commit. You will need to do this when your submission is ready for grading.

```shell
git commit --allow-empty -m "final commit"
git push
```

The `--allow-empty` option makes it possible to make a commit without having made any changes. This will enable you to just update the comment.

:bulb: You can commit as often as you like, and revert your code to any previous commit. I recommending making commits often with a comment describing the state of your code. The TAs will only grade your submission when the comment says "final commit".
:warning: You __MUST__ make a submission with the comment "final commit" before the deadline to be considered on time.

That's it! We've completed our work for this lab. We will use this submission process for all subsequent labs and assignments.

:bulb: Useful `git` references:
- https://guides.github.com/introduction/flow/
- https://help.github.com
- https://git-scm.com/doc

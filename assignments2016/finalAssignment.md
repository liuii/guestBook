# 2016秋季学期《计算思维》大作业

首先，不要惊讶。  
其次，我们的作业真的就是英文的。  
所以，请感谢我提供了一个给你练习英文的机会:)  

----
## 0. Introduction
In this assignment you will use the basic c++ programming techniques that you have learned in this paper and that we will have learned during this semester, in particular conditional statements and loops, and random number generation.

The idea for Camel originally came from the Heath Users Group and was published in More BASIC Computer Games in 1979. This version comes from Paul Craven's online text "Program Arcade Games with Python and Pygame" and Giovanni Moretti's tutorial.

The idea is to ride your camel across the desert while being chased. You need to manage your thirst, how tired the camel is, and how far ahead of the natives you are. It is easy to add sandstorms and other random events to the game to make it more interesting.

----
## 1. Sample Run of Camel

Here is a sample run of the game:

```
Welcome to Camel!
You have stolen a camel to make your way across the great Mobi desert.
The natives want their camel back and are chasing you down! Survive your
desert trek and outrun the natives.

A. Drink from your canteen.
B. Ahead moderate speed.
C. Ahead full speed.
D. Stop and rest.
E. Status check.
Q. Quit.
Your choice? C

You traveled 12 miles.

A. Drink from your canteen.
B. Ahead moderate speed.
C. Ahead full speed.
D. Stop and rest.
E. Status check.
Q. Quit.
Your choice? C

You traveled 17 miles.

A. Drink from your canteen.
B. Ahead moderate speed.
C. Ahead full speed.
D. Stop and rest.
E. Status check.
Q. Quit.
Your choice? e

Miles traveled:  29
Drinks in canteen:  3
The natives are 31 miles behind you.

A. Drink from your canteen.
B. Ahead moderate speed.
C. Ahead full speed.
D. Stop and rest.
E. Status check.
Q. Quit.
Your choice? b

You traveled 6 miles.

...and so on until...

A. Drink from your canteen.
B. Ahead moderate speed.
C. Ahead full speed.
D. Stop and rest.
E. Status check.
Q. Quit.
Your choice? C

You traveled 12 miles.
The natives are getting close!

A. Drink from your canteen.
B. Ahead moderate speed.
C. Ahead full speed.
D. Stop and rest.
E. Status check.
Q. Quit.
Your choice? C

You traveled 11 miles.
The natives are getting close!
You made it across the desert! You won!
```

----
## 2. Programming Guide

Here are the steps to complete this tutorial task. Feel free to modify and add to the program. Try the game with your classmates, or friends and family.

1. Create a new project named camel, and add a `c++ source file` named `camel.cpp` and add code to print the instructions to the screen. Do this with multiple output statements. Don't use one output statement and multiple \n characters to jam everything on one line.
    ```
        Welcome to Camel!
        You have stolen a camel to make your way across the great Mobi desert.
        The natives want their camel back and are chasing you down! Survive your
        desert trek and out run the natives.
    ```
2. Create a int variable called `done` and set to `0`.
3. Create a while loop that will keep looping while `done` is `0`.
4. Inside the loop, print out the following:
```
    A. Drink from your canteen.
    B. Ahead moderate speed.
    C. Ahead full speed.
    D. Stop for the night.
    E. Status check.
    Q. Quit.
```
    Ask the user for their choice. Make sure to add a space before the quote so the user input doesn't run into your text.
    If the user's choice is Q, then set done to True. By doing something like user_choice.upper() instead of just user_choice in your if statement you can make it case insensitive.
    Test and make sure that you can quit out of the game.
    Before your main program loop, create variables for miles traveled, thirst, camel tiredness. Set these to zero.
    Create a variable for the distance the natives have traveled and set it to -20. (Twenty miles back.)
    Create and set an inital number of drinks in the canteen.
    Add an elif in your main program loop and see if the user is asking for status. If so, print out something like this:

    Miles traveled:  0
    Drinks in canteen:  3
    The natives are 10 miles behind you.

    Add an elif in your main program loop and handle if the user wants to stop for the night. If the user does, reset the camel's tiredness to zero. Print that the camel is happy, and move the natives up a random amount from 7 to 14 or so.
    Add an elif in your main program loop and handle if the user wants to go ahead full speed. If the user does, go forward a random amount between 10 and 20 inclusive. Print how many miles the user traveled. Add 1 to thirst. Add a random 1 to 3 to camel tiredness. Move the natives up 7 to 14 miles.
    Add an elif in your main program loop and handle if the user wants to go ahead moderate speed. If the user does, go forward a random amount between 5 and 12 inclusive. Print how many miles the user traveled. Add 1 to thirst. Add a random 1 to camel tiredness. Move the natives up 7 to 14 miles.
    Add an elif in your main program loop and handle if the user wants to go ahead drink from the canteen. If the user does, make sure there are drinks in the canteen. If there are, subtract one drink and set the player's thirst to zero. Otherwise print an error.
    In the loop, print “You are thirsty” if the user's thirst is above 4.
    Print “You died of thirst” if the user's thirst is above 6. Set done to true.
    Print “Your camel is getting tired.” if the camel's tiredness is above 5.
    Print “Your camel is dead.” if the camel's tiredness is above 8.
    If the natives have caught up, print that they caught the player and end the game.
    Else if the natives are less than 15 miles behind, print “The natives are getting close!”
    If the user has traveled 200 miles across the desert, print that they won and end the game.
    Add a one-in-twenty chance of finding an oasis. Print that the user found it, refill the canteen, reset player thirst, and rest the camel.
    Play the game and tune the numbers so it is challenging but not impossible. Fix any bugs you find. 
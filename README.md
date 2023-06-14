# nimGameReinforcementLearning
Program to play nim game against  a computer which learns how to play NIM by reinforcement learning

Here is the relevant information about the program:

 There are two players. For this assignment, your program should have one human player (the user)
and one computer player. The computer player should move first.


 Between the two players is a pile of sticks. The pile should always start at 10 – changing the value
will cause the learning to fail.


 The players take turns (the computer player should start). Each turn, the player takes some number
of sticks from the pile in the middle. You should allow players to take up to 3 sticks.


 The winner of the game is the player that takes the last stick from the pile.
Your program does not need to have any graphics, but for each player’s turn it should be obvious whose
turn it is as well as how many sticks are left in the pile.

before:

<img width="383" alt="before" src="https://github.com/Korea19800/nimGameReinforcementLearning/assets/52956141/f8857776-52c4-46bf-a6aa-aed80bedb81c">


after:

<img width="374" alt="afterNIM" src="https://github.com/Korea19800/nimGameReinforcementLearning/assets/52956141/80cf9f65-cacc-471e-8f1d-ca5844e7356f">


What to Do:
You will be using reinforcement learning to allow the program to learn how to play a good game of NIM.
You will need an M x N array, where M is the maximum number of sticks a player can choose and N is
the initial number of sticks in the pile. You may assume that these numbers are 3 and 10 respectively;
you should NOT allow the user to select these values. In other words, the game should start with 10
sticks in the middle, and each player can take 1, 2, or 3 sticks on their turn. You should also have the
computer make the first move.

This array of yours will contain the Q-values that the program has calculated – the element in row i and
column j is the value of choosing to take i sticks when there are j sticks left in the pile. Be careful with
array indexing – remember array indices start with 0, not 1. Adjust your code accordingly!
Since it can take a while for the computer to learn to play a decent game, your program should also load
and save the learned information when the user starts or finishes the program respectively. This action
should be completely transparent to the user (in other words, the user shouldn’t even know that it is
happening). Simply pick a file name that will contain the learned information, and store and retrieve it
from there. If that file doesn’t exist, start the game off with a blank slate (all zeros in the array). You may
“seed” the array with values that take into account the rules of the game for small numbers of sticks left
– see discussion in class. When the game is over, save the array to the file.

The action of the game is simple – when it is the computer’s turn to play with x sticks in the pile, it should
look in the appropriate column and choose the row with the highest value. If there is a tie for highest
value, choose any of the tied moves – break the tie however you like. 

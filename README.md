Nine-Almonds

Chao Zhang  Lab 2

7.
1>c:\users\xiaoxiao\desktop\lab 2\lab 2\game.cpp(185): warning C4305: 'return' : truncation from 'en' to 'bool'
1>c:\users\xiaoxiao\desktop\lab 2\lab 2\game.cpp(128): warning C4715: 'NineAlmondsGame::prompt' : not all control paths return a value
1>c:\users\xiaoxiao\desktop\lab 2\lab 2\game.cpp(168): warning C4715: 'NineAlmondsGame::turn' : not all control paths return a value
1>c:\users\xiaoxiao\desktop\lab 2\lab 2\game.cpp(197): error C4716: 'usage_message' : must return a value

9.
When I do not input another string(NineAlmonds) on the command line, the main() function will call usage_message() function to tell reader, you should input another string namely NineAlmonds.Then you should input different coordinates.

When I input another string rather than NineAlmonds, it will show that "The game name is wrong. Please enter NineAlmonds."

When I input another string namely NineAlmonds on the command line, the object runs successfully. It will show the initial game board namely:

4
3   A A A
2   A A A
1   A A A
0
X 0 1 2 3 4

When I input the different values of coordiantes into the program, as in the right answer of Nine Almonds, I get the right answer as the right answer says namely there is a 5 in the center of the game board.
Move 1: 2,2 to 2,0 to 4,2 to 2,4 to 0,2
Move 2: 1,1 to 1,3
Move 3: 3,2 to 1,4 to 1,2
Move 4: 0,2 to 2,2
Output: 4 turns were played to complete the game successfully.  
4  
3    
2     A
1   
0
X 0 1 2 3 4
How to do in the commond line? When you input another string NineAlmonds, you will see the initial game board. Then you input 2,2 and 2,0. Then it will ask whether you will continue or not? Please input Y or y, then input 4,2, then you will continue to decide whether to continue or not? Then you will input Y or y, then input 2,4, then you will input Y or y, then input 0,2, then input N. This is the first turn or move. Then we will do the same process as this step. Finally, you will get the correct result.

I also test the condition of no further valid moves remains.
For example, it can test it in this condition.
Move 1: 2,2 to 2,0 to 4,2 to 2,4 to 0,2
Move 2: 1,1 to 1,3
Move 3: 3,3 to 1,4 to 1,2
Move 4: 0,2 to 2,2 to 1,2
Output: 4 turns were played and no valid movies remain.
4
3    
2       A
1   
0
X 0 1 2 3 4

When I input quit command, the program will stop.
Output: "The user asks to quit. 0 turns were played and the user quit."

Summary:
The program first initializes a class object. Then through different input values, we can change the game board and finally we can leave a game piece in the center of the game board successfully. But we can also face different conditions that no valid moves are left and we fail in the end.

We can also know that in each case, we can get correct result from the above statements.



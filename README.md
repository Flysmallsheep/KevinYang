# KevinYang
This folder contains academic projects that published by Kevin Yang

1.Motivation of the program design:

This assignment gives me an overview and basic concept of Object-Oriented design pattern which is very important for coding in industry-based environment , changes , it enhances my thinking way and coding skills, so I paid lots of effort on this assignment, Specially the extra functionality, such as give player different skill levels ,  different game elements , appropriate scoring system and promoted system ,that requires me lots of extra thinking and at the same time, I gain a lot from this game design. 

2.Why am I design the program that way:
 Firstly, when I did assignment 2 (which is a overall design of classes), I have to construct each class that contains many different functionalities, that do requires lots of thinking to imagine how the entire program works, I created two classes with main.cpp which the design brief recommend me to do and I think this design pattern is achievable and reasonable. 
Because whole program contains mainly three parts: Player, Board and Main.
Player class holds the player information such as name and scores;
Board class holds the board information such as board chances and board elements;
Main holds the brain of the logic that contains mainly commands that could be used by the players or boards.

Reflect on O-O design approach, let’s see what is OO design first, referring to wikipedia:
“Object-oriented design is the process of planning a system of interacting objects for the purpose of solving a software problem.”
On my program, the whole game is like a system, the interacting objects contains players and boards that holds the instructions and information, Also, to implement O-O design more completely,  encapsulation and inheritance concepts have been used across all the classes design part. So I create my classes that way.

3. How well I code it (problem and how I solve it):
 It gives me a hard time when I find the plan isn’t working very well when I try to make the plan become a real program. The planning process is easy, However, the implement process for plan is horrible.  I found several problems during the coding on Xcode. One of the problem I met is the logic of clue, the clue has to display to the user with three different situation : “o” “?” or nothing, Firstly, I am tried to look up online on stack-overflow website, I imitate someone used iterator to retrieve each user element and then compare them to the answer elements, the code is tidy ,clean and short, but , some logic part is overlap so it cause lots of errors, then I give up this solution. Finally I choose to used the basic if-else logic to solve the overlap issue. The logic is very understandable compare to the iterator one.


4. How to make it better:
	If I could do this program again, I will modify the logic of clue, because in my opinion, the clue is the most important part in this program due to that requires lots of thinking to avoid overlap of logic. If I could do this again, I will choose to use the “algorithms”, Because C++ have the algorithms standard library, I just simply type in #include <algorithms> so that I can use any algorithms I want ! and I think use algorithms method to solve the clue logic is efficient and effective. The algorithms code is very simple (just one line of code) otherwise  you might type hundreds lines of code to achieve the same functionality. and It also can make OO design cleaner, more efficient and understandable for freshman of coding.



That’s All, Thank You for reading! 

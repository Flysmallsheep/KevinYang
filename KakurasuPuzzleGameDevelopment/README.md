Welcome to Kevin's Project!

This is a Japanese puzzle game called Kakurasu, the objective of the app is to generate random matrics and find solutions. 
1.Describe:
Implementing Backtracking algorithm to solve the  kakurasu puzzle. The basic logic of backtracking algorithm is mainly these steps:
1. definethebacktrackingfunction
2. findthepossiblelocationthatnextstepcango
3. ifpossiblelocation==[]whichmeansthenextstepisemptywhereindicatesthatit
might be a correct answer or it might be wrong
4. insidetheifstatementinstep3,usecheckIfCorrectfunctiontocheckifthepartial
solution is the correct answer for that puzzle that meets all the requirements
5. else:loopthrougheveryitemandappendittothepartialsolution
6. thendotherecursivefunctioncalltoinvokeitselfagain
7. backtrack:pop()thepartialsolutionandtrytheotheralternativesolutioninstead
By appending the possible location to the partial solution each time, I set up a indicator to track which row or column that I am currently at: location[0,0]. Once the element go one by one in a single row, location[1] will += 1. Once the board is filled up with possible items, then checking if the size of the partial solution is equal to the size of the board. If they are equal, then check if the partial solution is the correct solution, then return the true answer for that puzzle as a nested list. Finally use printBoard(board, rowSum, colSum) to output the board.
2.Complexity:
complexity: because for each space(or element) inside the board, it either 0 or 1, which means each space have two possible chances. Let say the board size is the n, then the board have n*n elements, and each element have 2 states. Which represents by Big O Notation is . O(n) = 2**(n**2)
3.Certainity:
That algorithm will be very stable as I mentioned above, when I keep track of location that I am currently at, I will create a indicator to remind the program to stay on the track in order to prevent errors, also I created two variables called originCol and originRow which represents the previous attempt location compare with the current location, so that I can easily backtrack to the previous try and modify that value so I will not lose the previous location, so that the algorithm is reliable and the result have to be certain.


That's all, Thank you!

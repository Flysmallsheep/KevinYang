##############################################################################################################
##############################################################################################################
#Important notice: please enable the driver code in order to test the functions
##############################################################################################################
##############################################################################################################


# Task1A: printing board:

#driver code for Task1A and there is a function call underneath the printBoard() function:
rowSum = [1,7,7,8]
colSum = [5,0,9,9]
board = [[1,0,0,0],[0,0,1,1],[0,0,1,1],[1,0,1,1]]


# variables:
rowLength = len(rowSum) #4
colLength = len(colSum) #4
rowLengthArray = [i+1 for i in range(rowLength)] #[1,2,3,4]
colLengthArray = [i+1 for i in range(colLength)] #[1,2,3,4]


#Function: Task1A: printing board:
def printBoard(board, rowSum, colSum):


    #print the top header:
    print("   |",end=" ")

    #print the header number:
    for i in rowLengthArray:
        print(str(i) + " |", end=" ")
    print()

    #print the dotted line:
    for i in range(rowLength+1):
            print("---|",end="")
    print("---")

    #print the table content:
    for i in range(len(board)):

        #left header:
        print(" "+str(colLengthArray[i]) + " |",end=" ")

        #content:
        for eachElementIndex in range(len(board[i])):
            print(str(board[i][eachElementIndex]),end=" | ")

        #right header:
        print(str(rowSum[i]))

        #dotted line:
        for i in range(rowLength+1):
            print("---|",end="")
        print('---')


    #print the bottom header:
    print("   |",end=" ")
    for i in colSum: #print the header number
        print(str(i) + " |", end=" ")
    print()

#printBoard() function call:
printBoard(board, rowSum, colSum)



##############################################################################################################



# Task1B: converting a bitlist into a board:


def list2board(L):
    myBoard = []
    temperorarySubList = []

    base = 1
    while (len(L)/base ** 2 != 1): #calculate the boardsize
        base += 1
    # print(base) // base == 4

    for i in range(base): #iterate for 4 times in the example to get four row lists
        temperorarySubList = [] #initialize the sublist once each the iteration is over
        for j in range(base): # length = 4
             temperorarySubList.append(L[j]) #put every board_size element into a sublist and then append the sublist into board

        myBoard.append(temperorarySubList)

        L = L[base:] #slice the list to get rid of the sublist that is already append to the board
    return myBoard

#driver code:
L = [1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1]
board = list2board(L)
print(board)


##############################################################################################################




# Task1C: Check solution:




def isSolution(board, rowSum, colSum):

    board_size = len(board)

    #check the sumOfRow is equal to the given solution or not:
    for i in range(board_size): #step through every row in the board

        sumOfRow = 0
        for j in range(len(board[0])): # len = 4
            sumOfRow += board[i][j] * (j+1) #j here repesents every number in a single row, then add them together
        if sumOfRow != rowSum[i]:#compare the sum with the given answer, and check if equal, if not return False
            return False



    #check the sumOfCol is equal to the given solution or not:
    for i in range(board_size): #step through every column in the board

        sumOfCol = 0
        for j in range(len(board[0])): # len = 4
            sumOfCol += board[j][i] * (j+1) #j here repesents every number in a single column, then add them together
        if sumOfCol != colSum[i]:#compare the sum with the given answer, and check if equal, if not return False
            return False

    #If rowSum and colSum are both correct, return True
    return True

#driver code:
print(isSolution(board, rowSum, colSum))



##############################################################################################################
##############################################################################################################
##############################################################################################################


# Task 2B: Back tracking:

def backtrack(rowSum, colSum):

    #Initialize the partial solution and board_size:
    partial = []
    board_size = len(rowSum)

    #Initialize the answer from backtrackFunction logic and final displayed answer:
    answer = []
    FinalAnswer = []

    #location is a list represent [row, col], that used to keep track of which row is it now, which column is it now.
    #starts from row:0, column:0
    location = [0,0]

    #give a numebr of sublist as lines of row according to the size of the board:[[],[],[],[]]
    for i in range(board_size):
        partial.append([])

    #call the backtrackFunction logic and return a correct answer that is going to append on answer[]
    backtrackMain(rowSum, colSum, partial, location, answer)

    #return the final answer:
    for i in range(len(rowSum)):
        FinalAnswer.append(answer[i])
    return FinalAnswer




def backtrackMain(rowSum, colSum, partial, location, answer):

    #location is a list represent [row, col], that used to keep track of which row is it now, which column is it now.
    #starts from row:0, column:0

    #get the boardsize:
    boardSize = len(rowSum)

    #possible location that next step the chess can go:
    possibleLocation = [0,1]

    #if the location[0] == 4(which is the board size), that means the partial contains four rows already, that might be a correct answer
    if location[0] == boardSize:
        if isSolution(partial, rowSum, colSum): #Check if partial solution is a correct solution, if so, append it onto answer
            for everyRow in partial: #Loop through everyRow with each time a empty tempSubList and append the sublist with each element
                tempSubList = []
                for element in everyRow:
                    tempSubList.append(element)
                answer.append(tempSubList)

    #if the location[0] has not been filled up which means the board has not yet been filled up, then continued append item
    else:
        for element in possibleLocation: #To insert possibleLocation[0]or[1] and until fill up
            origin_row = location[0] #When inserting the possibleLocation loop begins, the origin_row holds the origin location that will
                                     #be used in the backtrack algoritm after, in order to get back to the location that previous attenpt
            origin_col = location[1]
            partial[location[0]].append(element) #Insert the possible element one by one on each row, the start is: location[0] == row:0
            location[1] += 1  #location[1]: column number += 1, means go to the next element in the same row

            if location[1] == len(rowSum): # If current row elements is already full, then go to the next row
                location[0] += 1    #next row
                location[1] = 0     #begins from first element

            backtrackMain(rowSum, colSum, partial, location, answer)#recursive function: Call the function itself again
            location[0] = origin_row #When the backtrack begins, the location get back to the origin location where the previous attempt at,
                                  #for example: [...,[0,0,0,0]] -> [...,[0,0,0]], now origin_row holds index 2(origin_row: originLocation),
                                  #not index 3(currentLocation)
            location[1] = origin_col
            partial[origin_row].pop() # Backtrack: delete the previous element, check if possible, then give another element to insert

    return True #return True if board is full or the partial solution is backtrack then call the function itself again



#driver code:
print("\n\nThis is the Kakurasu board that generated by the backtracking algorithm: \n")
rowSum = [1,3,5,3]
colSum = [1,3,9,0]
board = backtrack(rowSum, colSum)
printBoard(board, rowSum, colSum)





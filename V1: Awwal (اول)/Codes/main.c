// 7:56 2/10/25

#include <stdio.h>
#include <stdbool.h>


typedef struct
{
    int fill;   // 0: unfilled/unclaimed, 1: player1, 2: player2
    bool top;
    bool left;
    bool right;
    bool down;
} 
box;

void initializeGameBoard(box gameBoard[3][3])
{
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j].fill  = 1;
            gameBoard[i][j].top   = true;
            gameBoard[i][j].left  = true;
            gameBoard[i][j].right = true;
            gameBoard[i][j].down  = true;
        }
    }
}

void printGameBoard(box gameBoard[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)    // rows
    {    
        // for Top
        if (i == 0)     // prints this if only it is the first row. in all subsequent rows, only the bottom row does the printing. since gameBoard[i][0].bottom == gameBoard[i+1][0].top
        {
            printf(" + %c + %c + %c +\n", 
                ((gameBoard[i][0].top)? '-' : ' '),
                ((gameBoard[i][1].top)? '-' : ' '),
                ((gameBoard[i][2].top)? '-' : ' '));
        }

        // for left, right
        printf(" %c %c %c %c %c %c %c\n", 
                ((gameBoard[i][0].left)? '|' : ' '),
                ((gameBoard[i][0].fill == 1)? '1' : ((gameBoard[i][0].fill == 2)? '2' : ' ')),
                ((gameBoard[i][1].left)? '|' : ' '),   // or [i][0].right
                ((gameBoard[i][1].fill == 1)? '1' : ((gameBoard[i][1].fill == 2)? '2' : ' ')),
                ((gameBoard[i][2].left)? '|' : ' '),
                ((gameBoard[i][2].fill == 1)? '1' : ((gameBoard[i][2].fill == 2)? '2' : ' ')),
                ((gameBoard[i][2].right)? '|' : ' '));
        
        // for down
        printf(" + %c + %c + %c +\n", 
                ((gameBoard[i][0].down)? '-' : ' '),
                ((gameBoard[i][1].down)? '-' : ' '),
                ((gameBoard[i][2].down)? '-' : ' '));

    }
}

int main()
{
    box gameBoard[3][3];

    initializeGameBoard(gameBoard);
    printGameBoard(gameBoard);

    return 0;
}
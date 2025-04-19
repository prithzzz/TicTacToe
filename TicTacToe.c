#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int board[3][3]; 
const char Player = 'X';
const char Computer = 'O';

void resetBoard();
void printBoard();
int checkEmptySpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);

int main()
{
    char winner = ' ';

    resetBoard();

    while(winner == ' ' && checkEmptySpaces() != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkEmptySpaces() == 0)
        {
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkEmptySpaces() == 0)
        {
            break;
        }
    }
    
    printBoard();
    printWinner(winner);
    return 0;
}

void resetBoard()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}

int checkEmptySpaces()
{
    int freespace = 9;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (board[i][j] != ' ')
            {
                freespace--;
            }
        }
    }
    return freespace;
}

void playerMove()
{
    int x,y;
    do
    {
        printf("Enter row(1-3):");
        scanf("%d",&x);
        x--;
        printf("Enter column(1-3):");
        scanf("%d",&y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!");
        }
        else
        {
            board[x][y] = Player;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{

}

char checkWinner()
{
    //checking rows
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] || board[i][0] == board[i][1])
        {
            //before continuing, connect with github!!
        }

    }
}

void printWinner(char winner)
{
    if(winner == Player)
    {
        printf("You WIN!\n");
    }
    else if(winner == Computer)
    {
        printf("You LOSE!\n");
    }
    else
    {
        printf("It's a Draw!\n");
    }
}

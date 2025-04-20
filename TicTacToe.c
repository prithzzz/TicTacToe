#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    int response;
    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();
        printf("\nWelcome to Tic Tac Toe!\n");
        printf("You are 'X' and the computer is 'O'\n");

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

        printf("Do you want to play again?(Y/N):");
        scanf(" %c",&response);
        response = toupper(response);
        
    } while(response == 'Y');

    printf("Thanks for playing!\n");

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
            printf("Invalid move!\n");
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
    srand(time(0));
    int x,y;
    while(board[x][y] != ' ')
    {
        x = rand() % 3;
        y = rand() % 3;
    }
    board[x][y] = Computer;
}

char checkWinner()
{
    //checking rows
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //checking columns
    for(int i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //checking diagnols
    for(int i=0; i<3; i++)
    {
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
    }
    for(int i=0; i<3; i++)
    {
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
    }
    return ' ';
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

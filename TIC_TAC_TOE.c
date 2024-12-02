#include <stdio.h>
#include <stdlib.h>
char board[3][3] = {
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
};
int count = 0;

void FillBoard(char user_x)
{
    int i, j, pos;
    int bound = 1;

    while (bound)
    {

        printf("enter pos for '%c': ", user_x, pos);
        scanf("%d", &pos);

        bound = 0;
        if (pos == 1)
        {
            i = 0;
            j = 0;
        }

        else if (pos == 2)
        {
            i = 0;
            j = 1;
        }

        else if (pos == 3)
        {
            i = 0;
            j = 2;
        }

        else if (pos == 4)
        {
            i = 1;
            j = 0;
        }

        else if (pos == 5)
        {
            i = 1;
            j = 1;
        }

        else if (pos == 6)
        {
            i = 1;
            j = 2;
        }

        else if (pos == 7)
        {
            i = 2;
            j = 0;
        }

        else if (pos == 8)
        {
            i = 2;
            j = 1;
        }

        else if (pos == 9)
        {
            i = 2;
            j = 2;
        }
        else
        {
            printf("Invalid Position ---- please enter a valid position\n\n");
            bound = 1;
        }
    }
    if (board[i][j] == ' ')
    {
        board[i][j] = user_x;
        count++;
    }
    else
        printf("\nPLACE IS OCCUPIED...\n");
}

int CheckWin(char u)
{
    if ((board[0][0] == u && board[0][1] == u && board[0][2] == u) || (board[1][0] == u && board[1][1] == u && board[1][2] == u) ||
        (board[2][0] == u && board[2][1] == u && board[2][2] == u) ||
        (board[0][0] == u && board[1][0] == u && board[2][0] == u) || (board[0][1] == u && board[1][1] == u && board[2][1] == u) ||
        (board[0][2] == u && board[1][2] == u && board[2][2] == u) ||
        (board[0][0] == u && board[1][1] == u && board[2][2] == u))
    {
        printf("Game is won by player %c", u);
        return 3;
    }
    else
        return 0;
}

void PrintBoard()
{
    printf("\n<--Board State-->\n\n");
    printf(" %c  ||  %c  ||  %c\n", board[0][0], board[0][1], board[0][2]);
    printf("------------------\n");
    printf(" %c  ||  %c  ||  %c\n", board[1][0], board[1][1], board[1][2]);
    printf("------------------\n");
    printf(" %c  ||  %c  ||  %c\n\n", board[2][0], board[2][1], board[2][2]);
}

int main()
{

    printf("\n<--Board Configuration-->\n\n");
    printf(" 1  ||  2  || 3 \n");
    printf("------------------\n");
    printf(" 4  ||  5  || 6 \n");
    printf("------------------\n");
    printf(" 7  ||  8  || 9 \n\n");

    int c = 0, k = 0;
    while (c < 9 && k != 3) //  x --> 1st user     0 --> 2nd user
    {
        if ((count % 2) != 0)
        {
            FillBoard('0');
            PrintBoard();
            if (count >= 5)
                k = CheckWin('0');
        }

        else
        {
            FillBoard('X');
            PrintBoard();
            if (count >= 5)
                k = CheckWin('X');
        }
        c++;
    }
    if (k == 0)
        printf("Game is draw");

    return 0;
}
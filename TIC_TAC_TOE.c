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
    int i, j;
    printf("enter ith and jth pos for '%c': ", user_x);
    scanf("%d %d", &i, &j);
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

/*void PrintBoard()
{
    printf("\n<--Board State-->\n\n");
for(int i=0;i<3;i++)
{
  for(int j=0;j<3;j++)
  printf("%c     ",board[i][j]);
  printf("\n\n");
}
}*/

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
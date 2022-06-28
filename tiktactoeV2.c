#include <unistd.h>
#include <stdio.h>
#include <time.h>

void printBoard(char array[])
{
    int temp[];
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        printf("  %c  |  %c  |  %c\n", array[count], array[count + 1], array[count + 2]);
        
        if(i < 2)
        {
            printf("--------------------\n");
        }
        
        count = count + 3;
    }
}

void makePlayerMoves(int array[], int playerMark, int place)
{
    if(array[place] == 32)
    {
        array[place] = playerMark;
        if(checkforWin(array) == 1)
        {
            exit(1);
        }
    }
    else
    {
        while(array[place] != 32)
        {
            printf("Space Already Occupied. Please choose a different space\n");
            scanf("%d", space);
        }
        
        array[place] = playerMark;
    }
}

void makeCPUMoves(int array[], int cpuMark)
{
    int r = rand() % 9;
    
    if(array[r] == 32)
    {
        array[r] = cpuMark;
        if(checkforWin(array) == 1)
        {
            exit(1);
        }
    }
    else
    {
        while(array[r] != 32)
        {
            r = rand() % 9;
        }
        
        array[r] = cpuMark;
    }
}

int checkforWin(int array[])
{
    switch (array)
    {
     case (array[0] == 88 && array[1] == 88 && array[2] == 88) || (array[0] == 79 && array[1] == 79 && array[2] == 79):
        printf("%c Wins!", array[0]);
        return 1;
     ;
     case (array[3] == 88 && array[4] == 88 && array[5] == 88) || (array[3] == 79 && array[4] == 79 && array[5] == 79):
        printf("%c Wins!", array[3]);
        return 1;
     ;
     case (array[6] == 88 && array[7] == 88 && array[8] == 88) || (array[6] == 79 && array[7] == 79 && array[8] == 79):
        printf("%c Wins!", array[6]);
        return 1;
     ;
     
     
     
     case (array[0] == 88 && array[4] == 88 && array[8] == 88) || (array[0] == 79 && array[4] == 79 && array[8] == 79):
        printf("%c Wins!", array[0]);
        return 1;
     ;
     case (array[2] == 88 && array[4] == 88 && array[6] == 88) || (array[2] == 79 && array[4] == 79 && array[6] == 79):
        printf("%c Wins!", array[0]);
        return 1;
     ;
     
     
     
     case (array[0] == 88 && array[3] == 88 && array[6] == 88) || (array[0] == 79 && array[3] == 79 && array[6] == 79):
        printf("%c Wins!", array[0]);
        return 1;
     ;
     case (array[1] == 88 && array[4] == 88 && array[7] == 88) || (array[1] == 79 && array[4] == 79 && array[7] == 79):
        printf("%c Wins!", array[3]);
        return 1;
     ;
     case (array[2] == 88 && array[5] == 88 && array[8] == 88) || (array[2] == 79 && array[5] == 79 && array[8] == 79):
        printf("%c Wins!", array[6]);
        return 1;
     ;
    }
    
    return 0;
}


int main()
{
    
    srand(time(NULL));
    
    printf("Welcome to the game of Tik-Tac-Toe!\n");
    printf("Here is the board we will be using today!\n");
    printf("\n");
    int spaces[] = {32,32,32,32,32,32,32,32,32};
    printBoard(spaces);
    
    printf("The board is laid out like so...\n");
    printf("\n");
    printf("  0  |  1  |  2  \n");
    printf("-----------------\n");
    printf("  3  |  4  |  5  \n");
    printf("-----------------\n");
    printf("  6  |  7  |  8  \n");
    
    printf("\n");
    printf("When prompted, select the number of the space in which you would like to place your mark\n");
    printf("Speaking of marks, would you like to be X or O?\n");
    
    char c;
    int playerMark;
    int cpuMark;
    
    scanf("%c", c);
    if( c == 'X' || c == 'x')
    {
        printf("You are now X\n");
        playerMark = 88;
    }
    else if( c == 'O' || c == 'o')
    {
        printf("You are now O\n");
        playerMark = 79;
    }
    else
    {
        printf("Invalid Selection. Please try again\n");
        while(c != 'O' || c != 'X' || c != 'x' || c != 'o')
        {
            if(c == 'X' || c == 'x')
            {
                printf("You are now X\n");
                playerMark = 88;
            }
            else if( c == 'O' || c == 'o')
            {
                printf("You are now O\n");
                playerMark = 79;
            }
        }
    }
    
    if(c == 'X' || c == 'x')
    {
        printf("The CPU will be O\n");
        cpuMark = 79;
    }
    else
    {
        printf("The CPU will be X\n");
        cpuMark = 88;
    }
    
    printf("Time to Play! You get first move. Where would you like to put your mark?\n");
    int place;
    
    scanf("%d", place);
    

    return 0;
}
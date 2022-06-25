#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/// Enum of Message
enum MessageEntry
{
    StartMessage1 = 1,
    TippMessage = 2,
    GiveUpMessage = 3,
    StartMessage2 = 4,
    OriginalError = 5,
    WrongInputError = 6,
    SuccessMessage = 7,
};

/// print out the Message
void PrintfMessage(int MessageInput,int X,int Y)
{
    switch(MessageInput)
    {
        case 1:
            printf("  Please use arrow keyword to move your cursor and press [enter] to select your position.\n  ----- Space ----- : Tipp | ----- Tab ----- : give up | ----- c ----- : Save");
            break;
        case 2:
            printf("X: %d\tY: %d\nHere sould be number %d.",X,Y);
            break;
        case 3:
            printf("\n  you gave up!");
            break;
        case 4:
            printf("\n  Please press [enter] to select your position your wannt to change.\n  ----- Space ----- : Tipp | ----- Tab ----- : give up | ----- c ----- : Save");
            break;
        case 5:
            printf("X: %d,Y: %d\n  it is an original number which can not be changed.",X,Y);
            break;
        case 6:
            printf("\n\n  It is Wrong Input. Please try again!");
            break;
        case 7:
            printf("Conguration on your success!");
            break;
    }
}

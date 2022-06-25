#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "notice.h"
#include "consolesetting.h"
#include "algorithm.h"

int MapToGiven[9][9];

/**
 * @brief To format and print out the map.
 * @param UserInput : the orientation which user typed in.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 */
void MoveHandle(int UserInput,HANDLE *hOut,COORD *pos)
{
    switch(UserInput=getch())
    {
        case 72:
            /// the cursor must be insider the map
            if(pos->Y<=1)
            {
                break;
            }else{
                pos->Y = pos->Y - 2;
                SetConsoleCursorPosition(*hOut, *pos);
                break;
            }
        case 80:
            /// the cursor must be insider the map
            if(pos->Y>=17)
            {
                break;
            }else{
                pos->Y = pos->Y + 2;
                SetConsoleCursorPosition(*hOut, *pos);
                break;
            }
        case 75:
            /// the cursor must be insider the map
            if(pos->X<=4)
            {
                break;
            }else{
                pos->X = pos->X - 4;
                SetConsoleCursorPosition(*hOut, *pos);
                break;
            }
        case 77:
            /// the cursor must be insider the map
            if(pos->X>=36)
            {
                break;
            }else {
                pos->X = pos->X + 4;
                SetConsoleCursorPosition(*hOut, *pos);
                break;
            }
        default:
            break;
         }
}

/**
 * @brief To give user a tipp at current position.
 * @param X,Y : X and Y axis of console.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param ResultMap : to be used to find out the result in current position.
 */
void TippHandle(int X,int Y,HANDLE *hOut,COORD *pos,int ResultMap[9][9])
{
    int ConvertX;
    int ConvertY;

    X = pos->X;
    Y = pos->Y;

    pos->X = 42;
    pos->Y = 1;
    SetConsoleCursorPosition(*hOut, *pos);

    printf("X: %d\tY: %d\n",X,Y);

    pos->X = 42;
    pos->Y = 2;
    SetConsoleCursorPosition(*hOut, *pos);

    /// X and Y console axis will be transformed into map axis with form (Y-1)/2 and (X-4)/4).
    printf("Here sould be number %d.",ResultMap[((Y-1)/2)][((X-4)/4)]);

    pos->X = X;
    pos->Y = Y;

    SetConsoleCursorPosition(*hOut, *pos);
}

/**
 * @brief To give up game and print out the final result in map.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param ResultMap : to be used to find out the result in current position.
 * @param Map : current playing map.
 * @param OriginalMap : to compared with result map.
 */
int GiveUpHandle(HANDLE *hOut,COORD *pos,int Map[9][9],int OriginalMap[9][9])
{
    system("cls");

    pos->X = 0;
    pos->Y = 19;
    SetConsoleCursorPosition(*hOut, *pos);

    PrintfMessage(3,0,19);

    pos->X = 0;
    pos->Y = 0;
    SetConsoleCursorPosition(*hOut, *pos);

    SolveSoduku(Map);

    PrintMap(Map,OriginalMap,hOut);

    printf("\n\n\n  please press esc to exit...");

    system("pause");

    return 1;

}

/**
 * @brief In this function all check and invalidate logic of soduku will happen.
 * @param X,Y : X and Y axis of console.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param ResultMap : to be used to find out the result in current position.
 * @param Map : current playing map.
 * @param OriginalMap : to compared with result map.
 * @param Number : the value user typed in.
 * @param InvalidateNumber : to check if the value is legal or not.
 */
int GameHandle(int X,int Y,HANDLE *hOut,COORD *pos,int Map[9][9],int ResultMap[9][9],int OriginalMap[9][9],int Number,int InvalidateNumber,int Winn)
{

    /// prepare for save and output the game as txt file.
    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j< 9 ; j++)
        {
            MapToGiven[i][j] = Map[i][j];
        }
    }

    system("cls");

    PrintMap(Map,OriginalMap,hOut);

    X = pos->X;
    Y = pos->Y;

    pos->X = 0;
    pos->Y = 22;
    SetConsoleCursorPosition(*hOut, *pos);

    PrintfMessage(4,0,22);

    pos->X = 2;
    pos->Y = 20;
    SetConsoleCursorPosition(*hOut, *pos);

    /// to check if there,where the position that user typed in, is a original number. if yes, print out the error.
    if(OriginalMap[((Y-1)/2)][((X-4)/4)]!=0)
    {

        PrintfMessage(5,X,Y);

        pos->X = X;
        pos->Y = Y;

        SetConsoleCursorPosition(*hOut, *pos);
        return;
    }

    printf("Please enter your value:\t");

    scanf("%d",&Number);

    /// user function CheckNumber to check if the value is legal or not.
    InvalidateNumber = CheckNumber(Number,((X-4)/4),((Y-1)/2),Map);

    printf("InvalidateNumber is : %d",InvalidateNumber);

    /// if the value is not legal, then print out the error.
    if(InvalidateNumber == 1)
    {
        system("cls");

        PrintMap(Map,OriginalMap,hOut);

        pos->X = 0;
        pos->Y = 19;
        SetConsoleCursorPosition(*hOut, *pos);

        PrintfMessage(6,0,19);

        pos->X = 0;
        pos->Y = 22;
        SetConsoleCursorPosition(*hOut, *pos);

        PrintfMessage(4,0,22);
    }
    /// if the value is legal, then records it in current position.
    else
    {
        /// here will the axis be transformed.
        Map[((Y-1)/2)][((X-4)/4)] = Number;

        MapToGiven[((Y-1)/2)][((X-4)/4)] = Number;

        /// here with CheckForWinn function will be checked if winn or not.
        Winn = CheckForWinn(Map);

        if(Winn == 0)
        {
            system("cls");

            PrintMap(Map,OriginalMap,hOut);

            pos->X = 0;
            pos->Y = 22;
            SetConsoleCursorPosition(*hOut, *pos);

            PrintfMessage(4,0,22);
        }
        else
        {
            system("cls");

            PrintMap(Map,OriginalMap,hOut);

            pos->X = 0;
            pos->Y = 19;
            SetConsoleCursorPosition(*hOut, *pos);

            printf("Conguration on your success!");

            return 1;
        }
    }
    pos->X = X;
    pos->Y = Y;
    SetConsoleCursorPosition(*hOut, *pos);
    return 0;
}

/**
 * @brief To save the records of user as txt file and output.
 * @param X,Y : X and Y axis of console.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param Username : the filename which will be saved.
 * @param Map : current playing map.
 * @param OriginalMap : to compared with result map.
 */
int SaveGame(int X,int Y,char UserName[50],int Map[9][9],int OriginalMap[9][9],HANDLE *hOut,COORD *pos)
{
    int Save;
    int ReturnToMainMenu = 0;

    X = pos->X;
    Y = pos->Y;

    pos->X = 42;
    pos->Y = 10;
    SetConsoleCursorPosition(*hOut, *pos);

    printf("do you really want to save game?");

    pos->X = 42;
    pos->Y = 11;
    SetConsoleCursorPosition(*hOut, *pos);

    printf("Y : Save and Exit, N : No");

    pos->X = 42;
    pos->Y = 12;
    SetConsoleCursorPosition(*hOut, *pos);

    SetConsoleTextAttribute(*hOut, FOREGROUND_INTENSITY);

    switch(Save=getch())
    {
        case 121:
            SaveMapAsTxT(UserName,MapToGiven,OriginalMap);
            ReturnToMainMenu = 1;
            break;
        case 110:
            pos->X = X;
            pos->Y = Y;
            SetConsoleCursorPosition(*hOut, *pos);
            return ;
            break;
    }

    return ReturnToMainMenu;
}


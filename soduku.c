#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "map.h"
#include "algorithm.h"
#include "movement.h"
#include <time.h>
#include "menu.h"
#include <dirent.h>

/// Gobal Varibales definition
HANDLE hOut;
COORD pos;
clock_t begin;
clock_t end;
double cost;
int Map[9][9];
char UserName[50];
int OriginalMap[9][9];
int ResultMap[9][9];
int InvalidateNumber = 0;
int UserInput;
int X;
int Y;
int Number;
int Winn;


/**
 * @brief In this function the windows console Handle will be instantiated
 */
void GetConsoleInstance()
{
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

/**
 * @brief This function will start the timer for user.
 */
void TimeStart()
{
    begin = clock();
}

/**
 * @brief This function will end the timer for user and print the time spent after every action of user.
 */
void TimeEnd(int X,int Y,HANDLE *hOut,COORD *pos)
{
    X = pos->X;
    Y = pos->Y;

    end = clock();
    cost = (double)(end - begin)/CLOCKS_PER_SEC;

    pos->X = 42;
    pos->Y = 5;

    SetConsoleCursorPosition(*hOut, *pos);
    SetConsoleTextAttribute(*hOut,FOREGROUND_RED);
    printf("Time spent: %lf",cost);

    pos->X = X;
    pos->Y = Y;

    SetConsoleCursorPosition(*hOut, *pos);
}

/**
 * @brief Once "1.New   Game" in main menu was selected, this function will be called.
 * @brief This function will start a new game and get username and load new suduko map.
 */
void StartNewGame()
{
    GetConsoleInstance();

    MovePosition(0,19,&hOut,&pos);

    printf("  please enter your name :\t");

    scanf("%s",&UserName);

    MovePosition(0,0,&hOut,&pos);

    system("cls");

    if(UserName!="\0")
    {
        StartGame(1,UserName);
    }
}

/**
 * @brief Once "2.Load   Game" in main menu was selected, this function will be called.
 * @brief This function will load all stored soduku maps in "maps" folder, and user can select any map by inputing filename.
 */
void LoadGame()
{
    DIR *d;
    struct dirent *dir;
    int index = 1;
    char filename[100];

    GetConsoleInstance();

    system("cls");

    printf(
        "\t\t                                        \n"
        "\t\t                                        \n"
        "\t\t****************************************\n"
        "\t\t*                                      *\n"
        "\t\t*          Welcome to Sudoku!          *\n"
        "\t\t*             made by Fu               *\n"
        "\t\t*                                      *\n"
        "\t\t*      Please select your Game :       *\n"
        );


    d = opendir("./maps/");

    if(d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("\t\t      %d. %s         \n",index,dir->d_name);
            index++;
        }
        closedir(d);
    }

    printf(

        "\t\t*                                      *\n"
        "\t\t****************************************\n"
        "\t\t                                        \n"
        "\t\tPlease enter your filename:\t"
    );

    scanf("%s",&filename);

    system("cls");

    StartGame(0,filename);

}

/**
 * @brief The real game main function starts here
 * @param NewGameRequired : This parameter is used to specify whether to generate new game or load stored old game.
 * @param filename : if in "new game" this parameter will be the username user entered,
 *                   if in "load game" this parameter will be the old filename user selected.
 */
void StartGame(int NewGameRequired,char filename[100])
{

    /// Generate soduku Map and also original Map, which will be used to compare with the input value of user.
    fillMap(NewGameRequired,filename,Map,OriginalMap,ResultMap);

    /// Format and print the soduku map which user can formally play.
    InitMap(Map,&hOut,OriginalMap);

    /// Solve the soduku map to get the final result.
    SolveSoduku(ResultMap);

    /// Move the cursor.
    MovePosition(0,22,&hOut,&pos);

    /// Print Message.
    PrintfMessage(1,pos.X,pos.Y);

    /// Move the cursor.
    MovePosition(4,1,&hOut,&pos);

    /// Start timer.
    TimeStart();

    /// in this loop all input value for soduku map will be read.
    while( (UserInput=getch())!= 27 ) /// 27 is ESC.
    {
        switch(UserInput)
        {
            case 0xE0:
                /// if "(0xE0)" was pressed, then the function MoveHandle will be called to handle arrow cursor action.
                MoveHandle(UserInput,&hOut,&pos);
                break;
            case 32:
                /// if "Space" was pressed, then the function TippHandle will be called to give user a tipp at current position.
                TippHandle(X,Y,&hOut,&pos,ResultMap);
                break;
            case 9:
                /// if "Tab" was pressed, then the function GiveUphandle will be called which means the user has given up the game.
                /// and print the result.
                if (GiveUpHandle(&hOut,&pos,Map,OriginalMap)==1)
                {
                    system("cls");
                    /// turn back to main menu.
                    Start();
                }
                break;
            case 0x0d:
                /// Here the real logic check and validate of soduku self will happen.
                /// The inputed value from user will be check if this is a legal value.
                if (GameHandle(X,Y,&hOut,&pos,Map,ResultMap,OriginalMap,Number,InvalidateNumber,Winn)==1)
                {
                    system("cls");
                    /// turn back to main menu.
                    Start();
                }
                break;
            case 99:
                /// if "Tab" was pressed, then the function SaveGame will be called to save the current map as txt file.
                if(SaveGame(X,Y,filename,Map,OriginalMap,&hOut,&pos)==1)
                {
                    system("cls");
                    Start();
                }
                break;
            default:
                break;
        }


        /// End timer.
        TimeEnd(X,Y,&hOut,&pos);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "loadgame.h"
#include "RandomNummer.h"


/**
 * @brief To Generate soduku Map and also original Map, which will be used to compare with the input value of user.
 * @param filename : if in "new game" this parameter will be the username user entered,
 *                   if in "load game" this parameter will be the old filename user selected.
 * @param Map : The map where user will formally play.
 * @param OriginalMap : The map which will be compared with user input.
 * @param ResultMap : The result map.
 */
void fillMap(int NewGameRequired,char filename[100],int Map[9][9],int OriginalMap[9][9],int ResultMap[9][9])
{
    int TestMap[9][9];

    if(NewGameRequired == 1)/// "new game"
    {
        GenerateRandomNummer(TestMap);

    }else if(NewGameRequired == 0)/// "load game"
    {
        if (ReadMapFromFile(filename,TestMap)==0)
        {
            system("pause");
            LoadGame();
            return;
        }
    }

    /// assign original value to Map, Original Map, ResultMap.
    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j< 9 ; j++)
        {
            OriginalMap[i][j] = TestMap[i][j];
            Map[i][j] = TestMap[i][j];
            ResultMap[i][j] = TestMap[i][j];
        }
    }
}

/**
 * @brief To Init soduku map.
 * @param Map : The map where user will formally play.
 * @param hOut : the instance of windows console.
 * @param OriginalMap : The map which will be compared with user input.
 */
void InitMap(int Map[9][9],HANDLE *hOut,int OriginalMap[9][9])
{
    for(unsigned int i = 0; i < 9; i++)
    {
        if(i%3==0)
        {
            printf("  +-----------+-----------+-----------+\n");
        }

        for(unsigned int j = 0; j< 9 ; j++)
        {
            /// the input of user will be red. the original position will be default color.
            if(OriginalMap[i][j]==Map[i][j])
            {
                if(j==0)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf("  | %d  ",Map[i][j]);
                }else if(j==8)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    if(i==2||i==5||i==8)
                    {
                        printf(" %d |",Map[i][j]);
                    }else
                    {
                        printf(" %d |\n",Map[i][j]);
                    }

                }else if(j==2||j==5)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf(" %d |",Map[i][j]);
                }else
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf(" %d  ",Map[i][j]);
                }
            }else {

                if(j==0)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf("  | %d  ",Map[i][j]);
                }else if(j==8)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    if(i==2||i==5||i==8)
                    {
                        printf(" %d |",Map[i][j]);
                    }else
                    {
                        printf(" %d |\n",Map[i][j]);
                    }

                }else if(j==2||j==5)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf(" %d |",Map[i][j]);
                }else
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf(" %d  ",Map[i][j]);
                }
            }
        }
        printf("\n");
    }

    printf("  +-----------+-----------+-----------+\n");
}

/**
 * @brief To format and print out the map.
 * @param Map : The map where user will formally play.
 * @param hOut : the instance of windows console.
 * @param OriginalMap : The map which will be compared with user input.
 */
void PrintMap(int Map[9][9],int OriginalMap[9][9],HANDLE *hOut)
{
    for(unsigned int i = 0; i < 9; i++)
    {
        if(i%3==0)
        {
            printf("  +-----------+-----------+-----------+\n");
        }


        for(unsigned int j = 0; j< 9 ; j++)
        {
            if(OriginalMap[i][j]!=Map[i][j])
            {
                if(j==0)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_RED);
                    printf("  | %d  ",Map[i][j]);
                }else if(j==8)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_RED);
                    if(i==2||i==5||i==8)
                    {
                        printf(" %d |",Map[i][j]);
                    }else
                    {
                        printf(" %d |\n",Map[i][j]);
                    }

                }else if(j==2||j==5)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_RED);
                    printf(" %d |",Map[i][j]);
                }else
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_RED);
                    printf(" %d  ",Map[i][j]);
                }
            }else {

                if(j==0)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf("  | %d  ",Map[i][j]);
                }else if(j==8)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    if(i==2||i==5||i==8)
                    {
                        printf(" %d |",Map[i][j]);
                    }else
                    {
                        printf(" %d |\n",Map[i][j]);
                    }

                }else if(j==2||j==5)
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf(" %d |",Map[i][j]);
                }else
                {
                    SetConsoleTextAttribute(*hOut,FOREGROUND_INTENSITY);
                    printf(" %d  ",Map[i][j]);
                }
            }
        }
        printf("\n");
    }

    printf("  +-----------+-----------+-----------+\n");
}


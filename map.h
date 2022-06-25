#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief To Generate soduku Map and also original Map, which will be used to compare with the input value of user.
 * @param filename : if in "new game" this parameter will be the username user entered,
 *                   if in "load game" this parameter will be the old filename user selected.
 * @param Map : The map where user will formally play.
 * @param OriginalMap : The map which will be compared with user input.
 * @param ResultMap : The result map.
 */
void fillMap(int NewGameRequired,char filename[100],int Map[9][9],int OriginalMap[9][9],int ResultMap[9][9]);

/**
 * @brief To Init soduku map.
 * @param Map : The map where user will formally play.
 * @param hOut : the instance of windows console.
 * @param OriginalMap : The map which will be compared with user input.
 */
void InitMap(int Map[9][9],HANDLE *hOut,int OriginalMap[9][9]);

/**
 * @brief To format and print out the map.
 * @param Map : The map where user will formally play.
 * @param hOut : the instance of windows console.
 * @param OriginalMap : The map which will be compared with user input.
 */
void PrintMap(int Map[9][9],int OriginalMap[9][9],HANDLE *hOut);

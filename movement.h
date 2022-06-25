#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief To format and print out the map.
 * @param UserInput : the orientation which user typed in.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 */
void MoveHandle(int UserInput,HANDLE *hOut,COORD *pos);

/**
 * @brief To give user a tipp at current position.
 * @param X,Y : X and Y axis of console.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param ResultMap : to be used to find out the result in current position.
 */
void TippHandle(int X,int Y,HANDLE *hOut,COORD *pos,int ResultMap[9][9]);

/**
 * @brief To give up game and print out the final result in map.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param ResultMap : to be used to find out the result in current position.
 * @param Map : current playing map.
 * @param OriginalMap : to compared with result map.
 */
int GiveUpHandle(HANDLE *hOut,COORD *pos,int Map[9][9],int OriginalMap[9][9]);

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
int GameHandle(int X,int Y,HANDLE *hOut,COORD *pos,int Map[9][9],int ResultMap[9][9],int OriginalMap[9][9],int Number,int InvalidateNumber,int Winn);

/**
 * @brief To save the records of user as txt file and output.
 * @param X,Y : X and Y axis of console.
 * @param hOut : the instance of windows console.
 * @param pos :  the instance of windows console position to move cursor.
 * @param Username : the filename which will be saved.
 * @param Map : current playing map.
 * @param OriginalMap : to compared with result map.
 */
int SaveGame(int X,int Y,char UserName[50],int Map[9][9],int OriginalMap[9][9],HANDLE *hOut,COORD *pos);

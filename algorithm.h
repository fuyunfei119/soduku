#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief To check if map has un legal value
 * @param Map : the current played Map.
 * @param i,j : rows and columns.
 */
int validate(int x[9][9], int i, int j, int num);


/**
 * @brief To solve the current soduku and print out it in current map.
 * @param Map : the current played Map.
 */
void SolveSoduku(int x[9][9]);

/**
 * @brief To check if there is a same nummer in the same 3 x 3 block.
 * @param Map : the current played Map.
 * @param BlockStartX,BlockStartY : the axis of current block in map.
 * @param Number : the Number that user typed in.
 */
int CheckBlock(int BlockStartY,int BlockEndY,int BlockStartX,int BlockEndX,int Number,int Map[9][9]);

/**
 * @brief To check if the typed value from user is legal or not.
 * @param Map : the current played Map.
 * @param X,Y : the axis of current position in map.
 * @param Number : the Number that user typed in.
 */
int CheckNumber(int Number,int X,int Y,int Map[9][9]);

/**
 * @brief To check if the user has won or not.
 * @param Map : the current played Map.
 */
int CheckForWinn(int Map[9][9]);

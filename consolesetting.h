#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief To move cursor to target position.
 * @param X : X axis of console user want to move to.
 * @param Y : Y axis of console user want to move to.
 * @param hOut : Instance of windos console
 * @param pos  : Instance of console position
 */
void MovePosition(int X,int Y,HANDLE hOut,COORD pos);

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
 * @brief To check if map has un legal value
 * @param Map : the current played Map.
 * @param i,j : rows and columns.
 */
int validate(int x[9][9], int i, int j, int num)
{
    int row, column;
    int isPossible = 1;

    /// iterate through row i to see if there are duplicate values
    for (column = 0; column < 9; column++)
    {
        if (num == x[i][column]) isPossible *= 0;
        else isPossible *= 1;
    }

    /// Iterate through column j to see if there are duplicate values
    for (row = 0; row < 9; row++)
    {
        if (num == x[row][j]) isPossible *= 0;
        else isPossible *= 1;
    }

    /// iterate through the palace(box) where x[i][i] is located to check if there are duplicate values
    int box_i, box_j;

    int offset_x, offset_y;

    /// Calculate the offset in the x-direction
    offset_x = j - j % 3;

    /// Calculate the offset in the y-direction
    offset_y = i - i % 3;

    for (box_i = 0; box_i < 3; box_i++)
    {
        for (box_j = 0; box_j < 3; box_j++)
        {
            /// correct box_i,box_j to the correct map
            if (num == x[box_i + offset_y][box_j + offset_x]) isPossible *= 0;
            else isPossible *= 1;
        }
    }
    /// If there is no error and return 1, otherwise return 0
    return isPossible;
}

/**
 * @brief To solve the current soduku and print out it in current map.
 * @param Map : the current played Map.
 */
void SolveSoduku(int x[9][9])
{
    int i, j, num, flag=0;

    /// Create a new 2d array to record the location of numbers
    int can_not_modify[9][9] = { 0 };

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (x[i][j] != 0) can_not_modify[i][j] = 1;
        }
    }

    /// initialize i and j
    i = 0;
    j = 0;

    /// Iterate through the nine-box grid, starting with x[0][0] and trying

    while (i < 9)
    {
        while (j < 9)
        {
            /// check if it is a trial and error jump from the previous line
            start:if (flag == 1 && j == -1)
            {
                i--;
                j = 8;
                goto start;
            }

            /// check if it is a trial and error jump and the current value cannot be modified
            else if (flag == 1 && can_not_modify[i][j] == 1)
            {
                /// Continue back to the previous level
                j--;
                continue;
            }
            /// determine if the current map is unmodifiable
            else if (can_not_modify[i][j] == 1)
            {
                j++;
                continue;
            }
            /// Start trying
            else
            {
                num = x[i][j];
                /// If the current grid is not yet assigned, i.e. not jumped from the previous trial and error, try from 1
                if (num == 0) num = 1;
                /// If flag==1 is from the last trial and error, continue to try from the value of the last error+1
                else if (flag == 1) num = x[i][j] + 1;
                /// initialize the value of the jump identifier
                flag = 0;
                /// try one by one starting from num and working backwards
                for (; num <= 10; num++)
                {
                    /// use the validate function to determine if the attempted value is feasible
                    /// If it is possible to change the value of the current cell to num
                    if (validate(x, i, j, num) == 1 && num < 10)
                    {
                        x[i][j] = num;
                        j++;
                        break;
                    }
                    /// If no feasible value is filled in by 9, it means there is an error in the previous, the initial current value is 0,
                    /// return to the previous attempt
                    else if (num == 10)
                    {
                        x[i][j] = 0;
                        j--;
                        /// type the jump flag=1
                        flag = 1;
                        break;
                    }
                }
            }
        }
        /// Fill up one line and try again from the first of the next line
        j = 0;
        i++;
    }
}

/**
 * @brief To check if there is a same nummer in the same 3 x 3 block.
 * @param Map : the current played Map.
 * @param BlockStartX,BlockStartY : the axis of current block in map.
 * @param Number : the Number that user typed in.
 */
int CheckBlock(int BlockStartY,int BlockEndY,int BlockStartX,int BlockEndX,int Number,int Map[9][9])
{
    for(unsigned int h = BlockStartY; h<BlockEndY; h++)
    {
        for(unsigned int u = BlockStartX; u<BlockEndX; u++)
        {
            if(Map[h][u]==Number)
            {
                return 1;
            }
        }
    }
}

/**
 * @brief To check if the typed value from user is legal or not.
 * @param Map : the current played Map.
 * @param X,Y : the axis of current position in map.
 * @param Number : the Number that user typed in.
 */
int CheckNumber(int Number,int X,int Y,int Map[9][9])
{
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("X is: %d\n",X);
    printf("Y is: %d\n",Y);

    printf("Nummer %d\n", Number);

    if(Number == 0)
    {
        return 0;
    }

    /// the value can only between 0 to 9.
    if(Number < 0||Number >9)
    {
        return 1;
    }

    /// to check if there is a same nummer in the same column.
    for(unsigned int i = 0; i < 9; i++)
    {
        if(Map[Y][i] == Number)
        {
            return 1;
        }
    }

    /// to check if there is a same nummer in the same rows.
    for(unsigned int j = 0; j < 9; j++)
    {
        if(Map[j][X] == Number)
        {
            return 1;
        }
    }

    /// to check if there is a same nummer in the same 3 x 3 block.
    if(Y>=0&&Y<3)
    {
        if(X>=0&&X<3)
        {
            return CheckBlock(0,3,0,3,Number,Map);
        }

        if(X>=3&&X<6)
        {
            return CheckBlock(0,3,3,6,Number,Map);
        }

        if(X>=6&&X<9)
        {
            return CheckBlock(0,3,6,9,Number,Map);
        }
    }

    if(Y>=3&&Y<6)
    {
        if(X>=0&&X<3)
        {
            return CheckBlock(3,6,0,3,Number,Map);
        }

        if(X>=3&&X<6)
        {
            return CheckBlock(3,6,3,6,Number,Map);
        }

        if(X>=6&&X<9)
        {
            return CheckBlock(3,6,6,9,Number,Map);
        }
    }

    if(Y>=6&&Y<9)
    {
        if(X>=0&&X<3)
        {
            return CheckBlock(6,9,0,3,Number,Map);
        }

        if(X>=3&&X<6)
        {
            return CheckBlock(6,9,3,6,Number,Map);
        }

        if(X>=6&&X<9)
        {
            return CheckBlock(6,9,6,9,Number,Map);
        }
    }
    printf("\n");
}


/**
 * @brief To check if the user has won or not.
 * @param Map : the current played Map.
 */
int CheckForWinn(int Map[9][9])
{
    int IsStillZero = 1;

    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j< 9 ; j++)
        {
            if(Map[i][j]==0)
            {
                IsStillZero = 0;
            }
        }
    }

    return IsStillZero;
}

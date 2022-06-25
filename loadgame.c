#include <stdio.h>
#include <stdlib.h>

/**
 * @brief To switch Char data type to Integer type.
 * @param Number : the Number which wants to be changed.
 */
int SwtichCharToInteger(int Number)
{
    int Value;

    switch(Number)
    {
    case 48:
        Value = 0;
        break;
    case 49:
        Value = 1;
        break;
    case 50:
        Value = 2;
        break;
    case 51:
        Value = 3;
        break;
    case 52:
        Value = 4;
        break;
    case 53:
        Value = 5;
        break;
    case 54:
        Value = 6;
        break;
    case 55:
        Value = 7;
        break;
    case 56:
        Value = 8;
        break;
    case 57:
        Value = 9;
        break;
    default:
        break;
    }

    return Value;
}

/**
 * @brief With this function the stored map will be loaded from "maps" folder and be assigned into the current soduku map.
 * @param filename : the filename want to load.
 * @param array    : the array where the soduku from file will be read in.
 * @return ReadSuccess : check whether the file was successfully fund or not.
 */
int ReadMapFromFile(char filename[100],int array[9][9])
{
    char Number;
    int Value;
    char path[200];
    int ReadSuccess;

    /// the file path will be combined.
    sprintf(path,"./maps/%s.txt",filename);

    FILE *fp = fopen(path,"r");

    if(fp!=NULL)
    {
        /// here the array will be assigned.
        for(unsigned int i = 0; i < 9; i++)
        {
            for(unsigned int j = 0; j < 9; j++)
            {
                fscanf(fp,"%c",&Number);
                array[i][j] = SwtichCharToInteger((int)Number);
            }
         fscanf(fp,"\n");
        }
        ReadSuccess = 1;
    }else
    {
        printf("There is no file with this name!\n");
        ReadSuccess = 0;
    }

    fclose(fp);

    return ReadSuccess;
}

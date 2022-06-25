#include <stdio.h>
#include <stdlib.h>
/**
 * @brief In this function the played game will be saved as a txt file and out put.
 * @param Map : current playing map.
 * @param OriginalMap : to compared with result map.
 * @param Username : the filename.
 */
void SaveMapAsTxT(char UserName[50],int Map[9][9],int OriginalMap[9][9])
{
    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j< 9 ; j++)
        {
            printf("%d",Map[i][j]);
        }
    }

    char path[200];
    sprintf(path,"./maps/%s.txt",UserName);

    FILE * fp;

    fp = fopen(path,"w");

    for(unsigned int i = 0; i < 9; i++)
    {
        for(unsigned int j = 0; j< 9 ; j++)
        {
            fprintf(fp,"%d",Map[i][j]);
        }
    }

    fclose(fp);
}

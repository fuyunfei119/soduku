#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// simulate bool data type in c
typedef enum
{
    true=1, false=0
}bool;

/**
 * @brief To randomly remove some nummer in each rows of map.
 * @param Map : The map where user will formally play.
 */
void RandomRemoveNummerFromMap(int Map[9][9]);

/**
 * @brief To generate random soduku 2d array which just only can be once solved.
 * @param a : The map where user will formally play.
 */
void GenerateRandomNummer(int a[9][9]);

/**
 * @brief sub function of GenerateRandomNummer
 */
void rank(int *x, int *y);

/**
 * @brief sub function of GenerateRandomNummer
 */
bool check(int a[9][9], int n);



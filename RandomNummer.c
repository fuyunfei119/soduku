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
void (int Map[9][9])
{
    for (i = 0; i < 9; i++)
	{
	    /// random times remove
	    int randomtimes = rand() % 5;

	    for(int z = 0; z < randomtimes; z++)
        {
            /// remove nummer
            int randomofrows = rand() % 10;
            for (j = 0; j < 9; j++)
            {
                /// assign zero in this position
                Map[i][randomofrows] = 0;
            }
        }
	}
}

/**
 * It is a external function from another author. with that a random sudoku will be generate.
*/
void GenerateRandomNummer(int a[9][9])
{
	int *p[3][3], *m[3][6], *n[3][6], *r[9][4], *aa[9][9];
	int **q[9];
	int i, j, k, l, h, t, s = 0;
	void rank(int *x, int *y);
	bool check(int a[9][9], int n);
	srand((int)time(0));

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			p[i][j] = &a[i * 3 + 1][j * 3 + 1];
	for (k = 0; k < 9; k++)
		q[k] = &p[k / 3][k % 3];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 6; j++)
		{
			m[i][j] = &a[i * 3 + 1][2 * j - j / 2];
			n[i][j] = &a[2 * j - j / 2][i * 3 + 1];
		}
	for (k = 0; k < 9; k++)
		for (l = 0; l < 4; l++)
			r[k][l] = &a[(k / 3) * 3 + (l / 2) * 2][(k % 3) * 3 + (l % 2) * 2];
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			aa[i][j] = &a[i][j];
step1:
	for (i = 0; i < 9; i++)
	{
	next1:
		**q[i] = rand() % 10;
		if (**q[i] == 0)
			goto next1;
		for (j = 0; j < i; j++)
			if (**q[j] == **q[i])
				goto next1;
	}
step2:
	for (i = 0; i < 3; i++)
		for (j = 0; j < 6; j++)
		{
		next2:
			*m[i][j] = rand() % 10;
			if (*m[i][j] == 0)
				goto next2;
			for (k = 0; k < 3; k++)
				if (*m[i][j] == *p[i][k])
					goto next2;
			for (k = 0; k < j; k++)
				if (*m[i][j] == *m[i][k])
					goto next2;
			for (k = 0; k < i; k++)
				if (*m[i][j] == *m[k][j])
					goto step2;
		}
step3:
	for (i = 0; i < 3; i++)
	{
	next4:
		for (j = 0; j < 6; j++)
		{
		next3:
			*n[i][j] = rand() % 10;
			if (*n[i][j] == 0)
				goto next3;
			for (k = 0; k < 3; k++)
				if (*n[i][j] == *p[k][i])
					goto next3;
			for (k = 0; k < j; k++)
				if (*n[i][j] == *n[i][k])
					goto next3;
			for (l = 0; l < 2; l++)
			{
				if (*n[i][j] == *m[j / 2][i * 2 + l])
					goto next4;
			}
			for (k = 0; k < i; k++)
				if (*n[i][j] == *n[k][j])
					goto step3;
		}
	}
step4:
	for (i = 0; i < 3; i++)
	{
		for (h = 0; h < 2; h++)
		{
		next6:
			for (l = 0; l < 3; l++)
				for (j = 0; j < 2; j++)
				{
				next5:
					*r[i * 3 + l][h * 2 + j] = rand() % 10;
					if (*r[i * 3 + l][h * 2 + j] == 0)
						goto next5;
					if (*r[i * 3 + l][h * 2 + j] == **q[i * 3 + l])
						goto next5;
					for (k = 0; k < h * 2 + j; k++)
						if (*r[i * 3 + l][h * 2 + j] == *r[i * 3 + l][k])
							goto next5;
					for (k = 0; k < 2; k++)
					{
						if (*r[i * 3 + l][h * 2 + j] == *m[i][l * 2 + k])
							goto next5;
						if (*r[i * 3 + l][h * 2 + j] == *n[l][i * 2 + k])
							goto next5;
					}
					for (k = 0; k <= l * 3 + j * 2; k++)
						for (t = 0; t < k; t++)
							if (a[i * 3 + h * 2][k] == a[i * 3 + h * 2][t])
								goto next6;
				}
		}
	}
step5:
	for (i = 0; i < 3; i++)
	{
		if (check(a, i) == false)
		{
			for (j = 0; j < 9; j++)
			{
				rank(aa[j][i * 3], aa[j][i * 3 + 2]);
				if (check(a, i) == false)
					rank(aa[j][i * 3], aa[j][i * 3 + 2]);
				else if (check(a, i) == true)
					break;
			}
		}
		if (check(a, i) == false)
		{
			for (j = 0; j < 9; j++)
			{
				for (k = 8; k > j; k--)
				{
					rank(aa[j][i * 3], aa[j][i * 3 + 2]);
					rank(aa[k][i * 3], aa[k][i * 3 + 2]);
					if (check(a, i) == false)
					{
						rank(aa[j][i * 3], aa[j][i * 3 + 2]);
						rank(aa[k][i * 3], aa[k][i * 3 + 2]);
					}
					else if (check(a, i) == true)
						break;
				}
				if (check(a, i) == true)
					break;
			}
		}
		if (check(a, i) == false)
		{
			for (l = 0; l < 9; l++)
			{
				for (j = l + 1; j < 9; j++)
				{
					for (k = 8; k > j; k--)
					{
						rank(aa[l][i * 3], aa[l][i * 3 + 2]);
						rank(aa[j][i * 3], aa[j][i * 3 + 2]);
						rank(aa[k][i * 3], aa[k][i * 3 + 2]);
						if (check(a, i) == false)
						{
							rank(aa[l][i * 3], aa[l][i * 3 + 2]);
							rank(aa[j][i * 3], aa[j][i * 3 + 2]);
							rank(aa[k][i * 3], aa[k][i * 3 + 2]);
						}
						else if (check(a, i) == true)
							break;
					}
					if (check(a, i) == true)
						break;
				}
				if (check(a, i) == true)
					break;
			}
		}
		if (check(a, i) == false)
		{
			for (l = 0; l < 6; l++)
			{
				for (h = l + 1; h < 7; h++)
				{
					for (j = h + 1; j < 8; j++)
					{
						for (k = 8; k > j; k--)
						{
							rank(aa[l][i * 3], aa[l][i * 3 + 2]);
							rank(aa[h][i * 3], aa[h][i * 3 + 2]);
							rank(aa[j][i * 3], aa[j][i * 3 + 2]);
							rank(aa[k][i * 3], aa[k][i * 3 + 2]);
							if (check(a, i) == false)
							{
								rank(aa[l][i * 3], aa[l][i * 3 + 2]);
								rank(aa[h][i * 3], aa[h][i * 3 + 2]);
								rank(aa[j][i * 3], aa[j][i * 3 + 2]);
								rank(aa[k][i * 3], aa[k][i * 3 + 2]);
							}
							else if (check(a, i) == true)
								break;
						}
						if (check(a, i) == true)
							break;
					}
					if (check(a, i) == true)
						break;
				}
				if (check(a, i) == true)
					break;
			}
		}
		if (check(a, i) == false)
			goto step4;
	}

    RandomRemoveNummerFromMap(a);
}

/**
 * @brief sub function of GenerateRandomNummer
 */
void rank(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

/**
 * @brief sub function of GenerateRandomNummer
 */
bool check(int a[9][9], int n)
{
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < i; j++)
			if (a[i][n * 3] == a[j][n * 3])
				return false;
	return true;
}


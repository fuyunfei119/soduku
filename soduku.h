#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "map.h"
#include "algorithm.h"
#include "movement.h"

/**
 * @brief In this function the windows console Handle will be instantiated
 */
void GetConsoleInstance();

/**
 * @brief This function will start the timer for user.
 */
void TimeStart();

/**
 * @brief This function will end the timer for user and print the time spent after every action of user.
 */
void TimeEnd(int X,int Y,HANDLE *hOut,COORD *pos);

/**
 * @brief Once "1.New   Game" in main menu was selected, this function will be called.
 * @brief This function will start a new game and get username and load new suduko map.
 */
void StartNewGame();

/**
 * @brief Once "2.Load   Game" in main menu was selected, this function will be called.
 * @brief This function will load all stored soduku maps in "maps" folder, and user can select any map by inputing filename.
 */
void LoadGame();

/**
 * @brief The real game main function starts here
 * @param NewGameRequired : This parameter is used to specify whether to generate new game or load stored old game.
 * @param filename : if in "new game" this parameter will be the username user entered,
 *                   if in "load game" this parameter will be the old filename user selected.
 */
void StartGame();

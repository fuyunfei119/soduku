#include <stdio.h>
#include "soduku.h"

/**
 * @brief To print the main menu.
 */
void LoadMainMenu()
{

    printf(
        "\t\t                                        \n"
        "\t\t                                        \n"
        "\t\t****************************************\n"
        "\t\t*                                      *\n"
        "\t\t*          Welcome to Sudoku!          *\n"
        "\t\t*             made by Fu               *\n"
        "\t\t*                                      *\n"
        "\t\t*      Please select your option:      *\n"
        "\t\t*      1. New              Game        *\n"
        "\t\t*      2. Load             Game        *\n"
        "\t\t*      3. Exit             Sudoku      *\n"
        "\t\t*                                      *\n"
        "\t\t****************************************\n"
        "\t\t                                        \n"
        "\t\tPlease enter your selection:\t"
    );
}

/**
 * @brief To get seleced option of user and go to next function.
 * @param BreakMenuLoop This parameter is used to end the loop of reading option of user after valid input.
 */
void ReadOptionOfUser(int BreakMenuLoop)
{
    int OptionOfUser;


    /// Reading Option of user
    scanf("%d",&OptionOfUser);

    system("cls");

    switch(OptionOfUser)
        {
        case(1):
            /**
             *If the user selects 1 then enter the function StartNewGame()
             */
            StartNewGame();
            BreakMenuLoop = 0;
            break;
        case(2):
            /**
             * If the user selects 2 then enter the function LoadGame()
             */
            LoadGame();
            BreakMenuLoop = 0;
            break;
        case(3):
            /**
             * If the user selects 3 then finish the program
             */
            exit(0);
            break;
        default:
            /**
             * All other inputs are considered invalid
             */
            system("cls");
            printf("\n\n\t\tWarning! Unknown Option. Please select available Option!\n");
        }
}



/**
 * @brief With this function the game gets started
 */
void Start()
{
    int UserInput;
    int BreakMenuLoop = 1;

    /// In this loop the user will be asked to select a function,
    /// once a function is selected the loop will be finished and come to next function
    do {
        LoadMainMenu();

        ReadOptionOfUser(BreakMenuLoop);

    }while(BreakMenuLoop);

}


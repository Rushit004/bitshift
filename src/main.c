#include <stdio.h>
#include <stdlib.h>

// Connecting the headers from the include/ directory

#include "../include/calculator.h"
#include "../include/converter.h"


int main()
{
    int choice;
    while (1)
    {
        printf("\n====================================\n");
        printf("       NUMBER SYSTEM TOOLKIT\n");
        printf("====================================\n");
        printf(" 1. Convert Number\n");
        printf(" 2. Calculator\n");
        printf(" 3. Exit\n");
        printf("====================================\n");
        printf(" Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (choice == 3)
        {

            printf("Thank you for using Number System Toolkit!\n");
            printf("================================\n");

            break;
        }

        switch (choice)
        {
        case 1:
            system("cls");
            ConverterModule();
            break;
        case 2:
            system("cls");
            CalculatorModule();
            break;

        default:
            printf("Invalid Choice Try again.\n");
        }
    }

    return 0;
}
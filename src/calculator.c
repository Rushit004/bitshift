#include <stdio.h>
#include "../include/calculator.h"
#include "../include/converter.h"

double performCalculation(double num1, double num2, char op, int *valid)
{
    *valid = 1;

    switch (op)
    {
    case '+':
        return num1 + num2;

    case '-':
        return num1 - num2;

    case '*':
        return num1 * num2;

    case '/':
        if (num2 == 0.0)
        {
            *valid = 0;
            return 0;
        }
        return num1 / num2;

    default:
        *valid = 0;
        return 0;
    }
}

void CalculatorModule()
{
    char num1[50], num2[50];
    char op;
    int base;

    double decimal1, decimal2, resultDecimal;
    char resultBase[50];

    int valid;

    printf("\n==============================\n");
    printf("     MULTI-BASE CALCULATOR\n");
    printf("==============================\n");

    printf("Enter first number: ");
    scanf("%49s", num1);

    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%49s", num2);

    printf("Enter input base (2 / 8 / 10 / 16): ");
    scanf("%d", &base);

    if (base != 2 && base != 8 && base != 10 && base != 16)
    {
        printf("Invalid base selected.\n");
        return;
    }

    // Convert inputs to decimal
    decimal1 = toDecimal(num1, base);
    if (decimal1 < 0)
        return;

    decimal2 = toDecimal(num2, base);
    if (decimal2 < 0)
        return;

    // Perform operation
    resultDecimal = performCalculation(decimal1, decimal2, op, &valid);

    if (!valid)
    {
        printf("Invalid operation or division by zero.\n");
        return;
    }

    // Convert result back to selected base
    fromDecimal(resultDecimal, base, resultBase);

    printf("\n\n");
    printf("================================\n");
    printf("      CALCULATION RESULT\n");
    printf("================================\n\n");

    printf("Input              : %s %c %s   (Base %d)\n\n", num1, op, num2, base);

    printf("\033[1;32mAnswer              : %s\033[0m\n\n", resultBase);

    printf("Decimal Equivalent : %.6lf\n", resultDecimal);

    printf("\n--------------------------------\n");
    printf("Press Enter to continue...");
    getchar();
    getchar();
    
}
#include <stdio.h>
#include "../include/converter.h"

#define PRECISION 6

// helper function
int charToValue(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

// Convert any base → decimal (with fraction)
double toDecimal(char number[], int base)
{
    double result = 0.0;
    int i = 0;

    // -------- INTEGER PART --------
    while (number[i] != '\0' && number[i] != '.')
    {
        int value = charToValue(number[i]);

        if (value < 0 || value >= base)
        {
            printf("\n'%c' is not valid for base %d\n", number[i], base);
            return -1.0;
        }

        result = result * base + value;
        i++;
    }

    // -------- FRACTION PART --------
    if (number[i] == '.')
    {
        i++; // skip '.'
        double fractionPower = 1.0;

        while (number[i] != '\0')
        {
            int value = charToValue(number[i]);

            if (value < 0 || value >= base)
            {
                printf("'%c' is not valid for base %d\n", number[i], base);
                return -1.0;
            }

            fractionPower /= base;
            result += value * fractionPower;
            i++;
        }
    }

    return result;
}

// Convert decimal → any base (with fraction)
void fromDecimal(double decimal, int base, char result[])
{
    int isNegative = 0;

    if (decimal < 0)
    {
        isNegative = 1;
        decimal = -decimal;
    }

    char temp[50];
    int index = 0;

    int intPart = (int)decimal;
    double fraction = decimal - intPart;

    // -------- INTEGER PART --------
    if (intPart == 0)
    {
        temp[index++] = '0';
    }
    else
    {
        while (intPart > 0)
        {
            int remainder = intPart % base;

            if (remainder < 10)
                temp[index++] = remainder + '0';
            else
                temp[index++] = remainder - 10 + 'A';

            intPart /= base;
        }
    }

    // reverse integer part
    int start = 0;
    int end = index - 1;

    while (start < end)
    {
        char t = temp[start];
        temp[start] = temp[end];
        temp[end] = t;
        start++;
        end--;
    }

    // copy integer part
    int k = 0;
    for (int i = 0; i < index; i++)
    {
        result[k++] = temp[i];
    }

    // -------- FRACTION PART --------
    if (fraction > 0.0)
    {
        result[k++] = '.';

        for (int i = 0; i < PRECISION; i++)
        {
            fraction *= base;
            int digit = (int)fraction;

            if (digit < 10)
                result[k++] = digit + '0';
            else
                result[k++] = digit - 10 + 'A';

            fraction -= digit;

            if (fraction < 0.000001)
                break;
        }
    }

    if (isNegative)
    {
        for (int i = k; i > 0; i--)
            result[i] = result[i - 1];

        result[0] = '-';
        k++;
    }

    result[k] = '\0';
}

// UI Module
void ConverterModule()
{
    char number[50];
    int base;
    double decimalValue;

    char binary[50];
    char octal[50];
    char hex[50];

    printf("\n==============================\n");
    printf("      NUMBER CONVERTER\n");
    printf("==============================\n");

    printf("Enter number: ");
    scanf("%49s", number);

    printf("Enter input base (2 / 8 / 10 / 16): ");
    scanf("%d", &base);

    // validate base
    if (base != 2 && base != 8 && base != 10 && base != 16)
    {
        printf("Invalid base selected.\n");
        return;
    }

    decimalValue = toDecimal(number, base);

    // error already printed in toDecimal()
    if (decimalValue < 0)
    {
        return;
    }

    fromDecimal(decimalValue, 2, binary);
    fromDecimal(decimalValue, 8, octal);
    fromDecimal(decimalValue, 16, hex);

    printf("\n\n");
    printf("================================\n");
    printf("        CONVERTED RESULTS\n");
    printf("================================\n\n");

    printf("Input Number        : %s\n", number);
    printf("Input Base          : %d\n\n", base);

    printf("Binary              : %s\n", binary);
    printf("Octal               : %s\n", octal);
    printf("Decimal Equivalent  : %.6lf\n", decimalValue);
    printf("Hexadecimal         : %s\n", hex);

    printf("\n--------------------------------\n");
    printf("Press Enter to continue...");
    getchar();
    getchar();
    
}
#include <cs50.h>
#include <stdio.h>

long get_num(void);
string card_checkr(long num);

int main(void)
{
    long num = get_num();
    printf("%s", card_checkr(num));
}

//get cc number
long get_num(void)
{
    long num = get_long("Number: ");
    return num;
}

//card checker
string card_checkr(long num)
{
    int digit1 = num % 10;
    int digit2 = (num / 10) % 10;
    int digit3 = (num / 100) % 10;
    int digit4 = (num / 1000) % 10;
    int digit5 = (num / 10000) % 10;
    int digit6 = (num / 100000) % 10;
    int digit7 = (num / 1000000) % 10;
    int digit8 = (num / 10000000) % 10;
    int digit9 = (num / 100000000) % 10;
    int digit10 = (num / 1000000000) % 10;
    int digit11 = (num / 10000000000) % 10;
    int digit12 = (num / 100000000000) % 10;
    int digit13 = (num / 1000000000000) % 10;
    int digit14 = (num / 10000000000000) % 10;
    int digit15 = (num / 100000000000000) % 10;
    int digit16 = (num / 1000000000000000) % 10;

    /* digit check
        printf("%i\n", digit1);
        printf("%i\n", digit2);
        printf("%i\n", digit3);
        printf("%i\n", digit4);
        printf("%i\n", digit5);
        printf("%i\n", digit6);
        printf("%i\n", digit7);
        printf("%i\n", digit8);
        printf("%i\n", digit9);
        printf("%i\n", digit10);
        printf("%i\n", digit11);
        printf("%i\n", digit12);
        printf("%i\n", digit13);
        printf("%i\n", digit14);
        printf("%i\n", digit15);
        printf("%i\n", digit16);
    */

    int chk1_1 = (2 * digit2) % 10 + (2 * digit4) % 10 + (2 * digit6) % 10 + (2 * digit8) % 10 + (2 * digit10) % 10 +
                 (2 * digit12) % 10 + (2 * digit14) % 10 + (2 * digit16) % 10;
    int chk1_2 = (2 * digit2 / 10) % 10 + (2 * digit4 / 10) % 10 + (2 * digit6 / 10) % 10 + (2 * digit8 / 10) % 10 +
                 (2 * digit10 / 10) % 10 + (2 * digit12 / 10) % 10 + (2 * digit14 / 10) % 10 + (2 * digit16 / 10) % 10;
    int chk1 = chk1_1 + chk1_2;

    int chk2 = digit1 + digit3 + digit5 + digit7 + digit9 + digit11 + digit13 + digit15;

    /*  sum check
        printf("%i\n", chk1);
        printf("%i\n", chk2);
    */
//final sum; needs % = 0
    int sum = chk1 + chk2;

//    printf("%i\n", sum);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    string type;
    int length = 0;
    int start_digs = 0;
    long count = num;

//count the digits
    while (count > 0)
    {
        count /= 10;
        length++;
    }
//     printf("%i\n", length);
    
//get starting digits
    switch (length)
    {
        case 13:
            start_digs = num / 100000000000;
            break;
        case 15:
            start_digs = num / 10000000000000;
            break;
        case 16:
            start_digs = num / 100000000000000;
            if ((start_digs / 10) % 10 == 4)
            {
                start_digs = 4;
            }
            break;
        default:
            type = "INVALID\n";
    }
//    printf("%i\n", start_digs);

//determine card type
    if (sum % 10 == 0)
    {
        if (length == 15 && (start_digs == 34 || start_digs == 37))
        {
            type = "AMEX\n";
        }
        else if (length == 16 && (start_digs == 51 || start_digs == 52 || start_digs == 53 || start_digs == 54 || start_digs == 55))
        {
            type = "MASTERCARD\n";
        }
        else if ((length == 13 || length == 16) && start_digs == 4)
        {
            type = "VISA\n";
        }
        else
        {
            type = "INVALID\n";
        }
    }
    else
    {
        type = "INVALID\n";
    }
 
    return type;
}

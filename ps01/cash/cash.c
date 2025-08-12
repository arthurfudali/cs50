#include <cs50.h>
#include <stdio.h>
#include <string.h>

/*
Quarters = 25
Dimes = 10
Nickels = 5
Pennies = 1
 */
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    // Prompt the user for change owed, in cents
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    // calculates quarters

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // calculates dimes
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // calculate nickels
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // calculate pennies
    int pennies = calculate_pennies(cents);
    cents = cents - pennies;

    int total = (quarters + dimes + nickels + pennies);
    printf("%d \n", total);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer

    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    }
    return quarters;
}
int calculate_dimes(int cents)
{
    // Calculate how many dimes you should give customer

    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}
int calculate_nickels(int cents)
{
    // Calculate how many nickels you should give customer

    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}
int calculate_pennies(int cents)
{
    // Calculate how many pennies you should give customer

    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}

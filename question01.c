#include <stdio.h>

int digitSum(unsigned long long number)
{
    if (number < 10) {
        return (int)number;
    }

    return (int)(number % 10) + digitSum(number / 10);
}

int checkDigit(unsigned long long number)
{
    if (number < 10) {
        return (int)number;
    }

    return checkDigit(digitSum(number));
}

int main(void)
{
    unsigned long long accountNumber;

    printf("Enter account number: ");
    if (scanf("%llu", &accountNumber) != 1) {
        return 1;
    }

    printf("Check digit: %d\n", checkDigit(accountNumber));
    return 0;
}
#include <stdio.h>
const float UNIT_RATE = 12.0f;
const float TAX_RATE = 0.17f;

void calculateBill(int units)
{
    double subtotal = units * (double)UNIT_RATE;
    double tax = subtotal * TAX_RATE;

    printf("Subtotal: Rs. %.2f\n", subtotal);
    printf("Tax: Rs. %.2f\n", tax);
    printf("Final bill: Rs. %.2f\n", subtotal + tax);
}
int main(void)
{
    int units;

    printf("Enter units consumed: ");
    if (scanf("%d", &units) != 1 || units < 0) {
        printf("Invalid units\n");
        return 1;
    }

    calculateBill(units);
    return 0;
}
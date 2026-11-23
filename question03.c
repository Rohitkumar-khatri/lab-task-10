#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main(void)
{
    int length, width;

    printf("Enter floor length and width in feet: ");
    if (scanf("%d %d", &length, &width) != 2 || length <= 0 || width <= 0) {
        printf("Invalid dimensions\n");
        return 1;
    }

    int side = gcd(length, width);
    long long tiles = (long long)(length / side) * (width / side);

    printf("Tile side: %d ft\n", side);
    printf("Tiles needed: %lld\n", tiles);

    return 0;
}
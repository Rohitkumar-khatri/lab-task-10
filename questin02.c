#include <stdio.h>
#define MAX_PLAYERS 100

struct Player {
    char name[50];
    int runs;
    int balls;
    double strikeRate;
};

int main(void)
{
    struct Player players[MAX_PLAYERS];
    int count;

    printf("Enter number of players (1-%d): ", MAX_PLAYERS);
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_PLAYERS) {
        printf("Invalid player count\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("\nPlayer %d name: ", i + 1);
        if (scanf(" %49[^\n]", players[i].name) != 1) {
            return 1;
        }

        printf("Enter runs and balls faced: ");
        if (scanf("%d %d", &players[i].runs, &players[i].balls) != 2 ||
            players[i].runs < 0 || players[i].balls < 0) {
            printf("Invalid runs or balls\n");
            return 1;
        }

        players[i].strikeRate = 0.0;
        if (players[i].balls > 0) {
            players[i].strikeRate = 100.0 * players[i].runs / players[i].balls;
        }
    }

    int best = 0;
    double total = 0.0;

    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", players[i].name, players[i].strikeRate);
        total += players[i].strikeRate;

        if (players[i].strikeRate > players[best].strikeRate) {
            best = i;
        }
    }

    printf("Best player: %s (%.2f)\n",
           players[best].name, players[best].strikeRate);
    printf("Team average strike rate: %.2f\n", total / count);

    return 0;
}
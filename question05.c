#include <stdio.h>

struct Patient {
    int id;
    char name[50];
    int age;
    double temperature;
};

const char *checkFever(struct Patient patient)
{
    if (patient.temperature > 97) {
        return "Fever";
    }

    return "Normal";
}

int main(void)
{
    struct Patient patients[2];

    for (int i = 0; i < 2; i++) {
        printf("\nPatient %d ID: ", i + 1);
        if (scanf("%d", &patients[i].id) != 1) {
            return 1;
        }

        printf("Name: ");
        if (scanf(" %49[^\n]", patients[i].name) != 1) {
            return 1;
        }

        printf("Enter age and temperature in Fahrenheit: ");
        if (scanf("%d %lf", &patients[i].age, &patients[i].temperature) != 2) {
            return 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        printf("\nID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Temperature: %.2f F\n", patients[i].temperature);
        printf("Status: %s\n", checkFever(patients[i]));
    }
    return 0;
}
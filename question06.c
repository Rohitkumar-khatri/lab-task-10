#include <stdio.h>
#include <string.h>

struct Parcel {
    char trackingID[20];
    char city[50];
    float weight;
    char status[20];
};

int searchParcel(const struct Parcel parcels[], int count, const char id[])
{
    for (int i = 0; i < count; i++) {
        if (strcmp(parcels[i].trackingID, id) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    struct Parcel parcels[] = {
        {"PK101", "Lahore", 2.50f, "In Transit"},
        {"PK102", "Karachi", 1.75f, "Pending"},
        {"PK103", "Islamabad", 3.20f, "In Transit"}
    };

    int count = sizeof parcels / sizeof parcels[0];
    char id[20];

    printf("Enter tracking ID: ");
    if (scanf("%19s", id) != 1) {
        return 1;
    }

    int index = searchParcel(parcels, count, id);
    if (index == -1) {
        printf("Not found\n");
        return 0;
    }

    printf("Tracking ID: %s\n", parcels[index].trackingID);
    printf("City: %s\n", parcels[index].city);
    printf("Weight: %.2f kg\n", parcels[index].weight);
    printf("Current status: %s\n", parcels[index].status);

    strcpy(parcels[index].status, "Delivered");
    printf("Updated status: %s\n", parcels[index].status);

    return 0;
}
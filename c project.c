#include <stdio.h>
#include <string.h>

struct Ticket
{
    char passenger[50];
    int source;
    int destination;
    int fare;
};

int main()
{
    struct Ticket t;

    char username[20];
    char password[20];

    printf("=====================================\n");
    printf("   METRO TICKET MANAGEMENT SYSTEM\n");
    printf("=====================================\n");

    printf("\nADMIN LOGIN\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "metro123") == 0)
    {
        printf("\nLogin Successful!\n");

        printf("\nEnter Passenger Name: ");
        scanf("%s", t.passenger);

        printf("\nMetro Stations:\n");

        printf("1. Kashmere Gate\n");
        printf("2. Rajiv Chowk\n");
        printf("3. Central Secretariat\n");
        printf("4. AIIMS\n");
        printf("5. HUDA City Centre\n");

        printf("\nEnter Source Station Number: ");
        scanf("%d", &t.source);
        printf("Source = %d\n", t.source);

        printf("Enter Destination Station Number: ");
        scanf("%d", &t.destination);
        printf("Destination = %d\n", t.destination);

        if (t.source < 1 || t.source > 5 ||
            t.destination < 1 || t.destination > 5)
        {
            printf("\nInvalid Station Selection!\n");
            return 0;
        }

        if (t.source == t.destination)
        {
            printf("\nSource and Destination Cannot Be Same!\n");
            return 0;
        }

        /* Fare Calculation */

        if (t.destination > t.source)
        {
            t.fare = (t.destination - t.source) * 10;
        }
        else
        {
            t.fare = (t.source - t.destination) * 10;
        }

        printf("\n=================================\n");
        printf("          METRO TICKET\n");
        printf("=================================\n");

        printf("Passenger Name : %s\n", t.passenger);

        printf("Source         : ");

        if (t.source == 1)
            printf("Kashmere Gate");
        else if (t.source == 2)
            printf("Rajiv Chowk");
        else if (t.source == 3)
            printf("Central Secretariat");
        else if (t.source == 4)
            printf("AIIMS");
        else if (t.source == 5)
            printf("HUDA City Centre");

        printf("\n");

        printf("Destination    : ");

        if (t.destination == 1)
            printf("Kashmere Gate");
        else if (t.destination == 2)
            printf("Rajiv Chowk");
        else if (t.destination == 3)
            printf("Central Secretariat");
        else if (t.destination == 4)
            printf("AIIMS");
        else if (t.destination == 5)
            printf("HUDA City Centre");

        printf("\n");

        printf("Total Fare     : Rs.%d\n", t.fare);

        /* File Handling */

        FILE *fp;

        fp = fopen("tickets.txt", "a");

        if (fp == NULL)
        {
            printf("\nFile Error!\n");
            return 0;
        }

        fprintf(fp, "\nPassenger: %s\n", t.passenger);

        fprintf(fp, "Source: ");

        if (t.source == 1)
            fprintf(fp, "Kashmere Gate\n");
        else if (t.source == 2)
            fprintf(fp, "Rajiv Chowk\n");
        else if (t.source == 3)
            fprintf(fp, "Central Secretariat\n");
        else if (t.source == 4)
            fprintf(fp, "AIIMS\n");
        else if (t.source == 5)
            fprintf(fp, "HUDA City Centre\n");

        fprintf(fp, "Destination: ");

        if (t.destination == 1)
            fprintf(fp, "Kashmere Gate\n");
        else if (t.destination == 2)
            fprintf(fp, "Rajiv Chowk\n");
        else if (t.destination == 3)
            fprintf(fp, "Central Secretariat\n");
        else if (t.destination == 4)
            fprintf(fp, "AIIMS\n");
        else if (t.destination == 5)
            fprintf(fp, "HUDA City Centre\n");

        fprintf(fp, "Fare: Rs.%d\n", t.fare);

        fclose(fp);

        printf("\nTicket Saved Successfully!\n");
    }
    else
    {
        printf("\nInvalid Username or Password!\n");
    }

    return 0;
}

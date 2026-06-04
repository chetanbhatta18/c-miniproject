// c-mini project on parking management
// These are the necessary header files used in this program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct parking
{
    int bike, car, cycle;
    int totalAmount;
    char ownerName[50];
    int vehicleNumber;
    char parktime[30];
} p1;
int main()
{
    time_t t;
    struct tm *tm_info;
    int choice;
    p1.totalAmount = 0;
    p1.cycle = 0;
    p1.car = 0;
    p1.bike = 0;
    FILE *fptr;
    while (1)
    {
        printf("\n====================================\n");
        printf(" FAR WESTERN UNIVERSITY\n");
        printf(" PARKING MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("\n1. Park Bike (Rs.20)");
        printf("\n2. Park Car (Rs.50)");
        printf("\n3. Park Cycle (Rs.10)");
        printf("\n4. Show Record");
        printf("\n5. Delete Record");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d%*c", &choice);
        switch (choice)
        {
        case 1:
            p1.bike++;
            p1.totalAmount = 20;
            t = time(NULL);
            tm_info = localtime(&t);
            strftime(p1.parktime, sizeof(p1.parktime), "%Y-%m-%d %H:%M:%S", tm_info);

            printf("\nEnter Bike Owner Name: ");
            fgets(p1.ownerName, sizeof(p1.ownerName), stdin);
            p1.ownerName[strcspn(p1.ownerName, "\n")] = 0;
            printf("Enter Bike Number: ");
            scanf("%d%*c", &p1.vehicleNumber);
            printf("\nBike parked successfully!\n");
            printf("Owner Name   : %s\n", p1.ownerName);
            printf("Bike Number  : %d\n", p1.vehicleNumber);
            printf("Parking Slot : B-%d\n", p1.bike);
            printf("Parking Time : %s\n",p1.parktime);
            printf("Total Amount : Rs.%d\n", p1.totalAmount);
            fptr = fopen("parking_record.txt", "a");
            if (fptr == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            fprintf(fptr, "Owner Name   : %s\nBike Number  : %d\nParking Slot : B-%d\nParking Time : %s\nTotal Amount : Rs.%d\n", p1.ownerName, p1.vehicleNumber, p1.bike , p1.parktime , p1.totalAmount);
            fclose(fptr);
            break;

        case 2:
            p1.car++;
            p1.totalAmount = 50;
            t = time(NULL);
            tm_info = localtime(&t);
            strftime(p1.parktime, sizeof(p1.parktime), "%Y-%m-%d %H:%M:%S", tm_info);

            printf("\nEnter Car Owner Name: ");
            fgets(p1.ownerName, sizeof(p1.ownerName), stdin);
            p1.ownerName[strcspn(p1.ownerName, "\n")] = 0;

            printf("Enter Car Number: ");
            scanf("%d%*c", &p1.vehicleNumber);

            printf("\nCar parked successfully!\n");
            printf("Owner Name   : %s\n", p1.ownerName);
            printf("Car Number   : %d\n", p1.vehicleNumber);
            printf("Parking Slot : C-%d\n", p1.car);
            printf("Parking Time : %s\n",p1.parktime);
            printf("Total Amount : Rs.%d\n", p1.totalAmount);
            fptr = fopen("parking_record.txt", "a");
            if (fptr == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            fprintf(fptr, "Owner Name   : %s\ncar Number  : %d\nParking Slot : C-%d\nParking Time : %s\nTotal Amount : Rs.%d\n", p1.ownerName, p1.vehicleNumber, p1.car, p1.parktime , p1.totalAmount);
            fclose(fptr);
            break;

        case 3:
            p1.cycle++;
            p1.totalAmount = 10;
            t = time(NULL);
            tm_info = localtime(&t);
            strftime(p1.parktime, sizeof(p1.parktime), "%Y-%m-%d %H:%M:%S", tm_info);

            printf("\nEnter Cycle Owner Name: ");
            fgets(p1.ownerName, sizeof(p1.ownerName), stdin);
            p1.ownerName[strcspn(p1.ownerName, "\n")] = 0;

            printf("\nCycle parked successfully!\n");
            printf("Owner Name   : %s\n", p1.ownerName);
            printf("Parking Slot : CY-%d\n", p1.cycle);
            printf("Parking Time : %s\n",p1.parktime);
            printf("Total Amount : Rs.%d\n", p1.totalAmount);
            fptr = fopen("parking_record.txt", "a");
            if (fptr == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            fprintf(fptr, "Owner Name   : %s\nParking Slot : B-%d\nParking Time : %s\nTotal Amount : Rs.%d\n", p1.ownerName, p1.cycle, p1.parktime , p1.totalAmount);
            fclose(fptr);
            break;

        case 4:
            printf("\n========== PARKING RECORD ==========\n");
            fptr = fopen("parking_record.txt", "r");
            char dat[300];
            if (fptr == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            while (fgets(dat, sizeof(dat), fptr) != NULL)
            {
                printf("%s", dat);
            }
            fclose(fptr);
            printf("====================================\n");
            break;
        case 5:
            fptr = fopen("parking_record.txt", "w");
            if (fptr == NULL)
            {
                printf("Error opening file.\n");
                return 1;
            }
            fclose(fptr);
            printf("\nAll parking records deleted!\n");
            break;
        case 6:
            printf("\n====================================\n");
            printf(" Thank You For Using Parking System\n");
            printf("====================================\n");
            exit(0);
        default:
            printf("\nInvalid Choice! Try again.\n");
        }
    }
    return 0;
}
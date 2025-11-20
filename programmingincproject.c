#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char name[51], from[21], to[21], train[30];
    int seats = 1100, waiting = 51;
    int tickets;
    int ticket_price = 2100;
    int total_fare;
    int age;
    int pnr = 10001;

    printf("**** INDIAN RAILWAY WELCOMES YOU ****\n");

    do {

        printf("Menu:\n");
        printf("1) Book Ticket\n");
        printf("2) Check Available Seats\n");
        printf("3) Cancel Ticket\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nEnter your name: ");
                scanf("%s", name);
               //fgets(name,sizeof(name),stdin);

                printf("\nEnter your age: ");
                scanf("%d", &age);

                printf("From: ");
                scanf("%s", from);

                printf("To: ");
                scanf("%s", to);

                printf("Train Name: ");
                scanf("%s", train);

                printf("How many tickets you want: ");
                scanf("%d", &tickets);

                if(tickets <= seats) {

                    seats = seats - tickets;
                    pnr = pnr + 11;
                    total_fare = ticket_price * tickets;

                    printf("\nBooking Successful\n");
                    printf("------------------------\n");
                    printf("PNR Number : %d\n", pnr);
                    printf("Passenger Name : %s\n", name);
                    printf("Train : %s\n", train);
                    printf("From : %s\n", from);
                    printf("To : %s\n", to);
                    printf("Tickets : %d\n", tickets);
                    printf("Total Fare : %d\n", total_fare);
                    printf("Seats Left : %d\n", seats);

                }
                else if (tickets <= seats + waiting) {

                    int tickets_in_waiting = tickets - seats;
                    waiting = waiting - tickets_in_waiting;
                    seats = 0;

                    printf("\nSeats not enough. %d in waiting.\n", tickets_in_waiting);
                    printf("Confirmation will be given later.\n");

                }
                else {
                    printf("\nSorry, not enough seats even in waiting  seats are not available.\n");
                }

                break;


            case 2:
                printf("\nSeats Available : %d\n", seats);
                printf("Waiting Slots   : %d\n", waiting);
                break;


            case 3:
                printf("\nEnter number of tickets to cancel: ");
                scanf("%d", &tickets);

                seats = seats + tickets;

                printf("Cancellation Done. Seats Available : %d\n", seats);
                break;


            case 4:
                printf("\nThank you for using IRCTC.\n");
                break;


            default:
                printf("\nInvalid choice..! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}

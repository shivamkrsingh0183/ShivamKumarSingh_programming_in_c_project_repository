#include <stdio.h>
#include <string.h>

#include<stdio.h>
#include<string.h>
 struct details{
    char passenger__first_name[51];
    char passenger_middle_name[21];
    char passenger_last_name[21];
    int Age;
    char train_name[21];
    int pnr_no;
     char From[52];
     char  To[52];
     int no_of_tickets;
};

void  ticket_booking(struct details  *p){

    printf("\nenter passengers's name:\n");
    scanf("%50s",p->passenger__first_name);

    printf("enter passenger's middle name:\n");
    scanf("%20s",p->passenger_middle_name);
     

    printf("enter passenger's last name:\n");
    scanf("%20s",p->passenger_last_name);

    printf("\nenter passenger's age:\n");
    scanf("%d",&p->Age);
    

    printf("enter train name:\n");
    scanf("%20s",p->train_name);
    
    printf("enter pnr number:\n");
    scanf("%d",&p->pnr_no);

    printf("from:\n");
    scanf("%50s",p->From);
   
    printf("To:\n");
    scanf("%50s",p->To);

    printf("enter n.o of tickets you want:\n");
    scanf("%d",&p->no_of_tickets);

}


int main(){
    int choice;
    int seats=1100;
    int waiting_list=51;
    int ticket_price=2100;
    int cancel_tickets;
    int total_fare;

struct details p;


printf("INDIAN RAILWAY WELCOMES YOU!!!!\n");
do{
    printf("\nMenu:\n");
    printf("1) Book Ticket\n");
    printf("2)Check Available Seats\n");
    printf("Cancel Ticket\n");
    printf("4)exit\n");
    printf("enter your choice\n");
    scanf("%d",&choice);


    switch(choice){
        case 1: ticket_booking(&p);
        if(p.no_of_tickets<=seats) {
            seats-=p.no_of_tickets;
            total_fare =p.no_of_tickets*ticket_price;

        printf("\nBooking Successful!,Have a nice journey\n");
        printf("******************************\n");
        printf(" Train's onr n.o:%d",p.pnr_no);
        printf("passenger's name:%s %s %s\n",p.passenger__first_name,p.passenger_middle_name,p.passenger_last_name);
        printf("passenger's age:%d\n",p.Age);
        printf("Train's name:%s\n",p.train_name);
        printf("From:%s\n",p.From);
        printf("To:%s\n",p.To);
        printf("total n.o of tickets:%d\n",p.no_of_tickets);
        printf("total fare is:%d\n",total_fare);
        printf("seats left now:%d\n",seats);

        }
        else if(p.no_of_tickets<=seats+waiting_list){
            int tickets_in_waiting=p.no_of_tickets-seats;
            waiting_list-=tickets_in_waiting;
            seats=0;
            printf("\nAll seats are filled,but %d tickets are in waiting list.\n",tickets_in_waiting);
            printf("you will get confirmation later.\n");
        }
        else{
            printf("\n not enough seats avialble bor booking nor waiting seats are available\n");

        }
        break;

    

        
    

        case 2: printf("\nAvailable seats are:%d\n",seats);
            printf("waiting slots:%d\n",waiting_list);
            break;

        case 3:printf("enter n.o of tickets you want to cancel:\n");
              scanf("%d",&cancel_tickets);
              seats+=cancel_tickets;
              printf("cancellation successful! seats available now:%d\n",seats);
              break;


              case 4:printf("\n thanking you for using indian railway site\n");
              break;
    default:printf("\n invalid choice! try again.\n");
    }
}while(choice!=4);
return 0;
}
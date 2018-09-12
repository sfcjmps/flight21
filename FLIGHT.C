#include<stdio.h>
#include <stdlib.h>
#include<string.h>

//STRUCTURE
typedef struct{
	char flightNo[5];
	char date[12];
	char time[6];
	char gate[3];
}Flight;
Flight flight={"YZ22","10-12-2008","20:30","RT"};

typedef struct{
	char name[30];
	char booking_ID[3];
	int seats;
}Seat;
Seat choice[4][5];  

void displaymenu();
void booking();
void seat();
void ticket();
void records();
void looping();
void exit_();
	
//Variables
int selection;	
int i;
int j;
int seats_num[20]={0};
int booking_ID=100;
int seatsAvailable=20;
int password;

int main(void)
{
	displaymenu();
	while(selection!=4)
	{
		looping();
	}
	return 0;
}
		
	void displaymenu()
	{
	printf("\n");
	printf("\tAirline System\n"
		  "\t=======================\n"
		  "\t  MENU\n"
		  "\t=======================\n"
		  "\t1.BOOKING\n"
		  "\t2.SEAT\n"
		  "\t3.RECORDS\n"
		  "\t4.EXIT\n\n");

	printf("\tEnter your selection : ");
	scanf("%d",&selection);
	looping();
	return;
	}

	//looping()
	void looping()
	{	
	switch(selection)
		{
		case 1:
			booking();
			break;
		case 2:
			seat();
			break;
		case 3:
			records();
			break;
		case 4:
			exit_();
			break;
		default:
		printf("\tInvalid selecion.Try again\n");
	}
	return;
	}
	
	//booking	
	void booking()
	{
		for(i=0;i<4;i++)
			for(j=0;j<5;j++)  
		{			
		printf("\tPlease enter seats number   : ");
		scanf("%d",&choice[i][j].seats);
		fflush(stdin);

		if(choice[i][j].seats<=seatsAvailable)
		{
		printf("\tPlease enter passenger name : ");
		scanf("%[^\n]",choice[i][j].name);
		fflush(stdin);
		ticket();
		booking_ID++;
			}
		seatsAvailable=seatsAvailable-choice[i][j].seats;
		
		system("pause");
		system("cls");
		displaymenu();	
		}

		if (seatsAvailable<0)
		{
			printf("\n");
			printf("\tSORRY, the flight is fully booked\n");
			printf("\t=================END=================\n\n");
			displaymenu();
		}
		if(choice[i][j].seats>seatsAvailable)
			{
				printf("\n");
				printf("\tThe flight leave %d seats\n",seatsAvailable);
				displaymenu();
			}
	return;
	}
	
	void ticket()
	{
	printf("\n\n");
	
	printf("\t-----------------AIRLINE BOOKING TICKET----------------\n");
	printf("\t============================================================\n");
	printf("\t Booking ID : %d	 \t\t\tFlight No : %s\n",booking_ID,flight.flightNo);
	printf("\t Passenger  : %s\n",choice[i][j].name);
	printf("\t\t\t						Date	  : %s\n",flight.date);
	printf("\t						Time	  : %s\n",flight.time);
	printf("\t						Gate	  : %s\n",flight.gate);
	printf("\t						  Seats No. : %d%c  \n\n",i+1,j+65);
	printf("\t============================================================\n");
	return;}


	//seat
	void seat()
	{	
		printf("  A   B	  C	  D	E\n");
		for(j=0;j<5;j++)
		{
		printf("%d  ",booking_ID); 
		}
		for(i=0;i<4;i++)
		{
			printf("\n");
			printf("%d\n",i+1);
		}
		system("pause");
		system("cls");
		displaymenu();
	return;
	}

	void records()	 //For Staff to View the flight's records
	{	
	printf("\tPlease enter password: ");
	scanf("%d", &password);   //111

	if (password==111)
	{
		system("cls");
	
		printf("\t====================================\n");
		printf("\tALL FLIGHT RECORDS\n");  
		printf("\t====================================\n");
		printf("\tSeats Available left : %d \n",seatsAvailable);
		
		ticket();
		system("pause");
		system("cls");
		displaymenu();
	}
	else
	{
		printf("\tInvalid password\n\n");
		system("pause");
		system("cls");
		displaymenu();
	}		
	return;
	}

	void exit_()
	{
	printf("\tThank you for using this system\n");
	exit(1);
	return;
	}

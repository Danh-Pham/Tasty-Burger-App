#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>



typedef struct order{
    char name[50];
    int order_number;
    int number_of_food;
    float cost;
}order;
order *oP=NULL;
int order_count = 0, served_count = 0;  //GLOBAL VARIABLE
int flag=1; 
int cancel;



void items ()
{
    printf("..................................MENU....................................\n");

    printf("---------------------------------------------------------------------------\n");

    printf("----------------------------Select Burger Type-----------------------------\n");
    printf("[A]--------------------------Chicken Burger --------------------------15$--\n");
    printf("[B]----------------------------Ham Burger-----------------------------17$--\n");
    printf("[C]---------------------------Vegie Burger----------------------------13$--\n");
    printf("[X]------------------------To return to Main Menu--------------------------\n");


}

void cancelation()
{
	int i;
	printf("Please enter your receipt number (the digit after B00) \n");
	printf("B00");
	scanf("%d",&cancel);
	for(i=0; i<order_count;i++)
	{
		if(cancel==oP[i].order_number)
		{
			oP[order_count].order_number=0;
			flag =0;
			order_count--;
			printf("Your order B00%d has been canceled successfully .\n",oP[order_count].order_number);
		}
		if (flag==1)
			printf("Sorry , invalid receipt number. Please try again... \n");
	}
	
}
int main ()
{
again:
    printf ("\t\t     Welcome to Tasty Burgers\n");
    while (1){
        printf ("1. to Order\n2. to Cancel\n3. to Exit the program\n");

        int in;
        scanf ("%d", &in);
        getchar ();
        switch (in){
            case 1 : {
	oP=realloc(oP,sizeof(order)*(order_count+1));
    int n, qu;
	char in;

    printf ("please enter your name: ");
    gets (oP[order_count].name);
    oP[order_count].order_number =order_count+1;
    items(); 
    oP[order_count].number_of_food = n;
    oP[order_count].cost = 0;
    oP[order_count].number_of_food = 0;
    
    level:
    printf ("How many items you want to order? ");
    scanf ("%d", &n);

    getchar ();
    while (n--){
        printf ("\nEnter chosen item :\n");
        scanf ("%c", &in);
        getchar();
        switch(in){
    case 'A' : {
        do{
        printf("You choose Chicken Burger\n");
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        }while(qu==0);
        oP[order_count].number_of_food +=qu;
			oP[order_count].cost +=(15*qu);
		printf("Your currently bill value is $%.2f \n",oP[order_count].cost);

        break;
    }
    case 'B' :{
        do{
        printf("You choose Ham Burger \n");
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
		}while(qu==0);

        oP[order_count].number_of_food +=qu;
		oP[order_count].cost +=(17*qu);
		printf("Your currently bill value is $%.2f \n",oP[order_count].cost);
		


        break;
    }
    case 'C' :{

        do{
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
		}while(qu==0);

        oP[order_count].number_of_food +=qu;
		oP[order_count].cost +=(13*qu);
		printf("Your currently bill value is $%.2f \n",oP[order_count].cost);

 

        break;
    }
	case 'X':{
		goto again;
		break;
	}

    default : {
        printf ("Invalid selection try again\n");	
        n++;
    }
        }
    }				    
	char temp;
    printf ("Do you want to order anything else?(y/n)\n ");
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        goto level;
    printf ("\nNumber of food ordered %d\n", oP[order_count].number_of_food);
	printf ("\nYour total bill is %.2f \n",oP[order_count].cost);
	if(oP[order_count].number_of_food>5){
		printf("Discount = $%.2f \n", (oP[order_count].cost*10)/100);
	oP[order_count].cost=oP[order_count].cost-(oP[order_count].cost*10)/100;}
	fflush(stdin);
    printf ("Thank you %s for your order. Your bill is $%.2f.\n\n", oP[order_count].name, oP[order_count].cost);
	fflush(stdin);

    printf ("Please go to a register and make the payment by quoting the Receipt Number - B00%d \n",oP[order_count].order_number);
    printf ("Order B00%d by %s is ready\n", oP[order_count].order_number, oP[order_count].name);
    printf ("Enjoy your meal\n\n");
    served_count++;
    order_count ++;
				break;
            }
            case 2 : {
                cancelation();
                break;
            }
            case 3 : {
                system ("COLOR 2");
                printf ("We are closed \n\n");
                printf ("\nThank you for your ordering\n");
                printf ("Have A Good Burger For The Day\n\n");
                printf ("See you next time. Have a good day\n");
                printf ("\n Phu Danh Pham - 102619398\n\n");
                return 0;
            }
        }
    }
}

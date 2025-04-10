#include<stdio.h>

int main(void) {
    double accounts[] = {
        25.73,
        560.0, 
        120.0,
        12007.03
    };
    int choice;
    int sel1;
    int sel2;

    while (1) {
        printf("0. Exit\n");
        printf("1. Check balance\n");
        printf("2. Change balance\n");
        printf("3. Add/Remove account\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            // clear bad input from buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if (choice == 0) {
            printf("Goodbye.\n");
            break;
        }
        if (choice == 1) {
            printf("You chose to check a balance.\nWhich account do you want to check? ");
            scanf("%i", &sel1);
            if (sel1 < 1 || sel1 > sizeof(accounts) / sizeof(accounts[0])) {
                printf("Invalid account. Try again. \n");
                continue;
            }
            printf("Account %i's balance is $%.2f.\n",sel1, accounts[sel1-1]);
        } else if (choice == 2) {
            printf("You chose to change a balance.\nWhich account do you want to change? ");
            scanf("%i", &sel1);
            if (sel1 < 1 || sel1 > sizeof(accounts) / sizeof(accounts[0])) {
                printf("Invalid account. Try again. \n");
                continue;
            }
            printf("\nYou chose account %i which currently has a balance of $%.2f. What do you want to change it to? ", sel1, accounts[sel1-1]);
            scanf("%lf", &accounts[sel1-1]);
            printf("Account %i's balance is now $%.2f.\n",sel1, accounts[sel1-1]);
        } else if (choice == 3) {
            printf("sorry this dont work because im too lazy to figure out how to use malloc and realloc :(\n");
        } else {
            printf("You didn't enter a valid option. Try again.\n");
            continue;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAcc.h"
#include "bankLL.h"

struct accNode* head = NULL;

static int accNumbers = 0;

// creating new account
struct acc* createAcc(char* name)
{
  // create acc with name
  struct acc* newAcc = (struct acc*)malloc(sizeof(struct acc));
  
  if(newAcc != NULL){
    newAcc->accName = strdup(name); 
    newAcc->accBalance = 0.0;
    newAcc->accNumber = accNumbers++;
    addAccount(&head, newAcc);  
    

    printf("New account with name %s has been created and account Number %d\n", newAcc->accName, newAcc->accNumber);
    printf("Please remeber your account number to keep acces to your account\n");
    printf("Your account number is %d\n", newAcc->accNumber);
    printf("Account Balance %.2f\n", newAcc->accBalance);

    return newAcc;
  }
  return 0;
}

// deposit into existing account
void deposit(float amount, struct acc* account){
  if(amount > 0){
    account->accBalance += amount;
    printf("%.2f have been deposited into your account(%s). Your new balance is now %.2f\n"
           , amount, account->accName, account->accBalance);
  }
  else {
    printf("Deposit failed\n");
  }
}

void withdraw(float amount, struct acc* account){
    if(amount > 0 || amount < account->accBalance){
        account -> accBalance-= amount;
        printf("You have withdrawn %.2f from your Account(%s). Your new balance is %.2f\n"
               , amount, account->accName, account->accBalance);
    }else{
        printf("Withdraw failed\n");
    }
}

 //User interface
int interface(){
    printf(
        "==================================================\n"
        " Welcome to the BigusBank Management System\n"
        "==================================================\n"
        "\n"
        "Please choose an option:\n"
        "1. Create a New Account\n"
        "2. Deposit into Account\n"
        "3. Withdraw from Account\n"
        "9. Exit\n"
        "\n"
        "Enter your choice (1-3): "
    );
  
    int choice;
    char nameAccount[30];
    float depo;
    int accNumberDepo;

    scanf("%d", &choice);
        if(choice<1 || choice>10){
        printf("invalid input");
        return 1;
    }


    switch(choice){
        case 1:
            printf("Please input an account name\n"),
            scanf("%s", nameAccount);
            createAcc(nameAccount);
            break;

        case 2:
            printf("Pleas input the account number of your account\n");
            scanf("%d", &accNumberDepo);
        
            printf("Please enter the amount you want to deposit\n");
            scanf("%f", &depo);

            struct acc* depositAcc = findAcc(head, accNumberDepo);
            if(depositAcc != NULL){
            deposit(depo, depositAcc);
            }
            else {
                printf("account number %d not found. \n", accNumberDepo);
            }
            break;

        case 3:
            printf("Pleas input the account number of your account\n");
            scanf("%d", &accNumberDepo);

            printf("Please enter the amount you want to withdraw\n");
            scanf("%f", &depo);

            struct acc* withdrawAcc = findAcc(head, accNumberDepo);
            if(withdrawAcc != NULL){
                withdraw(depo, withdrawAcc);
            }
            else {
                printf("account number %d not found. \n", accNumberDepo);
            }
            break;

        case 9:
            printf(
                    "==================================================\n"
                    "                   Goodbye \n"
                    "==================================================\n"
                    );
            exit(0);

        default:
            printf("invalid option please try again\n");
        }

    return 0;
  } 


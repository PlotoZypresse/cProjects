#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankAcc.h"



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

    printf("New account with name %s has been created and account Number %d\n", newAcc->accName, newAcc->accNumber);
    printf("Account Balance %.2f\n", newAcc->accBalance);

    return newAcc;
  }
  return 0;
}

// deposit into existing account
void deposit(float amount, struct acc* account)
{
  if(account != NULL && amount > 0){
    account->accBalance += amount;
    printf("%.2f have been deposited into your account(%s). Your new balance is now %.2f\n"
           , amount, account->accName, account->accBalance);
  }
  else {
    printf("Deposti failed\n");  
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
    "3. Exit\n"
    "\n"
    "Enter your choice (1-3): "
  );
  
  int choice;
  char nameAccount[30];
  float depo;

  scanf("%d", &choice);
  if(choice<1 || choice>3){
    printf("invalid input");
    return 1;
  }

    switch(choice){

    case 1:
      printf("Please input an account name\n"),
        scanf("%s", nameAccount);
      struct acc* myAcc = createAcc(nameAccount);
      if(myAcc == NULL){
        printf("Something went wrong. No account was created");
        free(myAcc->accName);
        free(myAcc);
      }
      break;

    case 2:
      if(myAcc == NULL){
        printf("Please create an account first");
      }else{
      printf("Please enter the amount you want to deposit\n");
        if(scanf("%f", &depo) != 1){
          printf("Failed to read the deposit amount.\n");
        }else{
          deposit(depo, myAcc);
        }
      }
      break;
    
    case 3:
      printf("thank you\n");
      exit(0);

    default:
      printf("invalid option please try again\n");
  }

  return 0;
} 


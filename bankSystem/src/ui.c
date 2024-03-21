#include "bankAcc.h"
#include "bankLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User interface
int interface() {
  printf("==================================================\n"
         " Welcome to the BigusBank Management System\n"
         "==================================================\n"
         "\n"
         "Please choose an option:\n"
         "1. Create a New Account\n"
         "2. Deposit into Account\n"
         "3. Withdraw from Account\n"
         "4. Get account balance\n"
         "9. Exit\n"
         "\n"
         "Enter your choice (1-3): ");

  int choice;
  char nameAccount[30];
  float depo;
  int accNumberDepo;

  scanf("%d", &choice);
  if (choice < 1 || choice > 10) {
    printf("invalid input");
    return 1;
  }

  switch (choice) {
  case 1:
    printf("Please input an account name\n"), scanf("%s", nameAccount);
    createAcc(nameAccount);
    break;

  case 2:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberDepo);

    printf("Please enter the amount you want to deposit\n");
    scanf("%f", &depo);

    struct acc *depositAcc = findAcc(head, accNumberDepo);
    if (depositAcc != NULL) {
      deposit(depo, depositAcc);
    } else {
      printf("account number %d not found. \n", accNumberDepo);
    }
    break;

  case 3:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberDepo);

    printf("Please enter the amount you want to withdraw\n");
    scanf("%f", &depo);

    struct acc *withdrawAcc = findAcc(head, accNumberDepo);
    if (withdrawAcc != NULL) {
      withdraw(depo, withdrawAcc);
    } else {
      printf("account number %d not found. \n", accNumberDepo);
    }
    break;

  case 4:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberDepo);
    struct acc *balanceAcc = findAcc(head, accNumberDepo);
    if (balanceAcc != NULL) {
      getBalance(balanceAcc);
    } else {
      printf("account number %d not found. \n", accNumberDepo);
    }
    break;

  case 9:
    printf("==================================================\n"
           "                   Goodbye \n"
           "==================================================\n");
    exit(0);

  default:
    printf("invalid option please try again\n");
  }

  return 0;
}

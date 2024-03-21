#include "bankAcc.h"
#include "bankLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User interface
int interface(void) {
  printf("==================================================\n"
         " Welcome to the BigusBank Management System\n"
         "==================================================\n"
         "\n"
         "Please choose an option:\n"
         "1. Create a New Account\n"
         "2. Deposit into Account\n"
         "3. Withdraw from Account\n"
         "4. Get account balance\n"
         "5. Transfer funds from Account to Account\n"
         "9. Exit\n"
         "\n"
         "Enter your choice (1-3): ");

  int choice;
  char nameAccount[30];
  float depo;
  float transferAmount;
  int accNumberDepo;
  int accNumberFrom;
  int accNumberTo;

  scanf("%d", &choice);
  if (choice < 1 || choice > 10) {
    printf("invalid input");
    return 1;
  }

  switch (choice) {

    // create account
  case 1:
    printf("Please input an account name\n"), scanf("%s", nameAccount);
    createAcc(nameAccount);
    break;

    // deposit into account
  case 2:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberDepo);

    printf("Please enter the amount you want to deposit\n");
    scanf("%f", &depo);

    struct acc *depositAcc = findAcc(globalHead, accNumberDepo);
    if (depositAcc != NULL) {
      deposit(depo, depositAcc);
    } else {
      printf("account number %d not found. \n", accNumberDepo);
    }
    break;

    // withdraw from account
  case 3:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberDepo);

    printf("Please enter the amount you want to withdraw\n");
    scanf("%f", &depo);

    struct acc *withdrawAcc = findAcc(globalHead, accNumberDepo);
    if (withdrawAcc != NULL) {
      withdraw(depo, withdrawAcc);
    } else {
      printf("account number %d not found. \n", accNumberDepo);
    }
    break;

    // get account balance
  case 4:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberDepo);
    struct acc *balanceAcc = findAcc(globalHead, accNumberDepo);
    if (balanceAcc != NULL) {
      getBalance(balanceAcc);
    } else {
      printf("account number %d not found. \n", accNumberDepo);
    }
    break;

    // Transfer funds
  case 5:
    printf("Pleas input the account number of your account\n");
    scanf("%d", &accNumberFrom);

    printf("Pleas input the account number of the account you want to transfer "
           "to\n");
    scanf("%d", &accNumberTo);

    printf("How much do you want to transfer?\n");
    scanf("%f", &transferAmount);

    struct acc *accFrom = findAcc(globalHead, accNumberFrom);
    struct acc *accTo = findAcc(globalHead, accNumberTo);

    transfer(transferAmount, accFrom, accTo);

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

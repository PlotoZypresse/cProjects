#include "bankAcc.h"
#include "bankLL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct accNode *head = NULL;

static int accNumbers = 0;

// creating new account
struct acc *createAcc(char *name) {
  // create acc with name
  struct acc *newAcc = (struct acc *)malloc(sizeof(struct acc));

  if (newAcc != NULL) {
    newAcc->accName = strdup(name);
    newAcc->accBalance = 0.0;
    newAcc->accNumber = accNumbers++;
    addAccount(&head, newAcc);

    printf("New account with name %s has been created and account Number %d\n",
           newAcc->accName, newAcc->accNumber);
    printf(
        "Please remeber your account number to keep acces to your account\n");
    printf("Your account number is %d\n", newAcc->accNumber);
    printf("Account Balance %.2f\n", newAcc->accBalance);

    return newAcc;
  }
  return 0;
}

// deposit into existing account
void deposit(float amount, struct acc *account) {
  if (amount > 0) {
    account->accBalance += amount;
    printf("%.2f have been deposited into your account(%s). Your new balance "
           "is now %.2f\n",
           amount, account->accName, account->accBalance);
  } else {
    printf("Deposit failed\n");
  }
}
// withdraw from specific account
void withdraw(float amount, struct acc *account) {
  if (amount > 0 || amount < account->accBalance) {
    account->accBalance -= amount;
    printf("You have withdrawn %.2f from your Account(%s). Your new balance is "
           "%.2f\n",
           amount, account->accName, account->accBalance);
  } else {
    printf("Withdraw failed\n");
  }
}

// transfer from an account to another
void transfer(float amount, struct acc *fromAcc, struct acc *toAcc) {}

// prints the balance of a specific account
void getBalance(struct acc *account) {
  printf("Your balance is %.2f\n", account->accBalance);
}

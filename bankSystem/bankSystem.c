#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct acc{
  float accBalance;
  //int accNumber; 
  char* accName;
};

//int accNumbers[] = {};

// creating new account
struct acc* createAcc(char* name)
{
  // create acc with name
  struct acc* newAcc = (struct acc*)malloc(sizeof(struct acc));
  
  if(newAcc != NULL){
    newAcc->accName = strdup(name); 
    newAcc->accBalance = 0.0;
    
    printf("New account with name %s has been created\n", newAcc->accName);
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

int main(int argc, char *argv[])
{
  struct acc* myAcc = createAcc("Peter Griffin");
  if(myAcc == NULL){
     printf("Something went wrong. No account was created");
  }
  
  float depositAm;

  printf("Please enter amount to deposit: \n");
  scanf("%f\n", &depositAm); 

  deposit(depositAm, myAcc);
  printf("deposit done");


  free(myAcc->accName);
  free(myAcc);


  return 0;
}


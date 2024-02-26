#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct acc{
  float accBalance;
  //int accNumber; 
  char* accName;
};

struct acc* createAcc(char* name){
  // create acc with name
  struct acc* newAcc = (struct acc*)malloc(sizeof(struct acc));
  
  if(newAcc != NULL){
    newAcc->accName = strdup(name); 
    newAcc->accBalance = 0.0;
    
    return newAcc;
  }
  
  return 0;
}

int main(int argc, char *argv[])
{
  struct acc* myAcc = createAcc("Peter Griffin");
  if(myAcc != NULL){
    printf("account crated for %s\n", myAcc->accName);

    free(myAcc->accName);
    free(myAcc);
  }
  else{
    printf("Account creation failed");
  }

  return 0;
}


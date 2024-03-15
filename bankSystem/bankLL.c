#include "bankLL.h"
#include "bankAcc.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addAccount(struct accNode** head, struct acc *newAccount){
  struct accNode* newNode = (struct accNode*)malloc(sizeof(struct accNode));
  if(newNode == NULL){
    printf("failed to allocate memory for a new accNode\n");
    return;
  }

  newNode->account=newAccount;
  newNode->next=NULL;

  // if the list is empty
  if(*head == NULL){  
    *head = newNode;
  }else{
    struct accNode* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current ->next = newNode;
  }
}  

struct acc* findAcc(struct accNode* head, int accNumber){
  struct accNode* current = head;
  while(current != NULL){
    if(current->account->accNumber == accNumber){
      return current->account;
    }
    current = current -> next;
  }
  return NULL;
} 

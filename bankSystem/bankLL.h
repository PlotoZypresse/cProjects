#ifndef BANKLL_H
#define BANKLL_H

struct accNode{
  struct acc* account;
  struct accNode* next;
};

extern struct accNode* head;

void addAccount(struct accNode** head, struct acc* newAccount);

struct acc* findAcc(struct accNode* head, int accNumber);

#endif
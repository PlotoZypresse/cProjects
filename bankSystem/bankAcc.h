#ifndef BANKACC_H
#define BANKACC_H

struct acc {
    int accNumber;
    float accBalance;
    char* accName;
};

struct accNode{
  struct acc* account;
  struct accNode* next;
};


struct acc* createAcc(char* name);



void deposit(float amount, struct acc* account);
void withdraw(float amount, struct acc* account);
void transfer(float amount, struct acc* fromAcc, struct acc* toAcc);

int interface();

#endif

#ifndef BANKACC_H
#define BANKACC_H

struct acc {
  int accNumber;
  float accBalance;
  char *accName;
};

struct acc *createAcc(char *name);
struct acc *deleteAcc(int accNumber);
void deposit(float amount, struct acc *account);
void withdraw(float amount, struct acc *account);
void transfer(float amount, struct acc *fromAcc, struct acc *toAcc);
void getBalance(struct acc *account);
int interface(void);

#endif

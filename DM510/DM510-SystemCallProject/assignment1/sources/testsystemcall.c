#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "arch/x86/include/generated/uapi/asm/unistd_64.h"



void testBasicFunc(){
    char *in = "This is the basic function test";
    char msg[99];
    long msglen;

    printf("message: %s\n", in);
    syscall(__NR_dm510_msgbox_put, in, strlen(in));

    msglen = syscall(__NR_dm510_msgbox_get, msg, 99);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);
}


void testZeroLeng(){
    char *in = "";
    char msg[99];
    long msglen;

    printf("message: %s\n", in);
    syscall(__NR_dm510_msgbox_put, in, 0);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 99);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    //printf("%ld", result);
}

void testOneLeng(){
    char *in = "J";
    char msg[99];
    long msglen;

    printf("message: %s\n", in);
    syscall(__NR_dm510_msgbox_put, in, strlen(in)+1);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 99);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    //printf("%ld", result);
}

void test100Leng(){
    char *in = "87WHsekAo4OSElsK9BkLuaLLwnZeU9vdBRSCa1HzvrMqjPEH9SVpUyPy9NKnxS6vPHy25Br8cT2vJEYtKCwimdfUfvHCHjitZrtf";
    char msg[100];
    long msglen;

    printf("message: %s\n", in);
    syscall(__NR_dm510_msgbox_put, in, strlen(in)+1);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);
}

void test200Leng(){
    char *in = "87WHsekAo4OSElsK9BkLuaLLwnZeU9vdBRSCa1HzvrMqjPEH9SVpUyPy9NKnxS6vPHy25Br8cT2vJEYtKCwimdfUfvHCHjitZrtf87WHsekAo4OSElsK9BkLuaLLwnZeU9vdBRSCa1HzvrMqjPEH9SVpUyPy9NKnxS6vPHy25Br8cT2vJEYtKCwimdfUfvHCHjitZrtf";
    char msg[100];
    long msglen;

    printf("message: %s\n", in);
    syscall(__NR_dm510_msgbox_put, in, strlen(in)+1);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);
}

void testNegativeLength(){
    char *in = "ghjghj";
    char msg[100];
    long msglen;

    printf("message: %s\n", in);
    syscall(__NR_dm510_msgbox_put, in, -1);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);
}

void testMultipleMsg(){
    char msg[100];
    long msglen;
    char *in1 = "Hello1";
    char *in2 = "Hello2";
    char *in3 = "Hello3";
    char *in4 = "Hello4";
    char *in5 = "Hello5";
    char *in6 = "Hello6";

    printf("message: %s\n", in1);
    syscall(__NR_dm510_msgbox_put, in1, strlen(in1)+1);
    printf("\n");

    printf("message: %s\n", in2);
    syscall(__NR_dm510_msgbox_put, in2, strlen(in2)+1);
    printf("\n");

    printf("message: %s\n", in3);
    syscall(__NR_dm510_msgbox_put, in3, strlen(in3)+1);
    printf("\n");

    printf("message: %s\n", in4);
    syscall(__NR_dm510_msgbox_put, in4, strlen(in4)+1);
    printf("\n");

    printf("message: %s\n", in5);
    syscall(__NR_dm510_msgbox_put, in5, strlen(in5)+1);
    printf("\n");

    printf("message: %s\n", in6);
    syscall(__NR_dm510_msgbox_put, in6, strlen(in6)+1);
    printf("\n");

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);
}

void testGetEmpty(){
    char msg[100];
    long msglen;

    msglen = syscall(__NR_dm510_msgbox_get, msg, 100);
    printf("message length: %ld\n", msglen);
    printf("the message: %s\n", msg);
}


int main(int argc, char ** argv) {
    printf("\n");
    printf("Basic function test:\n");
    testBasicFunc();
    printf("\n");
s
    printf("Zero length test:\n");
    testZeroLeng();
    printf("\n");

    printf("One length test:\n");
    testOneLeng();
    printf("\n");

    printf("100 length test:\n");
    test100Leng();
    printf("\n");

    printf("200 length test:\n");
    test200Leng();
    printf("\n");

    printf("Negative length test:\n");
    testNegativeLength();
    printf("\n");

    printf("Multiple messages test:\n");
    testMultipleMsg();
    printf("\n");

    printf("Empty stack test:\n");
    testGetEmpty();
    printf("\n");
}


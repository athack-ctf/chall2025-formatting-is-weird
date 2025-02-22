#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint64_t ___stack_chk_guard = 0;
        
uint64_t secret(char *key) {
    uint64_t hash = 0;
    while (*key) {
        hash += (uint8_t)(*key);
        hash += (hash << 10);
        hash ^= (hash >> 6);
        key++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

void setCan(char *input){
    ___stack_chk_guard = secret(input);
}

void ___stack_chk_fail() {
    printf("*** stack smashing detected ***: terminated\nAborted\n");
    exit(6);
}

void grabUsername() {
    char usr[64];
    printf("Enter your username:\n");
    fgets(usr, sizeof(usr), stdin);
    setCan(usr);
    printf("Welcome ");
    printf(usr);
}

void vuln() {
    char buf[64];
    uint64_t canary = ___stack_chk_guard;
    printf("\nEnter your password:\n");
    gets(buf);

    if (canary != ___stack_chk_guard) {
        ___stack_chk_fail();
    }
}

int secret_function() {
    asm("pop %rdi; ret");
}

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    grabUsername();
    vuln();
}


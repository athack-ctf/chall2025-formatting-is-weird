#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint64_t ___stack_chk_guard = 0;
const char b64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        
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

int base64_value(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return -1;
}

void base64_decode(const char *input, char *output) {
    int i, j;
    int input_len = strlen(input);
    uint8_t buffer[4];

    for (i = 0, j = 0; i < input_len; i += 4) {
        memset(buffer, 0, sizeof(buffer));
        
        for (int k = 0; k < 4; k++) {
            if (i + k < input_len) {
                buffer[k] = base64_value(input[i + k]);
                if (buffer[k] == -1) buffer[k] = 0;
            }
        }

        output[j++] = (buffer[0] << 2) | (buffer[1] >> 4);
        if (input[i + 2] != '=' && j < 64) output[j++] = (buffer[1] << 4) | (buffer[2] >> 2);
        if (input[i + 3] != '=' && j < 64) output[j++] = (buffer[2] << 6) | buffer[3];
    }

    output[j] = '\0';
}

void setCan(char *input){
    ___stack_chk_guard = secret(input);
}

void ___stack_chk_fail() {
    printf("*** stack smashing detected ***: terminated\nAborted\n");
    exit(6);
}

void killcode() {
    char code[128];
    char decoded[128];
    printf("[SYSTEM] Enter your personal killcode:\n");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = 0;
    setCan(code);
    base64_decode(code, decoded);

    printf("[INFO] validating the following killcode:\n");
    printf(decoded);
}

void failed() {
    printf("[SYSTEM] Killcode verification could not be completed\n");
}

void vuln() {
    char buf[64];
    uint64_t canary = ___stack_chk_guard;
    printf("\n[SYSTEM] Provide 2FA code:\n");
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
    printf("\n[INFO] Jester AI is online.\n");
    killcode();
    vuln();
    failed();
    return 0;
}


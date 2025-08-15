#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Supported characters
const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
#define CHARSET_SIZE (sizeof(charset) - 1)

// Find index of a character
int get_index(char c) {
    for (int i = 0; i < CHARSET_SIZE; i++) {
        if (charset[i] == c) return i;
    }
    return -1; // Not found
}

// Banner
void banner() {
    printf("\n============================\n");
    printf("     ENCODER / DECODER v1.4\n");
    printf("============================\n");
    printf("1 - Encode text\n");
    printf("2 - Decode text\n");
    printf("0 - Exit\n");
    printf("============================\n");
    printf("Choose an option: ");
}

// Encode text ignoring spaces
void encode() {
    char text[100];
    int encoded[100];
    int count = 0;

    printf("\nEnter the text (A-Z, a-z, 0-9): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // remove \n

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            continue; // ignore spaces
        }
        if (!isalnum((unsigned char)text[i])) {
            printf("[Warning] Character '%c' is not alphanumeric! Marking as -1.\n", text[i]);
            encoded[count++] = -1;
        } else {
            encoded[count++] = get_index(text[i]) + 1; // +1 to start from 1
        }
    }

    printf("\nEncoded: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", encoded[i]);
    }
    printf("\n");
}

// Decode numbers ignoring empty tokens
void decode() {
    char line[300];
    int encoded[100];
    char decoded[100];
    int count = 0;

    printf("\nEnter the numbers separated by spaces: ");
    fgets(line, sizeof(line), stdin);

    char *token = strtok(line, " ");
    while (token != NULL && count < 100) {
        if (strlen(token) > 0 && token[0] != '\n') { // avoid empty tokens
            encoded[count++] = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {
        int idx = encoded[i] - 1; // -1 to match charset index
        if (idx >= 0 && idx < CHARSET_SIZE)
            decoded[i] = charset[idx];
        else
            decoded[i] = '?';
    }
    decoded[count] = '\0';

    printf("\nDecoded: %s\n", decoded);
}

int main() {
    int option;

    do {
        banner();
        scanf("%d", &option);
        getchar(); // consume \n

        switch (option) {
            case 1:
                encode();
                break;
            case 2:
                decode();
                break;
            case 0:
                printf("\nExiting... Goodbye!\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while (option != 0);

    return 0;
}

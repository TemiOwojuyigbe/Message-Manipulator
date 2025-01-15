#include <stdio.h>
#include <stdlib.h>
#include "cFunctions.h"

// Function prototypes
void displayMenu();

int main() {
    char choice;
    do {
        displayMenu();
        printf("Enter an option: ");
        scanf(" %c", &choice); 
        while (getchar() != '\n'); 

        switch (choice) {
            case 's': case 'S':
                displayMessages();
                break;
            case 'r': case 'R':
                readNewMessage();
                break;
            case 'c': case 'C':
                caesarCipher();
                break;
            case 'f': case 'F':
                frequencyDecrypt();
                break;
            case 'q': case 'Q':
                printf("bye!\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}


void displayMenu() {
    printf("\nEncryption menu options:\n");
    printf("s - Show current messages\n");
    printf("r - Read new message\n");
    printf("c - Caesar cipher\n");
    printf("f - Frequency decrypt\n");
    printf("q - Quit program\n");
}

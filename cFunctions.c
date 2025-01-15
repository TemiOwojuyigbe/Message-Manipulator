#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cFunctions.h"

#define TOTAL_MSGS 10
#define MSG_LENGTH 256

// Storage for the messages
static char msgStorage[TOTAL_MSGS][MSG_LENGTH] = {
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message.",
    "This is the original message."
};

// Function to display stored messages
void displayMessages() {
    for (int msgIndex = 0; msgIndex < TOTAL_MSGS; msgIndex++) {
        printf("Message[%d]: %s\n", msgIndex, msgStorage[msgIndex]);
    }
}

// Function to read and validate a new message
void readNewMessage() {
    static int currentSlot = 0; // Tracks the slot for the next message
    char userInput[MSG_LENGTH];

    printf("Enter your new message: ");
    fgets(userInput, MSG_LENGTH, stdin);

    // Remove trailing newline if it exists
    size_t inputLength = strlen(userInput);
    if (inputLength > 0 && userInput[inputLength - 1] == '\n') {
        userInput[inputLength - 1] = '\0';
    }

    // Validate the message format
    if (inputLength > 8 &&
        isupper(userInput[0]) &&
        (userInput[strlen(userInput) - 1] == '.' ||
         userInput[strlen(userInput) - 1] == '?' ||
         userInput[strlen(userInput) - 1] == '!')) {
        // Save the message and move to the next slot
        strncpy(msgStorage[currentSlot], userInput, MSG_LENGTH - 1);
        msgStorage[currentSlot][MSG_LENGTH - 1] = '\0'; // Ensure null-termination
        printf("Message added successfully.\n");
        currentSlot = (currentSlot + 1) % TOTAL_MSGS; // Circular buffer logic
    } else {
        printf("Invalid message. Must start with a capital letter and end with '.', '!', or '?'.\n");
    }
}

// Encrypts a message using the Caesar cipher
void caesarCipher() {
    int shiftAmount, targetMsgIndex;
    char encryptedMessage[MSG_LENGTH];

    printf("Enter the shift value: ");
    scanf("%d", &shiftAmount);

    printf("Enter the message index (0-9): ");
    scanf("%d", &targetMsgIndex);

    // Validate the message index
    if (targetMsgIndex < 0 || targetMsgIndex >= TOTAL_MSGS) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // Call the assembly function to encrypt
    encrypt_caesar(msgStorage[targetMsgIndex], encryptedMessage, shiftAmount);

    printf("Original message: %s\n", msgStorage[targetMsgIndex]);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Update the message in storage
    strncpy(msgStorage[targetMsgIndex], encryptedMessage, MSG_LENGTH - 1);
    msgStorage[targetMsgIndex][MSG_LENGTH - 1] = '\0';
}

// Decrypts a message using frequency analysis
void frequencyDecrypt() {
    int msgIndex;
    printf("Enter the message index (0-9) to decrypt: ");
    scanf("%d", &msgIndex);

    // Validate the message index
    if (msgIndex < 0 || msgIndex >= TOTAL_MSGS) {
        printf("Invalid index. Try again.\n");
        return;
    }

    char* currentMessage = msgStorage[msgIndex];
    int letterCounts[26] = {0};

    // Count character frequencies
    for (int i = 0; currentMessage[i] != '\0'; i++) {
        if (isalpha(currentMessage[i])) {
            char lowercase = tolower(currentMessage[i]);
            letterCounts[lowercase - 'a']++;
        }
    }

    // Find the 5 most frequent characters
    int topFrequencies[5] = {-1, -1, -1, -1, -1};
    for (int topIndex = 0; topIndex < 5; topIndex++) {
        int mostCommon = -1;
        for (int charIndex = 0; charIndex < 26; charIndex++) {
            if ((mostCommon == -1 || letterCounts[charIndex] > letterCounts[mostCommon]) &&
                (topIndex == 0 || letterCounts[charIndex] < letterCounts[topFrequencies[topIndex - 1]])) {
                mostCommon = charIndex;
            }
        }
        topFrequencies[topIndex] = mostCommon;
    }

    // Generate possible decryptions
    printf("Possible decryptions for message[%d]: %s\n", msgIndex, currentMessage);
    for (int attempt = 0; attempt < 5; attempt++) {
        if (topFrequencies[attempt] == -1) break; // No more frequent characters

        int calculatedShift = topFrequencies[attempt] - ('e' - 'a'); // Align to 'e'

        printf("Decryption %d (shift = %d): ", attempt + 1, calculatedShift);
        for (int charPos = 0; currentMessage[charPos] != '\0'; charPos++) {
            char c = currentMessage[charPos];
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = base + ((c - base - calculatedShift + 26) % 26); // Reverse the shift
            }
            putchar(c);
        }
        printf("\n");
    }
}

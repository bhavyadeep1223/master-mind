#include <stdio.h>
#include <string.h>

int main() {
    char secret[20], guess[20];
    int len;

    printf("Enter secret number: ");
    scanf("%s", secret);

    len = strlen(secret);

    while (1) {
        printf("\nEnter guess: ");
        scanf("%s", guess);

        // If guessed correctly, exit loop
        if (strcmp(secret, guess) == 0) {
            printf("Correct guess! Game over.\n");
            break;
        }

        int usedSecret[20] = {0};
        int usedGuess[20]  = {0};

        // Check correct digits in correct position
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                printf("Number %c is matched in correct position (%d)\n",
                        secret[i], i + 1);
                usedSecret[i] = 1;
                usedGuess[i] = 1;
            }
        }

        // Check correct digits but wrong position
        for (int i = 0; i < len; i++) {
            if (usedGuess[i]) continue; // already matched in correct position

            for (int j = 0; j < len; j++) {
                if (!usedSecret[j] && guess[i] == secret[j]) {
                    printf("Number %c is matched but the position should be altered\n",
                            guess[i]);
                    usedSecret[j] = 1;
                    usedGuess[i] = 1;
                    break;
                }
            }
        }
    }

    return 0;
}

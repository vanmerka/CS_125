/***********************************
This is prototype H_NGM_N, a hangman game you can play in C90.
Authors: Alexandra VanMerkesteyn, Your Name
***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WORD_COUNT 5
#define WORD_LENGTH 20
#define MAX_ATTEMPTS 5
/* Function prototypes */
int selectRandomWord(void);
void initializeDisplay(char display[], int length);
int updateDisplay(char word[], char display[], char guess);
int main(void)
{
char words[WORD_COUNT][WORD_LENGTH] = {
"burger",
"shake",
"fries",
"soda",
"pie"
};
char display[WORD_LENGTH];
char guess;
int wordIndex;
int attemptsLeft = MAX_ATTEMPTS;
int wordLength = 0;
int correctGuess;
int i;
int won = 0;
srand((unsigned int)time(NULL));
wordIndex = selectRandomWord();
/* Find word length */
while (words[wordIndex][wordLength] != '\0')
{
wordLength++;
}
initializeDisplay(display, wordLength);
printf("Welcome to the Word Guess Game!\n");
while (attemptsLeft > 0)
{
printf("\nWord: ");
for (i = 0; i < wordLength; i++)
{
printf("%c ", display[i]);
}
printf("\nGuess a letter: ");
scanf(" %c", &guess);
correctGuess = updateDisplay(words[wordIndex], display, guess);
if (correctGuess)
{
printf("Correct!\n");
}
else
{
attemptsLeft--;
printf("Wrong! Attempts left: %d\n", attemptsLeft);
}
/* Check if word is fully guessed */
won = 1;
for (i = 0; i < wordLength; i++)
{
if (display[i] == '_')
{
won = 0;
break;
}
}
if (won)
{
printf("\nYou guessed the word!\n");
break;
}
}
if (!won)
{
printf("\nGame Over! The word was: %s\n", words[wordIndex]);
}
return 0;
}
/* Selects a random word index */
int selectRandomWord(void)
{
return rand() % WORD_COUNT;
}
/* Initializes display with underscores */
void initializeDisplay(char display[], int length)
{
int i;
for (i = 0; i < length; i++)
{
display[i] = '_';
}
}
/* Updates display if guess is correct */
int updateDisplay(char word[], char display[], char guess)
{
int i;
int found = 0;
for (i = 0; word[i] != '\0'; i++)
{
if (word[i] == guess && display[i] == '_')
{
display[i] = guess;
found = 1;
}
}
return found;
}

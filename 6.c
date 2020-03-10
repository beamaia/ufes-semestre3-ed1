#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *word;
    char *tabletop;
    int word_len,
        errors,
        letters_correct;
} Game;

void read_secret_word(Game *g) {
    char word[101];

    printf("Player 1, write the secret word\n");
    scanf(" %100[^\n]%*c", word);
    system("clear");

    g->word_len = strlen(word);
    g->errors = 0;
    g->letters_correct = 0;
    g->word = (char *) malloc(sizeof(char) * g->word_len);

    for(int i = 0; i < g->word_len; i++) {
        g->word[i] = toupper(word[i]);
    }
}

void create_tabletop(Game *g) {
    g->tabletop = (char *) malloc(sizeof(char) * g->word_len);
    for(int i = 0; i < g->word_len; i++) {
        g->tabletop[i] = '_';
    }
}

int uncover_letter(char letter, Game *g) {
    int situation = 0;
    for(int i = 0; i < g->word_len; i++) {
        if(letter == g->word[i]) {
            if(letter == g->tabletop[i]) {
                printf("You have already guessed this letter!\n");
                break;
            } else {
                g->tabletop[i] = letter;
                situation = 1;
                g->letters_correct++;
            }
        }
    }
    return situation;
}

void guess_letter(Game *g) {
    char letter;
    printf("Guess a letter: ");
    scanf("%c%*c", &letter);
    letter = toupper(letter);

    if(!uncover_letter(letter, g)) {
            g->errors++;
    }
}

void show_tabletop(Game *g) {
    for(int i = 0; i < g->word_len; i++) {
        printf("%c ", g->tabletop[i]);
    }
    printf("\n");
}

void show_errors(Game *g) {
    printf("Errors %d/5\n\n", g->errors);
}

void ending_message(Game *g) {
    if(g->letters_correct == g->word_len) {
        printf("Congrats! You won the game :)\n");
    }
    else if(g->errors == 5) {
        printf("Oh no! You lost the game :(\n");
    }
}

void hangman(Game *g) {
    for(int i = 0; g->letters_correct < g->word_len && g->errors < 5;i++) {
        guess_letter(g);
        show_tabletop(g);
        show_errors(g);
        ending_message(g);
    }
}

void free_game(Game *g) {
    free(g->word);
    free(g->tabletop);
    free(g);
}

int main() {
    Game *game = (Game *) malloc(sizeof(Game));

    read_secret_word(game);
    create_tabletop(game);
    hangman(game);
    free_game(game);

    return 0;
}
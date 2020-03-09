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

    printf("Player 1, write the secret word\nPlease use at max 100 letters\n");
    scanf("%[^\n]%*c", word);
    system("clear");

    g->word_len = strlen(word);
    g->errors = 0;
    g->letters_correct = 0;
    g->word = strdup(word);
}

void create_tabletop(Game *g) {
    g->tabletop = (char *) malloc(sizeof(char) * g->word_len);
    for(int i = 0; i < g->word_len; i++) {
        g->tabletop[i] = '_';
    }
}

unsigned int letter_in_word(char letter, Game *g) {
    for(int i = 0; i < g->word_len; i++) {
        if(letter == g->word[i]) 
            return 1;
    }

    return 0;
}

unsigned int letter_on_board(char letter, Game *g) {
    for(int i = 0; i < g->word_len; i++) {
        if(letter == g->tabletop[i]) {
            printf("You have already guessed this letter");
            return 1;
        }
    }

    return 0;
}

int uncover_letter(char letter, Game *g) {
    int sit = 0;
    for(int i = 0; i < g->word_len; i++) {
        if(letter == g->word[i]) {
            g->tabletop[i] = letter;
            sit = 1;
        }

        printf("%c ", g->tabletop[i]);
    }

    return sit;
}

void guess_letter(Game *g) {
    char letter;
    printf("Guess a letter: ");
    scanf("%c", &letter);
    letter = toupper(letter);
    
    for(int i = 0; i < g->word_len; i++) {
        if(!letter_in_word(letter, g)){
            if(!uncover_letter(letter, g)) {
                g->errors++;
            }
        }
    }
    printf("\n");
}

void show_errors(Game *g) {
    printf("Errors %d/5\n", g->errors);
}

void hangman(Game *g) {
    for(int i = 0; g->letters_correct < g->word_len && g->errors < 5;i++) {
        guess_letter(g);
        show_errors(g);
    }

}

void free_game(Game *g) {
    for(int i = 0; i < g->word_len; i++) {
        free(g->word[i]);
        free(g->tabletop[i]);
    }

    free(g);
}

int main() {
    char word[101];
    Game *game = (Game *) malloc(sizeof(Game));

    read_secret_word(game);
    create_tabletop(game);
    hangman(game);
    free_game(game);

    return 0;
}
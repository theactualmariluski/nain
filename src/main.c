/*
###################################################
### The nain programming language #################
###################################################

Thanks for using nain!
Nain is a new and modern programming language made to be easy to learn and use.

Nain is currently on development, v0.01 dev
*/

#include <stdio.h>
#include "./headers/lexer.h"
#include <stdlib.h> 
int main() {
    // reads file contents
    char *input = malloc(sizeof(char) * 1000);
    FILE *file = fopen("src/main.nain", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    fread(input, sizeof(char), 1000, file);
    if (getTokens(input) != 0) {
      printf("Error in file!\n");
    } else {
        printf("File parsed successfully!\n");
        printf(getTokens(input));
    }
    fclose(file);
    return 0;
}
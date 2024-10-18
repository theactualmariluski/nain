/*
###################################
### Nain Testing Script             ###
###################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    printf("Welcome to the Nain Testing Script!\n");
    printf("This script will test the functionality of the Nain programming language.\n");
    printf("Starting tests...\n");
    char text[] = " with lib studio \n \
    fn main() { \n \
     print('Hello, World!') \n \
     }";
    if (getTokens(text) == 0)
    {
        printf("Lexer tests passed!\n");
    }
    return 0;
}
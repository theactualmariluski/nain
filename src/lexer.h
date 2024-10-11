//############################################################################
//######### The main project lexer header file ###############################
//############################################################################

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include "./libs/log.h" // thanks to rxi for the log.h library

#endif

typedef enum {
    CON_DEF,
    CON_CONDITIONAL,
    CON_LOOP,
    CON_FUNCTION,
    CON_EXPRESSION,
    CON_ENUM_DEFINITION,
    CON_SEMICOLON,
    CON_PARSING_INPUT,
    CON_EOF,
    CON_NULL
} Contexts;

// Token types
typedef enum {
    TOK_EOF,
    TOK_INT,
    TOK_STR,
    TOK_PLUS,
    TOK_MINUS,
    TOK_MULT,
    TOK_DIV,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_SEMI,
    TOK_COMMA,
    TOK_COLON,
    TOK_ASSIGN,
    TOK_NEWLINE,
    ERROR
} TokensType;

TokensType advance(char *input,int tokenIndex) { // advances until it finds a keyword, function, expression, ect, and returns a token from the list
    // Gets where the index is in the input
    int inputLen = strlen(input);
    if (inputLen == 0) { // validates the input
        log_error("fatal: no input provided");
        return ERROR;
    } else if (input == NULL) {
        log_error("fatal: input is null");
        return ERROR;
    }
    char *providedIndexToken = inputLen - tokenIndex;
}

// Function to get tokens from input
TokensType getTokens(const char *input) {
    Contexts context = NULL;
    if (input == NULL) {
        log_error("fatal: there is no input");
        return ERROR; // Returns an error if there isn't input
    } else if (input[0] == '\0') {
        log_error("fatal: searched for token, found end of file"); // logs error if the input is empty
    }
    return TOK_EOF; // Returns The End Of File when all tokens are read
}

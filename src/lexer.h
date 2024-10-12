//############################################################################
//######### The main project lexer header file ###############################
//############################################################################

#ifndef lexer_h
#define lexer_h

#include <stdio.h>
#include "./libs/log.h" // thanks to rxi for the log.h library
#include <string.h>

// Enum for different parsing contexts
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
    TOK_WITH,
    TOK_LIB,
    TOK_FILE,
    TOK_CLASS,
    TOK_QUOTE,
    ERROR
} TokensType;

#endif // LEXER_H

// Function to advance through the input and return the next token
TokensType advance(const char *input, int tokenIndex) { 
    int inputLen = strlen(input);
    if (inputLen == 0 || input == NULL) { 
        log_error("fatal: invalid input provided");
        return ERROR;
    }

    // Check if we are out of bounds
    if (tokenIndex >= inputLen) {
        return TOK_EOF;
    }

    char currentChar = input[tokenIndex];
    printf("Current character: %c\n", currentChar);
    // Gets token type based on current character/s
    switch (currentChar) {
        case '+': return TOK_PLUS;
        case '-': return TOK_MINUS;
        case '*': return TOK_MULT;
        case '/': return TOK_DIV;
        case '(': return TOK_LPAREN;
        case ')': return TOK_RPAREN;
        case ';': return TOK_SEMI;
        case ',': return TOK_COMMA;
        case ':': return TOK_COLON;
        case '=': return TOK_ASSIGN;
        case '\n': return TOK_NEWLINE;
        case 'int': return TOK_INT;
        case 'string': return TOK_STR;
        case '\0': return TOK_EOF;
        case 'with': return TOK_WITH;
        case 'lib': return TOK_LIB;
        case 'file': return TOK_FILE;
        case 'class': return TOK_CLASS;
        case '"': return TOK_QUOTE;
            default:
            if (currentChar >= '0' && currentChar <= '9') {
                return TOK_INT; // Return integer token if it's a digit
            }
            break;
    }

    return ERROR;
}

// Function to get tokens from input
TokensType getTokens(const char *input) {
    if (input == NULL || input[0] == '\0') {
        log_error("fatal: invalid input provided");
        return ERROR;
    }

    int tokenIndex = 0;
    TokensType token;

    // Iterate through input and get tokens
    while ((token = advance(input, tokenIndex)) != TOK_EOF) {
        printf("Token: %d\n", token);
        tokenIndex++;
        if (token == ERROR) {
            log_error("fatal: encountered an invalid token");
            return ERROR;
        }
    }

    return TOK_EOF;
}

//############################################################################
//######### The main project lexer header file ###############################
//############################################################################

#ifndef lexer_h
#define lexer_h

#include <stdio.h>
#include "libs/log.h" // thanks to rxi for the log.h library
#include <string.h>

// Enum defining various parsing contexts
// Each context represents a state during parsing, which could be useful
// for more complex grammar structures.
typedef enum {
    CON_DEF,             // Default context
    CON_CONDITIONAL,     // Parsing a conditional (e.g., if-else)
    CON_LOOP,            // Parsing a loop (e.g., for, while)
    CON_FUNCTION,        // Parsing a function
    CON_EXPRESSION,      // Parsing an expression
    CON_ENUM_DEFINITION, // Parsing an enum definition
    CON_SEMICOLON,       // Expecting a semicolon
    CON_PARSING_INPUT,   // Actively parsing input
    CON_EOF,             // End of file/input
    CON_NULL             // Null context, no current context
} Contexts;

// Enum for defining different types of tokens
// Each token represents a lexical unit, such as operators, literals, or keywords.
typedef enum {
    TOK_EOF,        // End of file/input
    TOK_INT,        // Integer token
    TOK_STR,        // String token
    TOK_PLUS,       // '+' operator
    TOK_MINUS,      // '-' operator
    TOK_MULT,       // '*' operator
    TOK_DIV,        // '/' operator
    TOK_LPAREN,     // '(' symbol
    TOK_RPAREN,     // ')' symbol
    TOK_SEMI,       // ';' symbol
    TOK_COMMA,      // ',' symbol
    TOK_COLON,      // ':' symbol
    TOK_ASSIGN,     // '=' symbol
    TOK_NEWLINE,    // Newline token
    TOK_WITH,       // 'with' keyword
    TOK_LIB,        // 'lib' keyword
    TOK_FILE,       // 'file' keyword
    TOK_CLASS,      // 'class' keyword
    TOK_QUOTE,      // " symbol
    TOK_FN_CALL,    // Function call
    TOK_FN_DEF,     // Function definition
    TOK_FN_ARGS,    // Function arguments (e.g., "(x, y)")
    TOK_BACKSLASH,  // '\' symbol
    ERROR           // Token that signifies an error or invalid input
} TokensType;

#endif // LEXER_H

// Function to match keywords in the input string.
// This function checks if the current input matches known keywords (e.g., "int", "string").
// Returns the corresponding token if a match is found, otherwise returns ERROR.
TokensType matchKeyword(const char *input, int tokenIndex) {
    if (strncmp(input + tokenIndex, "int", 3) == 0) {
        return TOK_INT;
    } else if (strncmp(input + tokenIndex, "string", 6) == 0) {
        return TOK_STR;
    } else if (strncmp(input + tokenIndex, "with", 4) == 0) {
        return TOK_WITH;
    } else if (strncmp(input + tokenIndex, "lib", 3) == 0) {
        return TOK_LIB;
    } else if (strncmp(input + tokenIndex, "file", 4) == 0) {
        return TOK_FILE;
    } else if (strncmp(input + tokenIndex, "class", 5) == 0) {
        return TOK_CLASS;
    } else if (strncmp(input + tokenIndex, "fn", 2) == 0) {
        return TOK_FN_DEF;
    } else if (strncmp(input + tokenIndex, "()", 2) == 0) {
        return TOK_FN_ARGS;
    } else if (strncmp(input + tokenIndex, "\"", 1) == 0) {
        return TOK_QUOTE;
    }
    return ERROR; // Not a recognized keyword
}

// Function to advance through the input string and return the next token.
// It skips whitespace, handles single-character tokens (e.g., '+', '-'), and checks for keywords.
// If an invalid character is encountered, it returns ERROR.
TokensType advance(const char *input, int *tokenIndex) {
    int inputLen = strlen(input);
    if (inputLen == 0 || input == NULL) { 
        printf("fatal: invalid input provided");
        return ERROR;
    }

    // Check if we've reached the end of input
    if (*tokenIndex >= inputLen) {
        return TOK_EOF;
    }

    char currentChar = input[*tokenIndex];
    printf("Current character: %c\n", currentChar);

    // Skip whitespace and tabs
    while (currentChar == ' ' || currentChar == '\t') {
        (*tokenIndex)++;
        currentChar = input[*tokenIndex];
    }

    // Handle single-character tokens
    switch (currentChar) {
        case '+': (*tokenIndex)++; return TOK_PLUS;
        case '-': (*tokenIndex)++; return TOK_MINUS;
        case '*': (*tokenIndex)++; return TOK_MULT;
        case '/': (*tokenIndex)++; return TOK_DIV;
        case '(': (*tokenIndex)++; return TOK_LPAREN;
        case ')': (*tokenIndex)++; return TOK_RPAREN;
        case ';': (*tokenIndex)++; return TOK_SEMI;
        case ',': (*tokenIndex)++; return TOK_COMMA;
        case ':': (*tokenIndex)++; return TOK_COLON;
        case '=': (*tokenIndex)++; return TOK_ASSIGN;
        case '\n': (*tokenIndex)++; return TOK_NEWLINE;
        case '"': (*tokenIndex)++; return TOK_QUOTE;
        case '\'': (*tokenIndex)++; return TOK_QUOTE;
        case '\\': (*tokenIndex)++; return TOK_BACKSLASH;
        default:
            // Handle numbers (integers)
            if (currentChar >= '0' && currentChar <= '9') {
                while (input[*tokenIndex] >= '0' && input[*tokenIndex] <= '9') {
                    (*tokenIndex)++; // Skip the entire number
                }
                return TOK_INT;
            }

            // Check for keywords like "int", "string", etc.
            TokensType keywordToken = matchKeyword(input, *tokenIndex);
            if (keywordToken != ERROR) {
                *tokenIndex += strlen("fn"); // Increment tokenIndex based on keyword length
                return keywordToken;
            }
            break;
    }

    return ERROR; // If none of the cases match, return ERROR
}

// Function to tokenize the input string.
// This function iterates through the input, calling 'advance' to extract tokens one by one.
// If an invalid token is found, it returns ERROR; otherwise, it keeps processing until EOF.
TokensType getTokens(const char *input) {
    if (input == NULL || input[0] == '\0') {
        printf("fatal: invalid input provided");
        return ERROR;
    }

    int tokenIndex = 0;
    TokensType token;

    // Process the input until the end (TOK_EOF)
    while ((token = advance(input, &tokenIndex)) != TOK_EOF) {
        printf("Token: %d\n", token);
        if (token == ERROR) {
            printf("fatal: encountered an invalid token");
            return ERROR;
        }
    }

    return TOK_EOF; // Successfully reached end of input
}

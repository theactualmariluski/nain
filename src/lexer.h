/*
#####################################
### Nain Lexer Header             ###
#####################################
*/

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#endif

// Token types

typedef enum 
{
    // Misc
    TOK_EOF,    // 0 - End of file
    TOK_IDENT,  // 1 - Identifier
    // Data types
    TOK_INT,    // 2 - Integer (round number)
    TOK_FLOAT,  // 3 - Floating point number
    TOK_STR,    // 4 - String
    TOK_CHAR,   // 5 - Character
    // Boolean keywords
    TOK_BOOL,   // 6 - Boolean
    TOK_TRUE,   // 7 - True
    TOK_FALSE,  // 8 - False
    // Operators
    TOK_EQ,     // 9 - Equal to
    TOK_NEQ,    // 10 - Not equal to
    TOK_LT,     // 11 - Less than
    TOK_GT,     // 12 - Greater than
    TOK_LEQ,    // 13 - Less than or equal to
    TOK_GEQ,    // 14 - Greater than or equal to
    TOK_AND,    // 15 - And
    TOK_OR,     // 16 - Or
    TOK_NOT,    // 17 - Not
    TOK_ADD,    // 18 - Add
    TOK_SUB,    // 19 - Subtract
    TOK_MUL,    // 20 - Multiply
    TOK_DIV,    // 21 - Divide
    TOK_MOD,    // 22 - Modulo
    TOK_INC,    // 23 - Increment
    TOK_DEC,    // 24 - Decrement
    TOK_ASSIGN, // 25 - Assign
    TOK_ELSE_IF, // 26 - Else if
    TOK_DO,     // 27 - Do
    // Declarations
    TOK_VAR,    // 28 - Variable (with var)
    TOK_LET,    // 29 - Variable (with let)
    TOK_CONST,  // 30 - Constant (with const)
    TOK_TYPE,   // 31 - Type (with type)
    TOK_FUNC,   // 32 - Function (with fn)
    // Function keywords
    TOK_RETURN, // 33 - Return (with return)
    TOK_CALL,   // 34 - Calls a function (with call)
    // Conditionals
    TOK_IF,     // 35 - If (with if)
    TOK_ELSE,   // 36 - Else (with else)
    TOK_WHILE,  // 37 - While (with while)
    TOK_FOR,    // 38 - For (with for)
    TOK_IN,     // 39 - In (with in)
    TOK_BREAK,  // 40 - Break (with break)
    TOK_CONTINUE,// 41 - Continue (with continue)
    // Others
    TOK_INDENT,  // 42 - Indentation
    // Special characters
    TOK_LPAREN, // 43 - Left parenthesis
    TOK_RPAREN, // 44 - Right parenthesis
    TOK_LBRACE, // 45 - Left brace
    TOK_RBRACE, // 46 - Right brace
    TOK_LBRACK, // 47 - Left bracket
    TOK_RBRACK, // 48 - Right bracket
    TOK_SEMIC,  // 49 - Semicolon
} toks;


// Makes an array of identifiers
char idents[1000000]; // Don't confuse with the TOK_INDENT token

// Function to classify tokens
int getTokens(char *code);

// Helper function to retrieve the current token
toks getCurrentToken(int *index, char *code) {
    char c = code[*index];

    // Skip whitespace
    while (c == ' ' || c == '\n' || c == '\t') {
        (*index)++;
        c = code[*index];
    }

    // Handle single-line comments
    if (c == '/' && code[*index + 1] == '/') {
        (*index) += 2;
        while (code[*index] != '\n' && code[*index] != '\0') {
            (*index)++;
        }
        return getCurrentToken(index, code);  // Skip the comment and continue
    }

    // Handle custom multi-line comments starting with '/' and ending with '\'
    if (c == '/' && code[*index + 1] != '/') {
        (*index)++;
        while (!(code[*index] == '\\')) {
            (*index)++;
            if (code[*index] == '\0') {
                printf("Error: Unterminated multi-line comment.\n");
                exit(EXIT_FAILURE);
            }
        }
        (*index)++; // Skip the ending '\'
        return getCurrentToken(index, code);  // Skip the comment and continue
    }

    // Check for EOF
    if (c == '\0') {
        return TOK_EOF;
    }

    // Operators and symbols
    switch (c) {
        case '+': (*index)++; return TOK_ADD;
        case '-': (*index)++; return TOK_SUB;
        case '*': (*index)++; return TOK_MUL;
        case '/': (*index)++; return TOK_DIV;
        case '=': (*index)++; return (code[*index] == '=') ? ((*index)++, TOK_EQ) : TOK_ASSIGN;
        case '!': (*index)++; return (code[*index] == '=') ? ((*index)++, TOK_NEQ) : TOK_NOT;
        case '<': (*index)++; return (code[*index] == '=') ? ((*index)++, TOK_LEQ) : TOK_LT;
        case '>': (*index)++; return (code[*index] == '=') ? ((*index)++, TOK_GEQ) : TOK_GT;
        // Add more operators here...
    }

    // Handle identifiers and keywords
    if (isalpha(c) || c == '_') {
        int start = *index;
        while (isalnum(code[*index]) || code[*index] == '_') {
            (*index)++;
        }

        int len = *index - start;
        strncpy(idents, code + start, len);
        idents[len] = '\0';

        // Check for keywords (e.g., "if", "else", etc.)
        if (strcmp(idents, "if") == 0){ return TOK_IF;}
        if (strcmp(idents, "else") == 0){ return TOK_ELSE;}
        if (strcmp(idents, "while") == 0){ return TOK_WHILE;}
        if (strcmp(idents, "for") == 0){ return TOK_FOR;}
        if (strcmp(idents, "in") == 0){ return TOK_IN;}
        if (strcmp(idents, "do") == 0){ return TOK_DO;}
        if (strcmp(idents, "let") == 0){ return TOK_LET;}
        if (strcmp(idents, "const") == 0){ return TOK_CONST;}
        if (strcmp(idents, "var") == 0){ return TOK_VAR;}
        if (strcmp(idents, "fn") == 0){ return TOK_FUNC;}
        if (strcmp(idents, "return") == 0){ return TOK_RETURN;}
        if (strcmp(idents, "break") == 0){ return TOK_BREAK;}
        if (strcmp(idents, "continue") == 0){ return TOK_CONTINUE;}
        if (strcmp(idents, "true") == 0){ return TOK_TRUE;}
        if (strcmp(idents, "false") == 0){ return TOK_FALSE;}
        if (strcmp(idents, "type") == 0){ return TOK_TYPE;}

        // If not a keyword, it's an identifier
        return TOK_IDENT;
    }

    // Handle numbers (int and float)
    if (isdigit(c)) {
        int has_dot = 0;
        while (isdigit(code[*index]) || (code[*index] == '.' && !has_dot)) {
            if (code[*index] == '.') {
                has_dot = 1;
            }
            (*index)++;
        }
        return has_dot ? TOK_FLOAT : TOK_INT;
    }

    // If we reach here, the token is unrecognized
    printf("Error: Unrecognized character '%c'\n", c);
    exit(EXIT_FAILURE);
}

// Helper function to convert a token to its enum representation
int toTok(int code) {
    if (code >= 0 && code <= 49) {
        return code; // Return the token as it's already represented in the enum
    } else {
        printf("Error: Invalid token number '%d'\n", code);
        return -1; // Return an error value for an invalid token
    }
}

// Function to iterate over code and tokenize it
int getTokens(char *code) {
    int index = 0;
    toks current_token;
    while ((current_token = getCurrentToken(&index, code)) != TOK_EOF) {
        // Print each token (for debugging)
        printf("Token: %d\n", current_token);
        return current_token;
    }
    return 0;
}


//TODO: fuck, i deleated it... now to do it again

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
#endif

typedef enum toks
{
    // Misc
    TOK_EOF,   // End of file
    TOK_IDENT, // Identifier
    // Data types
    TOK_INT,   // Integer (round number)
    TOK_FLOAT, // Floating point number
    TOK_STR,   // String
    TOK_CHAR,  // Character
    // Boolean keywords
    TOK_BOOL,  // Boolean
    TOK_TRUE,  // True
    TOK_FALSE, // False
    // Operators
    TOK_EQ,    // Equal to
    TOK_NEQ,   // Not equal to
    TOK_LT,    // Less than
    TOK_GT,    // Greater than
    TOK_LEQ,   // Less than or equal to
    TOK_GEQ,   // Greater than or equal to
    TOK_AND,   // And
    TOK_OR,    // Or
    TOK_NOT,   // Not
    TOK_ADD,   // Add
    TOK_SUB,   // Subtract
    TOK_MUL,   // Multiply
    TOK_DIV,   // Divide
    TOK_MOD,   // Modulo
    TOK_INC,   // Increment
    TOK_DEC,   // Decrement
    TOK_ASSIGN,// Assign
    // Declarations
    TOK_VAR,   // Variable (with var)
    TOK_LET,    // Variable (with let)
    TOK_CONST,  // Constant (with const)
    TOK_TYPE,   // Type (with type)
    TOK_FUNC,   // Function (with fn)
    // Function keywords
    TOK_RETURN, // Return (with return)
    TOK_CALL,   // Calls a function (with call)
    // Conditionals
    TOK_IF,     // If (with if)
    TOK_ELSE,   // Else (with else)
    TOK_WHILE,  // While (with while)
    TOK_FOR,    // For (with for)
    TOK_IN,     // In (with in)
    TOK_BREAK,  // Break (with break)
    TOK_CONTINUE,// Continue (with continue)
    // Others
    TOK_INDENT, // Indentation
};

// Makes an array of identifiers
char idents[1000000]; // Don't confuse with the TOK_INDENT token

int getTokens(char *code) {
    int i = 0;
    for (i = 0; i < strlen(code); i++) {
        getCurrentToken(i, code);
    }
}

char getCurrentToken(int index, char *code) {
    char c = code[index];
    if (c == ' ') { // Skips whitespaces
        getCurrentToken(index++, code);
    }

    // Checks for a /
    if (c == '/') {
        if (getCurrentToken(index++, code) == '/') { // and then for other
            while (c != '\n') { // skips until a new line
                index++;
            }
            if (getCurrentToken(index, code)) {}
        } else if (c >= strlen(code)) { // if not, checks for EOF
            return TOK_EOF; // and returns it
        }
    } else {
        printf("Error: Unexpected character '%c'\n", c);
        exit(EXIT_FAILURE);
        }
}

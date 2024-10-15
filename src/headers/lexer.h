/*
#############################################
#### The Nain programming language lexer ####
#############################################
*/

#ifndef lexer_h
#define lexer_h

#include "../lib/log.h" // thanks to rxi for the amazing log.h library.
#include <stdio.h>
#include <string.h> // Added for strncmp

// Here the types of tokens
typedef enum
{
    TOK_WITH,
    TOK_LIB,
    TOK_FILE,
    TOK_FN,
    TOK_EOF,
    TOK_ERROR,
    TOK_INT,
    TOK_BOOL,
    TOK_STR,
    TOK_CHAR,
    TOK_FLOAT,
    TOK_DOUBLE,
    TOK_VAR,
    TOK_CONST,
    TOK_IF,
    TOK_ELSE,
    TOK_WHILE,
    TOK_FOR,
    TOK_IN,
    TOK_RETURN,
    TOK_TRUE,
    TOK_FALSE,
    TOK_NULL,
    TOK_BREAK,
    TOK_CONTINUE,
    TOK_AND,
    TOK_OR,
    TOK_NOT,
    TOK_NEW,
    TOK_DELETE,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_SEMI,
    TOK_COMMA,
    TOK_NO,
    // now, error tokens
    ERR_UNEXPECTED_CHAR,
    ERR_UNEXPECTED_EOF,
    ERR_UNMATCHED_PAREN,
    ERR_MISSING_PAREN,
    ERR_MISSING_BRACE,
    ERR_MISSING_SQUARE,
    ERR_MISSING_COMMA,
    ERR_UNEXPECTED_TOKEN,
    ERR_TOKEN_NOT_FOUND,
    ERR_LIBRARY_NOT_FOUND,
    ERR_FILE_NOT_FOUND,
    ERR_CONST_CHANGED,
    ERR_CONST_NOT_FOUND,
    ERR_VAR_NOT_FOUND,
    ERR_TYPE_MISMATCH,
} Toks;

// Function declarations

Toks getIfKeyword(int *index, char *input);
Toks getClosingOrOpeningToken(int *index, char *input);
Toks advance(int *index, char *input);

int getTokens(char *input) {
    // This function returns the tokens of the input
    int index = 0;
    while (input[index] != '\0') {
        Toks token = advance(&index, input);
        if (token == TOK_ERROR) {
            return 1; // Error occurred
        }
    }
    return 0; // No errors
}

Toks advance(int *index, char *input) {
    if (input[*index] == '\0') {
        return TOK_EOF; // Returns the EOF (end of file) token
    } else if (getClosingOrOpeningToken(index, input) != TOK_NO) {
        return getClosingOrOpeningToken(index, input);
    } else if (getIfKeyword(index, input) != TOK_NO) {
        return getIfKeyword(index, input);
    } else {
        log_warn("fatal: unexpected character: %c.", input[*index]);
    }
    return TOK_NO; // Fallback return
}

Toks getIfKeyword(int *index, char *input) {
    // Gets if input is a valid keyword, nor operators or identifiers
    if (strncmp(&input[*index], "for", 3) == 0) return TOK_FOR;
    if (strncmp(&input[*index], "if", 2) == 0) return TOK_IF;
    if (strncmp(&input[*index], "else", 4) == 0) return TOK_ELSE;
    if (strncmp(&input[*index], "while", 5) == 0) return TOK_WHILE;
    if (strncmp(&input[*index], "in", 2) == 0) return TOK_IN;
    if (strncmp(&input[*index], "return", 6) == 0) return TOK_RETURN;
    if (strncmp(&input[*index], "true", 4) == 0) return TOK_TRUE;
    if (strncmp(&input[*index], "false", 5) == 0) return TOK_FALSE;
    if (strncmp(&input[*index], "nil", 3) == 0) return TOK_NULL;
    if (strncmp(&input[*index], "break", 5) == 0) return TOK_BREAK;
    if (strncmp(&input[*index], "continue", 8) == 0) return TOK_CONTINUE;

    return TOK_NO; // Not a keyword
}

Toks getClosingOrOpeningToken(int *index, char *input) {
    // This function returns the closing or opening token of a parenthesis, brace, or bracket
    switch (input[*index]) {
    case '(': return TOK_LPAREN;   // Corrected to use TOK_LPAREN
    case ')': return TOK_RPAREN;   // Corrected to use TOK_RPAREN
    case '{': return TOK_LBRACE;    // Corrected to use TOK_LBRACE
    case '}': return TOK_RBRACE;    // Corrected to use TOK_RBRACE
    case '[': return TOK_LBRACKET;  // Corrected to use TOK_LBRACKET
    case ']': return TOK_RBRACKET;   // Corrected to use TOK_RBRACKET
    default: return TOK_NO;          // No token found
    }
}

#endif

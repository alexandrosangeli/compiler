typedef enum {
    TOKEN_EOF = 0,
    TOKEN_IDENTIFIER,
    TOKEN_RETURN,
    TOKEN_WHILE,
    TOKEN_FOR,
    TOKEN_ERROR,
    TOKEN_ADD,
    TOKEN_SUBTRACT,
    TOKEN_MULT,
    TOKEN_DIV,
    TOKEN_FUNCTION_CALL,
    TOKEN_FUNCTION_DEF
} token_t;
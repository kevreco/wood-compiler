#ifndef WOOD_LEXER_H
#define WOOD_LEXER_H

#include "manager.h"
#include "source_location.h"

#ifdef __cplusplus
extern "C" {
#endif

struct w_token_value {
	enum w_token_type type;
	dstr_view value;
};

struct w_token_float {
	enum w_token_type type;
	double float_value;
	bool overflow : 1;
	bool is_double : 1;
};

struct w_token_int {
	enum w_token_type type;
	int integer_value;
	bool overflow : 1;
};

struct w_token_bool {
	enum w_token_type type; 
	bool bool_value;
};

union w_token {
	enum w_token_type type; /* shared with all w_token_* struct below */
	struct w_token_value value;
	struct w_token_float f;
	struct w_token_int i;
};

struct w_lex {
    struct w_manager* mgr;

    const char* filepath;
    const char* src;
    const char* end;
    const char* cur;

    int len;

    union w_token token; /* current token */
    struct w_source_location location; /* current location */
};

void w_lex_init(struct w_lex* l, struct w_manager* mgr);
void w_lex_destroy(struct w_lex* l);

void w_lex_set_source(struct w_lex* l, const char* source_content, size_t source_len, const char* path);

enum w_token_type {

	/* Single character token */

	w_token_type_EOF,// =           '\0', // ascii 0 @UNUSED
	w_token_type_EXCLAM, // =       '!', // ascii 33 @UNUSED
	w_token_type_DOUBLE_QUOTE, // = '"', // ascii 34 @UNUSED
	w_token_type_HASH, // =         '#', // ascii 35 @UNUSED
	w_token_type_DOLLAR, // =       '$', // ascii 36 @UNUSED
	w_token_type_PERCENT, // =      '%', // ascii 37 @UNUSED
	w_token_type_AMP, // =          '&', // ascii 38 @UNUSED
	w_token_type_QUOTE, // =        ''', // ascii 39 @UNUSED
	w_token_type_PAREN_LEFT, // =   '(', // ascii 40 @UNUSED
	w_token_type_PAREN_RIGHT, // =  ')', // ascii 41 @UNUSED
	w_token_type_STAR, // =         '*', // ascii 42 @UNUSED
	w_token_type_Plus, // =         '+', // ascii 43 @UNUSED
	w_token_type_COMMA, // =        ',', // ascii 44 @UNUSED
	w_token_type_MINUS, // =        '-', // ascii 45 @UNUSED
	w_token_type_DOT, // =          '.', // ascii 46 @UNUSED
	w_token_type_SLASH, // =        '/', // ascii 47 @UNUSED
	w_token_type_COLON, // =        ':', // ascii 58 @UNUSED
	w_token_type_SEMI_COLON, // =   ';', // ascii 59 @UNUSED
	w_token_type_LESS, // =         '<', // ascii 60 @UNUSED
	w_token_type_EQUAL, // =        '=', // ascii 61 @UNUSED
	w_token_type_GREATER, // =      '>', // ascii 62 @UNUSED
	w_token_type_QUESTION, // =     '?', // ascii 63 @UNUSED
	/* 65-90 is ascii form A to Z */
	w_token_type_SQUARE_LEFT, // =  '[', // ascii 91 @UNUSED
	w_token_type_SQUARE_RIGHT, // = ']', // ascii 93 @UNUSED
	w_token_type_CARET, // =        '^', // ascii 94 @UNUSED
	/* 97-122 is ascii form a to z */
	w_token_type_BRACE_LEFT, // =   '{', // 123 @UNUSED
	w_token_type_PIPE, // =         '|', // 124 @UNUSED
	w_token_type_BRACE_RIGHT, // =  '}', // 125 @UNUSED
	w_token_type_TILDE, // =        '~', // 126 @UNUSED

	/*** Operators ***/

	/*  Comparison */
	w_token_type_EQUAL_EQUAL,   // "==" @UNUSED
	w_token_type_NOT_EQUAL,     // "!=" @UNUSED
	w_token_type_LESS_EQUAL,    // "<=" @UNUSED
	w_token_type_GREATER_EQUAL, // ">=" @UNUSED

	/* Logical */
	w_token_type_AMP_AMP,     // "&&" @UNUSED
	w_token_type_PIPE_PIPE,   // "||" @UNUSED

	/* Shift */
	w_token_type_LESS_LESS,       // "<<" @UNUSED
	w_token_type_GREATER_GREATER, // ">>" @UNUSED

	w_token_type_LESS_LESS_EQUAL,       // "<<=" @UNUSED
	w_token_type_GREATER_GREATER_EQUAL, // ">>=" @UNUSED

	w_token_type_ARROW,      // "->" @UNUSED

	/* ArithEqual */
	w_token_type_PLUS_EQUAL,  // "+=" @UNUSED
	w_token_type_MINUS_EQUAL, // "-=" @UNUSED
	w_token_type_MUL_EQUAL,   // "*=" @UNUSED
	w_token_type_DIV_EQUAL,   // "/=" @UNUSED
	w_token_type_MOD_EQUAL,   // "%=" @UNUSED

	/* BitwiseEqual */
	w_token_type_AMP_EQUAL,   // "&=" @UNUSED
	w_token_type_PIPE_EQUAL,  // "|=" @UNUSED
	w_token_type_CARET_EQUAL, // "^=" @UNUSED

	w_token_type_DOT_DOT,     // ".." @UNUSED
	w_token_type_DOT_DOT_DOT, // "..." @UNUSED

	/* Misc. */
	w_token_type_Error,

	/* Keywords */
	w_token_type_DEFER,  // defer @UNUSED
	w_token_type_ELSE,   // else @UNUSED
	w_token_type_ENUM,   // enum @UNUSED
	w_token_type_FOR,    // for @UNUSED
	w_token_type_IF,     // if @UNUSED
	w_token_type_RETURN, // return @UNUSED
	w_token_type_SIZEOF, // sizeof @UNUSED
	w_token_type_STRUCT, // struct @UNUSED
	w_token_type_WHILE,  // while @UNUSED

	/* Literals */
	token_type_NULL,              // null @UNUSED
	w_token_type_LITERAL_BOOL,    // true, false @UNUSED
	w_token_type_LITERAL_CHAR,    // '\n' @UNUSED
	w_token_type_LITERAL_INTEGER, // 42 @UNUSED
	w_token_type_LITERAL_FLOAT,   // 42.0f, 42.0 // float and double @UNUSED
	w_token_type_LITERAL_STRING,  // "my string" @UNUSED

	/* Identifier */
	w_token_type_IDENTIFIER, // @UNUSED
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_LEXER_H */
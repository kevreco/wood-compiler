#ifndef WOOD_LEXER_H
#define WOOD_LEXER_H

#include "manager.h"
#include "location.h"

#ifdef __cplusplus
extern "C" {
#endif

struct w_token_float {
	double value;
	bool overflow : 1;
	bool is_double : 1;
};

struct w_token_int {
	int value;
	bool overflow : 1;
};

struct w_token_bool {
	bool value;
};

struct w_token {
	enum w_token_type type;
	dstr_view text;
	union {
		struct w_token_float f;
		struct w_token_int i;
		struct w_token_bool b;
	} u;
};

struct w_lex_options {
	bool enable_hex_float;
};

struct w_lex {
    struct w_manager* mgr;
	struct w_lex_options options;

    const char* filepath;
    const char* src;
    const char* end;
    const char* cur;

    int len;

	struct w_token token; /* current token */
    struct w_location location; /* current location */
};

void w_lex_init(struct w_lex* l, struct w_manager* mgr);
void w_lex_destroy(struct w_lex* l);

void w_lex_set_source(struct w_lex* l, const char* source_content, size_t source_len, const char* filepath);
const struct w_token* w_lex_goto_next(struct w_lex* l);

dstr_view w_token_type_to_strv(enum w_token_type type);
dstr_view w_token_to_strv(const struct w_token t);

enum w_token_type {

	w_token_type_AMP,
	w_token_type_AMP_EQUAL,
	w_token_type_ARROW, 
	w_token_type_BRACE_L,
	w_token_type_BRACE_R,
	w_token_type_CARET,
	w_token_type_CARET_EQUAL,
	w_token_type_COLON,
	w_token_type_COMMA,
	w_token_type_DEFER,
	w_token_type_DIV_EQUAL,
	w_token_type_DOLLAR,
	w_token_type_DOT,
	w_token_type_DOUBLE_AMP,
	w_token_type_DOUBLE_DOT,
	w_token_type_DOUBLE_EQUAL,
	w_token_type_DOUBLE_GREATER,
	w_token_type_DOUBLE_LESS,
	w_token_type_DOUBLE_PIPE,
	w_token_type_DOUBLE_QUOTE,
	w_token_type_ELSE,
	w_token_type_ENUM,
	w_token_type_EOF,
	w_token_type_EQUAL,
	w_token_type_ERROR,
	w_token_type_EXCLAM,     
	w_token_type_FOR,    
	w_token_type_GREATER, 
	w_token_type_GREATER_EQUAL,
	w_token_type_HASH,   
	w_token_type_IDENTIFIER,
	w_token_type_IF,
	w_token_type_LESS,     
	w_token_type_LESS_EQUAL,
	w_token_type_LITERAL_BOOL,    
	w_token_type_LITERAL_CHAR,    
	w_token_type_LITERAL_FLOAT,   
	w_token_type_LITERAL_INTEGER,
	w_token_type_LITERAL_NULL,
	w_token_type_LITERAL_STRING,
	w_token_type_MINUS,   
	w_token_type_MINUS_EQUAL,
	w_token_type_MOD_EQUAL,
	w_token_type_MUL_EQUAL,
	w_token_type_NOT_EQUAL,
          
	w_token_type_PAREN_L, 
	w_token_type_PAREN_R,
	w_token_type_PERCENT,
	w_token_type_PIPE,   
	w_token_type_PIPE_EQUAL,
	w_token_type_PLUS,      
	w_token_type_PLUS_EQUAL,
	w_token_type_QUESTION, 
	w_token_type_QUOTE,  
	w_token_type_RETURN,
	w_token_type_SEMI_COLON,
	w_token_type_SIZEOF,
	w_token_type_SLASH,  
	w_token_type_SQUARE_L,
	w_token_type_SQUARE_R,
	w_token_type_STAR,
	w_token_type_STRUCT,
	w_token_type_TILDE,
	w_token_type_TRIPLE_DOT,
	w_token_type_WHILE,
	w_token_type_COUNT
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_LEXER_H */
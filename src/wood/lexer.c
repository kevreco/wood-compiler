#include "lexer.h"

void w_lex_init(struct w_lex* l, struct w_manager* mgr)
{
	memset(l, 0, sizeof(struct w_lex));

	l->mgr = mgr;
}

void w_lex_destroy(struct w_lex* l)
{
	(void)l;
}

void w_lex_set_source(struct w_lex* l, const char* source_content, size_t source_len, const char* path)
{
	(void)l;
	(void)source_content;
	(void)source_len;
	(void)path;
}

const union w_token w_lex_get_next(struct w_lex* l)
{
	(void)l;
	union w_token t = {0};
	return t;
}

void w_lex_goto_next(struct w_lex* l)
{
	(void)l;
}
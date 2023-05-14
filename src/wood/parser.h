#ifndef WOOD_PARSER_H
#define WOOD_PARSER_H

#include "lexer.h"
#include "manager.h"

#ifdef __cplusplus
extern "C" {
#endif

struct w_parser
{
	struct w_manager* mgr;
	struct w_lex lex;
};

void w_parser_init(struct w_parser* p, struct w_manager* mgr);
void w_parser_destroy(struct w_parser* p);

bool w_parser_parse(struct w_parser* p, const char* content, size_t size, const char* filepath);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_PARSER_H */
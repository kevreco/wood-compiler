#include "parser.h"

void w_parser_init(struct w_parser* c, struct w_manager* mgr)
{
	memset(c, 0, sizeof(struct w_parser));

	c->mgr = mgr;
}

void w_parser_destroy(struct w_parser* c)
{
	(void)c;
}

bool w_parser_parse(struct w_parser* c, const char* content, size_t size, const char* filepath)
{
	(void)c;
	(void)content;
	(void)size;
	(void)filepath;

	return false;
}
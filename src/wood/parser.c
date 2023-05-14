#include "parser.h"

#include "global.h"
#include "lexer.h"

void w_parser_init(struct w_parser* p, struct w_manager* mgr)
{
	memset(p, 0, sizeof(struct w_parser));

	p->mgr = mgr;

	w_lex_init(&p->lex, mgr);
}

void w_parser_destroy(struct w_parser* p)
{
	(void)p;

	w_lex_destroy(&p->lex);
}

bool w_parser_parse(struct w_parser* p, const char* content, size_t content_size, const char* filepath)
{
	w_lex_set_source(&p->lex, content, content_size, filepath);

	int serial_id = 0; /* @TODO, remove this, this is just for debugging purpose */
	const struct w_token* token;
	while ((token = w_lex_goto_next(&p->lex))->type != w_token_type_EOF)
	{
		dstr_view str = w_token_to_strv(*token);
		printf("%d : '%.*s' \n", serial_id, str.size, str.data);

		++serial_id;
	}

	return true;
}

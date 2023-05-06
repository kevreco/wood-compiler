#include "compiler.h"

#include <re/dstr.h>

#include "parser.h"
#include "converter_c.h"

void w_compiler_options_init_default(struct w_compiler_options* o)
{
	o->step = w_compilation_step_ALL;
}

void w_compiler_init(struct w_compiler* c, struct w_compiler_options options)
{
	memset(c, 0, sizeof(struct w_compiler));

	c->options = options;

	w_manager_init(&c->mgr);
}

void w_compiler_destroy(struct w_compiler* c)
{
	w_manager_destroy(&c->mgr);
}

bool w_compiler_compile(struct w_compiler* c, const char* wood_file, const char* c_file)
{
	/* load file into memory */
	struct w_source_file* source = w_manager_load_content(&c->mgr, wood_file);

	if (!source)
	{
		return 0;
	}

	/*** Parsing ***/
	
	struct w_parser parser;
	w_parser_init(&parser, &c->mgr);

	if (!w_parser_parse(&parser,
		source->content.data,
		source->content.size, 
		source->filepath)
		) {
		return false;
	}
	
	/*** Type/semantic check ***/

	if ((c->options.step & w_compilation_step_SEMANTIC) == 0) return true;
	
	/* @TODO */
	
	/*** Generate ***/

	if ((c->options.step & w_compilation_step_GENERATING) == 0) return true;


	struct w_converter_c conv;

	w_converter_c_init(&conv, &c->mgr);

	w_converter_c_convert(&conv, c_file);

	w_converter_c_destroy(&conv);

	return true;
}
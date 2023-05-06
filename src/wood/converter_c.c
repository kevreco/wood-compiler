#include "converter_c.h"

void w_converter_c_init(struct w_converter_c* c, struct w_manager* mgr)
{
	memset(c, 0, sizeof(struct w_converter_c));

	c->mgr = mgr;
}

void w_converter_c_destroy(struct w_converter_c* c)
{
	(void)c;
}

void w_converter_c_convert(struct w_converter_c* c, const char* filepath)
{
	(void)c;
	(void)filepath;

	printf("w_converter_c_convert: @WIP, at some point this will create a .c file from a .w file.");
}
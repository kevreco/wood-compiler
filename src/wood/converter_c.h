#ifndef WOOD_CONVERTER_C_H
#define WOOD_CONVERTER_C_H

#include "manager.h"

#ifdef __cplusplus
extern "C" {
#endif

struct w_converter_c
{
	struct w_manager* mgr;
};

void w_converter_c_init(struct w_converter_c* c, struct w_manager* mgr);
void w_converter_c_destroy(struct w_converter_c* c);

void w_converter_c_convert(struct w_converter_c* c, const char* filepath);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_CONVERTER_C_H */
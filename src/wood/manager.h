#ifndef WOOD_MANAGER_H
#define WOOD_MANAGER_H

#include "stdbool.h"

#include <re/dstr.h>

#ifdef __cplusplus
extern "C" {
#endif

struct w_source_file
{
	const char* filepath; /* using dstr instead of dstr_view fopen requires a c string at the end */
	dstr content;
};

struct w_manager
{
	/* keep reference to destroy it. */
	struct w_source_file source_file;
};

void w_manager_init(struct w_manager* m);
void w_manager_destroy(struct w_manager* m);

struct w_source_file* w_manager_load_content(struct w_manager* m, const char* filepath);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_MANAGER_H */
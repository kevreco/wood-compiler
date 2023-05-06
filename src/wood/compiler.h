#ifndef WOOD_COMPILER_H
#define WOOD_COMPILER_H

#include "manager.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

enum w_compilation_step {
	w_compilation_step_NONE = 1 << 0,
	w_compilation_step_SEMANTIC = 1 << 2,
	w_compilation_step_GENERATING = 1 << 3,
	w_compilation_step_ALL = w_compilation_step_SEMANTIC | w_compilation_step_GENERATING,
};

struct w_compiler_options
{
	enum w_compilation_step step;
};

struct w_compiler
{
	struct w_compiler_options options;
	struct w_manager mgr;
};

void w_compiler_options_init_default(struct w_compiler_options* o);

void w_compiler_init(struct w_compiler* c, struct w_compiler_options o);
void w_compiler_destroy(struct w_compiler* c);

bool w_compiler_compile(struct w_compiler* c, const char* wood_file, const char* c_file);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_COMPILER_H */
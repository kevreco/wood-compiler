#ifndef WOOD_LOCATION_H
#define WOOD_LOCATION_H

#include <re/dstr.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct w_location
{
	const char* filepath;
	int row, col, pos;
};

/* @UNUSED */
static void w_location_init(struct w_location* l) {
	l->filepath = 0;
	l->row = -1;
	l->col = -1;
	l->pos = -1;
}

static void w_location_init_with_file(struct w_location* l, const char* filepath) {
	l->filepath = filepath;
	l->row = 1;
	l->col = 0;
	l->pos = 0;
}

/* @UNUSED */
static inline bool w_location_has_row_and_column(const struct w_location* l) {
	l->row > -1 && l->col > -1 && l->pos > -1;
}

/* @UNUSED */
static inline bool w_location_is_empty(const struct w_location* l) {
	return l->filepath == 0 && !w_location_has_row_and_column(l);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_LOCATION_H */
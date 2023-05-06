#ifndef WOOD_SOURCE_LOCATION_H
#define WOOD_SOURCE_LOCATION_H

#include <re/dstr.h>

#ifdef __cplusplus
extern "C" {
#endif

struct w_source_location
{
	const char* filepath;
	int row, col, pos;
};

static inline struct w_source_location source_location_make(struct w_source_location* l) {
	l->filepath = 0;
	l->row = -1;
	l->col = -1;
	l->pos = -1;
}

static inline void source_location_increment_row(struct w_source_location* l) {
	l->row++;
	l->col = 0;
	l->pos++;
}

static inline void source_location_increment_column(struct w_source_location* l) {
	l->col++;
	l->pos++;
}

static inline bool source_location_has_row_and_column(const struct w_source_location* l) {
	l->row > -1 && l->col > -1 && l->pos > -1;
}

static inline bool source_location_is_empty(const struct w_source_location* l) {
	return l->filepath == 0 && !source_location_has_row_and_column(l);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_SOURCE_LOCATION_H */
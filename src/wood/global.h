#ifndef WOOD_GLOBAL_H
#define WOOD_GLOBAL_H

#include "location.h"

#ifdef __cplusplus
extern "C" {
#endif

void w_report_error(const char* fmt, ...);
void w_report_warning(const char* fmt, ...);
void w_report_error_loc(struct w_location loc, const char* fmt, ...);
void w_report_warning_loc(struct w_location loc, const char* fmt, ...);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_GLOBAL_H */
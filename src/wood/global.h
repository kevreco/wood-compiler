#ifndef WOOD_GLOBAL_H
#define WOOD_GLOBAL_H

#ifdef __cplusplus
extern "C" {
#endif

void w_report_error(const char* fmt, ...);
void w_report_warning(const char* fmt, ...);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WOOD_GLOBAL_H */
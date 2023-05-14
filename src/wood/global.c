#include "global.h"

#include <stdarg.h>
#include <stdio.h>

#include "location.h"

static void report_error_v(const char* fmt, va_list args);
static void report_warning_v(const char* fmt, va_list args);

void w_report_error(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	report_error_v(fmt, args);

	va_end(args);
}

void w_report_warning(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	report_warning_v(fmt, args);

	va_end(args);
}

static void report_error_v(const char* fmt, va_list args)
{
	vfprintf(stderr, fmt, args);
}

static void report_warning_v(const char* fmt, va_list args)
{
	/* for now we report warning the same way we report errors */
	vfprintf(stderr, fmt, args);
}

void w_report_error_loc(struct w_location loc, const char* fmt, ...)
{
	(void)loc;
	(void)fmt;

	assert(0 && "@TODO");
}

void w_report_warning_loc(struct w_location loc, const char* fmt, ...)
{
	(void)loc;
	(void)fmt;

	assert(0 && "@TODO");
}
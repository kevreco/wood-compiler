#include "manager.h"

#include "stdbool.h"

#include "re/file/file.h"
#include "re/file/path.h"

#include "global.h"

bool try_get_file_content(const char* filepath, dstr* content);

void w_manager_init(struct w_manager* m)
{
	memset(m, 0, sizeof(struct w_manager));
}

void w_manager_destroy(struct w_manager* m)
{
	if (!dstr_empty(&m->source_file.content))
	{
		dstr_destroy(&m->source_file.content);
	}
}

struct w_source_file* w_manager_load_content(struct w_manager* m, const char* filepath)
{
	if (m->source_file.content.data != 0)
	{
		w_report_error("w_manager_load_content: Cannot load multiple content.");
		return 0;
	}

	if (!re_file_exists(filepath))
	{
		w_report_error("w_manager_load_content: file '%s' does not exist.", filepath);
		return 0;
	}

	dstr content;
	dstr_init(&content);

	if (try_get_file_content(filepath, &content))
	{
		m->source_file.filepath = filepath;
		m->source_file.content = content;

		return &m->source_file;
	}
	else
	{
		w_report_error("w_manager_load_content: Cannot load file into memory.");
		return 0;
	}
}

bool try_get_file_content(const char* filepath, dstr* content)
{
	if (!re_path_is_absolute_str(filepath)) {
		w_report_error("try_get_file_content: filepath must be an absolute path.\n");
		return false;
	}

	if (!re_file_exists(filepath)) {
		w_report_error("try_get_file_content: file does not exist.\n");
		return false;
	}

	// [Windows] "rb" is need to avoid some translation/encoding platform dependent stuff
	// \r\n are handled in the lexer
	FILE* file;
	errno_t error = fopen_s(&file, filepath, "rb");

	if (error != 0) {
		w_report_error("try_get_file_content: can't open '%s'.\n", filepath);
		return false;
	}

	// TODO: move this into a function in re/file.h ?
	fseek(file, 0, SEEK_END);
	long fsize = ftell(file);
	fseek(file, 0, SEEK_SET);

	if (!fsize) {
		w_report_warning("try_get_file_content: empty file '%s'\n", filepath);
		return true;
	}

	re_file_read_all(content, file);

	if (dstr_empty(content)) {
		w_report_error("try_get_file_content: can't read file content'%s'\n", filepath);
		return false;
	}

	return true;
}

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WOOD_VERSION "0.0.0-dev"

struct cmd
{
	int (*func)(const struct cmd* cmd, int argc, char** argv);
	const char* name;
	unsigned int strlen;
	const char* usage;
};

int help(const struct cmd* cmd, int argc, char** argv);
int version(const struct cmd* cmd, int argc, char** argv);
int compile(const struct cmd* cmd, int argc, char** argv);

static const struct cmd commands[] = {
	{help,    "help",    sizeof("help") -1,     "wood help"},
	{version, "version", sizeof("version") - 1, "wood version"},
	{compile, "compile", sizeof("compile") - 1, "wood compile <filename>"},
	{0, 0, 0, 0},
};

int display_help() { help(0, 0, 0); return -1; }

int help(const struct cmd* cmd, int argc, char** argv )
{
	(void)cmd;
	(void)argc;
	(void)argv;

	const struct cmd* c = commands;

	fprintf(stdout, "Wood compiler command line interface.");
	fprintf(stdout, "usage:\n");


	while (c->name)
	{
		fprintf(stdout, "\n%s", c->usage);
		++c;
	}

	return 0;
}

int version(const struct cmd* cmd, int argc, char** argv)
{
	(void)cmd;
	(void)argc;
	(void)argv;
	
	fprintf(stdout, WOOD_VERSION);

	return 0;
}

int compile(const struct cmd* cmd, int argc, char** argv)
{
	(void)cmd;
	(void)argc;
	(void)argv;

	fprintf(stderr, "Not implemented yet");

	return 0;
}

int main(int argc, char** argv)
{
	char* command_name;
	int result = 0;
	const struct cmd* c = commands;

	if (!*argv) { /* no argument */
		return display_help();
	}

	/* skip application name */
	--argc;
	++argv;

	if (!*argv) { /* no argument */
		return display_help();
	}

	/* process first command and go to next */
	command_name = *argv;
	--argc;
	++argv;

	while (c->name)
	{
		if (strncmp(command_name, c->name, c->strlen) == 0)
		{
			result = c->func(c, argc, argv);
			break;
		}
		++c;
	}

	/* we reach the end of commands list, no command was found, display help */
	if (c->name == 0) {
		return display_help();
	}

	return result;
}

#ifdef __cplusplus
} /* extern "C" */
#endif
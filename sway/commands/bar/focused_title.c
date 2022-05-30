#include <stdlib.h>
#include <string.h>
#include "sway/commands.h"
#include "log.h"

// Must be in alphabetical order for bsearch
static const struct cmd_handler bar_focused_title_handlers[] = {
	{ "max_length", bar_cmd_focused_title_max_length },
	{ "only_active_output", bar_cmd_focused_title_only_active_output },
};

struct cmd_results *bar_cmd_focused_title_max_length(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "max_length", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}
	int max_length = atoi(argv[0]);
	if (max_length < 0) {
		return cmd_results_new(CMD_INVALID,
				"Invalid focused title max height value: %s", argv[0]);
	}
	config->focused_title->max_length = max_length;
	sway_log(SWAY_DEBUG, "Setting focused title max length %d on bar: %s",
			max_length, config->current_bar->id);
	return cmd_results_new(CMD_SUCCESS, NULL);
}

struct cmd_results *bar_cmd_focused_title_only_active_output(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "only_active_output", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}
	bool only_active_output = atob(argv[0]);
	if (max_length < 0) {
		return cmd_results_new(CMD_INVALID,
				"Invalid focused title max height value: %s", argv[0]);
	}
	config->focused_title->max_length = max_length;
	sway_log(SWAY_DEBUG, "Setting focused title max length %d on bar: %s",
			max_length, config->current_bar->id);
	return cmd_results_new(CMD_SUCCESS, NULL);
}


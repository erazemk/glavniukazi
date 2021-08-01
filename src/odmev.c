#include <stdio.h>

int odmev(int argc, char **argv) {
	if (argc >= 1) {
		fprintf(stdout, "%s", argv[1]);
		for (int i = 2; i <= argc; i++) fprintf(stdout, " %s", argv[i]);
	}

	fprintf(stdout, "\n");
	return 0;
}

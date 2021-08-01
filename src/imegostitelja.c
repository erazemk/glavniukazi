#include <stdio.h>
#include <unistd.h>

int imegostitelja(int argc, char** argv) {
	char imegostitelja[512];
	imegostitelja[511] = '\0';
	gethostname(imegostitelja, 511);
	fprintf(stdout, "%s\n", imegostitelja);
	return 0;
}

#include <stdio.h>

int macka(int argc, char* argv[]) {
	int crka;
	for (int i = 1; i < argc; i++) {
		FILE *datoteka = fopen(argv[i], "r");
		if (datoteka == NULL) {
			fprintf(stdout, "Datoteka %s ne obstaja.", argv[i]);
			return 1;
		}

		while ((crka = getc(datoteka)) != EOF) {
			putc(crka, stdout);
		}

		putc('\n', stdout);
	}

	return 0;
}

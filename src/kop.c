#include <stdio.h>

int kop(int argc, char* argv[]) {
	FILE *vhod;
	FILE *izhod;
	int znak;

	if (argc != 2) {
		fprintf(stderr, "%s potrebuje dva argumenta.", argv[0]);
		return 1;
	}

	vhod = fopen(argv[2], "r");
	if (vhod == NULL) {
		fprintf(stderr, "Datoteka %s ne obstaja.", argv[1]);
		return 1;
	}

	izhod = fopen(argv[3], "w");
	if(izhod == NULL) {
		fprintf(stderr, "Datoteke %s ni bilo mogoče ustvariti", argv[2]);
		return 1;
	}

	do {
		znak = fgetc(vhod);
		if (znak != EOF) {
			fputc(znak, izhod);
		}
	} while (znak != EOF);

	fclose(vhod);
	fclose(izhod);
	return 0;
}

#include <stdio.h>
#include <dirent.h>

int imv(int argc, char** argv) {
	if (argc != 1) {
		fprintf(stderr, "%s potrebuje en argument.", argv[0]);
		return 1;
	}

	DIR *mapa;
	struct dirent *dat;
	mapa = opendir(argv[1]);

	if (mapa != NULL) {
		while (dat = readdir(mapa)) {
			puts(dat->d_name);
		}

		(void) closedir(mapa);
	} else {
		fprintf(stderr, "%s ni mogel odpreti mape %s\n", argv[0], argv[1]);
	}
}

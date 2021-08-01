#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include "glave.h"

int pomoc(char* argv[]);

int main(int argc, char* argv[]) {
	if (argc < 2) {
		pomoc(&argv[0]);
		return 1;
	}

	argc -= 2;

	int arg;
	while ((arg = getopt(argc, argv, "h")) != -1) {
		switch(arg) {
		case 'h':
			pomoc(&argv[0]);
		}
	}


	if (strncmp(argv[1], "imegostitelja", 14) == 0) return imegostitelja(argc, &argv[1]);
	else if (strncmp(argv[1], "kop", 4) == 0) return kop(argc, &argv[1]);
	else if (strncmp(argv[1], "macka", 6) == 0) return macka(argc, &argv[1]);
	else if (strncmp(argv[1], "napacno", 3) == 0) return napacno(argc, &argv[1]);
	else if (strncmp(argv[1], "odmev", 6) == 0) return odmev(argc, &argv[1]);
	//else if (strncmp(argv[1], "podlaga32", 10) == 0) return podlaga32(argc, &argv[1]);
	//else if (strncmp(argv[1], "podlaga64", 10) == 0) return podlaga64(argc, &argv[1]);
	else if (strncmp(argv[1], "res", 4) == 0) return res(argc, &argv[1]);
	else return pomoc(&argv[0]);
}

int pomoc(char *argv[]) {
	fprintf(stdout, "Uporaba: %s [ukaz] (argumenti)", argv[0]);
	return 0;
}

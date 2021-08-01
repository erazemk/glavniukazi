#include <stdio.h>

int podlaga32(int argc, char* argv[]){
    if (argc != 2) {
		fprintf(stderr, "%s potrebuje argument.", argv[0]);
		return 1;
	}

    FILE *vhod = fopen(argv[1],"r");
    if(vhod == NULL){
        fprintf(stdout, "Datoteke %s ni mogoče odpreti", argv[1]);
    }

    char* abeceda = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    char* medpomnilnik;
    int n;
    while( (n = fread(medpomnilnik, 1, 5, vhod)) != 0){
        char* kodirano = "========";
        switch(n){
            case 5:
                kodirano[7] = abeceda[medpomnilnik[4] & 0x1f];
                kodirano[6] = abeceda[((medpomnilnik[3] & 0x3) << 3) + ((medpomnilnik[4] & 0xC0) >> 5)];
            case 4:
                if(kodirano[6] == '=') kodirano[6] = abeceda[((medpomnilnik[3] & 0x3) << 3)];
                kodirano[5] = abeceda[((medpomnilnik[3] & 0x7E) >> 2)];
                kodirano[4] = abeceda[((medpomnilnik[3] & 0x80) >> 7) + ((medpomnilnik[2] & 0xF) << 1)];
            case 3:
                if(kodirano[4] == '=') kodirano[4] = abeceda[((medpomnilnik[2] & 0xF) << 1)];
                kodirano[3] = abeceda[((medpomnilnik[2] & 0xF0) >> 4) + ((medpomnilnik[1] & 0x1) << 4)];
            case 2:
                if(kodirano[3] == "=") kodirano[3] = abeceda[(medpomnilnik[1] & 0x1) << 4];
                kodirano[2] = abeceda[(medpomnilnik[1] & 0x3E) >> 1];
                kodirano[1] = abeceda[((medpomnilnik[1] & 0xC0) >> 6) + ((medpomnilnik[0] & 0x7) << 2)];
            case 1:
                if(kodirano[1] == "=") kodirano[1] = abeceda[((medpomnilnik[0] & 0x7) << 2)];
                kodirano[0] = abeceda[(medpomnilnik[0] & 0xF8) >> 3];
        }
        fprintf(stdout, "%s", kodirano);
    }
}

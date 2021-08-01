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

    char* abeceda = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char* medpomnilnik;
    int n;
    while( (n = fread(medpomnilnik, 1, 3, vhod)) != 0){
        char* kodirano = "====";
        switch(n){
            case 3:
                kodirano[3] = abeceda[(medpomnilnik[2] & 0x3F)];
                kodirano[2] = abeceda[((medpomnilnik[2] & 0xC0) >> 6) + ((medpomnilnik[2] & 0xF) << 2)];
            case 2:
                if(kodirano[2] == "=") kodirano[2] = abeceda[((medpomnilnik[1] & 0xF) << 2)];
                kodirano[1] = abeceda[((medpomnilnik[1] & 0xF0) >> 4) + ((medpomnilnik[0] & 0x3) << 4)];
            case 1:
                if(kodirano[1] == "=") kodirano[1] = abeceda[((medpomnilnik[0] & 0x3) << 4)];
                kodirano[0] = abeceda[(medpomnilnik[0] & 0xFC) >> 2];
        }
        fprintf(stdout, "%s", kodirano);
    }
}

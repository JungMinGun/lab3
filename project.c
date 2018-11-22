#include <stdio.h>
#include <stlib.h>
#include <errno.h>

void main(int argc, char *argv[]){
	FILE *src;
	FILE *dst;
	char cj; init count = 0;

	if(argc <3){
		printf("Usage#include <stdio.h>
#include <stlib.h>
#include <errno.h>

void main(int argc, char *argv[]) {
        FILE *src;
        FILE *dst;
        char ch; int count = 0;

        if (argc < 3) {
                printf("Usage: file_copy source_file destination_file\ n");
                exit(1);
        }
        if ((src = fopen(argv[1], "r")) == NULL ) {
                perror("fopen: src");
                exit(1);
        }
        if ((dst = fopen(argv[2], "w")) == NULL ) {
                perror("fopen: dst");
                exit(1);
        }
        while (!feof(src)) {
                ch = (char) fgetc(src);
                if (ch != EOF)
                        fputc((int)ch, dst);
                        count++;
        }

#include <stdio.h>
#include <stdarg.h>
#include "../include/stdin_stdout.h"


void print_stdin_to_stdout(FILE *stdin, FILE *stdout) {
    int c;

    while ((c = getc(stdin)) != EOF) {
        putc(c, stdout);
    }
}

void print_file_content_to_stdout(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Expected a file as input arg(s)");
        return;
    }

    FILE *file;

    while (--argc > 0) {
        file = fopen(*++argv, "r");

        if (file == NULL) {
            fprintf(stderr, "Cannot open file: %s ", *argv);
            return;
        }

        print_stdin_to_stdout(file, stdout);

        fclose(file);
    }
}


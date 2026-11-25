#include <stdio.h>
#include "../include/stdin_stdout.h"

int main(int argc, char *argv[]) {
   if (argc > 1) {
      print_file_content_to_stdout(argc, argv);
   } else {
      print_stdin_to_stdout(stdin, stdout);
   }
}


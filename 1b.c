//cp command
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 8192

int main(int argc, char* argv[]) {
    int input_fd, output_fd;
    ssize_t ret_in, ret_out;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: cp file1 file2");
        return 1;
    }

    input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        perror("open");
        return 2;
    }

    output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (output_fd == -1) {
        perror("open");
        return 3;
    }

    while ((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0) {
        ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
        if (ret_out != ret_in) {
            perror("write");
            return 4;
        }
    }

    close(input_fd);
    close(output_fd);
    return EXIT_SUCCESS;
}
/*Command Line: 
    $ gcc cpprogram.c
    $ ./a.out file1 file2 
*/

//mvcommand
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int input_fd, output_fd;

    if (argc != 3) {
        printf("Usage: mv file1 file2\n");
        return 1;
    }

    input_fd = link(argv[1], argv[2]);
    if (input_fd == -1) {
        perror("link error");
        return 2;
    }

    output_fd = unlink(argv[1]);
    if (output_fd == -1) {
        perror("unlink");
        return 3;
    }

    return 0;
}
 /* 
    $ gcc mvprogram.c
    $ ./a.out file1 file2
 */

//rm command
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: rm file\n");
        return 1;
    }

    int output_fd = unlink(argv[1]);
    if (output_fd == -1) {
        perror("unlink error");
        return 3;
    }

    return 0;
}
/*
$ gcc rmprogram.c
$ ./a.out file1
    */
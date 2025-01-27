#include <stdio.h>
#include <dirent.h>   //handle directory
#include <sys/stat.h> //file info
#include <pwd.h>      //user info
#include <grp.h>
#include <time.h>
#include <unistd.h>

int main()
{
    //execl("/bin/ls", "ls", "-la", NULL);   
    DIR *d;            // directory
    struct dirent *de; // directory entry
    struct stat buf;   // file info
    int i, j;
    char P[10] = "rwxrwxrwx", AP[10] = " ";
    struct passwd *p;
    struct group *g;
    struct tm *t;
    char time[26];
    d = opendir(".");
    readdir(d);
    readdir(d);
    while ((de = readdir(d)) != NULL) // read all entries until end of directory
    {
        stat(de->d_name, &buf);
        // File Type
        if (S_ISDIR(buf.st_mode))
            printf("d");
        else if (S_ISREG(buf.st_mode))
            printf("-");
        else if (S_ISCHR(buf.st_mode))
            printf("c");
        else if (S_ISBLK(buf.st_mode))
            printf("b");
        else if (S_ISLNK(buf.st_mode))
            printf("l");
        else if (S_ISFIFO(buf.st_mode))
            printf("p");
        else if (S_ISSOCK(buf.st_mode))
            printf("s");

        // File Permissions P-Full Permissions AP-Actual Permissions
        for (i = 0, j = (1 << 8); i < 9; i++, j >>= 1)
            AP[i] = (buf.st_mode & j) ? P[i] : '-';
        printf("%s", AP);

        // No. of Hard Links
        printf("%5d", buf.st_nlink);

        // User Name
        p = getpwuid(buf.st_uid);
        printf(" %.8s", p->pw_name);

        // Group Name
        g = getgrgid(buf.st_gid);
        printf(" %-8.8s", g->gr_name);

        // File Size
        printf(" %8lld", buf.st_size);

        // Date and Time of modification
        t = localtime(&buf.st_mtime);
        strftime(time, sizeof(time), "%b %d %H:%M", t);
        printf(" %s", time);

        // File Name
        printf(" %s\n", de->d_name);
    }
}
// Command-line execution

//     $ gcc lsprogram.c
//     $ ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void traverse_dir(const char *path, int depth);

// checks command line arguemnts and starts traversal
int main(int argc, char **argv) {

    if (argc != 2) {
        // checks for exactly one arguement

        fprintf(stderr, "Usage: %s <starting_directory_path>\n", argv[0]);

        exit(EXIT_FAILURE);
    }

    printf("||| Recursive File System Traversal |||\n");

    // start at depth 0
    traverse_dir(argv[1], 0);

    return EXIT_SUCCESS;
}


 // recursively traverses the file system.

void traverse_dir(const char *path, int depth) {
    DIR *dp;
    struct dirent *dirp;
    struct stat statbuf;
    
    // create indentation string based on depth
    char indentation[100];
    memset(indentation, ' ', 100);
    
    if (depth * 2 < 100) {

        indentation[depth * 2] = '\0';
    } else 
    {
        // Safety fallback for very deep paths
        indentation[0] = '\0';
    }

    //  open directory stream
    if ((dp = opendir(path)) == NULL) {

        fprintf(stderr, "%sError occured opening directory %s\n", indentation, path);

        return;
    }

    // read entries
    while ((dirp = readdir(dp)) != NULL) {
        // Skip current directory (.) and parent directory (..) to prevent infinite loops
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {

            continue;
        }

        // construct full path
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, dirp->d_name);

        // file status
        if (lstat(full_path, &statbuf) < 0) {

            fprintf(stderr, "%sError when calling lstat on %s\n", indentation, full_path);

            continue;
        }

        // check whether directory, or file
        if (S_ISDIR(statbuf.st_mode)) {

            // It is a directory
            printf("%s[DIR] %s\n", indentation, dirp->d_name);
            
            
            traverse_dir(full_path, depth + 1);

        } else if (S_ISREG(statbuf.st_mode)) {
            // if regular file

            printf("%s[FILE] %s\n", indentation, dirp->d_name);

        } else {

            // other file types (link, FIFO, etc.)
            printf("%s[OTHER] %s\n", indentation, dirp->d_name);
        }
    }

    // close directory stream
    closedir(dp);
}

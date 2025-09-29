CS 332/532 - Lab 5: Recursive Directory Traversal
Program: recursive_readdir.c

This C program implements a recursive file system traversal utility. It takes a starting directory path as a command-line argument. It prints the entire hierarchy of files and subdirectories within it, using indentation to represent the depth of the directory structure.

 The program uses  UNIX system calls as required by the lab:

    opendir: To open and access directory streams.

    readdir: To read entries (files and directories) from the stream.

    lstat: To retrieve file status information (specifically, the file type).

How to Compile

Use the GNU Compiler Collection (gcc) on a CS Linux system.

gcc -o recursive_readdir recursive_readdir.c

How to Run

Execute the compiled program by providing the desired starting path as an argument.

Example Command
	

Description

./recursive_readdir .
	

Traverses the current directory (and all subdirectories).

./recursive_readdir /home/user/test
	

Traverses the specified absolute path.

Expected Output Format:

The program outputs the file type and name, indented by two spaces for each level of depth.

--- Recursive File System Traversal ---
[DIR] .
  [FILE] file1.txt
  [DIR] subdir1
    [FILE] inner_file.c
  [OTHER] symbolic_link

Program Logic Overview

The core functionality is contained within the traverse_dir function, which operates recursively:

    Error Handling: It first attempts to opendir and immediately returns if the directory cannot be opened.

    Traversal Loop: It uses a while loop with readdir to process every entry in the current directory.

    Skipping: It ignores . (current directory) and .. (parent directory) entries to prevent infinite recursion.

    Path Construction: It dynamically constructs the full_path for each entry to correctly call lstat.

    Type Check: It uses lstat to get the file status and the S_ISDIR macro to check if the entry is a directory.

    Recursion: If the entry is a directory, it prints the entry and makes a recursive call to traverse_dir, increasing the depth counter for proper indentation.

    Cleanup: Finally, it calls closedir to release the directory stream resources.
![printf image image (1)](https://pbs.twimg.com/media/Gg3-FCFWwAEnvUE?format=jpg&name=medium)

# **Simple Shell**

## Description
This project aims to implement a simple shell program that reads commands, processes them, and executes the corresponding programs in a child process. It involves various concepts such as dynamic memory allocation, string manipulation, linked lists, and process management.

The program reads input from the user, tokenizes the command using spaces as delimiters, and looks for the command in the directories specified by the PATH variable.

## Files
[simpleshell01.c](https://github.com/tramiNGY/holbertonschool-simple_shell/blob/main/simpleshell01.c)
These functions form a basic shell that can execute commands by searching for executables in the PATH directories, forking a child process, and running the command with arguments passed from the user input. It handles basic command execution and errors, and manages memory dynamically to ensure smooth execution.

[processcommand.c](https://github.com/tramiNGY/holbertonschool-simple_shell/blob/main/processcommand.c)
This function is responsible for taking a user input command, finding its executable in the system, forking a child process to execute it, and managing errors and memory throughout the process.

[pathvar.c](https://github.com/tramiNGY/holbertonschool-simple_shell/blob/main/pathvar.c)
This function is responsible for tokenizing a PATH variable and storing the directories in a linked list.

[freelist.c](https://github.com/tramiNGY/holbertonschool-simple_shell/blob/main/freelist.c)
The free_list function is responsible for freeing the memory allocated to a linked list.

[shell.h](https://github.com/tramiNGY/holbertonschool-simple_shell/blob/main/shell.h)
The shell.h header file defines the structure and function prototypes necessary for implementing a basic shell program with a linked list to manage PATH directories

## Other requirements
- Betty style: Holbertonschool code layout rules
- No more than 5 functions per File
- No more than 40 lines per function
- Your shell should not have any memory leaks
- All your header files should be include guarded

## Flowchart
![printf flowchart image (1)](https://cdn.discordapp.com/attachments/1308098368370638849/1327074372334387273/Flowchart.jpg?ex=6781bdd2&is=67806c52&hm=49456d3af46f65d8bf890de1a11c7555eabb9d95351ebc86513a4b82004fcd99&)

## List of allowed functions and system calls
all functions from string.h

| Functions | Man |
| :---------------: |:---------------:|
|access |man 2 access|
|chdir |man 2 chdir|
|close |man 2 close|
|closedir |man 3 closedir|
|execve |man 2 execve|
|exit |man 3 exit|
|_exit |man 2 _exit|
|fflush | man 3 fflush|
|fork |man 2 fork|
|free |man 3 free|
|getcwd |man 3 getcwd|
|getline |man 3 getline|
|getpid |man 2 getpid|
|isatty |man 3 isatty|
|kill |man 2 kill|
|malloc |man 3 malloc|
|open |man 2 open|
|opendir |man 3 opendir|
|perror |man 3 perror|
|printf |man 3 printf|
|fprintf |man 3 fprintf|
|vfprintf |man 3 vfprintf|
|sprintf |man 3 sprintf|
|putchar |man 3 putchar|
|read |man 2 read|
|readdir |man 3 readdir|
|signal |man 2 signal|
|stat |man 2 stat|
|lstat| man 2 lstat|
|fstat |man 2 fstat|
|strtok |man 3 strtok|
|wait |man 2 wait|
|waitpid |man 2 waitpid|
|wait3 |man 2 wait3|
|wait4 |man 2 wait4|
|write |man 2 write|

## Compilation
The command used to compile in GNU under Ubuntu 20.04 LTS is:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```
### Test Output without the use of PATH
```
#cisfun$ ls
./shell: No such file or directory
```
```
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c
```
```
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
```
```
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
```
```
#cisfun$ exit
./shell: No such file or directory
```
```
#cisfun$ ^C
```
```
echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c
```
### Test Output with the use of PATH
```
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh
```
```
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh
```
```
:) ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
```
## Authors
- [Tra Mi NGUYEN](https://github.com/tramiNGY)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Badge](https://badgen.net/badge/icon/github?icon=github&label)
- [Tom DIBELLONIO](https://github.com/totomus83)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![Badge](https://badgen.net/badge/icon/github?icon=github&label)

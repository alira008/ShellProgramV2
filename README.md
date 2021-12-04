#   Shell Program

## Introduction:

This program will be a command shell that will be able to perform (&&) and (||) connectors also be able to execute commands chained together with semicolons. 

We will be using composite patterns to create our shell and inheritance in general.  This program will be similar to the command line we use in the terminal/command prompt.


## Research: 

### [Linux Manual Page](https://man7.org/linux/man-pages/)

- __wait(int -wstatus)__: This function stops the execution of a calling process until any child finishes its execution. Depending on the value of pid, it can specify which specific child process it waits for.
  
- __fork()__: Creates a child process that runs at the same time the parent process does. It returns a process ID. If it is negative, it could not create a child process. If it is zero it is from the child process and a positive value if it returns the process ID of the child process.

- __execvp(char- file, char-- arguments)__: This function will execute the arguments that are in an array of character strings in the second argument that is given to the function. The first arguments is the name of the file that will be executed.

- __dup2(int oldfd, int newfd)__: This function duplicates old file descriptor into the new one. This will be useful for pipe connector and output/input redirection connectors.

- __pipe(int fd[2])__: This function is useful for creating a pipe. It sets the variable you pass into the paramter with two ends of the pipe you need. pipefd[0] refers to the read end of the pipe. pipefd[1] refers to the write end of the pipe.

## Classes

- __Shell__: This class takes user input command as string and creates instances of classes that the shell needs.

- __Parser__: Abstract class parser where all Parser classes will inherit from.

- __Operators__: Class that contains methods for checking if a string is an operator and precedence of operators. 

- __Postfixer__: Class for converting vector of string vectors from infix to postfix.

- __Cmdline__: Abstract class where Cmd and Connector classes will inherit from.
  
- __Command__: This class has a private list of arguments that will be executed using execvp(). fork(), dup2(), and wait() will be used here.

- __Or__: This class includes function with how to deal with the connector || in a line of commands. It will execute the command on the right if the command on the left returns an error.
  
- __And__: This class includes function with how to deal with the connector && in a line of commands. It will execute the command on the right if the command on the left executes successfully.
  
- __Semicolon__: This class includes function with how to deal with the ; in a line of commands. It will execute the command on the right regardless if the command on the left returns an error or not.

- __Exit__: This class will call exit() and stop the shell accordingly.

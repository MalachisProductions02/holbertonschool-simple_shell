// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <string.h>

// extern char **environ;

// /**
//  * main - Simple Shell replica
//  * Return: Always 0.
//  */
// int main(void)
// {
//     char *line = NULL;
//     size_t len = 0;
//     ssize_t read;
//     char *args[100];
//     char *token;
//     pid_t pid;
//     int status;

//     while (1)
//     {
//         int i;

//         if (isatty(STDIN_FILENO))
//             write(STDOUT_FILENO, "#cisfun$ ", 9);

//         read = getline(&line, &len, stdin);
//         if (read == -1)
//         {
//             free(line);
//             break;
//         }

//         /* Remover salto de línea */
//         if (line[read - 1] == '\n')
//             line[read - 1] = '\0';

//         /* Tokenizar entrada */
//         i = 0;
//         token = strtok(line, " ");
//         while (token != NULL && i < 99)
//         {
//             args[i++] = token;
//             token = strtok(NULL, " ");
//         }
//         args[i] = NULL;

//         if (args[0] == NULL)
//             continue;

//         pid = fork();
//         if (pid == 0)
//         {
//             if (execve(args[0], args, environ) == -1)
//             {
//                 perror("./shell");
//                 exit(EXIT_FAILURE);
//             }
//         }
//         else if (pid > 0)
//         {
//             wait(&status);
//         }
//         else
//         {
//             perror("fork");
//         }
//     }

//     free(line);
//     return 0; /* Times that I corrected this code: 21...damn... */
// }

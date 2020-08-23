#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "./source_code/pq.h"

char process[STRLEN], language[STRLEN], proc[STRLEN]; // global

void is_python(char * script, char * lang) {
    if (strstr(script, ".py")) {
        strcpy(lang, "python");
    }
}

void is_r(char * script, char * lang) {
    if (strstr(script, ".R")) {
        strcpy(lang, "Rscript");
    }
}

void is_exe(char * script, char * lang) {
    int i, count = 0;
    /* count how many dots
     * the one in './' and whether it has the dot of extension */
    for (i = 0; script[i] != '\0'; i++) {
        if (script[i] == '.')
            count++;
    }
    if (count == 1)
        strcpy(lang, "exe");
}

// pass a function as an argument (function pointer)
void assign_language(void( * assign)(char * , char * )) {
    assign(process, language);
    // or assign(&process, &language);
}

int main(int argc, char ** argv) {
    char * input = argv[1];
    printf("\n\tInput File is ./%s\n", input);
    struct linked_queue * front = NULL, * rear = NULL;
    int choice, n, priority, executable, queue_size = 0;
    //char *proc = (char *)malloc(sizeof(STRLEN));

    do {
        printf("\n1.Insert process in the queue\n"
               "2.Execute process from the queue\n"
               "3.Display the queue\n"
               "\n Please enter your choice: ");

        scanf("%i", & choice);
        switch (choice) {
            case 1:
                puts("\nEnter task: ");
                // regex to read space from stdin
                scanf(" %[^\t\n]s", proc); // task is already a pointer (&task)
                //fgets(task, 20, stdin);
                puts("\nEnter priority: ");
                scanf("%i", & priority);
                enqueue( & front, & rear, proc, priority);
                queue_size++;
                break;

            case 2:
                strcpy(proc, execute( & front, & rear)); // gets name of process
                strcpy(process, "./");
                //memset(process, 0, sizeof(process));
                strcat(process, proc); // concats everything in arg1

                // function pointer
                assign_language(is_python);
                assign_language(is_r);
                assign_language(is_exe);

                printf("\nProcess %s to be processed using %s ...\n", process, language);

                pid_t pid = fork();

                if (pid == -1) {
                    printf("\n\t Can't fork process: %s\n", strerror(errno));
                    // _exit(EXIT_FAILURE);
                    return 1;
                }
                    // pid == 0
                else if (!pid) {
                    if (strstr(language, "exe")) {
                        executable = execlp(process, process, input, (char * ) NULL);
                    } else {
                        executable = execlp(language, language, process, input, (char * ) NULL);
                    }
                    if (executable == -1) {
                        printf("\n\tCan't run script: %s\n", strerror(errno));
                        return 1;
                    }
                    exit(0);
                } else {
                    if (pid > 0) {
                        int status;
                        waitpid(pid, & status, 0);
                    }
                }

                break;

            case 3:
                display(front, rear);
                break;

            default:
                puts("Invalid Input\n");
        }

        // to return interactively to the beginning of while
        printf("\nDo you want to continue (press 1 for yes or 0 to exit): ");
        scanf("%i", & n);
    } while (n == 1);
    return 0;
}
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_project_core.h"

// From here
int run = 1;

void stop(int signum)
{
    run = 0;
}

typedef void (*signalFunc_t)(int signum);

static void
setSignalHandler(int signum, signalFunc_t sigHandler)
{
    struct sigaction new;

    memset(&new, 0, sizeof(new));
    new.sa_handler = sigHandler;

    sigaction(signum, &new, NULL);
}

// till here, will be used to stop the continous while loop

int main(int argc, char* argv[])
{
    if (init() < 0)
        return -1;

    printf("\t\tRobotic ARM Control v0.3\n");

    printf("Click Ctrl+C to stop the execution\n");
    setSignalHandler(SIGINT, stop);

    while (run) {
        float angle;

        for (int i = 0; (i < sizeof(servos) / sizeof(servo)) && (run); i++) {
            printf("Enter angle for %s:", servos[i].name);
            scanf("%f", &angle);
            set_servo_position(servos[i], angle);
        }

        printf("\nDone\n");
    }

    cleanup();

    return 0;
}

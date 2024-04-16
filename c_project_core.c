// #include <pigpiod_if2.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_project_core.h"

/*
$ gcc -Wall -pthread -o c_project c_project.c -lpigpiod_if2

This software requires the pigpio daemon to be running.

$ sudo pigpiod
*/

servo servos[6] = {
    { GRIPPER, "Gripper" }, { WRIST_PITCH, "Wrist Pitch" },
    { WRIST_ROLL, "Wrist Roll" }, { ELBOW, "Elbow" },
    { SHOULDER, "Shoulder" }, { WAIST, "Waist" }
};

unsigned int map_f(float angle)
{
    // Map an given angle between 0 to 180 to corresponding pulsewidth
    int pw = (int)((angle * 10.3) + 546);
    return pw;
}

int pi = -1;

void _init_servo(servo s)
{
    // set_PWM_frequency(s.gpio, PWM_FREQ);
    // set_PWM_range(s.gpio, PWM_RANGE);
}

int init()
{
    // Reference: https://abyz.me.uk/rpi/pigpio/pdif2.html#pigpio_start
    // pi = pigpio_start(NULL, NULL);
    // return 1,2,3
    // 3
    pi=4;

    for (int i = 0; i < sizeof(servos) / sizeof(servo); i++) {
        _init_servo(servos[i]);
    }

    return pi;
}

void set_servo_position(servo s, unsigned int angle)
{
    printf("%s: %d\n", s.name, angle);
    // set_servo_pulsewidth(pi, s.gpio, map_f(angle));
}

void cleanup()
{
    printf("\nExiting\n");

    for (int i = 0; i < sizeof(servos) / sizeof(servo); i++) {
        // set_servo_pulsewidth(pi, servos[i].gpio, 0);
    }

    // pigpio_stop(pi);
}
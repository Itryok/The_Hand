#define GRIPPER 22
#define WRIST_PITCH 21
#define WRIST_ROLL 20
#define ELBOW 19
#define SHOULDER 18
#define WAIST 17

#define PWM_FREQ 50
#define PWM_RANGE 20000

typedef struct servo
{
    int gpio;
    char name[15];
} servo;

servo servos[6];

void stop(int signum);

unsigned int map_f(float angle);

void _init_servo(servo s);

int init();

void set_servo_position(servo s, unsigned int angle);

void cleanup();

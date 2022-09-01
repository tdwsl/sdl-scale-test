#ifndef PERSON_H
#define PERSON_H

#define PERSON_MAX 200
#define PATHSTEP_MAX 40

enum {
    PSTATE_NORMAL,
    PSTATE_DEAD,
    PSTATE_SLEEPING,
    PSTATE_WAITING,
    PSTATE_GOTO,
    PSTATE_GUN,
    PSTATE_KNIFE,
};

enum {
    PFLAG_HOSTILE=1,
    PFLAG_TARGET=2,
};

enum {
    PATH_GOTO,
    PATH_FACE,
    PATH_TURN,
    PATH_MARCH,
    PATH_WAIT,
    PATH_SLEEP,
};

struct path_step {
    char ins;
    int op1, op2;
};

struct path {
    struct path_step steps[PATHSTEP_MAX];
    char current, length;
};

struct person {
    int x, y, dx, dy, tx, ty;
    char d;
    int counter;
    char state, flags;
    struct path path;
    int outfit, head;
};

extern struct person person_arr[];
extern int person_num;

const static char dirs[] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0,
};

#endif

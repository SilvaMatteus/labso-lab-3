#include <math.h>
#include <sys/time.h>
#include <stdio.h>

#define POW_COUNT 1000000000

struct timeval tv;
struct timezone tz;

long n = 0;

time_t i_sec, f_sec;
suseconds_t i_usec, f_usec;

int
main(int argc, char **argv) 
{
    gettimeofday(&tv, &tz);
    i_sec = tv.tv_sec;
    i_usec = tv.tv_usec;

    while(n++ < POW_COUNT) {
        pow(1.2, 2.3);
    }

    gettimeofday(&tv, &tz);
    f_sec = tv.tv_sec;
    f_usec = tv.tv_usec;

    printf("%li.%d %li.%d\n", i_sec, i_usec, f_sec, f_usec);

    return 0;
}


#include <math.h>
#include <sys/time.h>
#include <stdio.h>

#define POW_COUNT 809629778
#define SECONDS 1

struct timeval tv;
struct timezone tz;

long n = 0;
int i = 0;

time_t i_sec, f_sec;
suseconds_t i_usec, f_usec;

int
main(int argc, char **argv)
{
    gettimeofday(&tv, &tz);
    i_sec = tv.tv_sec;
    i_usec = tv.tv_usec;

    while (i < SECONDS) {
        while(n++ < POW_COUNT) {
            pow(1.2, 2.3);
        }

        i++;
        n = 0;
    }

    gettimeofday(&tv, &tz);
    f_sec = tv.tv_sec;
    f_usec = tv.tv_usec;

    printf("%li.%li %li.%li\n", i_sec, i_usec, f_sec, f_usec);

    return 0;
}

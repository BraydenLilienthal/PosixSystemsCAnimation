#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

int main(void)
{

	struct timespec requested_time;
	struct timespec remaining_time;
	requested_time.tv_sec = 0;
	requested_time.tv_nsec = 500000000;
	for (int i = 0; i < 10; i++)
	{

	}
}
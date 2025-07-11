#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>



void Nanosleep(struct timespec time, struct timespec remaining_time)
{
	if (nanosleep(&time, &remaining_time) == -1) {
		if (errno != EINTR) {
			perror("Nanosleep failed");
		}
	}
};

int main(int argc, char* argv[])
{
	//write(STDOUT_FILENO, "HELLLOOOO", 10);

	//clears the terminal for creating the first image


	struct timespec time;
	struct timespec remaining_time;
	time.tv_sec = 0;
	time.tv_nsec = 150000000;


	//this is the current frame stored as a string
	char frames[30][1000];
	
	//this stores the sizes of each animatiom, so we can just access it in a loop easier.
	int frameSize[30];


	for (int i = 0; i < atoi(argv[2]); i++)
	{
		

		//current file name
		char currentFile[200];

		sprintf(currentFile, "%s%d.txt", argv[1], i+1);


		int animFile = open(currentFile, O_RDONLY);
		if (animFile == -1)
		{
			exit(EXIT_FAILURE);
		}

		frameSize[i] = read(animFile, frames[i], 1000);

		if (frameSize[i] == -1)
		{
			exit(EXIT_FAILURE);
		}

		//closing file
		if (close(animFile) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i < atoi(argv[2]); i++)
	{
		//clearing the terminal each time we go to display our frame
		system("clear");

		//displaying frame to terminal
		write(STDOUT_FILENO, frames[i], frameSize[i]);
		write(STDOUT_FILENO, "\n\n\n", 4);
		fflush(stdout);

		//sleeping for set amount of time
		Nanosleep(time, remaining_time);
		if (i == atoi(argv[2])-1)
		{
			i = 0;
		}
	}
	
}
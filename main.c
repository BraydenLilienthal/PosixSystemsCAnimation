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
	time.tv_nsec = 100000000;


	//this is the current frame stored as a string
	char currFrame[1000];
	
	//this stores the sizes of each animatiom, so we can just access it in a loop easier.
	int animationSize;


	for (int i = 1; i <= atoi(argv[2]); i++)
	{
		

		//current file name
		char currentFile[200];

		sprintf(currentFile, "%s%d.txt", argv[1], i);


		int animFile = open(currentFile, O_RDONLY);
		if (animFile == -1)
		{
			exit(EXIT_FAILURE);
		}

		animationSize = read(animFile, currFrame, 1000);
		
		Nanosleep(time, remaining_time);

		//clearing the terminal each time we go to display our frame
		system("clear");

		if (animationSize == -1)
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			//displaying frame to terminal
			write(STDOUT_FILENO, currFrame, animationSize);
			write(STDOUT_FILENO, "\n\n\n", 4);
			fflush(stdout);

		}

		//closing file
		if (close(animFile) == -1)
		{
			exit(EXIT_FAILURE);
		}
		
		//sleeping for set amount of time
		
		if (i == atoi(argv[2]))
		{
			i = 0;
		}
		
	}
	
}
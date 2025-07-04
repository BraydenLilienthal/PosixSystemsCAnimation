#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>

#define NUM_FRAMES 12

void Nanosleep(struct timespec time, struct timespec remaining_time)
{
	if (nanosleep(&time, &remaining_time) == -1) {
		if (errno != EINTR) {
			perror("Nanosleep failed");
		}
	}
};

int main(void)
{
	//write(STDOUT_FILENO, "HELLLOOOO", 10);

	//clears the terminal for creating the first image


	struct timespec time;
	struct timespec remaining_time;
	time.tv_sec = 0;
	time.tv_nsec = 200000000;


	//I am using a defined int to represent the number of frames (drawings in the animation), that the animation will use. This can be changed and you can insert a given number of frames into the vector of frames
	//i recommend changing the size of each char array to the size of your largest char array/
	char animation[NUM_FRAMES][521] =
	{
		"                           //\n       _                  [||]-\n        \\`*-.                    \n(ZZ.. )  )  _`-.         \n(ZZ..)  .  : `. .   (ZZZ..)\n        : _   '  \\               \n      _ ; -` _.   `*-._          \n    ( ) `-.-'          `-.       \n          ;       `       `.     \n          :.       .        \\    \n          . \\  .   :   .-'   .   \n          '  `+.;  ;  '      :   \n          :  '  |    ;       ;-. \n          ; '   : :`-:     _.`* ;\n       .*' /  .*' ; .*`- +'  `*' \n       `*-*   `*-*  `*-*'\n\n\n",
		"                //	\n       _       [||]- \n        \\`*-.                    \n(ZZ.. )  )  _`-.                 \n(ZZ..)  .  : `. .                \n        : _   '  \\               \n        ; -` _.   `*-._          \n        `-.-'          `-.       \n          ;       `       `.     \n         :.        .        \\    \n          . \\  .   :   .-'   .   \n          '  `+.;  ;  '      : \n          :  '  |    ;       ;-. \n          ; '   : :`-:     _.`* ;\n       .*' /  .*' ; .*`- +'  `*' \n       `*-*   `*-*  `*-*'\n\n\n", 
		"       \n        \\`*-.                    \n(ZZ.. )  )  _`-.                 \n(ZZ..)  .  : `. .                \n        : _   '  \\               \n        ; -` _.   `*-._          \n        `-.-'          `-.       \n  \\\\       ;       `       `.     \n -[||]    :.      .        \\ ]  \n          . \\  .   :   .-'   .   \n          '  `+.;  ;  '      :   \n          :  '  |    ;       ;-. \n          ; '   : :`-:     _.`* ;\n       .*' /  .*' ; .*`- +'  `*' \n       `*-*   `*-*  `*-*'\n\n\n",
		"       _                        \n  !    \\`*-.   ??\n        )  _`-.\n    !  .  : `. .     ?!         \n       : _   '  \\               \n       ; *` _.   `*^._          \n       `-.-'    ^     `}^       \n   \\\\    ;    ^   `      ^.     \n-[||]    :.       . ^      \\    \n         . \\  .   :   .-'   .   \n         '  `+.;  ;  '      :   \n         '  '  |    ;       ;\\-. \n        /  '   : :`-:     _.`* ;\n     .*'  /  .*' ; .*`- +'  `*' \n     `*-*    `*-*  `*-*'\n\n\n",
		"       _                        \n       \\`*-.                    \n        )  _`-.                 \n       .  : `. .                \n       : _   '  \\               \n       ; o  _.   `*-._          \n       `-.-'          `-.       \n  \\\\     ;       `       `.     \n-[||]    : .      .        \\    \n         . \\  .   :   .-'   . _  \n         '  `+.;  ;  '      :< \\   \n         /  -'  |    ;       ;: . \n     .*'- '    : :`-:     _.`* ; \n     `*-*'   .*' ; .*`- +'  `*' \n             `*-*  `*-*'\n\n\n",
		"       _                        \n       \\`+-.   *                 \n     *  )  _`-.  *             \n       .  : `. .              \n       : /   '  \\               \n       ; o  _.   `*-._          \n   \\\\  `-.-'          `-.       \n-[||]   ;   '     `       `.     \n         : .      .        \\    \n         . \\  .   :   .-'   .     \n         '  `+.;  ;  '      : /'`\\\n        /  -'  |    ;       ;< .\\/\n     .*'- '    : :`-:     _.`* ;\n     `*-*'   .*' ; .*`- +'  `*' \n             `*-*  `*-*'\n\n\n",
		"       _\n       \\`*-.           !!\n !      )  _`-.   !!\n       .  : `. .               !!!\n  !!   : /   '  \\\n       ; o   _.   `*-._ \n  \\\\   `--.-'          `-. \n-[||]     ;       `       `.\n         : .      .        \\    \n         . \\  .   :   .-'   .   _\n         /  `+.;  ;  '      : /'`*\\   \n     .*'-  -'  |    ;       ;< ./ }\n     `*-*''    : :`-:     _.`* ;\n             .*' ; .*`- +'  `*' \n             `*-*  `*-*'\n\n\n",
		"       _\n       \\`*-.           !!        \n !      )  _`-.   !!             \n       .  : `. .               !!!\n  !!   : /   '  \\               \n       ; o   _.   `*-._\n   \\\\  `--.-'          `-.       \n -[||]    ;       `       `.     \n     .*'+*-: .:    .        \\    \n     `*-* _ -. .      .-'   .   _\n             :       '      : /'`*\\   \n;|    ;       ;< ./ }\n               : :`-:     _.`* ; \n             .*' ; .*`- +'  `*' \n             `*-*  `*-*'\n\n\n",
		"       _\n       \\`*-.           ??\n??      )  _`-.   ??\n       .  : `. .               ??\n       : ^   '  \\               \\\\\n       ; o   _.   `*-._       -[||]\n       `--.-'          `-.       \n          ;       `       `.     \n     .*'+*-: .:    .        \\    \n     `*-* _ -. .      .-'   .   _\n             :       '      : /'`*\\   \n              ;|    ;       ;< ./ }\n               : :`-:     _.`* ;\n             .*' ; .*`- +'  `*' \n             `*-*  `*-*'\n\n\n",
		"       _\n       \\`*-.           ??\n ??     )  _`-.   ??\n       .  : `. .               ??\n       : -   '  \\                  \\\\\n       ; o   _.   `*-._          -[||]\n       `--.-'          `-.       \n          ;       `       `.     \n          -: .:    .        \\\n          ; -. .      .-'   .   _\n         . \\  .   :   .-'   .  _\n         /  `+.;  ;  '      : < }    \n     .*'-  -'  |    ;       ;- +\n     `*-*''    : :`-:     _.`* ,\n             .*' ; .*`- +'  `*' \n             `*-*  `*-*'",
		"       _\n       \\`*-.           ?? \n ??      )  _`-.   ??\n       .  : `. .               ??\n       : -   '  \\                 \n       ; *   _.   `*-._           \n       `--.-'          `-.       \n          ;    ^   `      ^.     \n        :.       . ^      \\\\    \n         . \\  .   :   .-'   .   \n         '  `+.;  ;  '      :   \n         '  '  |    ;       ;\\-. \n        /  '   : :`-:     _.`* ;\n     .*'  /  .*' ; .*`- +'  `*' \n     `*-*    `*-*  `*-*'\n\n\n",
		"       _\n        \\`*-.\n(ZZ.. )  )  _`-.\n(ZZ..)  .  : `. .\n        : _   '  \\\n        ; -` _.   `*-._\n        `-.-'          `-.\n          ;       `       `.\n          :.       .        \\\n          . \\  .   :   .-'   .   \n          '  `+.;  ;  '      :   \n          :  '  |    ;       ;-. \n          ; '   : :`-:     _.`* ;\n       .*' /  .*' ; .*`- +'  `*' \n       `*-*   `*-*  `*-*'\n\n\n",
	};
	
	//this stores the sizes of each animatiom, so we can just access it in a loop easier.
	int animationSize[NUM_FRAMES] =
	{
		521,
		511,
		479,
		459,
		497,
		495,
		427,
		461,
		466,
		494,
		457,
		519



	};


	for (int i = 0; i < NUM_FRAMES; i++)
	{
		//clearing the terminal each time we go to display our frame
		system("clear");

		//displaying frame to terminal
		write(STDOUT_FILENO, animation[i], animationSize[i]);
		
		//sleeping for set amount of time
		Nanosleep(time, remaining_time);
		
		if (i == NUM_FRAMES - 1)
		{
			i = -1;
		}
	}

}
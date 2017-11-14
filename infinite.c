#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *randstring(size_t length);

int main ()
{
size_t seed = time(NULL);
srand(seed);
size_t annoying = 0;
unsigned int goody = 0;
	for (;;){
		annoying = rand() % 100000;	
                goody = rand() % 10;
		char *letters;
		letters = randstring(annoying);
		printf("%s",letters);
		printf("\n");
                printf("%u",goody);		
		printf("\n");
	}
}
		

char *randstring(size_t length) {

	static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
	char *randomString;

	if(length) {
		randomString = malloc(length + 1);

			if (randomString) {
				int l = (int) (sizeof(charset) - 1);
				int key;
				for (int n = 0; n < length; n++) {
						int key = rand() % l;
						randomString[n] = charset[key];
				}

				randomString[length] = '\0';
			}
	}
	return randomString;

}

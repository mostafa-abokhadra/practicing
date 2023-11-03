#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
		char sent[] = "my name is mostafa * ok o **";
		char *splitted;
		const char separator[4] = " ";

		splitted = strtok(sent, separator);
		
		while (splitted)
		{
			printf("%s\n", splitted);
			splitted = strtok(0, separator);
		}

		return (0);
}

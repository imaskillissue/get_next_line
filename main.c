#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
	int fd = open("1char.txt", O_RDONLY);
	char *text = get_next_line(fd);
	while (text)
	{
		printf("%s\n", text);
		free(text);
		text = get_next_line(fd);
	}
	return 0;
}

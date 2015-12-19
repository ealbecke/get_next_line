#include <stdio.h> // Include for printf
#include <fcntl.h> // Include for open
#include <unistd.h> // Include for close
#include "get_next_line.h"

int	main(int argc, char **argv) {
	int fd;
	char *line;
	fd = 0;
	
	printf("%s %s\n", "Launch of", argv[0]);

	if (argc > 1) {
		if ((fd = open(argv[1], O_RDONLY)) > -1)
		{
			while (get_next_line(fd, &line) == 1)
			{
				printf("line : %s\n", line);
			}
			close(fd);
		}
		else
		{
			printf("Can't open the file.\n");
		}

	}
	printf("%s %s\n", "End of", argv[0]);

	return (0);
}

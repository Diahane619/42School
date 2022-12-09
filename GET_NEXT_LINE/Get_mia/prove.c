#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	// We open the file and assign the returned file descriptor
	// to the fd variable in order to use it later:
	fd = open("fichier.txt", O_RDONLY);
	// Then we make sure the file was correctly opened:
	if (fd == -1)
	return (-1);
	// ...
	// And we close the file with the reference to its fd:
	close(fd);
	return (0);
}

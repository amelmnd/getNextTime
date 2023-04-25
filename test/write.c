
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(int fd, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int fd, int n)
{
	if (n == -2147483648)
		ft_putstr_fd(fd, "-2147483648");
	else if (n < 0)
	{
		ft_putchar_fd(1, '-');
		ft_putnbr(fd, -n);
	}
	else if (n >= 10)
	{
		ft_putnbr(fd, n / 10);
		ft_putchar_fd(fd, n % 10 + '0');
	}
	else
		ft_putchar_fd(fd, n + '0');
}

int	main(void)
{
	int	fd;
	//code qui creer un fichier et ecrit un Z dedans quelque soit le nombre de compilation du code le fichier ne comptiendra qu'un seul Z
	/*fd = open("write_z", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1){
		ft_putstr("open() failed\n");
		return (1);
	}
	ft_putnbr(fd);
	ft_putchar(fd, 'Z');*/

	// ajout de flag a open : O_APPEND => permet d'ecrire depuis le derniere octet du fichier
	/*
		fd = open("write_z", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1){
		ft_putstr("open() failed\n");
		return (1);
	}
	ft_putnbr(fd);
	ft_putchar(fd, 'Z');
	*/
	// ajout de flag a open : O_TRUNC => ecrire depuis le preier octet du fichier et supprime tout son contenu

		fd = open("write_z", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1){
		ft_putstr_fd(1, "open() failed\n");
		return (1);
	}
	ft_putnbr(1, fd);
	ft_putstr_fd(fd, "Hello world !");

	if (close(fd) == -1)
	{
		ft_putstr_fd(1,"close() failed\n");
		return (1);
	}


	return (0);
}

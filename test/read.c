
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// #define BUFFER_SIZE 4096
#define BUFFER_SIZE 10

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648");
	else if (n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar_fd(n % 10 + '0');
	}
	else
		ft_putchar_fd(n + '0');
}

int	main(void)
{
	// int	fd;
	// int ret;
	// char buf[BUFFER_SIZE + 1];

	// fd = open("42", O_RDONLY);
	// if (fd == -1){
	// 	ft_putstr_fd(1, "open() failed\n");
	// 	return (1);
	// }
	// ret = read(fd, buf, BUFFER_SIZE);
	// buf[ret] = '\0';
	// ft_putnbr(1, ret);
	// ft_putchar_fd(1, '\n');
	// ft_putstr_fd(1, buf);
	// if (close(fd) == -1)
	// {
	// 	ft_putstr_fd(1, "close() failed\n");
	// 	return (1);
	// }

	// cas ou l'on ne connais pas le nombre d'octet a parcourir

	int	fd;
	int ret;
	char buf[BUFFER_SIZE + 1];

	fd = open("42", O_RDONLY);
	if (fd == -1){
		ft_putstr_fd("open() failed\n");
		return (1);
	}

	while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		// ret = read(fd, buf, BUFFER_SIZE);
		ft_putnbr(ret);
		ft_putchar_fd('\n');
		ft_putstr_fd(buf);
	}
	buf[ret] = '\0';
	ft_putnbr(ret);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n");
		return (1);
	}
	return (0);
}

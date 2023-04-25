
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
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
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int	main(void)
{
	int	fd;

	// ouvrir un fichier en lecture seule
	/*
	fd = open("alph", O_RDONLY);
	ft_putnbr(fd);
	*/


	// creer et ouvrir un fichier en ecriture seule
	/*
	fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	// on de creer un fichier nommer 42 en ecriture seule, de donner les droits d'ecriture et de lecture dessus et ensuite d'imprimer le file descriptor
	ft_putnbr(fd);
	*/
	// gestion d'un fd == -1 : cas d'erreur
	/*
	fd = open("/dev/42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
		ft_putstr("open() failed\n");
	ft_putnbr(fd);
	*/
	// fermer un fichier
	fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1){
		ft_putstr("open() failed\n");
		return (1);
	}
	ft_putnbr(fd);
	if(close(fd) == -1){
		ft_putstr("close() failed\n");
		return (1);
	}


	return (0);
}

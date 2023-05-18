#include "push_swap.h"

static int	pf_parsing(const char *format, va_list ap);
static int	pf_by_conversion(char c, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = pf_parsing(format, ap);
	va_end(ap);
	return (len);
}

static int	pf_parsing(const char *format, va_list ap)
{
	int	len;
	int	read_size;

	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspiduxX%%", *(++format)))
			read_size = pf_by_conversion(*format, ap);
		else
			read_size = print_char(*format);
		if (read_size < 0)
			return (-1);
		len += read_size;
		format++;
	}
	return (len);
}

static int	pf_by_conversion(char c, va_list ap)
{
	int	len;

	if (c == 'c')
		len = print_char(va_arg(ap, int));
	else if (c == '%')
		len = print_char('%');
	else if (c == 's')
		len = print_str(va_arg(ap, char *));
	else if (c == 'i' || c == 'd')
		len = print_nbr(va_arg(ap, int));
	else
		len = 0;
	return (len);
}

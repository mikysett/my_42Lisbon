# include <stdio.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...)
{
	int result;
	va_list		ap;
	
	va_start(ap, format);
	result = vfprintf(stdout, format, ap);
	va_end(ap);
	return (result);
}

int		main(void)
{
	int res0;
	int res1;
	printf("   ----> TESTER FOR PRINTF <----\n");
	printf("### no arguments\n");
	res0 = printf("this is a string with this result\n");
	res1 = ft_printf("this is a string with this result\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	res0 = printf("\n");
	res1 = ft_printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	res0 = printf("");
	res1 = ft_printf("");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	printf("### char\n");
	res0 = printf("%c", 'a');
	res1 = ft_printf("%c", 'a');
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	res0 = printf("char at the end of the string %c", 'a');
	printf("\n");
	res1 = ft_printf("char at the end of the string %c", 'a');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	res0 = printf("char at the end of the string %c", 'a');
	printf("\n");
	res1 = ft_printf("char at the end of the string %c", 'a');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("%c at the start of the string", '\0');
	printf("\n");
	res1 = ft_printf("%c at the start of the string", '\0');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	res0 = printf("in the middle: %c of the string", 'Q');
	printf("\n");
	res1 = ft_printf("in the middle: %c of the string", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with precision: %.4c of four", 'Q');
	printf("\n");
	res1 = ft_printf("with precision: %.4c of four", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with precision: %.0c of 0", 'Q');
	printf("\n");
	res1 = ft_printf("with precision: %.0c of 0", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width: %10c of 10", 'Q');
	printf("\n");
	res1 = ft_printf("with width: %10c of 10", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	return (0);
}
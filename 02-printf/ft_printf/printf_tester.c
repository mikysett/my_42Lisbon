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
	printf("\n");
	res1 = ft_printf("%c", 'a');
	printf("\n");
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
	
	res0 = printf("with width on left: %-10c of 10", 'Q');
	printf("\n");
	res1 = ft_printf("with width on left: %-10c of 10", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width by 0: %010c of 10", 'Q');
	printf("\n");
	res1 = ft_printf("with width by 0: %010c of 10", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width by 0 left: %-010c of 10", 'Q');
	printf("\n");
	res1 = ft_printf("with width by 0 left: %-010c of 10", 'Q');
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);



	printf("      ######### STRING ########\n\n");
	res0 = printf("%s", "THIS IS A BASIC STRING");
	printf("\n");
	res1 = ft_printf("%s", "THIS IS A BASIC STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	res0 = printf("char at the end of the string %s", "THIS IS A BASIC STRING");
	printf("\n");
	res1 = ft_printf("char at the end of the string %s", "THIS IS A BASIC STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("EMPTY STRING:\n");
	res0 = printf("empty string:%s<", "");
	printf("\n");
	res1 = ft_printf("empty string:%s<", "");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("PRECISION 5:\n");
	res0 = printf("empty string:%.5s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%.5s<", "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("PRECISION 0:\n");
	res0 = printf("empty string:%.0s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%.0s<", "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("WIDTH 5:\n");
	res0 = printf("empty string:%5s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%5s<", "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("WIDTH 25:\n");
	res0 = printf("empty string:%25s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%25s<", "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("WIDTH 25 LEFT PADDED:\n");
	res0 = printf("empty string:%-25s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%-25s<", "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);




	
	printf("### int\n");
	res0 = printf("%d", 114);
	printf("\n");
	res1 = ft_printf("%d", 114);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	res0 = printf("char at the end of the string %d", 114);
	printf("\n");
	res1 = ft_printf("char at the end of the string %d", 114);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	res0 = printf("char at the end of the string %d", 114);
	printf("\n");
	res1 = ft_printf("char at the end of the string %d", 114);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("%d at the start of the string", 117);
	printf("\n");
	res1 = ft_printf("%d at the start of the string", 117);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	res0 = printf("in the middle: %d of the string", 1493);
	printf("\n");
	res1 = ft_printf("in the middle: %d of the string", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with precision: %.4d of four", 1493);
	printf("\n");
	res1 = ft_printf("with predision: %.4d of four", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with predision: %.0d of 0", 1493);
	printf("\n");
	res1 = ft_printf("with predision: %.0d of 0", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width: %10d of 10", 1493);
	printf("\n");
	res1 = ft_printf("with width: %10d of 10", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width on left: %-10d of 10", 1493);
	printf("\n");
	res1 = ft_printf("with width on left: %-10d of 10", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width by 0: %010d of 10", 1493);
	printf("\n");
	res1 = ft_printf("with width by 0: %010d of 10", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with width by 0 left: %-010d of 10", 1493);
	printf("\n");
	res1 = ft_printf("with width by 0 left: %-010d of 10", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	return (0);
}
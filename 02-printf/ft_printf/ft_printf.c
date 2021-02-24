/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:09:10 by msessa            #+#    #+#             */
/*   Updated: 2021/02/24 20:33:05 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_str_part(t_str_part *str_part)
{
	int i;

	i = 0;
	printf("#########---- PRINTING STR_PART\n");
	while (str_part)
	{
		printf("str type: %d\n", str_part->str_type);
		str_part = str_part->next;
		i++;
	}
	printf("#########---- i: %d\n", i);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_str_part	**str_part;
	int			print_count;

	if (!(str_part = ft_set_str((char *)format)))
		return (-1);
	// ft_print_str_part(*str_part);
	va_start(ap, format);
	if (!ft_set_args(ap, *str_part))
		return (-1);
	va_end(ap);
	print_count = ft_printer(*str_part);
	ft_free_padding();
	ft_free_str_part(str_part);
	return (print_count);
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
	
	printf("empty character \\0\n");
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

	printf("PRECISION 30:\n");
	res0 = printf("empty string:%.30s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%.30s<", "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("PRECISION -30:\n");
	res0 = printf("empty string:%.-30s<", "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%.-30s<", "THIS IS A GOOD STRING");
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

	printf("WIDTH -25 (WITH INT VARIABLE) LEFT PADDED:\n");
	res0 = printf("empty string:%*s<", -25, "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%*s<", -25, "THIS IS A GOOD STRING");
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);

	printf("WIDTH -25 (WITH INT VARIABLE) + minus sign LEFT PADDED:\n");
	res0 = printf("empty string:%-*s<", -25, "THIS IS A GOOD STRING");
	printf("\n");
	res1 = ft_printf("empty string:%-*s<", -25, "THIS IS A GOOD STRING");
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
	
	res0 = printf("with precision: %.20d of 20", 1493);
	printf("\n");
	res1 = ft_printf("with predision: %.20d of 20", 1493);
	printf("\n");
	printf("   printf: %d\nft_printf: %d\n\n", res0, res1);
	
	res0 = printf("with precision: %.-20d of -20", 1493);
	printf("\n");
	res1 = ft_printf("with predision: %.-20d of -20", 1493);
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

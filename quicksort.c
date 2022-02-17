/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:36:49 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/17 12:53:10 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int *quicksort(int *arr, int beg, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (beg < last)
	{
		pivot = beg;
		i = beg;
		j = last;

		while (i < j)
		{
			while (arr[i] <= arr[pivot] && i < last)
				i++;
			while (arr[j] > arr[pivot] && j)
				j--;
			if (i < j)
				swap(&arr[i], &arr[j]);
		}
		swap(&arr[pivot], &arr[j]);
		quicksort(arr, beg, j - 1);
		quicksort(arr, j + 1, last);
	}
	return (arr);
}

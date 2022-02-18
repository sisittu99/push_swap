/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:36:49 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/18 10:06:35 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
#include <stdio.h>
// int	*quicksort(int *arr, int beg, int last)
// {
// 	int	i;
// 	int	j;
// 	int	pivot;

// 	printf("numeri in mano a QS:\t\t");
// 	for (int x = beg; x < last; x++)
// 		printf("%d ", arr[x]);
// 	printf("\n\n");
// 	if (beg < last)
// 	{
// 		pivot = beg;
// 		i = beg;
// 		j = last;

// 		while (i < j)
// 		{
// 			while (arr[i] <= arr[pivot] && i < last)
// 				i++;
// 			while (arr[j] > arr[pivot] && j)
// 				j--;
// 			if (i < j)
// 				swap(&arr[i], &arr[j]);
// 		}
// 		swap(&arr[pivot], &arr[j]);
// 		arr = quicksort(arr, beg, j - 1);
// 		arr = quicksort(arr, j + 1, last);
// 	}
// 	return (arr);
// }

int *quicksort(int *number,int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      number = quicksort(number,first,j-1);
      number = quicksort(number,j+1,last);

   }
   return (number);
}

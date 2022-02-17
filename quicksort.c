/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:36:49 by mcerchi           #+#    #+#             */
/*   Updated: 2022/02/17 12:35:49 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// void quicksort(int a[MAX],int primo,int ultimo){
//    int i, j, pivot, temp;
// /*pivot -- inizialmente il pivot è il primo elemento
// primo e ultimo sono le due variabili che servono per scorrere l'array
// */
//    if(primo<ultimo){
//       pivot=primo;
//       i=primo;
//       j=ultimo;

//       while(i<j){
//          while(a[i]<=a[pivot]&&i<ultimo)
//             i++;
//          while(a[j]>a[pivot])
//             j--;
//          if(i<j){
//             temp=a[i];
//             a[i]=a[j];
//             a[j]=temp;
//          }
//       }

//       temp=a[pivot];
//       a[pivot]=a[j];
//       a[j]=temp;
//       quicksort(a,primo,j-1);
//       quicksort(a,j+1,ultimo);
//    }
// }
void quicksort(int *arr, int beg, int last)
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
}
#include <stdio.h>
int main()
{
	int arr[8] = {12, 24, 1, -3, 45, 64852, -321, 0};
	quicksort(arr, 0, 7);
	for (int i; i < 8; i++)
		printf("%d\n", arr[i]);
}

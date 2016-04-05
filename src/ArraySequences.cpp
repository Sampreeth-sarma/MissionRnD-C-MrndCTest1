/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL)
		return NULL;
	if (len <= 0)
		return NULL;
	int *res = (int *)malloc(6 * sizeof(int)), count = 0, j = 1, i = 0, k = 0;
	for (int l = 0; l < 6; l++)
	{
		res[l] = -1;
	}
	while (i<len)
	{
		if ((arr[i + j] - arr[i + j - 1]) == (arr[i + j + 1] - arr[i + j])){
			if (res[count]<0)
				res[count] = i;
			j++;
		}
		else if (res[count] >= 0)
		{
			res[++count] = i + j; break;
		}
		else
		{
			i++;
		}


	}


	count++;
	j = 1;
	while (k<len)
	{
		if (k > res[0] && k >= res[1])
		{
			if ((arr[k + j] - arr[k + j - 1]) == (arr[k + j + 1] - arr[k + j]))
			{
				if (res[count] < 0)
				{

					res[count] = k;
				}
				j++;
			}

			else if (res[count] >= 0)
			{
				res[++count] = k + j; break;
			}
			else
			{
				k++;
			}
		}
		else
			k++;

	}
	
	count++;
	j = 1;
	k = 0;
	while (k < len)
	{
		if (!((k >= res[0] && k < res[1]) || (k >= res[2] && k < res[3])))
		{
			if (((arr[k + j - 1]) * (arr[k + j + 1])) == (arr[k + j])*(arr[k + j]))
			{
				if (res[count] < 0)
				{
					res[count] = k;
				}
				j++;
			}

			else if (res[count] >= 0){
				res[++count] = k + j; break;
			}
			else
			{
				k++;
			}

		}
		else
			k++;
	}

	return res;


}
#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include "Transaction.h"

 int getTransactionNumber();
void getOneItemset(LinkedList<int> transactions[],Transaction oneItemset[],int size, int tranCount);
void generateOneItemset(Transaction transaction[], LinkedList<Transaction> &oneItemSet, float support, int size,int transCount);
void generateKItemset(LinkedList<Transaction> &KItemset, LinkedList<Transaction> &multiItemset, float support, int size);
void getKItemset(LinkedList<int> transactions[],LinkedList<Transaction> &multiItemset, LinkedList<Transaction> &freItemset, int k, int size);
 int isExist(LinkedList<int> transactions[], Transaction item, int k, int size);
void readTransactions(const string &filename, LinkedList<int> transactions[]);
void show(LinkedList<Transaction> &kItemset, int k);




/*     Pre:  an array and its size
*     Post:  sort the array with bubble sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void bubbleSort(T list[], int size)
{
	bool swapped = true;
	T temp;
	int	i;
	
	while (swapped)
	{
		swapped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (list[i+1] < list[i])
			{
				temp = list[i+1];
				list[i+1] = list[i];
				list[i] = temp;
				swapped = true;
			}
		}
	}
}
/*     Pre:  an array and its size
*     Post:  sort the array with insertion sort
*  Purpose:  to sort the array
*****************************************************************************/
template <class T>
void insertionSort(T list[], int size)
{
	int i,
		j;
	T value;
	for (i = 1; i < size; i++)
	{
		value = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > value)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = value;	
	}
	
}




#endif //! Header_h
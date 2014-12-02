#include "Header.h"

using namespace std;

int main()
{
	
	LinkedList<int> transactions[1000];
	Transaction oneItemset[100];
	readTransactions("T5.N0.1K.D1K.txt", transactions);
	getOneItemset(transactions,oneItemset,100,1000);

	for(int i = 0; i < 100; i++)
	{
		cout << "item: " << oneItemset[i].item.getData(0) << " count: " << oneItemset[i].count << endl;
	}
	insertionSort(oneItemset,100);
	for(int i = 0; i < 100; i++)
	{
		cout << "item: " << oneItemset[i].item.getData(0) << " count: " << oneItemset[i].count << endl;
	}
	cin.get();
	return 0;
}
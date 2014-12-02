#include "Header.h"


/*     Pre: 1. all transactions
			2. an array to hold the 1 item itemset
			3. size of the itemset, which is the number of distinct items in the market
			4. the number of transactions
*     Post: 1 item itemset gets initialized.
*  Purpose: to initialized the 1 item itemset
*****************************************************************************/
void getOneItemset(LinkedList<int> transactions[],Transaction oneItemset[], int size, int tranCount)
{
	int i,
		y;
	for(i = 0; i < size; i++)
	{
		oneItemset[i].item.insert(i);
	}
	for(i = 0; i < tranCount; i++)
	{
		for(y = 0; y < transactions[i].getCount(); y++)
		{
			oneItemset[transactions[i].getData(y)].count++;
		}
	}
	
}


void readTransactions(const string &filename, LinkedList<int> transactions[])
{
	ifstream input(filename);
	int ID;
	int item;

	if(input.good())
	{
		while(!input.eof())
		{
			input >> ID >> item;
			transactions[ID-1].insert(item);			
		}
		
		input.close();
		cout << "reading transactions complete.." << endl;
	}
	
	else
		cout << "Can't open the file.." << endl;

}
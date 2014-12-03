#include "Header.h"

using namespace std;

int main()
{
	
	float support = 0.25f;
	LinkedList<int> transactions[1000]; //transaction dataset
	Transaction oneItemset[100];        //one itemset candidate
	LinkedList<Transaction> oneItemFreSet; //one item frequent sets
	LinkedList<Transaction> multiSet;      //k item candidate set
	LinkedList<Transaction> kItemset;      //k item frequent set
	readTransactions("T5.N0.1K.D1K.txt", transactions);
	getOneItemset(transactions,oneItemset,100,1000);
	generateOneItemset(oneItemset,oneItemFreSet,support,100,1000);
	getKItemset(transactions, multiSet,oneItemFreSet,2,1000);
	generateKItemset(kItemset,multiSet,support,1000);
	show(kItemset,2);
	
	int k = 3;
	while(multiSet.getCount()!=0)
	{
		getKItemset(transactions,multiSet,kItemset,k,1000);
		generateKItemset(kItemset,multiSet,support,1000);
		show(kItemset,k);
		k++;
	}
	if(multiSet.getCount() == 0)
	{
		cout << "complete.." << endl;
	}
	
	
	cin.get();
	return 0;
}
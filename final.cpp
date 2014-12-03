#include "Header.h"

using namespace std;

int main()
{
	string filename = "T5.N0.1K.D1K.txt"; //filename;
	float support = 0.0025f;  //support number
	int transactionCount = getTransactionNumber(filename);  //get the transaction counts
	int itemNumber = 100;   //the number of different item in the transaction

	if(transactionCount == -1)
		return 1;

	cout << "N(number of items): " << itemNumber << endl;
	cout << "D(number of trans): " << transactionCount << endl;
	cout << "S(support): " << support << endl;
	cin.get();

	LinkedList<int> transactions[10000]; //transaction dataset
	Transaction oneItemset[100];        //one itemset candidate
	LinkedList<Transaction> oneItemFreSet; //one item frequent sets
	LinkedList<Transaction> multiSet;      //k item candidate set
	LinkedList<Transaction> kItemset;      //k item frequent set

	//read transaction
	readTransactions(filename, transactions);

	//one item itemset candidate
	getOneItemset(transactions,oneItemset,itemNumber,transactionCount);

	//one item itemset frequent set
	generateOneItemset(oneItemset,oneItemFreSet,support,itemNumber,transactionCount);

	//two item itemset candidate
	getKItemset(transactions, multiSet,oneItemFreSet,2,transactionCount);

	//two item itemset frequent set
	generateKItemset(kItemset,multiSet,support,transactionCount);

	show(kItemset,2);
	
	//multiple item set candidate and frequent sets
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
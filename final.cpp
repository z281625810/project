#include "Header.h"

using namespace std;

int main()
{
	int support = 10;
	LinkedList<int> transactions[1000]; //transaction dataset
	Transaction oneItemset[100];        //one itemset candidate
	LinkedList<Transaction> oneItemFreSet; //one item frequent sets
	LinkedList<Transaction> multiSet;      //k item candidate set
	LinkedList<Transaction> kItemset;      //k item frequent set
	readTransactions("T5.N0.1K.D1K.txt", transactions);
	getOneItemset(transactions,oneItemset,100,1000);
	generateOneItemset(oneItemset,oneItemFreSet,support,100);
	getKItemset(transactions, multiSet,oneItemFreSet,2,1000);
	
	support = 10;
	generateKItemset(kItemset,multiSet,support,1000);
	show(kItemset,2);
	getKItemset(transactions,multiSet,kItemset,3,1000);
	support = 5;
	generateKItemset(kItemset,multiSet,support,1000);
	show(kItemset,3);
	getKItemset(transactions,multiSet,kItemset,4,1000);
	support = 1;
	generateKItemset(kItemset,multiSet,support,1000);
	show(kItemset,4);
	getKItemset(transactions,multiSet,kItemset,5,1000);
	generateKItemset(kItemset,multiSet,support,1000);
	show(kItemset,5);
	
	cin.get();
	return 0;
}
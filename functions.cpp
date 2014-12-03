#include "Header.h"


/*     Pre: 1. filename
*     Post: get the transaction count
*  Purpose: to return how many transaction in the file
*****************************************************************************/
int getTransactionNumber(const string &filename)
{
	ifstream input(filename);
	string str;
	

	if(input.good())
	{
		while(input >> std::ws && getline(input,str))
			;
		input.close();
		istringstream s(str);
		s >> str;

		return stoi(str);
	}
	
	else
		cout << "Can't open the file.." << endl;
	return -1;


}

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
		//oneItemset[i].item.insert(i);
		oneItemset[i].item[0] = i;
	}
	for(i = 0; i < tranCount; i++)
	{
		for(y = 0; y < transactions[i].getCount(); y++)
		{
			oneItemset[transactions[i].getData(y)].count++;
		}
	}
	
}


/*     Pre: 1. all transaction database
			2. oneItemset frequent set
			3. support number
			4. the number of different kinds of items
			5. transaction count
*     Post: generate oneItem frequent set
*  Purpose: to generate oneItem frequent set
*****************************************************************************/
void generateOneItemset(Transaction transaction[], LinkedList<Transaction> &oneItemSet, float support, int size,int transCount)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if((float)transaction[i].count/transCount >= support)
			oneItemSet.insert(transaction[i]);

	}

}


/*     Pre: 1. K item itemset frequent set
			2. k item candidate set
			3. support number
			4.number of transaction
*     Post: generate the k item frequent set
*  Purpose: to generate the k item frequent set
*****************************************************************************/
void generateKItemset(LinkedList<Transaction> &KItemset, LinkedList<Transaction> &multiItemset, float support, int size)
{
	int i;
	KItemset.clear();
	for(i = 0; i < multiItemset.getCount(); i++)
	{
		if((float)multiItemset.getData(i).count/size >= support)
			KItemset.insert(multiItemset.getData(i));
	}

}


/*     Pre: 1. transaction database
			2. k item candidate set
			3. k-1 item frequent set
			4. k value, which is the round
			5. number of transactions
*     Post: get the k item candidate set
*  Purpose: to get the k item candidate set
*****************************************************************************/
void getKItemset(LinkedList<int> transactions[],LinkedList<Transaction> &multiItemset, 
				 LinkedList<Transaction> &freItemset, int k,int size)
{
	int i,y;
	Transaction temp;
	multiItemset.clear();
	if(k <= 2)
	{
		for(i = 0; i < freItemset.getCount()-1; i++)
		{
			temp.item[0] = freItemset.getData(i).item[0];

			for(y = i + 1; y < freItemset.getCount(); y++)
			{
				temp.item[1] = freItemset.getData(y).item[0];
				temp.count = isExist(transactions,temp,k,size);
				multiItemset.insert(temp);
			}
		}
	}
	else
	{
		int count;
		for(i = 0; i < freItemset.getCount()-1; i++)
		{
			for(int z = 0; z < k - 1; z++)
			{
				temp.item[z] = freItemset.getData(i).item[z];
			}
			for(y = i + 1; y < freItemset.getCount(); y++)
			{
				count = 0;
				for(int a = 0; a < k-2; a++)
				{
					if(freItemset.getData(i).item[a] == freItemset.getData(y).item[a])
					{
						count++;
					}
					if(count == k-2)
					{
						temp.item[k-1] = freItemset.getData(y).item[k-2];
						temp.count = isExist(transactions,temp,k,size);
						multiItemset.insert(temp);
					}
				}
			}
		}
		

	}
}


/*     Pre: 1. transaction database
			2. a transaction object
			3. k value, which is the round
			4. number of transaction
*     Post: return how many times the itemset is existed in the database
*  Purpose: to find how many times the itemset is exisetd in the database
*****************************************************************************/
int isExist(LinkedList<int> transactions[], Transaction item, int k, int size)
{
	int i,y;
	int num = 0; //count how many time it is true
	int countNum = 0;

	for(i = 0; i < size; i++) //transaction
	{
		for(y = 0; y < k; y++)
		{
			
			if(transactions[i].isExist(item.item[y]))
			{
				num++;
			}
			if(num == k)
			{
				countNum++;
				num = 0;
			}
		}
		num = 0;
	}
	return countNum;
}


/*     Pre: 1. filename
			2. transaction database
*     Post: initialize the database
*  Purpose: to initialize the database
*****************************************************************************/
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


/*     Pre: 1. k itemset
			2. k indicate how many items
*     Post: display the items of k itemset 
*  Purpose: to display the items of k itemset
*****************************************************************************/
void show(LinkedList<Transaction> &kItemset, int k)
{
	int i,y;
	for(y = 0; y < kItemset.getCount(); y++)
	{
		cout << "item: ";
		for(i = 0; i < k; i++)
		{
			 cout << kItemset.getData(y).item[i] << " "; 

		}
		cout << " count : " << kItemset.getData(y).count << endl;
	}


}
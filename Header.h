#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <sstream>
#include "Transaction.h"

 int getTransactionNumber(const string &filename);
void getOneItemset(LinkedList<int> transactions[],Transaction oneItemset[],int size, int tranCount);
void generateOneItemset(Transaction transaction[], LinkedList<Transaction> &oneItemSet, float support, int size,int transCount);
void generateKItemset(LinkedList<Transaction> &KItemset, LinkedList<Transaction> &multiItemset, float support, int size);
void getKItemset(LinkedList<int> transactions[],LinkedList<Transaction> &multiItemset, LinkedList<Transaction> &freItemset, int k, int size);
 int isExist(LinkedList<int> transactions[], Transaction item, int k, int size);
void readTransactions(const string &filename, LinkedList<int> transactions[]);
void show(LinkedList<Transaction> &kItemset, int k);


#endif //! Header_h
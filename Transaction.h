#ifndef Transaction_h
#define Tranaction_h

#include "LinkedList.h"
#include <string>

struct Transaction
{
	Transaction()
	{
		count = 0;
		for (int i = 0; i < 50; i++)
			item[i] = -1;
	}
	//LinkedList<int> item;
	int item[50];
	int count;
	
	inline bool operator<(const Transaction& rhs)
	{
		return this->count < rhs.count;
	}
	inline bool operator>(const Transaction& rhs)
	{
		return this->count > rhs.count;
	}
	
};



#endif //! Transaction_h
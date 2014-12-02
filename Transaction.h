#ifndef Transaction_h
#define Tranaction_h

#include "LinkedList.h"
#include <string>

struct Transaction
{
	Transaction()
	{
		count = 0;
	}
	LinkedList<int> item;
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
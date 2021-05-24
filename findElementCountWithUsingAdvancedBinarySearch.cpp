#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


int findElementCountWithUsingAdvancedBinarySearch(vector<int> v, int key)
{
	vector<int>::iterator tempIt;
	vector<int>::iterator beginIt = v.begin();
	vector<int>::iterator endIt = v.end();
	int mid;
	int first = 0;
	int count = v.size();

  // find first occurence iterator
	while (count > 0)
	{
		tempIt = beginIt;
		mid = count / 2;
		std::advance(tempIt, mid);
		if (*tempIt < key)
		{
      // iterate beginIt
			std::advance(beginIt, mid + 1);
			count = count - (mid + 1);
		}
		else
			count = mid;
	}

	count = v.size() - std::distance(v.begin(), beginIt);
	endIt = beginIt;

  // find last occurence iterator
	while (count > 0)
	{
		tempIt = endIt;
		mid = count / 2;
		std::advance(tempIt, mid);
		if (key >= *tempIt)
		{
      // iterate endIt
			std::advance(endIt, mid + 1);
			count = count - (mid + 1);
		}
		else
			count = mid;
	}

  // iterator difference
	return std::distance(beginIt, endIt);
	
}

int main()
{
	vector<int> input;
	input.push_back(0);
	input.push_back(1);
	input.push_back(2);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);
	input.push_back(5);
	input.push_back(5);
	input.push_back(6);
	input.push_back(6);
	input.push_back(6);
	input.push_back(6);
	input.push_back(7);
	input.push_back(7);
	input.push_back(8);
	input.push_back(9);
	input.push_back(9);

	int count2 = findElementCountWithUsingAdvancedBinarySearch(input, 6);
	cout << "count: " << count2 << endl;
  
  return 0;
}

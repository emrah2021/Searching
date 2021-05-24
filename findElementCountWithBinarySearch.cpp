#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int findElementCountWithBinarySearch(vector<int> v, int key)
{
	int low = 0;
	int high = v.size() - 1;
	int mid;
	int count = 0;
	int tempIndex = 0;

	if ((v[low] > key) || (v[high] < key))
		return 0;

	while (true)
	{
		mid = (high + low) / 2;
		if (v[mid] > key)
		{
			high = mid - 1; 
		}
		else if (v[mid] < key)
		{
			low = mid + 1; 
		}
		else
		{
			tempIndex = mid;
			while (true)
			{
				if (v[tempIndex] == key)
				{
					count++;
					tempIndex++;
				}
				else
					break;
			}
			while (true)
			{
				if (v[tempIndex] == key)
				{
					count++;
					tempIndex--;
				}
				else
					break;
			}		
			break;
		}
	}

	return count; 
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

	int count = findElementCountWithBinarySearch(input, 6);
	cout << "count: " << count << endl;
  
  return 0;
}
  

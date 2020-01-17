#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	if(startIndex<=lastIndex)
	{
		int midterm=(startIndex+lastIndex)/2;
		if(element == array[midterm])
		{
			return false;
		}
		else if(array[midterm]>element)
		{
			return binarySearchReacursive(array,startIndex,midterm-1,element);
		}
		else
		{
			return binarySearchReacursive(array,midterm+1,lastIndex,element);
		}
	}
  return true;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	while(startIndex<=lastIndex)
	{
		int midterm=(startIndex+lastIndex)/2;
		if(element == array[midterm])
		{
			return false;
		}
		else if(array[midterm]>element)
		{
			lastIndex=midterm-1;
		}
		else
		{
			startIndex=midterm+1;
		}
	}
  return true;
}


int main()
{
	int size;
	cout<<"Enter size - ";
	cin>>size;
	int *ary = new int[size];
	cout<<"Enter the array - ";
	for(int i=0;i<size;i++)
	{
		cin>>ary[i];
	}
	// Sorting the array
	sort(ary,ary+size);
	cout<<"\nSorted array - ";
	for(int i=0;i<size;i++)
	{
		cout<<ary[i]<<" ";
	}
	cout<<"\n\nEnter a number- ";
	int number;
	cin>>number;
	
	cout<<"\nBinary Search using Iteration - ";
	if(binarySearchIterative(ary,0,size-1,number))
	{
		cout<<"\n"<<number<<" is not present exists in the array";
	} else
	{
		cout<<"\n"<<number<<" is present in the array";
	}
	cout<<"\nBinary Search using Recursion - ";
	if(binarySearchReacursive(ary,0,size-1,number))
	{
		cout<<"\n"<<number<<" is not present in the array";
	}else
	{
		cout<<"\n"<<number<<" is present in the array";
	}
  
  return 0;
}

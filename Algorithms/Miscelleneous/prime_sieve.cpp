#include <iostream>

using namespace std;

int n;
int* arr;

void makeSieve()
{
	int i,j;
	for(i=2;i<=n;i++)
		if(!arr[i])
			for(j=i+i;j<=n;j+=i)
				arr[j]=1;
}

void printPrime()
{
	int i;
	for(i=2;i<=n;i++)
		if(!arr[i])
			cout<<i<<endl;
}

int main()
{
	cin>>n;
	int i;
	arr=(int*)malloc((n+1)*sizeof(int));

	//Make all elements in array as 0
	for(i=0;i<n;i++)
		arr[i]=0;

	makeSieve();
	printPrime();

	return 0;
}

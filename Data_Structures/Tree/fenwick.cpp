#include <iostream>

using namespace std;

//Important variables declared
int* arr;
int* fenwick;
int n;

//function to update the fenwick tree
void insert(int val,int pos)
{
	if(pos>n)
		return;
	fenwick[pos]+=val;
	insert(val,pos+(pos & (-pos)));
}

//function to evaluate sum till an index
int evaluate(int pos)
{
	if(pos==0)
		return 0;
	return fenwick[pos]+evaluate(pos-(pos & (-pos)));
}

int main()
{
	int sumTillIndex=5,i;
	cin>>n;
	arr=(int*)malloc(n*sizeof(int));
	fenwick=(int*)malloc((n+1)*sizeof(int));
	
	//input elements of fenwick tree
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		fenwick[i]=0;
	}
	fenwick[n]=0;
	
	//insert each element in fenwick tree
	for(i=0;i<n;i++)
		insert(arr[i],i+1);
		
		
	cout<<evaluate(sumTillIndex+1);
	return 0;
}

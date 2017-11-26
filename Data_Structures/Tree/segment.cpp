#include <iostream>
#include <cmath>

using namespace std;

int* arr;
int* segment;
int n;

//function to insert in segment tree
void insert(int val,int pos,int start,int end,int index)
{
	if(pos<start||pos>end)
		return;
	segment[index]+=val;
	if(start==end)
		return;
	int mid=(start+end)/2;
	insert(val,pos,start,mid,2*index+1);
	insert(val,pos,mid+1,end,2*index+2);
}

//function to evaluate
int evaluate(int initial,int final,int start,int end,int pos)
{
	if(start>=initial&&end<=final)
		return segment[pos];
	if(start>final||end<initial)
		return 0;
	int mid=(start+end)/2;
	return evaluate(initial,final,start,mid,2*pos+1)+evaluate(initial,final,mid+1,end,2*pos+2);
}

int main()
{
	int initial=0,final=4;
	cin>>n;
	arr=(int*)malloc(n*sizeof(int));
	int height=(int)(ceil(log2(n)));//height of tree;
	int max_size=2*(int)pow(2,height)-1;//size of segment tree array
	segment=(int*)malloc(max_size*sizeof(int));

	int i,sum=0;

	//Take inputs in array
	for(i=0;i<n;i++)
		cin>>arr[i];
	//Make every node in segment array as 0
	for(i=0;i<max_size;i++)
		segment[i]=0;
	//Insert elements in segment tree
	for(i=0;i<n;i++)
		insert(arr[i],i,0,n,0);
	cout<<evaluate(initial,final,0,n,0);
}

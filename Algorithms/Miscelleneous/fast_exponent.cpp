#include <iostream>
#include <cmath>
#define ll long long int
#define MOD 1000000009
 
using namespace std;

ll fast_exp(ll base,ll exp)
{
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
int main()
{
	ll base,exp;
	cin>>base>>exp;
	cout<<fast_exp(base,exp)<<endl;
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>data(n);
    for(int i=0;i<n;i++)
        cin>>data[i];
    int fi=-1;
    sort(data.begin(),data.end());
    int mid=n/2;
    int lo=mid-1;
    int hi=mid+1;
    while(data[lo]==data[mid]||data[hi]==data[mid])
    {
        if(data[lo]==data[mid])
            lo--;
        if(data[hi]==data[mid])
            hi++;
    }
    if(lo+1==n-hi)
        fi=data[mid];
    cout<<fi;
    return 0;
}
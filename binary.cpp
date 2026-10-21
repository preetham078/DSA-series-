
#include <iostream>
using namespace std;
int main(){
    int n,key,a[100],low,high,mid;
    bool found=false;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>a[i];}
    cin>>key;
    low=0;
    high=n-1;
    while(low<=high&&!found){
        mid=(low+high)/2;
        if(a[mid]==key){
            cout<<"Element found at position "<<mid+1<<"\n";
            found=true;
        }
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if(!found) cout<<"Element not found\n";
}

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}


#include<iostream>
using namespace std;
int main(){
    int arr1[5]={10,20,30,40,50};
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
        
    }cout<<endl;
        arr1[2]=35;
        arr1[4]=60;
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }

    return 0;
}

// #include<iostream>
// using namespace std;
// int main(){
//     int arr1[5]={10,20,30,40,50};
//     for(int i=0;i<5;i++){
//         cout<<arr1[i]<<" ";
        
//     }cout<<endl;
//         arr1[2]=35;
//         arr1[4]=60;
//     for(int i=0;i<5;i++){
//         cout<<arr1[i]<<" ";
//     }
//     cout<<endl;
//     int arr2[2][3]={{1,2,3},{4,5,6}};
//     for(int i=0;i<2;i++){
//         for(int j=0;j<3;j++){
//             cout<<arr2[i][j]<<" ";
//         }cout<<endl;
//     }

//     return 0;
// }


#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
      
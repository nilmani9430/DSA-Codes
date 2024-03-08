#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*int n;
    cin>>n;
    int **arr=new int *[n];
    for (int  i = 0; i < n; i++)
    {
        arr[i]=new int [n];
    } //Creation done

    //Taking input
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    //Taking output
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }*/
    int row,col;
    cin>>row;
    cin>>col;
    int **arr=new int *[row];

    for (int  i = 0; i < row; i++)
    {
        arr[i]=new int [col];
    } 
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    //Taking output
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j <col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }

    //Releasing memory
    for (int i = 0; i < row; i++)
    {
        delete []arr[i]; 
    }
    delete []arr;
    

    
    
}
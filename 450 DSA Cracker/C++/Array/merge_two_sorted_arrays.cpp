#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
	if(gap<=1)
        return 0;
    return (gap/2)+(gap%2);
}

void merge(int *arr1, int *arr2, int n, int m)
{
	int i,j,gap=n+m;
	for(gap=nextGap(gap);gap>0;gap=nextGap(gap))
    {
        for(i=0;i+gap<n;i++)
            if(arr1[i]>arr1[i+gap])
             swap(arr1[i],arr1[i+gap]);
            
        for(j=gap>n?gap-n:0; i<n&&j<m;i++,j++)
            if(arr1[i]>arr2[j])
             swap(arr1[i],arr2[j]);
        
        if(j<m)
        {
            for(j=0;j+gap<m;j++)
                if(arr2[j]>arr2[j+gap])
                 swap(arr2[j],arr2[j+gap]);
        }
    }
}


// METHOD 2 :- 
void merge2(int ar1[], int ar2[], int m, int n) 
{ 
    // Iterate through all elements of ar2[] starting from 
    // the last element 
    for (int i=n-1; i>=0; i--) 
    { 
        /* Find the smallest element greater than ar2[i]. Move all 
        elements one position ahead till the smallest greater 
        element is not found */
        int j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
            ar1[j+1] = ar1[j]; 

        // If there was a greater element 
        if (j != m-2 || last > ar2[i]) 
        { 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
    } 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
    
        for(int j=0;j<m;j++)
            cin>>b[j];
    
        merge(a,b,n,m);
    
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
    
        for(int j=0;j<m;j++)
            cout<<b[j]<<" ";
    
        cout<<endl;
    }
}

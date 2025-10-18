#include <iostream>
//[,1,0,2,1,0,1,3,2,1,2,1] 12,6     4,2,0,3,2,5   6,9
using namespace std;

int give_diff(int *p,int lar1,int size)
{
    int max=lar1+1;
    for(int i=lar1+2;i<size;i++)
    {
       if(p[i]>p[max]) 
       {
            max=i;
            for(int j=i+1;j<size;j++)
            {
                if(p[j]>max)
                {
                    max=j;
                }
            }
            return max;
       }
    }
    return max;
}

int main()
{
    int size;
    cout<<"Enter No of bars: ";
    cin>>size;

    int arr[size];

    for(int i=0;i<size;i++)
    {
        cout<<"Enter bar lengths: ";
        cin>>arr[i];
    }

    int larg1=0,larg2,count=0;
    for(int i=0;i<size;i++)
    {

    }
    for(int i=0;i<size;i++)
    {
            larg2=give_diff(arr,larg1,size);
            if(larg2==larg1+1)
            {
                larg1++;
                continue;
            }
        for(int diff=larg1+1;diff<larg2;diff++)
        {
            if(arr[larg2]>arr[larg1])
            {
                count+=(arr[larg1]-arr[diff]);
            }
            else
            {
                count+=(arr[larg2]-arr[diff]);
            }
        }
        larg1=larg2;
    }
    cout<<"Max Water trapped is: "<<count;
    return 0;
}
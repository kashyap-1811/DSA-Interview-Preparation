#include <iostream>
using namespace std;
 
int main()
{
    int size;
    cout<<"Enter no of days: ";
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the prize of the stock at day no.: ["<<i+1<<"]: ";
        cin>>arr[i];
    }

    int buy_day=0,sell_day=0;
    int max=INT32_MIN;
    int diff;

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            diff=arr[j]-arr[i];
            if(diff>max)
            {
                max=diff;
                buy_day=i+1;
                sell_day=j+1;
            }
        }
    }

    cout<<endl<<"Stock should be bought on day: "<<buy_day<<endl;
    cout<<"Stock should be sell on day: "<<sell_day<<endl;
    cout<<"Max profit in trading is: "<<max<<endl;

    return 0;
}
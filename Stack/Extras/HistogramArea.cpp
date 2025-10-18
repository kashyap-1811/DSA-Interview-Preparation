//    //  BRUTE FORCE
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     vector<int>heigth={2,1,5,6,2,3};

//     int area=0;

//     for(int i=0;i<heigth.size();i++)
//     {
//         int width=1,j=i-1,k=i+1;

//         while(k<(heigth.size()))
//         {
//             if(heigth[i]<=heigth[k])
//             {
//                 width++;
//             }
//             else{
//                 break;
//             }
//             k++;
//         }
//         while(j>0)
//         {
//             if(heigth[i]<=heigth[j])
//             {
//                 width++;
//             }
//             else
//             {
//                 break;
//             }
//             j--;
//         }

//         if(area<(heigth[i]*width))
//         {
//             area=heigth[i]*width;
//         }
//     }

//     cout<<"Max area is:  "<<area;
//     return 0;
// }

//      IMPROVED
#include <bits/stdc++.h>

using namespace std;

int MaxHistoArea(vector<int>&height)
{
    vector<int>nsr(height.size());
    vector<int>nsl(height.size());
    stack<int>s;

    //next smaller left
    nsl[0]=-1;
    s.push(0);

    for(int i=1;i<height.size();i++)
    {
        int curr=height[i];

        while(!s.empty() && curr<=height[s.top()])
        {
            s.pop();
        }

        if(s.empty())
            nsl[i]=-1;
        else
            nsl[i]=s.top();

        s.push(i);
    }

    while(!s.empty())
        s.pop();

    //next smaller right
    int n=height.size();
    nsr[n-1]=n;
    s.push(n-1);

    for(int i=n-2;i>=0;i--)
    {
        int curr=height[i];

        while(!s.empty() && curr<=height[s.top()])
            s.pop();

        if(s.empty())
        {
            nsr[i]=n;
        }
        else
        {
            nsr[i]=s.top();
        }

        s.push(i);
    }

    int Maxarea=0;
    for(int i=0;i<height.size();i++)
    {
        int area=height[i]*(nsr[i]-nsl[i]-1);

        if(Maxarea<area)
            Maxarea=area;
    }
    return Maxarea;
}

int main()
{
    vector<int>height={2,1,5,6,2,3};

    cout<<MaxHistoArea(height);
    return 0;
}
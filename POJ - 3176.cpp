POJ - 3176 
Cow Bowling 

    The cows don't use actual bowling balls when they go bowling. They each take a number (in the range 0..99), though, and line up in a standard bowling-pin-like triangle like this:

              7



            3   8



          8   1   0



        2   7   4   4



      4   5   2   6   5

    Then the other cows traverse the triangle starting from its tip and moving "down" to one of the two diagonally adjacent cows until the "bottom" row is reached. The cow's score is the sum of the numbers of the cows visited along the way. The cow with the highest score wins that frame.

    Given a triangle with N (1 <= N <= 350) rows, determine the highest possible sum achievable. 
Input
    Line 1: A single integer, N

    Lines 2..N+1: Line i+1 contains i space-separated integers that represent row i of the triangle. 
Output
    Line 1: The largest sum achievable using the traversal rules 
Sample Input

    5
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5

Sample Output

    30

Hint
    Explanation of the sample:

              7

             *

            3   8

           *

          8   1   0

           *

        2   7   4   4

           *

      4   5   2   6   5

    The highest score is achievable by traversing the cows as shown above. 
    
My Code:
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll way[355][355];
ll dp[355][355];
ll Max(ll x,ll y)
{
	return x>y?x:y;
}
void Input(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cin>>way[i][j];
		}
	}
}
void Solve(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i][j]=Max(dp[i-1][j-1],dp[i-1][j])+way[i][j];
		}
	}
}
void Output(int n)
{
	int max=-1;
	for(int i=0;i<n;i++)
	{
		max=Max(dp[n-1][i],max);
	}
	cout<<max<<endl;
}

int main()
{
	memset(way,0,sizeof(way));
	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	Input(n);
	Solve(n);
	Output(n);
	return 0;
} 

这个题的思路就是简单dp，dp[i][j]表示的是第i行第j个保龄球的值，状态转移方程为dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
当j==0时（每行第一个）只能继承dp[i-1][0];
遍历最后一行即可 

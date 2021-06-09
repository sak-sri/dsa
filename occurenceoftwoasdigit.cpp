#include<bits/stdc++.h>
using namespace std;
long long int binexpo(int a,int b){
    if(b==0)
        return 1ll;
    else if(b==1)
        return a;
    int temp=binexpo(a,b/2);
    temp=temp*temp;
    if(b%2)
        return temp*a;
    else
        return temp;
}
long long int count2sinRangeAtDigit(long long int number, long long int d)
{
// Your code goes here
    int powerof10=binexpo(10,d);
    int nextpowerof10=10*powerof10;
    int digit=(number/powerof10)%10;
    int rounddown=number-(number%nextpowerof10);
    int roundup=rounddown+nextpowerof10;
    if(digit<2){
        return rounddown/10;
    }else if(digit>2){
        return roundup/10;
    }else{
        return (rounddown/10)+1+(number%powerof10);
    }
}

/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
    long long int temp=number;
    long long int len=to_string(number).length();
    long long int ans=0;
    for(int i=0;i<len;i++){
        ans+=count2sinRangeAtDigit(number,i);   
    }
    return ans;
}
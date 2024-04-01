#include <iostream>
#include <cmath>
using namespace std;
bool prime(int i)
{
    if (i == 2)
    {return true;}
    else if(i == 1){return false;}
    int h = (int) sqrt(i);
    for (int j = 2; j <= h; j++)
    {
        if (i % j == 0)
        {return false;}
    }
    return true;
}
int main(){
    int count = 4, ary[100]={2,3,5,7}, i = 0, maxi = 429496729,aryi = 4,paus = 4;
    cout << "2\n3\n5\n7\n";
    while(1){
        for(i;ary[i] != 0;i++){
            for (int digit = 1; digit<10;digit+=2){
                if (prime(ary[i]*10+digit) && (ary[i]<maxi)){
                    ary[aryi] = ary[i]*10+digit;
                    aryi++;
                    count++;
                    paus++;
                    cout<<ary[aryi-1]<<endl;
                    if (paus==20){
                        system("pause");
                        system("cls");
                        paus = 0;
                    }
                    if (count ==83){
                        cout<< "Count = "<< count<<endl;
                        system("pause");
                        exit(0);
                    }
                }
            }
        }
    }
}
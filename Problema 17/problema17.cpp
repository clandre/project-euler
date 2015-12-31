#include<time.h>
#include<iostream>
#include<map>
#define n 1000

using namespace std;

void hashTable(map<int,int> &digitSize);
int countSize(map<int,int> &digitSize);

int main(void)
{
    clock_t start = clock();
    map<int,int> digitSize;
    hashTable(digitSize);
    clock_t end = clock();
    cout << countSize(digitSize) << " in " <<(float)(end - start)/CLOCKS_PER_SEC << " segundos." << endl;
    return 0;
}

void hashTable(map<int,int> &digitSize)
{
    digitSize.insert(pair<int,int>(1,3));
    digitSize.insert(pair<int,int>(2,3));
    digitSize.insert(pair<int,int>(3,5));
    digitSize.insert(pair<int,int>(4,4));
    digitSize.insert(pair<int,int>(5,4));
    digitSize.insert(pair<int,int>(6,3));
    digitSize.insert(pair<int,int>(7,5));
    digitSize.insert(pair<int,int>(8,5));
    digitSize.insert(pair<int,int>(9,4));
    digitSize.insert(pair<int,int>(10,3));

    digitSize.insert(pair<int,int>(11,6));
    digitSize.insert(pair<int,int>(12,6));
    digitSize.insert(pair<int,int>(13,8));
    digitSize.insert(pair<int,int>(14,8));
    digitSize.insert(pair<int,int>(15,7));
    digitSize.insert(pair<int,int>(16,7));
    digitSize.insert(pair<int,int>(17,9));
    digitSize.insert(pair<int,int>(18,8));
    digitSize.insert(pair<int,int>(19,8));
    digitSize.insert(pair<int,int>(20,6));

    digitSize.insert(pair<int,int>(30,6));
    digitSize.insert(pair<int,int>(40,5));
    digitSize.insert(pair<int,int>(50,5));
    digitSize.insert(pair<int,int>(60,5));
    digitSize.insert(pair<int,int>(70,7));
    digitSize.insert(pair<int,int>(80,6));
    digitSize.insert(pair<int,int>(90,6));
    digitSize.insert(pair<int,int>(100,10));
    digitSize.insert(pair<int,int>(200,10));
    digitSize.insert(pair<int,int>(300,12));
    digitSize.insert(pair<int,int>(400,11));
    digitSize.insert(pair<int,int>(500,11));
    digitSize.insert(pair<int,int>(600,10));
    digitSize.insert(pair<int,int>(700,12));
    digitSize.insert(pair<int,int>(800,12));
    digitSize.insert(pair<int,int>(900,11));
    digitSize.insert(pair<int,int>(1000,11));
}

int countSize(map<int,int> &digitSize)
{
    int resp = 0;
    for(int i=1; i <= n; i++)
    {
        if((i <= 20) || (i % 100 == 0))
            resp += digitSize[i];
        else if(i < 100)
            resp += digitSize[(i/10)*10] + digitSize[i%10];
        else
        {
            int dezena = i % 100;
            if (dezena <= 20)
                resp += digitSize[i-dezena]+ digitSize[dezena] + 3;
            else
                resp += digitSize[i-dezena] + digitSize[(dezena/10)*10] + digitSize[dezena%10] +  3;
        }
    }
    return resp;
}

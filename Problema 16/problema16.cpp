#include<iostream>
#include<math.h>
#include<time.h>
#include<string>
#define ISNUM(x) ((x) >= 0 && (x) <= 9)

using namespace std;

int main(void){
clock_t start = clock();
int resp = 0;
double x = pow(2,1000);
string str = to_string(x);

for(char c : str)
	if(ISNUM(c - '0'))
    	resp += c - '0';
clock_t end = clock();
cout << resp << " in " <<(float)(end - start)/CLOCKS_PER_SEC << "segundos." << endl;

return 0;
}

#include<bits/stdc++.h>
using namespace std;

int arr[110] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6,9,9,11,10,10,9,11,11,10,6,9,9,11,10,10,9,11,11,10,5,8,8,10,9,9,8,10,10,9,5,8,8,10,9,9,8,10,10,9,5,8,8,10,9,9,8,10,10,9,7,10,10,12,11,11,10,12,12,11,6,9,9,11,10,10,9,11,11,10,6,9,9,11,10,10,9,11,11,10,7};

const int hunda = 10;
const int hund = 7;
int sum;
int main()
{
    //freopen("out.txt","w",stdout);
	int _, i, res, num, temp, temp2;
	for(i = 0; i < 100; i++)
		sum += arr[i];
	scanf("%d", &_);
	while(_--){
		res = 0;
		//scanf("%d", &num);
		//num=j;
		if(num == 1000){
			num--;
			res = 11;
		}
		temp = num % 100;
		temp2 = num / 100;
		for(i = 1; i <= temp; i++){
			res += arr[i];
			if(temp2 != 0)
				res += hunda + arr[temp2];
		}
		num = num - temp;
		for(i = 0; i * 100 < num; i++){
			if(i != 0){
			res += arr[i] + hund;
			res += (arr[i] + hunda) * 99;
			}
			res += sum;
		}
		if(i != 0)
		res += arr[i] + hund;
		printf("%d\n", res);
	}
	return 0;
}

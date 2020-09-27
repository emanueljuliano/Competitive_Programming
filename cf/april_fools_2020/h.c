#include <stdio.h>

int main(){
	int n;	
	scanf("%d", &n);
	int at = n/1000;
	int mod = n- at*1000;

	int i;
	int ans = 1;
	for(i=at; i>0; i=i-2){
		ans = ans*i;
		ans = ans%mod;
	}
	printf("%d\n", ans);
	return 0;
}

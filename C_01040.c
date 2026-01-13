#include <stdio.h>
int main(){
	int a;
	int b=0;
	scanf("%d", &a);
	int i;
	for(i=1; i<a; i++){
		if(a%i==0){
			b+=i;
		}
	}
	if(b==a){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}

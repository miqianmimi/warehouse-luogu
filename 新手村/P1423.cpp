#include <cstdio>
int main(){
	float distance;
	scanf("%f",&distance);
	float a = 2;
	float sum = 0;
	int count = 1;
	for (count = 1 ;; count ++ ){
		sum = sum + a ;
		a = a * 0.98 ;
		if (sum > distance){
			break;
		} 
	}
	printf("%d\n",count);
	return 0;
}

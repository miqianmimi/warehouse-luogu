#include<cstdio>
int distance(int x){
	int y = 0 ;
	if ( x > 0 && x < 6){
		y = 250;
	}  
	else{
		y = 0;
	}
	return y ;
}
int main(){
	int day = 0;
	int n = 0;
	scanf("%d %d",&day,&n);
	int sum = 0;
	for(int a = n ; a > 0 ; a --){
		sum += distance(day);
		day = (day+1) % 7;
	} 
	printf("%d\n",sum);
	return 0;
}

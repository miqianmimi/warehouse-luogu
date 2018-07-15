# include<stdio.h>
int main(){
	int k;
	scanf("%d",&k);
	float money;
	if (k < 150){
		money = k * 0.4463 ;
	}
	else if( 151< k && k < 400){
		money = 150 * 0.4463 + ( k -150 ) * 0.4663	;
	}
	else{
		money = 150 * 0.4463 + 250 * 0.4663 + ( k - 400 ) * 0.5663 ;
	}
	printf("%.1f\n",money);
}

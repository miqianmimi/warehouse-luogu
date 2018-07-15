#include<stdio.h>
int main(){
	int cost[12];
	int count = 0;
	while( count < 12 ){
		scanf("%d",&cost[count]);
		count ++;
	}
	int save = 0;
	int now_money = 0;
	count = 0;
	int month;
	while( count < 12 ){
		if ( cost[count] + 100 <= 300 + now_money ){
			int a = int ((300 + now_money - cost[count]) / 100 ) * 100;
			save = save + a;
			now_money = 300 + now_money - cost[count] - a ;		   	
		}
		else if ( cost[count] + 100 >= 300 + now_money && cost[count] <= 300 + now_money ){
			save = save;
			now_money = 300 + now_money - cost[count];
		}
		else if ( cost[count] > 300 + now_money){
			month = count + 1;
			break;
		}
		count ++;
	}
	if (count == 12 ){
		save = save * 1.2 + now_money;
		printf("%d\n",save);
	}
	else{
		printf("-%d\n",month);
	}
	return 0;
}


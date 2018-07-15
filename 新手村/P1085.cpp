#include<stdio.h>
#include<algorithm>
int main(){
	int study_in_school[7];
	int study_at_home[7];
	int count = 0;
	while (count < 7){
		scanf("%d%d",&study_in_school[count],&study_at_home[count]);		
		count ++ ; 
	}
	count = 0;
	int hour[7];
	while (count < 7){
		hour[count] = study_in_school[count] + study_at_home[count];
		count ++;
	}
	count = 0;
	int a = 0;
	int max = hour[0];
	int day = 1;
	while (count < 7){
		if (max < hour[count]){
			max = hour[count];
			day = count+1;
		}
		count ++;
	}
	if (max <= 8){
		day = 0;
	}
	printf("%d\n",day);	
	return 0;
}

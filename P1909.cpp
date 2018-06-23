//#include<stdio.h>
#include<cstdio>
#include<algorithm>
int min(int a, int b, int c) {
	int r = a;
	if (r > b) r = b;
	if (r > c) r = c;
	return r;
}
int main(){
	int total_num;
	scanf("%d",&total_num);
	int count = 0;
	int num[3];
	int money[3];
	while ( count < 3 ){
		scanf("%d %d",&num[count],&money[count]);
		count ++;
	}
	int total_box[3];
	int total_money[3];
	count = 0;
	while ( count < 3 ){
		if (total_num % num[count]==0){
			total_box[count] = (int)(total_num/num[count]);
		}
		else{
			total_box[count] = (total_num/num[count]) + 1;
		}
		total_money[count] = money[count] * total_box[count];
		count ++ ;
	}
	count = 0;
	int *a = total_money;
	//int mi = min(a[0], a[1], a[2]);
	//int *min_ptr = std::min_element(a, a + 3);
	int min_idx = std::min_element(a, a + 3) - a;
	//printf("%d\n",*min_ptr);
	std::printf("%d\n",a[min_idx]);
	return 0;
}

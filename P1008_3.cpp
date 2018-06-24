#include <cstdio>
#include <algorithm>
bool flag[10];
void change(int i){
	while(i){
		flag[i % 10] = true;
		i = i / 10;	
	}
}
int main(){
	int i = 111 ;
	while (i <= 333){
		int j = i * 2;
		int p = i * 3;
		for (int k = 0; k < 10; k++) flag[k] = false;
		change(i);
		change(j);
		change(p);	
		int count = 1;
		while(count<10){
			if (flag[count]== false){
				break;
			}
			count ++;
		}
		if (count == 10){
			printf("%d %d %d\n",i,j,p);
		}
		
		i++;
	}
	return 0;
}

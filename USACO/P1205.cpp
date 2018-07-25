#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n;
char a[100][100],b[100][100],c[100][100],d[100][100],e[100][100],f[100][100],g[100][100],h[100][100];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	//1.转90度
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){   
			c[j][n+1-i] = a[i][j];
		}
	}
/*	//print变化后函数
	cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout<<c[i][j];
      }
      cout<<endl;
  }
*/
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (b[i][j]!=c[i][j]){
    		//cout<<"not right"<<endl;
    		goto here2;
    	}
		}
	}
	cout<<1<<endl;
	return 0;
	here2:
	//2.转180度
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[n+1-i][n+1-j]=a[i][j];
		}
	}
/*	//print变化后函数
	cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<d[i][j];
      }
      cout<<endl;
  }
*/
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (b[i][j]!=d[i][j]){
    		//cout<<"not right"<<endl;
    		goto here3;
    	}
		}
	}
	cout<<2<<endl;
	return 0;
	here3:
	//3.转270度
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[n+1-j][i]=a[i][j];
		}
	}
/*	//print变化后函数
	cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<e[i][j];
      }
      cout<<endl;
  }
 */
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (b[i][j]!=e[i][j]){
    		//cout<<"not right"<<endl;
    		goto here4;
    	}
		}
	}
	cout<<3<<endl;
	return 0;
	here4:
	//4.反射
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][n+1-j]=a[i][j];
		}
	}
/*	//print变化后函数
	cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<f[i][j];
      }
      cout<<endl;
  }
*/
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (b[i][j]!=f[i][j]){
    		//cout<<"not right"<<endl;
    		goto here5;
    	}
		}
	}
	cout<<4<<endl;
	return 0;
	here5:
	//5.三种情况
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){   
			c[j][n+1-i] = f[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[n+1-i][n+1-j]=f[i][j];
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[n+1-j][i]=f[i][j];
		}
	}
/*	//print变化后函数
	cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<c[i][j];
      }
      cout<<endl;
  }
  cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<d[i][j];
      }
      cout<<endl;
  }  
	cout<<endl;
  for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cout<<e[i][j];
      }
      cout<<endl;
  }    
*/
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (c[i][j]!=b[i][j]){
    		//cout<<"not right"<<endl;
    		goto here52;
    	}
		}
	}
	cout<<5<<endl;
	return 0;	
	here52:
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (d[i][j]!=b[i][j]){
    		//cout<<"not right"<<endl;
    		goto here53;
    	}
		}
	}
	cout<<5<<endl;
	return 0;
	here53:
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (e[i][j]!=b[i][j]){
    		//cout<<"not right"<<endl;
    		goto here6;
    	}
		}
	}
	cout<<5<<endl;
	return 0;
	here6:
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    	if (a[i][j]!=b[i][j]){
    		//cout<<"not right"<<endl;
    		goto here7;
    	}
		}
	}
	cout<<6<<endl;
	return 0;
	here7:
	cout<<7<<endl;
	return 0;	
}



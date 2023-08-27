#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
using namespace std;

int main(){
//	int k,n=5,n1=5;
//	for(int i=11;i>0;i--){
//		n=n1;
//		for(int j=0;j<11;j++){
//			if(i==n || j==10){
//				cout<<n;
//			}else{
//			cout<<n;
//			n--;
//			}
//		}
//	
//		cout<<endl;
//	}


int k,n=5,n1=9, ch;
char c;
	for(int i=0;i<(2*n-1);i++){
		for(int j=0;j<(2*n-1);j++){
			for(int l=0;l<n;l++){
				if(i==l || j==l || i==(2*n-2)-l || j==(2*n-2)-l){
//					c=(char)n-l+96;
//					c=n-l;
					ch=n-l;
					cout<<ch <<" ";
					usleep(5000);
					break;
				}
			}
		}
		cout<<endl;
	}

getch();
}

#include <iostream>
#include <exception>
#include "Mat.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool lu(double*a,int*pivot,int n){
	Mat A(a,n);
	int i=0;
	int j=0;
	try{
		for(i=1;i<n;i++){
			for(j=0;j<n;j++){
				
				if(j<i){
					double Aij = A.get(i,j);
					double accumulation = 0.0;
					for(int r=0;r<j;r++){
						double Urj = A.get(r,j);
						double Lir = A.get(i,r);
						accumulation += Urj*Lir;
						
					}
					//¼ÆËãL
					double Lij;
					double Ujj = A.get(j,j);
					Lij = (Aij-accumulation)/Ujj;
					A.set(i,j,Lij);
				}
				else{
					double Aij = A.get(i,j);
					double accumulation = 0.0;
					for(int r=0;r<i;r++){
						double Urj = A.get(r,j);
						double Lir = A.get(i,r);
						accumulation += Urj*Lir;
						
					}
					double Uij;
					Uij = Aij-accumulation;
					A.set(i,j,Uij);
					
				}
			}
		}
	
		for(i=0;i<n;i++){
			pivot[i] = i;
		}
		return false;
	}
	catch(const char* msg){
		return true;
	}
	 
}
int main(int argc, char** argv) {
	double a[16]={2,2,3,4,2,4,9,16,4,8,24,63,6,16,51,100};
	for(int i=0;i<16;i++){
		if (i%4==0){
			cout<<endl;
		}
		cout<<a[i]<<" ";
	}
	cout<<endl; 
	int b[4];
	bool flag = lu(a,b,4);
	for(int i=0;i<16;i++){
		if (i%4==0){
			cout<<endl;
		}
		cout<<a[i]<<" ";
	}
	
}

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
					//计算L
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


bool guass(double const* lu, int const* p, double* b, int n){ 
	
	//计算 [L^-1] x [b] = [y]
	double new_lu[n*n];
	for(int i=0;i<n*n;i++){
		new_lu[i] = lu[i];
	} 
	Mat A(new_lu,n);

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			b[i] -= b[j]*A.get(i,j); 
		}
	}
	bool flag = true;
	//对上三角矩阵U 求解 Ux = y
	for(int i=n-1;i>=0;i--){
	 	// 第i行的常数项左移
		for(int j=n-1;j>i;j--){
			b[i] -= b[j]*A.get(i,j);
		} 
		if(A.get(i,i)==0 && b[i]!=0){
			flag = false;
			break;
		} 
		b[i] = b[i]/A.get(i,i);
	}
	
	if(flag){
		
		return false;	
	}
	else{
		return true;
	}
	
	
}


void qr(double *a,double*d,int n){
	
}
int main(int argc, char** argv) {
	double a[16]={3,1,0,0,2,3,1,0,0,2,3,1,0,0,1,3};
	for(int i=0;i<16;i++){
		if (i%4==0){
			cout<<endl;
		}
		cout<<a[i]<<" ";
	}
	cout<<endl; 
	int p[4];
	bool flag = lu(a,p,4);
	for(int i=0;i<16;i++){
		if (i%4==0){
			cout<<endl;
		}
		cout<<a[i]<<" ";
	}
	double b[4]={1,0,1,0};
 	cout<<endl;
 	cout<<endl;
 	cout<<endl;
	flag = guass(a,p,b,4);
	if(flag==false){
		for(int i=0;i<4;i++){
		cout<<b[i]<<endl;
		}	
	}
	
	
}

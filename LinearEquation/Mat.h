#include <iostream>
using namespace std;

class Mat{
	public:
		double get(int x,int y);
		void set(int x,int y, double val);
		double * get_row(int x);
		Mat(double * DataArray, int n);
	private:
		double * array;
		int dim;
};

Mat::Mat(double * DataArray, int n){
	array = DataArray;
	dim = n;
	
}

double Mat::get(int x, int y){
	int pos = x * dim + y;
	return *(array+pos);
}

void Mat::set(int x ,int y, double val){
	int pos = x * dim + y;
	*(array+pos) = val;
}
double * Mat::get_row(int x){
	return array+x*dim;
}

double inner_product(double *a,double *b,int n){
	double sum=0.0;
	for(int i=0;i<n;i++){
		sum+= (*(a+i)) * (*(b+i));;
	}
	return sum;
}

double norm(double *a,int n){
	double sum= 0.0;
	for(int i=0;i<n;i++){
		sum+=(*(a+i)) * (*(a+i));
	}
}

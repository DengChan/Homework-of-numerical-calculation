#include <iostream>
using namespace std;

class Mat{
	public:
		double get(int x,int y);
		void set(int x,int y, double val);
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




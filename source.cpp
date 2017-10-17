#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

const int N = 1000;

int main(){
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<int> s_dist(0,1);
	std::uniform_real_distribution<double> x_dist(-1.0,1.0);
	std::vector<double> x_data;
	std::vector<double> y_data;
	for(int i = 0;i < N;i++){
		double x = x_dist(mt);
		int s = s_dist(mt)==1?1:-1;
		double y = x * s;
		x_data.push_back(x);
		y_data.push_back(y);
		std::cout<<x<<" "<<y<<std::endl;
	}
	double x_avg = std::accumulate(x_data.begin(),x_data.end(),0.0)/N;
	double y_avg = std::accumulate(y_data.begin(),y_data.end(),0.0)/N;
	std::cout<<"# x avg = "<<x_avg<<std::endl<<"# y avg = "<<y_avg<<std::endl;
	double cov = std::inner_product(x_data.begin(),x_data.end(),y_data.begin(),0.0,std::plus<double>(),[&x_avg,&y_avg](double x,double y){return (x-x_avg)*(y-y_avg);})/N;
	std::cout<<"# cov = "<<cov<<std::endl;
}

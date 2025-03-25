#include <iostream>
using namespace std;
int main(){
	int i;
	cout << "你想输入多少个整形数据！请输入个数:\n\n" ;
	std::cin >> i;
	int num[i];
	cout << "请输入"<< i << "个整形数据！\n\n" ;
	for(int j=0; j<i;j++){
		cout<<"请输入第" << j+1 <<"个数据:";
		std::cin >>num[j];
	}
	int total =0;
	for(int j=0;j<i;j++){
		total+=num[j];
	}
	std::cout << "总和是：" << total << "\n";
	std::cout << "平均值是：" << (float)total/i << "\n";
	return 0;
}

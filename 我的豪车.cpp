#include <iostream>
#include <string.h>

class Car{
public:
	std::string color;
	std::string engine;
	float gas_tank;
	unsigned int wheel;
	
	void fill_tank(float liter);
	int running(void);
	void warning(void);
	void Setcolor(std::string col);
	void Setengine(std::string eng);
	void Setwheel(unsigned int whe);
};
#define Full_GAS 85
void Car::fill_tank(float liter){
	gas_tank += liter;
}
int Car::running(void){
	std::cout << "我正在以120时速往前移动\n";
	gas_tank--;
	std::cout <<"当前还剩" << 100*gas_tank/Full_GAS <<"%" << "油量\n";
	return gas_tank;
}

void Car::warning(void){
	std::cout << "Warnring!" << "还剩" << 100*gas_tank/Full_GAS << "%" << "油量";
}
void Car::Setcolor(std::string col){
	color = col;
}
void Car::Setengine(std::string eng){
	engine = eng;
}
void Car::Setwheel(unsigned int whe){
	wheel = whe;
}
int main(){
	char i;
	Car myself;
	myself.Setcolor("White");
	myself.Setengine("v8");
	myself.Setwheel(4);
	myself.gas_tank = Full_GAS;
	
	while(myself.running()){
		if(myself.running()<10){
			myself.warning();
			std::cout << "请问是否需要加满油在行使？(Y/N)\n";
			std::cin >> i;
			if('Y'==i||'y'==i){
				myself.fill_tank(Full_GAS);
			}
		}
	}
	
	
	return 0;
}

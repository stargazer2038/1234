#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){
	int target,guess,attempts =0;
	srand(time(0));
	target = rand() % 100 +1;
	
	printf("欢迎来到猜数字游戏\n");
	printf("我已经想好了1-100间的数字");
	
	do{
		printf("请输入你的猜测：");
		
		if(scanf("%d",&guess) != 1){
			while(getchar()!='\n');
			printf("输入错误，请输入数字\n\n");
			continue;
		}
		attempts++;
		
		if(guess<1 ||guess >100){
			printf("数字须在1到100之间\n\n");
		}
		else if(guess < target){
			printf("你猜的数字太小了");
		}
		else if(guess > target){
			printf("你猜的数字太大了");
		}
		else {
			printf("你猜对了！\n\n");
			printf("你用了%d次机会猜对!\n",attempts);
		}
	}while (guess != target);
	
	
	return 0;
}

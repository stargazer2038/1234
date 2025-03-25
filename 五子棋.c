#include <stdio.h>
#include <stdlib.h>

#define SIZE 15  // 棋盘尺寸
#define WIN_COUNT 5  // 获胜所需连续棋子数

// 棋盘格子状态
enum {
	EMPTY = 0,
	BLACK,
	WHITE
};

int board[SIZE][SIZE]; // 棋盘数组

// 初始化棋盘
void init_board() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = EMPTY;
		}
	}
}//函数1

// 打印棋盘
void print_board() {
	system("cls"); // 清屏（Windows）
	
	// 打印列号
	printf("   ");
	for (int i = 0; i < SIZE; i++) {
		printf("%2d ", i + 1);
	}
	printf("\n");
	
	// 打印棋盘内容
	for (int i = 0; i < SIZE; i++) {
		printf("%2d ", i + 1); // 行号
		for (int j = 0; j < SIZE; j++) {
			switch (board[i][j]) {
			case BLACK:
				printf(" ● ");
				break;
			case WHITE:
				printf(" ○ ");
				break;
				default:
					printf(" + ");
					break;
			}
		}
		printf("\n");
	}
}//函数2

// 判断是否胜利
int check_win(int player, int x, int y) {
	int directions[4][2] = {{1,0}, {0,1}, {1,1}, {1,-1}}; // 四个检查方向
	
	for (int d = 0; d < 4; d++) {
		int dx = directions[d][0];
		int dy = directions[d][1];
		int count = 1;
		
		// 正方向检查
		for (int i = 1; ; i++) {
			int nx = x + dx * i;
			int ny = y + dy * i;
			if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
			if (board[nx][ny] != player) break;
			count++;
		}
		
		// 反方向检查
		for (int i = 1; ; i++) {
			int nx = x - dx * i;
			int ny = y - dy * i;
			if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
			if (board[nx][ny] != player) break;
			count++;
		}
		
		if (count >= WIN_COUNT) return 1;
	}
	return 0;
}//函数3

int main() {
	int current_player = BLACK;
	int steps = 0;
	
	init_board();
	print_board();
	
	while (1) {
		int x, y;
		printf("玩家 %s 的回合，请输入坐标（行 列）：", 
			current_player == BLACK ? "黑棋" : "白棋");
		scanf("%d %d", &x, &y);
		
		// 转换为数组索引
		x--;
		y--;
		
		// 检查输入合法性
		if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
			printf("坐标超出范围！\n");
			continue;
		}
		if (board[x][y] != EMPTY) {
			printf("该位置已有棋子！\n");
			continue;
		}
		
		// 落子
		board[x][y] = current_player;
		steps++;
		print_board();
		
		// 检查胜利
		if (check_win(current_player, x, y)) {
			printf("玩家 %s 获胜！\n", current_player == BLACK ? "黑棋" : "白棋");
			break;
		}
		
		// 检查平局
		if (steps == SIZE * SIZE) {
			printf("平局！\n");
			break;
		}
		
		// 切换玩家
		current_player = (current_player == BLACK) ? WHITE : BLACK;
	}
	
	return 0;
}

//
//brainfuck interpreter
//標準入力を食ってしまうのでa
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//入力を最初に受けとる
	char input[1<<8];
	int l = 0;
	while(~scanf("%c\n", &input[l++]));

	//printf("%s\n", input);

	//実際に処理を行うpointer
	int *ptr = (int*)malloc((1<<8)*sizeof(int));

	//今どこのloopかを見る配列のような物
	//loop_ptr[d]には深さdのループの開始地点が入っている
	int*loop_ptr = (int*)malloc((1<<8)*sizeof(int));

	if (ptr == NULL || loop_ptr == NULL)
	{
		return -1;
	}

	//処理
	for (int i = 0; i < l; i++)
	{
		char c = input[i];
		if (c == '>') ptr++;
		if (c == '<') ptr--;
		if (c == '+') (*ptr)++;
		if (c == '-') (*ptr)--;
		if (c == '.') putchar(*ptr);
		if (c == ',') *ptr = getchar();
		if (c == '[')
		{
			*loop_ptr = i;
			loop_ptr++;
		}
		if (c == ']')
		{
			if ((*ptr) == 0)
			{
				loop_ptr--;
			}
			else
			{
				i = *(loop_ptr-1);
			}
		}
	}

	return 0;
}

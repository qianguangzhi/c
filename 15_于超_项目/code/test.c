#include"air.h"

int main(void)

{
	air_pcrft s;
	aircrft_init(&s);

	char n;
	int m=3;
	char password[10];//ad[10];
	
	do
	{
	m--;
	printf("\033[0;32;31m""你现在有%d次机会\n""\033[m",m+1);
	printf("请输入正确的管理员密码：");
	scanf("%s",password);
	getchar();
	if(m == 0)
		exit(1);
	}while(strcmp(password,"741")!=0);
		system("clear");
	while(1)
	{
		menu();
		printf("请选择\n");
		scanf("%s",&n);
		getchar();
			switch(n)
			{
				case '1':aircrft_list(s);
					break;

				case '2':aircrft_show(s);//scanf("%s",ad);system("clear");
					break;

				case '3':inquire(s);
					break;

				case '4':change(s);
					break;

				case '5':delete(s);
					break;

				case '6':sort(s);
					break;

				case '8':shutdown();
					break;
			
				case '7':buy_air_ticket(s);
					break;

				default:printf("没有这个选项\n");
			}

	}
	return 0;
}

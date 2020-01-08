void Proc()
{
	int i = 0;
	char bar[102] = { '\0' };
	char* buf = "-\\|/";
	while (i < 100)
	{
		bar[i] = '#';
		printf("[%-101s]   [%c][%d%%]\r", bar, buf[i % 4], i);
		fflush(stdout);
		usleep(100000);
	}
}
void menu()
{
	printf("****************************************************\n");
	printf("************     1.play     0.exit     *************\n");
	printf("****************************************************\n");
}
void print()
{
	printf(" %c | %c | %c \n");
	printf("---|---|---\n");
}
void game()
{
	print();
}

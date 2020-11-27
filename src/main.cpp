#include "Logging.h"

FILE* g_logFile = nullptr;

void output(const char* msg, int len)
{
	fwrite(msg, 1, len, g_logFile);
	fflush(g_logFile);
}

void initialize()
{
	g_logFile = fopen("debuglog.txt", "w");
	if(!g_logFile)
		g_logFile = stdout;
	muduo::Logger::setOutput(output);
	muduo::Logger::setLogLevel(muduo::Logger::DEBUG);
}

void fun()
{
	int num1 = 1993;
	long long num2 = 69542354126;
	unsigned num3 = 15;
	string str1 = "Hello world!";
	char* str2 = "How are you!";
	char c = 'a';
	LOG_INFO << str1 << " " << num1;
	LOG_DEBUG << str2 << " " << num2;
	LOG_DEBUG << c << " " << num3;
}

int main()
{
	initialize();
	fun();
    return 0;
}

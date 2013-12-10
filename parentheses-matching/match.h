typedef char String[256];
typedef struct{
	char* braces;
	int length;
	int top;
} charStack;
int matchBraces(String data);
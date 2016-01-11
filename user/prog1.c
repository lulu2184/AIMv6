#include "syscall/print.h"
#include "syscall/exit.h"

char *constant_str = "constant string print\r\n";
unsigned tmp = 10;

int main() {
	char *str = "Hello user space! :)\r\n";

	print(str);
	print(constant_str);
	puthex(tmp);

	exit(0);
}

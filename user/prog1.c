#include "syscall/print.h"
#include "syscall/exit.h"

char *constant_str = "[P1]constant string print\r\n";
unsigned tmp = 10;

int main() {
	char *str = "[P1]Hello user space! :)\r\n";

	print(str);
	print(constant_str);
	puthex(tmp);

	while(1) {
		print("[P1]I'm P1 process\r\n");
	}

	exit(0);
}

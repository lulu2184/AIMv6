obj = prog1.o

prog1.elf: $(obj) prog1.ld
	arm-unknown-eabi-ld -T prog1.ld -o prog1.elf $(obj)

.c.o:
	arm-unknown-eabi-gcc -o $@ -c $<

clean:
	rm *.o
	rm *.elf

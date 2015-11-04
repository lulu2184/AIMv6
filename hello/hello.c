void hello(void) {
    void (*uart_spin_puts)(const char *) = (void *)0x1FF0000C;

    uart_spin_puts("Hello 2nd partition!\r\n");
    while (1);
    return;
}


/**
 * Setup kernel pages.
 * Mapping VA <=> PA + KERN_BASE
 **/
static void setup_kernel_pages() {
	for (uint *addr = KERN_BASE; addr < EXTMEM_BASE; addr += PAGE_SIZE) {
		pde_t *pde;
		if ((pde = get_pde(*addr)) == 0) {
			pde_t *pde = setup_page_table(P_PDE(addr));
			 	
		}
	}	
}

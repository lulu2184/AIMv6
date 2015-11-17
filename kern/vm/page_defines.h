#define KERN_BASE 			0x80000000
#define EXTMEM_BASE 		0xE0000000 // in physics mem
#define PYMEM_SIZE			0x20000000
#define PRESERVED_MEM_BASE 	0x1FFF0000 // in physics mem
#define PAGE_SIZE			0x10000 //4K
#define PAGE_SHIFT			12
#define MEM_SECTION_SIZE	0x100000 //1M

/**
 *	diagram for virtual memory structure
 *
 *	+---------------+ \
 *	|				|  \
 *	|				|   \
 *	|				|	 \  2G user space
 *	|				|	 /
 *	|				|   /
 *	|				|  /	
 *	+---------------+ /
 *	|				|  \
 *	|				|	\ 
 *	+---------------+	 \ 2G kernel space
 *	|	PRESERVED 	|    /
 *	+---------------+	/
 *	|	EXT_MEM		|  /	
 *	+---------------+ /
**/

typedef struct pme_s {
	BITS(type, 2);
	BITS(B, 1);
	BITS(C, 1);
	BITS(XN, 1);
	BITS(domain, 4);
	BITS(zero1, 1);
	BITS(AP_L, 2);
	BITS(TEX, 3);
	BITS(AP_H, 1);
	BITS(S, 1);
	BITS(ng, 1);
	BITS(zero2, 1);
	BITS(NS, 1);
	BITS(base, 12);	
} pme_t;

typedef struct pde_s {
	BITS(type, 2);
	BITS(SBZ, 1);
	BITS(NS, 1);
	BITS(SBZ, 1);
	BITS(domain, 4);
	BITS(empty, 1);
	BITS(pte_base, 22);
} pde_t;

typedef struct pte_s {
	BITS(type, 2);
	BITS(memattr, 2);
	BITS(AP, 2);
	BITS(TEX, 3);
	BITS(APX, 1);
	BITS(S, 1);
	BITS(ng, 1);
	BITS(base, 20);
} pte_t;

// In page_init.c
void fill_pme_common(pme_t *pme);
void init_mapping();
void devices_mapping();
void init_first_page_table();


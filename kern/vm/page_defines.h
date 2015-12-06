
#ifndef _PAGE_DEFINES_H_
#define _PAGE_DEFINES_H_

#define KERN_BASE 			0x80000000
#define EXTMEM_BASE 		0xE0000000 // in physics mem
#define PYMEM_SIZE			0x20000000
#define PRESERVED_MEM_BASE 	0x1F000000 // in physics mem
#define PAGE_SIZE			0x10000 //4K
#define PAGE_SHIFT			16
#define MEM_SECTION_SIZE	0x100000 //1M
#define MEM_SECTION_SHIFT	20
#define PY_SAFE_BEGIN		0x2000000
#define PY_SAFE_END			PRESERVED_MEM_BASE
#define STACK_START			0xF00000

#define NULL 0

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

/**
 * struct for section entry in L1 page table
 **/  
typedef struct pme_s {
	unsigned type : 2;
	unsigned B : 1;
	unsigned C : 1;
	unsigned XN : 1;
	unsigned domain : 4;
	unsigned zero1 : 1;
	unsigned AP_L : 2;
	unsigned TEX : 3;
	unsigned AP_H : 1;
	unsigned S : 1;
	unsigned ng : 1;
	unsigned zero2 : 1;
	unsigned NS : 1;
	unsigned base : 12;	
} pme_t;

typedef struct pde_s {
	unsigned type : 2;
	unsigned SBZ1 : 1;
	unsigned NS : 1;
	unsigned SBZ2 : 1;
	unsigned domain : 4;
	unsigned empty : 1;
	unsigned pte_base : 22;
} pde_t;

typedef struct pte_s {
	unsigned type : 2;
	unsigned memattr : 2;
	unsigned AP : 2;
	unsigned TEX : 3;
	unsigned APX : 1;
	unsigned S : 1;
	unsigned ng : 1;
	unsigned base : 20;
} pte_t;

// In page_init.c
void fill_pme_common(pme_t *pme);
void init_mapping();
void devices_mapping();
void remove_low_mapping();
void init_first_page_table();

// In page_manager.c
void alloc_init();
char* alloc_pages(int pnum);
void free_pages(char *addr, unsigned size);
unsigned get_kmem_first_size();

#endif


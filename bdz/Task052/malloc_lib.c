#include <stdio.h> 
#include <unistd.h> 
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include "safe_printf_lib.h"

//используем safe_printf т.к. обычный printf для выделения памяти под буфер использует malloc

#ifdef DEBUG
	#define info(... ) safe_printf(__VA_ARGS__)
#else
	#define info(... )
#endif


int has_initialized = 0;	//флаг инициализации malloc_init
void* managed_memory_start; //указатель на начало выделенной памяти
void* last_valid_address;	//указатель на последний доступный адрес

struct mem_control_block {
	int is_available;
	int size;
};

void malloc_init()
{
	last_valid_address = sbrk(0);	// текущий адрес программы

	managed_memory_start = last_valid_address;

	has_initialized = 1;
}


void* malloc(long numbytes) {
	void* curr_location;
	struct mem_control_block* current_location_mcb;
	void* memory_location;

	if (!has_initalized) {
		malloc_init();
	}

	long total_size = numbytes + sizeof(struct mem_control_block);
	memory_location = sbrk(total_size);

	assert(memory_location != (void*)-1);

	current_location_mcb = (struct mem_control_block*)memory_location;

	current_location_mcb->is_available = 0;
	current_location_mcb->size = total_size - sizeof(struct mem_control_block);

	last_valid_address = sbrk(0);

	return (void*)(current_location_mcb + 1);
}

void free(void* firstbyte) {
	struct mem_control_block* mcb;
	mcb = (struct mem_control_block*)firstbyte - 1;
	mcb->is_available = 1;
}


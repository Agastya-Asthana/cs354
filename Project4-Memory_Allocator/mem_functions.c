#include "mem.h"                      
extern BLOCK_HEADER* first_header;

int isFree(BLOCK_HEADER *header);
int getSize(BLOCK_HEADER *header);

// return a pointer to the payload
// if a large enough free block isn't available, return NULL
void* Mem_Alloc(int size){
    BLOCK_HEADER *currentHeader = first_header;
    int blockSize = 8+size;
    while (blockSize%16) blockSize++;
    // find a free block that's big enough
    while (!isFree(currentHeader) || getSize(currentHeader) < blockSize){
        //checking if the current pointer is at the end
        //returning NULL since we can't find a block
        if (currentHeader->size_alloc == 1) return NULL;
        //amount to increment the pointer by
        int amountToMove = currentHeader->size_alloc-1;
        //casting moving and then casting back
        currentHeader = (BLOCK_HEADER*)((unsigned long)currentHeader + (unsigned long)amountToMove);
    }
    // allocate the block
    if (currentHeader->size_alloc == blockSize){
        currentHeader->size_alloc  = currentHeader->size_alloc | 1;
        currentHeader->payload = size;
        return ((void*)currentHeader+8);
    } else{ //a split needs to occur
        //capture the old full size of this block
        BLOCK_HEADER *placeholder = currentHeader;
        int oldSize = currentHeader->size_alloc;
        currentHeader->size_alloc = blockSize | 1;
        currentHeader->payload = size;

        currentHeader = (BLOCK_HEADER*)((unsigned long)currentHeader + (unsigned long)blockSize);

        currentHeader->size_alloc = oldSize-blockSize;
        currentHeader->payload = 0;

        return ((void *)placeholder + 8);

    }
}


// return 0 on success
// return -1 if the input ptr was invalid
int Mem_Free(void *ptr){
    ptr = ptr - 8;
    //check pointer validity
    // traverse the list and check all pointers to find the correct block
    // if you reach the end of the list without finding it return -1
    BLOCK_HEADER *block = (BLOCK_HEADER*)ptr;
    if ((unsigned long)block % 16 != 8) return -1;
    if (isFree(block)) return -1;
    if (block->size_alloc == 1) return -1;
    
    // free the block
    block->payload = 0;
    block->size_alloc -= 1;
    // coalesce adjacent free blocks
    BLOCK_HEADER *nextBlock = (BLOCK_HEADER*)((unsigned long)block + block->size_alloc);
    if (nextBlock->size_alloc == 1) return 0;
    if (isFree(nextBlock)){
        int bigSize = block->size_alloc + nextBlock->size_alloc;
        block->size_alloc = bigSize;
        block->payload = bigSize-8;
    }
    //check and clean block before
    BLOCK_HEADER *currentHeader = first_header;
    if (currentHeader == block) return 0;
    nextBlock = (BLOCK_HEADER*)((unsigned long)currentHeader + getSize(currentHeader));

    while (nextBlock != block){
        currentHeader = nextBlock;
        nextBlock = (BLOCK_HEADER*)((unsigned long)currentHeader + getSize(currentHeader));
    }
    if (isFree(currentHeader)){
        int bigSize = currentHeader->size_alloc + nextBlock->size_alloc;
        currentHeader->size_alloc = bigSize;
        currentHeader->payload = bigSize - 8;
    }

    return 0;
}

int isFree(BLOCK_HEADER *header){
    return (header->size_alloc % 2 == 0 ) ? 1 : 0;
}

int getSize(BLOCK_HEADER *header) {
    return (header->size_alloc % 2 == 0) ? header->size_alloc : header->size_alloc-1;
}


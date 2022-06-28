#include <stdio.h>
// THE CACHE
struct LINE{
    char valid;
    int tag;
    char data[32];
};
struct SET{
    struct LINE line[1];
};
struct CACHE {
    struct SET set[8];
} cache;
// GLOBALDATA
// increment these in your function
unsigned hit_count  = 0;
unsigned miss_count = 0;
unsigned read_data_count = 0;
// SYSTEM BUS 
// call Read_Data_From_Ram to update this
char system_bus[32];
// READ DATA FROM RAM
// this function copies 32 character from the text file to
// the system_bus array aligned with the system bus
// (we will not test this with input larger than the text file)
void Read_Data_From_Ram(unsigned address) {
    address >>= 5; address <<= 5; // get align the data
    read_data_count++;
    FILE *file;
    file = fopen("alice_in_wonderland.txt", "r");
    fseek(file, address, SEEK_SET);
    for (int i = 0; i<32; i++) system_bus[i] = fgetc(file);
    return;
}
// COMPLETE THE FOLLOWING FUNCTION 
//
// this code should check to see if the data in the cache is valid and the tag matches
// if so it should return the char matching the address and increment the hit count
//
// if not it should read the data from the system bus copy it into the cache and 
// increment the miss count and return the char matching the address
// 
char Read_Data_From_Cache(unsigned address){
    short unsigned int hit = 0;

    int byte_offset = address & 31; // should help me access each cell in data array 5 bits
    int set_number = address & 224; // 3 bits to tell me set number
    int tag_number = address - byte_offset - tag_number;
    
    struct SET current_set = cache.set[set_number];
    if(current_set.line[0].valid && current_set.line[0].tag == tag_number){
        hit = 1;
        hit_count++;
	//printf("1-matched tag\n");
        return current_set.line[0].data[byte_offset];
    }
    
    if(!hit){
        miss_count++;
       // read_data_count++;

        Read_Data_From_Ram(address);
 
	current_set.line[0].valid = 1;
        for(int i = 0; i < 32; i++){
	    //printf("%d", i);
            current_set.line[0].data[i] = system_bus[i];
            if(system_bus[i] == '\0') break;
        }
	return current_set.line[0].data[byte_offset];
        //Read_Data_From_Cache(address);
    }
}
int main() {
    // INITIALIZE CACHE
    for (int i = 0; i<8; i++) cache.set[i].line[0].valid = 0;
    
    // READ SOME DATA
    char c;
    c = Read_Data_From_Cache(0); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    printf("1\n");
    c = Read_Data_From_Cache(1); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    printf("2\n");
    c = Read_Data_From_Cache(2); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    printf("3\n");
    c = Read_Data_From_Cache(3); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    c = Read_Data_From_Cache(4); printf("data = %c : hit count = %-3u : miss count = %-3u : read data count = %-3u\n", c, hit_count, miss_count,read_data_count );
    // WRITE A LOT MORE TESTS
    return 0;
}

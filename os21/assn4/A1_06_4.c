/* 
 * Group Number : 06
 * Date: 21/08/2025
 *
 * Team details :
 * Name : Swapnaneel Ray(Team Leader), Swarnendu Banerjee, Rahul Pandey
 * Roll : 002311001015, 002311001016, 002311001021
 *
 * Assignment No: 4
 * Assignment Details: The objective of this programming assignment is to use mmap() call and observe page-fault using the ‘sar’ command.
 *
 * Input Description: None
 * Output Description: The program prints the random offset, random value written and the value read from the same offset in each iteration, and the sar command prints CPU stats.
 *
 * Compilation command: gcc A1_06_4.c -o out
 * Execution sequence: 
 * - To run program: ./out
 * - To check stats: sar -B 1
 *
 *
 * Output:
 *
 * - Output from program
 *
 * Creating A1_06_4_8GB.dat with size 8GB using fallocate...
 * File created successfully. Size: 8589934592 bytes (8.00 GB)
 * File successfully mapped into virtual address space at: 0x7f38b562d000
 * Offset value: 0x00000001EF0289AA
 * Writing value: 0x5A
 * Value read from file: 0x5A
 * Verification successful: values match!
 * 
 * Offset value: 0x000000010899E965
 * Writing value: 0x5C
 * Value read from file: 0x5C
 * Verification successful: values match!
 * 
 * Offset value: 0x0000000095E24A34
 * Writing value: 0x99
 * Value read from file: 0x99
 * Verification successful: values match!
 * 
 * Offset value: 0x0000000117D790AD
 * Writing value: 0xA9
 * Value read from file: 0xA9
 * Verification successful: values match!
 * 
 * Offset value: 0x00000001F8907D72
 * Writing value: 0x6F
 * Value read from file: 0x6F
 * Verification successful: values match!
 * 
 * Offset value: 0x00000000324550F0
 * Writing value: 0x17
 * Value read from file: 0x17
 * Verification successful: values match!
 * 
 * Offset value: 0x000000003CB738FC
 * Writing value: 0xD9
 * Value read from file: 0xD9
 * Verification successful: values match!  
 *
 * - Stats from sar command
 *
 * 09:38:52     pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
 * 09:38:53         0.00      0.00     18.00      0.00    121.00      0.00      0.00      0.00      0.00
 * 09:38:54         0.00    348.00      6.00      0.00      8.00      0.00      0.00      0.00      0.00
 * 09:38:55         0.00      0.00   1279.00     66.00    799.00      0.00      0.00      0.00      0.00
 * 09:38:56         0.00      0.00   1732.00    858.00    775.00      0.00      0.00      0.00      0.00
 * 09:38:57         0.00      0.00   1623.76    807.92    599.01      0.00      0.00      0.00      0.00
 * 09:38:58         0.00      0.00   1633.00    808.00    491.00      0.00      0.00      0.00      0.00
 * 09:38:59         0.00   5584.00   1749.00    869.00    389.00      0.00      0.00      0.00      0.00
 * 09:39:00         0.00   1144.00   1718.00    852.00    344.00      0.00      0.00      0.00      0.00
 * 09:39:01         0.00   3024.00   1767.00    878.00    272.00      0.00      0.00      0.00      0.00
 * ^C

 * Average:         0.00   1120.98   1281.02    571.25    422.20      0.00      0.00      0.00      0.00
*/

#define _GNU_SOURCE  

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/mman.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <string.h> 
#include <errno.h> 
#include <time.h> 
#include <stdint.h>

#define FILE_SIZE (8LL * 1024 * 1024 * 1024) 
#define FILENAME "A1_06_4_8GB.dat" 

int main() { 
	int fd; 
	char *mapped_memory; 
	off_t offset; 
	unsigned char write_value, read_value; 
	struct stat file_stat;

	// Seed random number generator 
	srand(time(NULL)); 
	printf("Creating %s with size 8GB using fallocate...\n", FILENAME); 
	
	// Create the big file 
	fd = open(FILENAME, O_CREAT | O_RDWR, 0666);
	if (fd == -1) { 
		perror("Error opening file"); 
		return 1; 
	} 
	
	// Use fallocate to allocate 8GB to file 
	if (fallocate(fd, 0, 0, FILE_SIZE) == -1) { 
		perror("Error with fallocate"); 
		// Try using ftruncate as fallback 
		if (ftruncate(fd, FILE_SIZE) == -1) { 
			perror("Error with ftruncate fallback"); 
			close(fd); 
			return 1; 
		} 
	}
	
	// Get file statistics 
	if (fstat(fd, &file_stat) == -1) { 
		perror("Error getting file stats"); 
		close(fd); 
		return 1; 
	} 
	printf("File created successfully. Size: %lld bytes (%.2f GB)\n", (long long)file_stat.st_size, 
			(double)file_stat.st_size / (1024*1024*1024)); 
	
	// Map the file into virtual memory using mmap 
	mapped_memory = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
	if (mapped_memory == MAP_FAILED) { 
		perror("Error mapping file"); 
		close(fd); 
		return 1; 
	} 
	printf("File successfully mapped into virtual address space at: %p\n", mapped_memory); 
	
	// Infinite loop for random read/write operations 
	while (1) { 
		// Generate random offset and byte to write
		offset = (off_t)(((double)rand() / RAND_MAX) * (FILE_SIZE - 1)); 
		printf("Offset value: 0x%016llX\n", 
				 (unsigned long long)offset); 
		
		write_value = (unsigned char)(rand() % 256); 
		printf("Writing value: 0x%02X \n", 
				write_value); 
		
		// Write the random byte at the random offset 
		mapped_memory[offset] = write_value; 
		
		// Read the byte from the same offset 
		read_value = mapped_memory[offset]; 
		printf("Value read from file: 0x%02X \n", 
				read_value); 
		
		// Verify that written and read values match 
		if (write_value != read_value) { 
			fprintf(stderr, "ERROR: Verification failed!\n"); 
			fprintf(stderr, "Written value: 0x%02X\n", write_value); 
			fprintf(stderr, "Read value: 0x%02X\n", read_value); 
			fprintf(stderr, "Offset: 0x%016llX\n", (unsigned long long)offset); 
			// Cleanup before exit 
			munmap(mapped_memory, FILE_SIZE); 
			close(fd); 
			return 1; 
		} 
		printf("Verification successful: values match!\n\n"); 
		
		// Small delay to make output readable and generate observable page faults 
		usleep(1000);
	} 
	close(fd); 
	return 0; 
}


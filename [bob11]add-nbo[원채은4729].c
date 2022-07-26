#include <stdint.h> // for uint16_t
#include <stdio.h> // for printf
#include <netinet/in.h> // for htonl, ntohl



int main(int argc, char** argv) {
	int state, state2;
		
	FILE* fp = fopen(argv[1], "rb+");
	FILE* fp2 = fopen(argv[2], "rb+");
		
	if(fp == NULL||fp2 == NULL){
		printf("File open error");
		return 1;
	}
	
	uint32_t num1;
	uint32_t* num1_p = &num1;
	uint32_t num2;
	uint32_t* num2_p = &num2;
	
	fread(num1_p, sizeof(uint32_t), 1, fp);
	fread(num2_p, sizeof(uint32_t), 1, fp2);
		
	num1 = ntohl(num1);
	num2 = ntohl(num2);
		
	uint32_t add = num1 + num2;
		
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", (int)num1, num1, (int)num2, num2, (int)add, add);
	state = fclose(fp);
	state2 = fclose(fp2);
	if(state != 0 || state2 != 0){
		printf("File close error");
		return 1;
	}
	return 0;
}

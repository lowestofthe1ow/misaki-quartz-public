#include <stdio.h>

int toBin (decimal_num) {
	int binary_num = 0, i = 1, remainder;
    while (decimal_num != 0) {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    return binary_num;
}

int main() {
    for (int value = 0; value <= 16; value++) {
    	printf("%d\t%d\t%o\t%X\n",value,toBin(value),value,value);
	}
     
    return 0;
}

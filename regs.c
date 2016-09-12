#include<stdio.h>
struct reg_set{
  char register_name[6];
  char *reg_type;
};
typedef struct reg_set r;
r reg_set[20]={{"al","reg8"},{"ah","reg8"},{"ax","reg16"},{"eax","reg32"},{"bh","reg8"},{"bl","reg8"},{"bx","reg16"},{"ebx","reg32"},{"cl","reg8"},{"ch","reg8"},{"cx","reg16"},{"ecx","reg32"},{"dl","reg8"},{"dh","reg8"},{"dx","reg16"},{"edx","reg32"},{"esi","reg32"},{"edi","reg32"},{"esp","reg32"},{"ebp","reg32"}};
main(){}
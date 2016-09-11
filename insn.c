#include<stdio.h>
struct instruction_set{
      char *instr_name;
      char *op1;
      char *op2;
      char *op_en;
      char *opcode;
};
typedef struct instruction_set instruction_set;
instruction_set insn[6]={{"add","al","imm8","I","04 ib"},{"add","ax","imm16","I","05 iw"},{"add","eax","imm32","I","05 id"},{"add","r/m16","r16","MR","01 /r"},{"add","r/m32","r32","MR","01 /r"},{"add","r/m16","imm8","MI","83 /0 ib"}};
main(){
        }

f = open("insn.dat",'r')
f2 = open("insn.h",'w')
l = f.readlines()
l1 = map(lambda x:x.strip(),l)
tokens =map(lambda x:x.split('\t'),l1)
tokens3 = map(lambda x: map(lambda y: (y.replace('[',']')).strip(']'),x),tokens)
f2.write("struct instruction_set{\n")
f2.write("      char *instr_name;\n");
f2.write("      char *op1;\n")
f2.write("      char *op2;\n")
f2.write("      char *op_en;\n")
f2.write("      char *opcode;\n")
f2.write("};\n")
f2.write("typedef struct instruction_set instruction_set;\n")
f2.write("#define MAX_INSTRUCTION_COUNT %d\n" %len(tokens3))
f2.write("instruction_set insn[MAX_INSTRUCTION_COUNT]={")


for i in range(0,len(tokens3)-1):
    op=tokens3[i][1].split(',')
    opEncodeVal=(tokens3[i][2].strip()).split(':')
    #print opEncodeVal
    f2.write("{\""+tokens3[i][0]+"\",\""+op[0]+"\",\""+op[1]+"\",\""+opEncodeVal[0]+"\",\""+opEncodeVal[1].strip()+"\"},")



op=tokens3[len(tokens3)-1][1].split(',')
opEncodeVal=tokens3[len(tokens3)-1][2].split(':')
f2.write("{\""+tokens3[len(tokens3)-1][0]+"\",\""+op[0]+"\",\""+op[1]+"\",\""+opEncodeVal[0]+"\",\""+opEncodeVal[1].strip()+"\"}};\n")



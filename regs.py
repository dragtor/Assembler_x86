from sys import argv
#filename = "regs.c"
file = open('regs.dat','r')
f =  file.readlines()
ou = open('regs.c','w')
ou.write("#include<stdio.h>\n")
ou.write("enum type{reg8,reg16,reg32};\n")
ou.write("struct reg_set{\n")
ou.write("  char register_name[6];\n")
ou.write("  enum type reg_type;\n")
ou.write("};\n")
ou.write("typedef struct reg_set r;\n")

ou.write("r reg_set[%d]" %len(f))
for line in range(0,len(f)-1):
    ou.write("\""+(f[line]).rstrip()+"\"")
    ou.write(",")
ou.write("\""+f[len(f)-1].rstrip()+"\"")
ou.write("};");


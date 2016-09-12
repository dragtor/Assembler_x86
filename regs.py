file = open('regs.dat','r')
f =  file.readlines()
ou = open('regs.h','w')
ou.write("struct reg_set{\n")
ou.write("  char register_name[6];\n")
ou.write("  char *reg_type;\n")
ou.write("};\n")
ou.write("typedef struct reg_set r;\n")
ou.write("#define MAX_REGISTER_COUNT %d\n" %len(f))
a = map(lambda x:x.rstrip(),f)
d = map(lambda x:x.split(),a)
l=d

ou.write("r reg_set[MAX_REGISTER_COUNT]={")
for d in range(0,len(f)-1):
  ou.write("{\""+l[d][0]+"\",\""+l[d][1]+"\"},")
ou.write("{\""+l[len(f)-1][0]+"\",\""+l[len(f)-1][1]+"\"}};\n")


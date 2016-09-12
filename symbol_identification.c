#include<stdio.h>
#include"directives.h"
#include"insn.h"
#include"instruction_tree.h"
#include"instru_opcode_encode_table.h"
#include"regs.h"
#include"mnemonic_tree.h"
#include"symbol.h"

int isRegister(char *reg_name){
  int i;
  for(i=0;i<MAX_REGISTER_COUNT ;i++){
   if(strcmp(reg_name,reg_set[i].register_name)==0)
     return 1;
  }
   return 0;
}

int isDirective(char *directive_name){
  int i;
  for(i=0;i<MAX_DIRECTIVE_COUNT ;i++){
   if(strcmp(directive_name,directive_set[i].directive_name)==0)
     return 1;
  }
   return 0;
}
int isAssemblerKeyword(char *token){
  if(isRegister(token))
    return 1;
  if(isDirective(token))
    return 2;
  if(search_mnemonic(mnemonic_Tree_main,token))
    return 3;
  return -1;
}
main(){
  int i;
  values = initialize_symbol_table();
   for(i=0;i<MAX_INSTRUCTION_COUNT;i++){
       mnemonic_Tree_main = insert_mnemonic(mnemonic_Tree_main,i);
    }
   int x=4;
   char temp[MAXIMUM_SYMBOL_SIZE];
   char *str;

  char reg_name[]="eax";
  char directive_name[]="bss";
  char mnemonic[]="add1";
  char token[]="add";
  int type;
  if(isRegister(reg_name))
    printf("reg\n");
  else
    printf("not reg\n");
  if(isDirective(directive_name))
    printf("directive\n");
  else
    printf("not directive\n");
  if(search_mnemonic(mnemonic_Tree_main,mnemonic))
    printf("mnemonic\n");
  else
    printf("not mnemonic\n");
  traverse_tree(mnemonic_Tree_main);
  switch(type=isAssemblerKeyword(token)){
    case 1: printf("reg\n");
            break;
    case 2: printf("directive\n");
            break;
    case 3: printf("mnemonic\n");
            break;
    default:printf("not any\n");
  }
  printf("%d\n",type);
  if(type==-1){
     if(is_present_in_bucket(values,token)){
           printf("\npresent\n");
     }else{
        printf("not present\n");
       insert_symbolInTable(values,token);
   read_bucket(values);
     }
   

  }
  /*initialize_values(values);
     while(x--){
          scanf("%s",temp);
            str = (char*)malloc(sizeof(char)*strlen(temp));
              strcpy(str,temp);
                insert(values,str);
                  }
        read_bucket(values);
          strcpy(str,"label1");
            if(is_present_in_bucket(values,str))
                  printf("\npresent\n");
              else
                    printf("not present\n");
*/
 // if(type==-1)
   // is_present_in_bucket(
}

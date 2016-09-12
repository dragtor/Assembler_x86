#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"instruction_tree.h"
#include"insn.h"
#include"regs.h"
#include"mnemonic_tree.h"

void generate_instruction_tree(){
  int i;
  char mne[]="mult";
  for(i=0;i<MAX_INSTRUCTION_COUNT;i++){
  mnemonic_Tree_main = insert(mnemonic_Tree_main,i);
 }
 traverse_tree(mnemonic_Tree_main);
 if(search_mnemonic(mnemonic_Tree_main,mne))
   printf("found\n");
 else
   printf("not found\n");
 traverse_tree(mnemonic_Tree_main);

}

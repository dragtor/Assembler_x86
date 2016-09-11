#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"instruction_tree.h"
#include"insn.h"
#include"regs.h"

instru_tree* create_mnemonic(int index){
   instru_tree *temp;
   temp = (instru_tree*)malloc(sizeof(instru_tree));
   temp -> mnemonic = (char*)malloc(sizeof(char)*strlen(insn[index].instr_name));
   strcpy(temp->mnemonic,insn[index].instr_name);
   temp->details =NULL;
   return temp;
}
mnemonic_details* create_mnemonic_details(int index){
  mnemonic_details *temp;
  temp = (mnemonic_details*)malloc(sizeof(mnemonic_details));
  temp -> op1 = (char*)malloc(sizeof(char)*strlen(insn[index].op1));
  temp -> op2 = (char*)malloc(sizeof(char)*strlen(insn[index].op2));
  temp -> op_en = (char*)malloc(sizeof(char)*strlen(insn[index].op_en));
  strcpy(temp-> op1,insn[index].op1);
  strcpy(temp-> op2,insn[index].op2);
  strcpy(temp-> op_en,insn[index].op_en);
  temp->index = index;
  return temp;
}
mnemonic_details* insert_mnemonic_details(mnemonic_details *mnemonice_List,int index){
  if(mnemonice_List==NULL){
    return create_mnemonic_details(index);
  }
  mnemonice_List -> next = insert_mnemonic_details(mnemonice_List->next,index);
  return mnemonice_List;
}
instru_tree* insert(instru_tree *mnemonic_Tree,int index){
   if(mnemonic_Tree == NULL){
     instru_tree *instruction;
     instruction =  create_mnemonic(index);
     instruction->details = insert_mnemonic_details(instruction->details ,index);
     return instruction;
   }
  else if(strcmp(mnemonic_Tree -> mnemonic,insn[index].instr_name)==0){
     mnemonic_Tree -> details = insert_mnemonic_details(mnemonic_Tree -> details ,index);
   }
   else if(strcmp(mnemonic_Tree -> mnemonic,insn[index].instr_name)<0)
     mnemonic_Tree -> left  = insert(mnemonic_Tree -> left ,index);
   else
     mnemonic_Tree -> right = insert(mnemonic_Tree -> right,index);
}
void print_list(mnemonic_details *mnemonic_List){
  if(mnemonic_List== NULL)
    return;
 printf("(%s,%s,%d,%s)\t", mnemonic_List -> op1,mnemonic_List -> op2,mnemonic_List->index,mnemonic_List->op_en);
 print_list(mnemonic_List->next);
}
void traverse_tree(instru_tree *mnemonic_Tree){
   if(mnemonic_Tree==NULL)
     return ;
   traverse_tree(mnemonic_Tree->left);
   printf("%s\t-->",mnemonic_Tree-> mnemonic);
   print_list(mnemonic_Tree ->details);
   printf("\n");
   traverse_tree(mnemonic_Tree->right);
}
main(){
  int i;
  instru_tree *mnemonic_Tree=NULL;
  for(i=0;i<MAX_INSTRUCTION_COUNT;i++){
  mnemonic_Tree = insert(mnemonic_Tree,i);
 }
 // traverse_tree(mnemonic_Tree);

}

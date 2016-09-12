#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXIMUM_SYMBOL_SIZE 256
#define MAXIMUM_BUCKET_SIZE 26

struct symbolList{
  char *symbol_name;
  struct symbolList *next;
};
typedef struct symbolList symbolList;
symbolList **values;


symbolList* create_symbol(char *symbol_name){
  symbolList *temp;
  temp = (symbolList*)malloc(sizeof(symbolList));
  temp -> symbol_name = symbol_name;
  temp -> next = NULL;
  return temp;
}
symbolList* insert_symbol(symbolList *list,char *symbol_name){
  symbolList *temp;
 if(list==NULL)
   return create_symbol(symbol_name);
 if(strcmp(symbol_name,list->symbol_name)< 0){
    temp = create_symbol(symbol_name);
    temp -> next = list;
    return temp;
 }
 list->next = insert_symbol(list->next,symbol_name);
 return list;
}

insert_symbolInTable(symbolList **values,char *symbol_name){
  values[tolower(*symbol_name)-97] = insert_symbol(values[tolower(*symbol_name)-97],symbol_name);
}
void initialize_values(symbolList **address){
  int i;
  for(i=0;i<MAXIMUM_BUCKET_SIZE;i++){
    address[i]=NULL;
  }
}
void print_symbolList(symbolList *list){
   if(list == NULL)
     return;
   printf("%s\t",list-> symbol_name);
   print_symbolList(list->next);
}
void read_bucket(symbolList **values){
  int i;
  for(i=0;i< MAXIMUM_BUCKET_SIZE ;i++){
    print_symbolList(values[i]);
    printf("\n");
  }
}
int search_symbol(symbolList *list,char *symbol_name){
   if(list == NULL)
     return 0;
   if(strcmp(symbol_name,list->symbol_name)<0)
     return 0;
   if(strcmp(symbol_name,list->symbol_name)==0)
     return 1;
   list->next = insert_symbol(list->next,symbol_name);
}
int is_present_in_bucket(symbolList **values,char *symbol_name){
 return search_symbol(values[tolower(*symbol_name)-97],symbol_name);
}

symbolList ** initialize_symbol_table(){
return (symbolList**)malloc(sizeof(symbolList*)*MAXIMUM_BUCKET_SIZE);
}

/*

main(){
  symbolList **values;
  int x=4;
  char temp[MAXIMUM_SYMBOL_SIZE];
  char *str;
  values = (symbolList**)malloc(sizeof(symbolList*)*MAXIMUM_BUCKET_SIZE);
  initialize_values(values);
  while(x--){
  scanf("%s",temp);
  str = (char*)malloc(sizeof(char)*strlen(temp));
  strcpy(str,temp);
  insert(values,str);
  }
  read_bucket(values);
  strcpy(str,"shubham");
  if(is_present_in_bucket(values,temp))
    printf("\npresent\n");
  else
    printf("not present\n");
}*/

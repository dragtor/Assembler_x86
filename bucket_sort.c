#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXIMUM_SYMBOL_SIZE 256
#define MAXIMUM_BUCKET_SIZE 26
struct LinkedList{
  char *symbol_name;
  struct LinkedList *next;
};
typedef struct LinkedList list;
list* create_symbol(char *symbol_name){
  list *temp;
  temp = (list*)malloc(sizeof(list));
  temp -> symbol_name = symbol_name;
  temp -> next = NULL;
  return temp;
}
list* insert_symbol(list *lst,char *symbol_name){
  list *temp;
 if(lst==NULL)
   return create_symbol(symbol_name);
 if(strcmp(symbol_name,lst->symbol_name)< 0){
    temp = create_symbol(symbol_name);
    temp -> next = lst;
    return temp;
 }
 lst->next = insert_symbol(lst->next,symbol_name);
 return lst;
}

insert(list **values,char *symbol_name){
  values[tolower(*symbol_name)-97] = insert_symbol(values[tolower(*symbol_name)-97],symbol_name);
}
void initialize_values(list **address){
  int i;
  for(i=0;i<MAXIMUM_BUCKET_SIZE;i++){
    address[i]=NULL;
  }
}
void print_list(list *lst){
   if(lst == NULL)
     return;
   printf("%s\t",lst-> symbol_name);
   print_list(lst->next);
}
void read_bucket(list **values){
  int i;
  for(i=0;i< MAXIMUM_BUCKET_SIZE ;i++){
    print_list(values[i]);
    printf("\n");
  }
}
int search_symbol(list *lst,char *symbol_name){
   if(lst == NULL)
     return 0;
   if(strcmp(symbol_name,lst->symbol_name)<0)
     return 0;
   if(strcmp(symbol_name,lst->symbol_name)==0)
     return 1;
   lst->next = insert_symbol(lst->next,symbol_name);
}
int is_present_in_bucket(list **values,char *symbol_name){
 return search_symbol(values[tolower(*symbol_name)-97],symbol_name);
}
main(){
  list **values;
  int x=4;
  char temp[MAXIMUM_SYMBOL_SIZE];
  char *str;
  values = (list**)malloc(sizeof(list*)*MAXIMUM_BUCKET_SIZE);
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
}

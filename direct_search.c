#include <stdio.h>
#define Table_size 10

int hash_function(int key){
    return key % Table_size ;
}
void insert_hash_table(int hash_table[],int key){
    int index = hash_function(key);
    while(hash_table[index]!=-1){
        index = (index +1)%Table_size;
    }
    hash_table[index] = key;
}
int Direct_Search(int hash_table[],int key){
    int index = hash_function(key);
    while (hash_table[index]!=-1)
    {
        if(hash_table[index]==key){
        return index;
        }
    index = (index+1)%Table_size;
    }
    return -1;

    
}
int main(){
    int hash_table[Table_size];
    for (int i = 0; i < Table_size; i++)
    {
        hash_table[i] = -1;
    }
    insert_hash_table(hash_table,12);
    insert_hash_table(hash_table,42);
    insert_hash_table(hash_table,22);
    insert_hash_table(hash_table,34);
    insert_hash_table(hash_table,45);
    insert_hash_table(hash_table,65);
    insert_hash_table(hash_table,66);
    insert_hash_table(hash_table,17);
    insert_hash_table(hash_table,19);
    printf("%d",Direct_Search(hash_table,42));
    return 0;
    
}
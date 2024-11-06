#include "sort.h"


void sort(PIECE *periodic_table,int n){
    PIECE temp;

     for (int i = 0; i < n - 1; i++) {
        
        int smallest= i;

        
        for (int j = i + 1; j < n; j++) {
            if (periodic_table[j].atomic < periodic_table[smallest].atomic) {
                smallest = j;  
            }
        }

        
        if (smallest != i) {
            temp = periodic_table[i];
            periodic_table[i] = periodic_table[smallest];
            periodic_table[smallest] = temp;
        }
    }
}
  

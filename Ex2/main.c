#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};  
    
    fp = fopen("a.bin", "wb");
    
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    
    fclose(fp);
    
    fp = fopen("a.bin", "rb");
    
    int a_read[3];
    fread(a_read, sizeof(int), 3, fp);
    
    char b_read[4]; 
    fread(b_read, sizeof(char), 3, fp);
    b_read[3] = '\0'; 
    
   
    float c_read[3];
    fread(c_read, sizeof(float), 3, fp);
    
    for (int i = 0; i < 3; i++) {
        printf("%d ", a_read[i]);
    }
    printf("\n");
    
    printf("%s\n", b_read);
    
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", c_read[i]);
    }
  
    fclose(fp);
    
    return 0;
}

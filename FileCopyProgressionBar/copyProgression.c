#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define buffer_s 1024


void progressBar(float progress) {
    int barSize = 20; 
    int pos = (int)(progress * barSize); 
    int midPoint = barSize / 2; 

    printf("[");

    
    for(int i = 0; i < midPoint - 2; i++) { 
        if(i < pos) printf("#");
        else printf("-");
    }
    printf(" %.1f%% ", progress * 100);
    for(int i = midPoint + 3; i < barSize; i++) { 
        if(i < pos) printf("#");
        else printf("-");
    }
    printf("]\r");
    fflush(stdout);
}


int main(int argc,char** argv) {
if(argc != 3){
  printf("Usage: ./Copier.exe src_file dst_file\n");
  return 1;
}
FILE *src, *dst;
printf("[*]Copying %s to %s\n", argv[1], argv[2]);

src = fopen(argv[1], "rb");
if(src == NULL){
  perror("[-]Error opening source file.");
  return 1;
}
dst = fopen(argv[2], "wb");
if(dst == NULL){
  perror("[-]Error opening destination file.");
  fclose(dst);
  return 1;
}

fseek(src, 0, SEEK_END);
long srcFileSize = ftell(src);
fseek(src, 0, SEEK_SET);

char *buffer = (char*)malloc(buffer_s);
size_t read;
long filePos = 0;
float progress = 0;

  
while(read = fread(buffer, 1, buffer_s, src)){
    fwrite(buffer, 1, read, dst);
    filePos += read;
    progress += (float)read/srcFileSize;
    progressBar(progress);
  
}


  fclose(src);
  fclose(dst);
  return 0;
}
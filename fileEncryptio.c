// NAMES : Connor Lirette, Cade Farragut, Abdulla Asad

// We first found the length of the file in bytes using fseek() and ftell(). Then we allocated space for a buffer to copy the file
// over into using malloc(). Next, we we used fread() to copy the file into the buffer, byte by byte. Lastly, we itterated over each
// byte of the file, XORing them with decimal 157. 

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main (int argc, char** argv){
    char * filepath;
    char* buff;
    long size;

    //Check argc for provided file
    if (argc != 2){
        printf("[*]No outfile provided... Setting default output\n");
        char* temp = "./tempOut";
        filepath = temp;
    }
    else{
        filepath = argv[1]; //Grab filepath from command line
    }
    FILE * dst;
    //Try to grab a handle to the file with write permissions
    //if the result of fopen is NULL then fopen failed
    if((dst = fopen(filepath,"r")) == NULL){
        printf("[!]ERROR: unable to open file %s for reading\n",filepath);
        printf("[*]Reason for error: %s", strerror(errno));
        return -1;
    }
    
    
	fseek(dst, 0, SEEK_END); // start at the beginning with no offset and go to the end

	size = ftell(dst); // grab the size of the file in bytes

    rewind(dst); // point back to the beginning

    buff = (char *)malloc(size * sizeof(char)); // allocate the space needed to copy the file to a buffer

    fread(buff, size, 1, dst); // copy the file byte by byte to buff[]

    fclose(dst); // close the file, no longer need it

    for ( int i = 0 ; i < size ; i++ ) { 
      buff[i] = buff[i]^157;  // XOR each byte with decimal 157
   } 
 
    printf("%s",buff); // prints the contents of the file after XORing each byte with decimal 157

    
    printf("The size of the file in bytes is: %lu\n", size);
    return 0; // password is M0mm@sL1LBoo_dan7

}

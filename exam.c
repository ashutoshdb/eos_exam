// Open the file /usr/share/dictionary.txt in
// process P1 and send the strings starting with letter 'm' to
// process P2 using share memory. In proce

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include<string.h>



char ch[10];
int smd;
char *data;
int main()
{
    FILE *fd;
    fd = fopen("./usr/share/dictionary.txt", "r"); 
    if(!fd){
        perror("Error \n:");
        exit(EXIT_FAILURE);
    }
    ch[10] = gets(fd);
    while (!EOF)
    {
       if(strstr(ch,"m"))
       break;
       
    }    
    smd = shm_open("/cdacshm", O_RDWR |O_CREAT,S_IRUSR |S_IWUSR); 
    ftruncate(smd,10 *sizeof(char));
    data = (char *)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED, smd,0); 
    data = ch;

    return 0;
}
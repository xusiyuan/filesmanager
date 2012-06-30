#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

#define BUFFER_SIZE 1024

/* 重定向 */ 
int main(int argc,char **argv) 
{ 
	int fd; 
	char buffer[BUFFER_SIZE]; 

	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s outfilename\n\a",argv[0]); 
		exit(1); 
	} 

	/* 打开指定文件 */
	if((fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR))==-1) 
	{ 
		fprintf(stderr,"Open %s Error:%s\n\a",argv[1],strerror(errno)); 
		exit(1); 
	} 

	/* 复制文件描述符fd至STDOUT_FILENO,同时关闭STDOUT_FILENO文件描述符 */
	if(dup2(fd,STDOUT_FILENO)==-1) 
	{ 
		fprintf(stderr,"Redirect Standard Out Error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	fprintf(stderr,"Now,please input string"); 
	fprintf(stderr,"(To quit use CTRL+D)\n"); 

	while(1) 
	{ 
		fgets(buffer,BUFFER_SIZE,stdin); // 读取输入字符串到buffer缓冲区中,大小上限BUFFER_SIZE
		if(feof(stdin)) break;           // 读到结尾,退出 
		write(STDOUT_FILENO,buffer,strlen(buffer));  //从buffer缓冲区写strlen(buffer)字节到STDOUT_FILENO文件(fd文件)
	} 
	exit(0); 
} 

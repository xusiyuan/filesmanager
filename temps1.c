#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* 拷贝文件 */
int main(int argc,char **argv)
{
	int from_fd,to_fd;
	int bytes_read,bytes_write;
	char buffer[BUFFER_SIZE];
	char *ptr;

	if(argc!=3)
	{
		fprintf(stderr,"Usage: %s fromfile tofile\n\a",argv[0]);
		exit(1);
	}

	/* 打开源文件 */
	if((from_fd=open(argv[1],O_RDONLY))==-1)
	{
		fprintf(stderr,"Open %s Error: %s\n",argv[1],strerror(errno));
		exit(1);
	}

	/* 创建目的文件 */
	if((to_fd=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
	{
		fprintf(stderr,"Open %s Error: %s\n",argv[2],strerror(errno));
		exit(1);
	}

	/* 经典拷贝文件代码 */
	while(bytes_read=read(from_fd,buffer,BUFFER_SIZE))  // 从文件from_fd读取BUFFER_SIZE字节到buffer缓冲区,返回BUFFER_SIZE
	{
		if((bytes_read==-1)&&(errno!=EINTR)) break; // 发生致命错误
		else if(bytes_read>0)
		{
			ptr=buffer;
			while(bytes_write=write(to_fd,ptr,bytes_read)) // 从buffer缓冲区写bytes_read字节到文件to_fd,返回实际字节
			{
				if((bytes_write==-1)&&(errno!=EINTR)) break; // 发生致命错误
				else if(bytes_write==bytes_read) break;      // 写完所有读的字节
				else if(bytes_write>0)                       // 只写了一部分,继续写
				{
					ptr+=bytes_write;
					bytes_read-=bytes_write;
				}
			}
			if(bytes_write==-1) break;                           // 写的时候发生致命错误
		}
	}

	close(from_fd);
	close(to_fd);
	exit(0);
}

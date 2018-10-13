/**************************

FileName: Serial_send_rev.cpp
Time: 2018年 10月 09日 星期二 14:38:51 CST
Author: fish
Description:
	1.  不想用rosserial, h文件与CPP文件分开
	2.  	发十六进制
others:
		sleep(1);    //秒
**************************/
#include <iostream>
#include "Serial_send_rev.h" 

int main(int argc, char *argv[])
{

	int  fd;
	// 01 03 03 00 00 1C 44 47
	//01 03 03 80 00 0C 44 63
	//char buff[] = "abc";
	//char buff[] ={0x01,0x03,0x03,0x00,0x00,0x1C,0x44,0x47};
	std::string str; 
	unsigned char buff[] = {0x01,0x03,0x03,0x80,0x00,0x0C,0x44,0x63};

	Serial m("/dev/ttyUSB0",9600,8,'n',1);

	std::cout <<"buff_size = " << sizeof(buff) << std::endl;

	char * a ;
	char a1[] ="abc";
	a = a1;
	std::string str1 = a ;
	std::cout << "str1 = "<<str1<<std::endl;
	//char recv1[8];

	char * p = new char[10];
	printf("sizeof(p) = %lu \n",sizeof(p) );
	delete [] p;

	int i = 3 ;
	while(i--)
	{	
		if(sizeof(buff) == m.write_data(buff,sizeof(buff)) ) 
		{
			printf("count: %i write yes ! \n",i);
		}
		usleep(500*1000); //毫秒
		
		//sleep(1.0); //毫秒
		
		m.read_data(17);
		for(int i=0; i < 17 ; i++) 
		{
			printf("hex recv = %x\n",m.Readbuf[i] );
		}

	}
	//m.close_port();
	return 0;

}




















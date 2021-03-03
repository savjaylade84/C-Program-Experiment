#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<time.h>

int main(void){

	char net_respond[] =  "[Status] => [Accept] => port[5001]";

	int net_socket;
	net_socket = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in net_conn_addr;
	net_conn_addr.sin_family = AF_INET;
	net_conn_addr.sin_port = htons(50001);
	net_conn_addr.sin_addr.s_addr = INADDR_ANY;

	bind(
			net_socket,
			(struct sockaddr*)&net_conn_addr,
			sizeof net_conn_addr
		);

	listen(net_socket,5);
	
	int client_socket = accept(net_socket,NULL,NULL);

	send(client_socket,net_respond,sizeof(net_respond),0);
	
	close(net_socket);
	

	return 0;
}
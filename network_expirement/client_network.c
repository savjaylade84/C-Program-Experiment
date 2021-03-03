#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){

	//instantiation of socket
	int net_socket;
	net_socket = socket(AF_INET,SOCK_STREAM,0);

	// specify network address
	struct sockaddr_in net_socket_addr;

	//specify type of network protocol
	net_socket_addr.sin_family = AF_INET;

	//specify port number to connect
	net_socket_addr.sin_port = htons(50001);

	//specifiy ip address
	net_socket_addr.sin_addr.s_addr = INADDR_ANY;

	int net_conn_status = connect(
	
								  net_socket,
		   	                      (struct sockaddr*)&net_socket_addr,
		                          sizeof(net_socket_addr)

		                          );

	if(net_conn_status == -1)
		perror("[Status] : Connection Failed!");	     

	char server_respond[150];
	recv(net_socket,server_respond,sizeof(server_respond),0);       

	if(strcmp(server_respond,NULL) || strcmp(server_respond,"")) 
		perror("[Status] : No Message Found!");

	//print the succesfull respond
	printf("[Respond] : [Message] => (%s)",server_respond);
	   
	close(net_socket);
	free(server_respond);
	
	return 0;             
	
}
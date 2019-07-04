#include<stdio.h>
#include <errno.h>
#include <winsock.h>
#include <mysql/mysql.h>

int main(int argc,char* argv[])
{
	MYSQL * conn;
	MYSQL_RES * res;
	MYSQL_ROW row;
	
	char *host = "localhost";
    char *user = "root";
    char *password = "";
    char *db = "mysql";
    unsigned int port = 3360;
    char *unix_socket = NULL;
    unsigned long client_flag = 0;
	
	conn = mysql_init(NULL);
	
	if(!conn){
		printf("mysql_init failed!\n");
		return -1;
	}
	
	conn = mysql_real_connect(conn, host, user, password, db, port, unix_socket, client_flag);
	
	if(conn){
		printf("Connection success......\n");
	}else{
		fprintf(stderr, "Connection failed......%d:%s\n", errno, strerror(errno));
	}
	
	if( mysql_query(conn,"select user,host,password from user") ){
		fprintf(stderr, "call mysql_query failed......%d:%s\n",errno, strerror(errno));
	}
	res = mysql_use_result(conn);
	fprintf(stdout, "select host,user,password from user talbe in the mysql database:\n");
	
	while((row = mysql_fetch_row(res))){
		fprintf(stdout, "%s\t%s\t'%s'\n", row[0],row[1],row[2]);
	}
		
	mysql_free_result(res);
	mysql_close(conn);
	printf("hello, this is conn!\n");
	return 0;
}
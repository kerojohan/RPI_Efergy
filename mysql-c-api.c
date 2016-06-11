/* 
See url for more info:
http://www.cyberciti.biz/tips/linux-unix-connect-mysql-c-api-program.html

*/
#include <mysql.h>
#include <stdio.h>

int main(void) {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
  /* Change me */
   char *server = "localhost";
   char *user = "root";
   char *password = "*****";
   char *database = "efergymonitor";
   
   conn = mysql_init(NULL);
   
   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   /* send SQL query */
   if (mysql_query(conn, "show tables")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   res = mysql_use_result(conn);
   
   /* output table name */
   printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);

   /* close connection */
   mysql_free_result(res);
   mysql_close(conn);
  
  return 0;
}

#include <stdio.h>
#include <mysql.h>

/************************************************************************/
/*  Function Name   : main                                              */
/*  Description     :                                                   */
/*  Input(s)        : argc            - The numbers of input value.     */
/*                  : **argv          - The input specific parameters.  */
/*  Output(s)       : NULL                                              */
/*  Returns         : 0                                                 */
/************************************************************************/
int main(int argc, const char *argv[])
{
	MYSQL my_connect;
	MYSQL_RES * result;
	MYSQL_ROW row;
	char * query = "select * from myTab";

	mysql_init(&my_connect);//my_connect = mysql_init(NULL);

	if ((mysql_real_connect(&my_connect, "localhost", "xiaofei", "1", "feiSql", 0, NULL, 0)) != NULL) {
		printf("connect ok!!!\n");
	} else {
		printf("error: mysql fail!!!\n");
		return -1;
	}

	if (mysql_query(&my_connect, query) != 0) {
		printf("fail to query!!!\n");
		return -1;
	} else {
		if ((result = mysql_store_result(&my_connect)) == NULL) {
			printf("fail to store result!!!\n");
			return -1;
		} else {
			while ((row = mysql_fetch_row(result)) != NULL) {
				printf("id is %s\t", row[0]);
				printf("name is %s\t", row[1]);
				printf("sex is %s\t", row[2]);
				printf("score is %s\t\n", row[3]);
			}
		}
	}

	mysql_free_result(result);
	mysql_close(&my_connect);

	return 0;
}

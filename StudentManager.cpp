#include "StudentManager.h"

StudentManager::StudentManager()
{
	con = mysql_init(NULL);

	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");

	if(!mysql_real_connect(con,host,user,pw,database_name,port,NULL,0))
	{
		exit(1);
	}
}

StudentManager::~StudentManager()
{
	mysql_close(con);
}

bool StudentManager::insert_student_1(Student_1& stu_1)
{
	char sql[1024];
	sprintf_s(sql, "insert into students_1 (student_name,password,gender,age,student_no) values('%s', '%s','%s',%d,'%s' )", stu_1.student_name.c_str(), stu_1.password.c_str(), stu_1.gender.c_str(),stu_1.age,stu_1.student_no.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to insert to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool StudentManager::insert_post(Post& stu_2)
{
	char sql[1024];
	sprintf_s(sql, "insert into post (id,title,content) values(%d,'%s', '%s' )", stu_2.id, stu_2.title.c_str(), stu_2.content.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to insert to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool StudentManager::insert_post_1(Post_1& stu_3)
{
	char sql[1024];
	sprintf_s(sql, "insert into activities (title,content,create_time) values('%s', '%s' ,'%s')", stu_3.title_1.c_str(), stu_3.content_1.c_str(),stu_3.time.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to insert to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

bool StudentManager::insert_post_2(Post_2& stu_4)
{
	char sql[1024];
	sprintf_s(sql, "insert into information (title,content) values('%s', '%s' )", stu_4.title_2.c_str(), stu_4.content_2.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to insert to database:Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}

vector<Post> StudentManager::get_students(string condition)
{
	vector<Post> stuList;

	char sql[1024];
	sprintf_s(sql, "SELECT * FROM post %s", condition.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data :Error:%s\n", mysql_error(con));
		return {};
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Post stu_2;
		stu_2.id = atoi(row[0]);
		stu_2.title = row[1];
		stu_2.content = row[2];

		stuList.push_back(stu_2);

	}
	return stuList;
}

vector<Post_1> StudentManager::get_students_1(string condition_1)
{
	vector<Post_1> stuList_1;

	char sql[1024];
	sprintf_s(sql, "SELECT * FROM activities %s", condition_1.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data :Error:%s\n", mysql_error(con));
		return {};
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Post_1 stu_3;
		stu_3.id_1 = atoi(row[0]);
		stu_3.title_1 = row[1];
		stu_3.content_1 = row[2];
		stu_3.time = row[3];

		stuList_1.push_back(stu_3);

	}
	return stuList_1;
}

vector<Post_2> StudentManager::get_students_2(string condition_2)
{
	vector<Post_2> stuList_2;

	char sql[1024];
	sprintf_s(sql, "SELECT * FROM information %s", condition_2.c_str());

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to selete data :Error:%s\n", mysql_error(con));
		return {};
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Post_2 stu_4;
		stu_4.id_2 = atoi(row[0]);
		stu_4.title_2 = row[1];
		stu_4.content_2 = row[2];

		stuList_2.push_back(stu_4);

	}
	return stuList_2;
}
/*bool StudentManager::update_student(Student& stu)
{
	char sql[1024];
	sprintf_s(sql, "UPDATE students SET student_name='%s', class_id='%s'""where student_id = %d", stu.student_name.c_str(), stu.class_id.c_str(), stu.student_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to update data :Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}*/

/*bool StudentManager::delete_student(int student_id)
{
	char sql[1024];
	sprintf_s(sql, "DELETE FROM students WHERE student_id = %d", student_id);

	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to delete data :Error:%s\n", mysql_error(con));
		return false;
	}
	return true;
}*/

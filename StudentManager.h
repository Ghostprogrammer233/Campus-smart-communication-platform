#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;


typedef struct Student_1 {
	string student_name;
	string password;
	string gender;
	int age;
	string student_no;

}Student_1;

typedef struct Post {
	int id;
	string title;
	string content;
}Post;

typedef struct Post_1 {
	int id_1;
	string title_1;
	string content_1;
	string time;
}Post_1;

typedef struct Post_2 {
	int id_2;
	string title_2;
	string content_2;
}Post_2;

class StudentManager
{
	StudentManager();
	~StudentManager();

public:
	static StudentManager* GetInstance()
	{
		static StudentManager StudentManager;
		return &StudentManager;
	}

public:
	bool insert_student_1(Student_1& t);
	bool insert_post(Post& t);
	bool insert_post_1(Post_1& t);
	bool insert_post_2(Post_2& t);

	vector<Post> get_students(string condition = "");
	vector<Post_1> get_students_1(string condition_1 = "");
	vector<Post_2> get_students_2(string condition_2 = "");

	/*public:
	bool update_student(Student& t);
	bool delete_student(int student_id);*/
	
private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "123456";
	const char* database_name = "database1";
	const int port = 3306;
};


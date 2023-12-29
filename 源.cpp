#include"StudentManager.h"

bool Login_verification();
void post();
void check_post();
void publish();
void check_activity();
void upload();
void check_information();

bool Login() 
{
	string student_no_1;
	string password_1;

	cout << "这里是登陆界面" << endl;
	cout << "请输入您的学号:" << endl;
	cin >> student_no_1;
	cout << "请输入您的密码:" << endl;
	cin >> password_1;
	return Login_verification();//登录校验

}

bool Login_verification() {


	return false;
}

void Register()
{
	string student_name;
	string student_no_2;
	string password_2;
	string password_3;
	bool switch_2 = true;
	int age;
	string gender;

	cout << "这里是注册界面" << endl;
	cout << "请输入您的姓名" << endl;
	cin >> student_name;

	cout << "请输入您的性别" << endl;
	cin >> gender;

	cout << "请输入您的学号:" << endl;
	cin >> student_no_2;

	cout << "请输入您的年龄" << endl;
	cin >> age;

	while (switch_2) {
		cout << "请设置您的密码:" << endl;
		cin >> password_2;
		cout << "请重复您的密码：" << endl;
		cin >> password_3;

		if (password_2 != password_3) {
			cout << "您的密码前后不一致，请重新输入：" << endl;
		}
		else {
			switch_2 = false;
		}
	}
	Student_1 stu_1{ student_name, password_2, gender,age,student_no_2};
	StudentManager::GetInstance()->insert_student_1(stu_1);
}


void Communication()
{
	int choice_3;
	bool switch_4 = true;


	while (switch_4) {
		cout << "欢迎进入校园贴吧\n请选择您要进行什么操作:" << endl;
		cout << "1.查看其他人的帖子" << endl;
		cout << "2.发布帖子" << endl;
		cout << "3.退回到上一个界面" << endl;
		cin >> choice_3;

		switch (choice_3) {
		case 1:
			check_post();
			continue;
		case 2:
			post();
			continue;
		case 3:
			switch_4 = false;
		}
	}
}
void post() {
	int id;
	string title;
	string content;
	cout << "欢迎来到发布页面" << endl;
	cout << "请输入您要发布的内容，请先输入标题序号，再输入标题，点击“Enter”以结束发布" << endl;
	cin >> id >> title;
	cout << "请输入您要发布的内容,请输入内容，点击“Enter”以结束发布" << endl;
	cin >> content;
	Post stu_2{ id ,title,content };
	StudentManager::GetInstance()->insert_post(stu_2);

	cout << "发布成功" << endl;
}

void check_post() {

	vector<Post> ret = StudentManager::GetInstance()->get_students();
	for (auto& t : ret) 
	{
		cout << t.id << endl << t.title <<endl<< t.content <<endl;
	}
	cout << "查看成功" << endl;
}


void Activity(){
		int choice_5;
		bool switch_5 = true;

		while (switch_5) {
			cout << "欢迎进入校园活动板块\n请选择您要进行什么操作：" << endl;
			cout << "1.发布校园活动" << endl;
			cout << "2.查看校园活动" << endl;
			cout << "3.退回上一个界面" << endl;
			cin >> choice_5;
			switch (choice_5) {
			case 1:
				publish();
				continue;
			case 2:
				check_activity();//查询活动
				continue;
			case 3:
				switch_5 = false;
				
			}
		}
}
void publish() {
	int id_1;
	string title_1;
	string content_1;
	string time;
	cout << "欢迎来到发布页面" << endl;
	cout << "请先输入标题序号，再输入标题点击“Enter”以结束发布" << endl;
	cin >> id_1 >>title_1;
	cout << "请输入活动内容,点击“Enter”以结束发布" << endl;
	cin >> content_1;
	cout << "请输入活动时间,点击“Enter”以结束发布" << endl;
	cin >> time;
	Post_1 stu_3{ id_1,title_1,content_1,time };
	StudentManager::GetInstance()->insert_post_1(stu_3);

	cout << "发布成功" << endl;
}

void check_activity(){
	vector<Post_1> ret = StudentManager::GetInstance()->get_students_1();
	for (auto& t_1 : ret)
	{
		cout << t_1.id_1 << endl << t_1.title_1 << endl << t_1.content_1 << endl<< t_1.time <<endl;
	}
	cout << "查看成功" << endl;
}

void Learn()
{
	bool switch_6 = true;
	int choice_4;

	while (switch_6) {
		cout << "欢迎进入校园学习板块\n请选择您要进行什么操作：" << endl;
		cout << "1.上传学习资料" << endl;
		cout << "2.查看往年学习资料" << endl;
		cout << "3.退回上一个界面" << endl;
		cin >> choice_4;
		switch (choice_4) {
		case 1:
			upload();
			continue;
		case 2:
			check_information();//查询资料
			continue;
		case 3:
			switch_6 = false;
		}


	}
}
void upload() {
	int id_2;
	string title_2;
	string content_2;
	cout << "欢迎来到发布页面" << endl;
	cout << "请先输入标题序号，再输入标题点击“Enter”以结束发布" << endl;
	cin >> id_2;
	cin >> title_2;
	cout << "请输入资料内容,点击“Enter”以结束发布" << endl;
	cin >> content_2;

	Post_2 stu_4{ id_2,title_2,content_2};
	StudentManager::GetInstance()->insert_post_2(stu_4);

	cout << "发布成功" << endl;

}

void check_information() {
	vector<Post_2> ret = StudentManager::GetInstance()->get_students_2();
	for (auto& t_2 : ret)
	{
		cout << t_2.id_2 << endl << t_2.title_2 << endl << t_2.content_2 << endl;
	}
	cout << "查看成功" << endl;
}

int main() 
{
	char space;
	int choice_1, choice_2;
	bool switch_1 = true,switch_3=true;
	
	string name;

	cout << "欢迎进入“张院智联”校园智慧交流平台\n请点击“t”进入登陆界面\n请输入:" << endl;
	cin >> space;
	if (space == 't') {

		while (switch_1) {
		cout << "欢迎进入登陆界面，如果需要登陆请输入“1”，如果需要注册请输入“2”\n请输入:" << endl;
		cin >> choice_1;
			if (choice_1 == 1) {
				switch_1 = Login();
				continue;
			}
			else if (choice_1 == 2) {
				Register();
				cout << "注册成功" << endl;
				switch_1 = false;
				continue;
			}
			else {
				cout << "请重新输入:" << endl;
			}

		}
	}

	cout << "登录成功" << endl;
	while(switch_3) {
		printf("您好\n您已进入校园智慧交流平台\n请选择您需要进行什么操作:\n");
		cout << "1.校园贴吧" << endl;
		cout << "2.校园学习" << endl;
		cout << "3.校园活动" << endl;
		cout << "4.退出平台" << endl;

		cin >> choice_2;
		switch (choice_2) {
		case 1:
			Communication();
			continue;
		case 2:
			Learn();
			continue;
		case 3:
			Activity();
			continue;
		case 4:
			switch_3 = false;
		}
	}
	return 0;
}
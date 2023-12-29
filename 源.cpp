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

	cout << "�����ǵ�½����" << endl;
	cout << "����������ѧ��:" << endl;
	cin >> student_no_1;
	cout << "��������������:" << endl;
	cin >> password_1;
	return Login_verification();//��¼У��

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

	cout << "������ע�����" << endl;
	cout << "��������������" << endl;
	cin >> student_name;

	cout << "�����������Ա�" << endl;
	cin >> gender;

	cout << "����������ѧ��:" << endl;
	cin >> student_no_2;

	cout << "��������������" << endl;
	cin >> age;

	while (switch_2) {
		cout << "��������������:" << endl;
		cin >> password_2;
		cout << "���ظ��������룺" << endl;
		cin >> password_3;

		if (password_2 != password_3) {
			cout << "��������ǰ��һ�£����������룺" << endl;
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
		cout << "��ӭ����У԰����\n��ѡ����Ҫ����ʲô����:" << endl;
		cout << "1.�鿴�����˵�����" << endl;
		cout << "2.��������" << endl;
		cout << "3.�˻ص���һ������" << endl;
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
	cout << "��ӭ��������ҳ��" << endl;
	cout << "��������Ҫ���������ݣ��������������ţ���������⣬�����Enter���Խ�������" << endl;
	cin >> id >> title;
	cout << "��������Ҫ����������,���������ݣ������Enter���Խ�������" << endl;
	cin >> content;
	Post stu_2{ id ,title,content };
	StudentManager::GetInstance()->insert_post(stu_2);

	cout << "�����ɹ�" << endl;
}

void check_post() {

	vector<Post> ret = StudentManager::GetInstance()->get_students();
	for (auto& t : ret) 
	{
		cout << t.id << endl << t.title <<endl<< t.content <<endl;
	}
	cout << "�鿴�ɹ�" << endl;
}


void Activity(){
		int choice_5;
		bool switch_5 = true;
		cout << "��ӭ����У԰����\n��ѡ����Ҫ����ʲô������" << endl;
		cout << "1.����У԰�" << endl;
		cout << "2.�鿴У԰�" << endl;
		cout << "3.�˻���һ������" << endl;

		while (switch_5) {
			cin >> choice_5;
			switch (choice_5) {
			case 1:
				publish();
				continue;
			case 2:
				check_activity();//��ѯ�
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
	cout << "��ӭ��������ҳ��" << endl;
	cout << "�������������ţ��������������Enter���Խ�������" << endl;
	cin >> id_1 >>title_1;
	cout << "����������,�����Enter���Խ�������" << endl;
	cin >> content_1;
	cout << "������ʱ��,�����Enter���Խ�������" << endl;
	cin >> time;
	Post_1 stu_3{ id_1,title_1,content_1,time };
	StudentManager::GetInstance()->insert_post_1(stu_3);

	cout << "�����ɹ�" << endl;
}

void check_activity(){
	vector<Post_1> ret = StudentManager::GetInstance()->get_students_1();
	for (auto& t_1 : ret)
	{
		cout << t_1.id_1 << endl << t_1.title_1 << endl << t_1.content_1 << endl<< t_1.time <<endl;
	}
	cout << "�鿴�ɹ�" << endl;
}

void Learn()
{
	bool switch_6 = true;
	int choice_4;
	cout << "��ӭ����У԰ѧϰ���\n��ѡ����Ҫ����ʲô������" << endl;
	cout << "1.�ϴ�ѧϰ����" << endl;
	cout << "2.�鿴����ѧϰ����" << endl;
	cout << "3.�˻���һ������" << endl;

	while (switch_6) {
		cin >> choice_4;
		switch (choice_4) {
		case 1:
			upload();
			continue;
		case 2:
			check_information();//��ѯ����
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
	cout << "��ӭ��������ҳ��" << endl;
	cout << "�������������ţ��������������Enter���Խ�������" << endl;
	cin >> title_2;
	cout << "��������������,�����Enter���Խ�������" << endl;
	cin >> content_2;

	Post_2 stu_4{ id_2,title_2,content_2};
	StudentManager::GetInstance()->insert_post_2(stu_4);

	cout << "�����ɹ�" << endl;

}

void check_information() {
	vector<Post_2> ret = StudentManager::GetInstance()->get_students_2();
	for (auto& t_2 : ret)
	{
		cout << t_2.id_2 << endl << t_2.title_2 << endl << t_2.content_2 << endl;
	}
	cout << "�鿴�ɹ�" << endl;
}

int main() 
{
	char space;
	int choice_1, choice_2;
	bool switch_1 = true,switch_3=true;
	
	string name;

	cout << "��ӭ���롰��Ժ������У԰�ǻ۽���ƽ̨\n������t�������½����\n������:" << endl;
	cin >> space;
	if (space == 't') {

		while (switch_1) {
		cout << "��ӭ�����½���棬�����Ҫ��½�����롰1���������Ҫע�������롰2��\n������:" << endl;
		cin >> choice_1;
			if (choice_1 == 1) {
				switch_1 = Login();
				continue;
			}
			else if (choice_1 == 2) {
				Register();
				cout << "ע��ɹ�" << endl;
				switch_1 = false;
				continue;
			}
			else {
				cout << "����������:" << endl;
			}

		}
	}

	cout << "��¼�ɹ�" << endl;
	while(switch_3) {
		printf("����\n���ѽ���У԰�ǻ۽���ƽ̨\n��ѡ������Ҫ����ʲô����:\n");
		cout << "1.У԰����" << endl;
		cout << "2.У԰ѧϰ" << endl;
		cout << "3.У԰�" << endl;
		cout << "4.�˳�ƽ̨" << endl;

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
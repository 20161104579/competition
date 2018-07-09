#include "head.h"

void menu()
{
    cout<<"功能"<<endl;
    cout<<"1.显示全部分数"<<endl;
    cout<<"2.计算分数"<<endl;
    cout<<"2.输入裁判信息"<<endl;
}
void UI()
{
	printf("1.节目信息\n");
	printf("2.评委信息\n");
	printf("0.退出系统\n");
}

string Trim(string& str)
{
	str.erase(0, str.find_first_not_of("\t\r\n"));
	str.erase(str.find_last_not_of("\t\r\n") + 1);
	return str;
}

void Menu()
{
	UI();//加载菜单
	int i, have = 1;
	Load2(J);
	Load1(L);
	printf("选择要进行的功能：");
	while (cin>>i)
	{
		switch (i)
		{
		case 1: menu1(L, J); break;
		case 2: menu2(J); break;
		case 0: have = 0; break;
		}
		if (have == 0)
			break;
		UI();//加载菜单
		printf("选择要进行的功能：");
	}
}
string fileNames = "player.csv";

void entertain::Load1()
{
	string str;
	int i = 1, j = 0, s = 0;
	string scores;
	ifstream file(fileNames, ios::in);
	while (getline(file, str)) {
		istringstream sin(str);
		vector<string>fields;
		string field;
		while (getline(sin, field, ',')) {
			fields.push_back(field);
		}
		L->elem[s].player_name = Trim(fields[0]);
		L->elem[s].sex = Trim(fields[1]);
		L->elem[s].classroom = Trim(fields[2]);
		L->elem[s].phone = Trim(fields[2]);
		L->elem[s].show_name = Trim(fields[2]);
		L->elem[s].category = Trim(fields[2]);
		scores = Trim(fields[2]);
		L->elem[s].score = atof(scores.c_str());
		s++;
	}
	L->last = s;
}
string doubleTranStr(double integer) {
	stringstream ss;
	ss << integer;
	return ss.str();
}
void Copy1(Seqlist* L)
{
	int i;
	string Score;
	ofstream file(fileNames, ios::out);
	if (!file)
	{
		cout << "\t  文件打开失败！" << endl;
	}
	else
	{
		for (i = 0; i < L->last; i++)
		{
			Score = doubleTranStr(L->elem[i].score);
			file << L->elem[i].player_name << "," << L->elem[i].sex << "," << L->elem[i].classroom<<","<< L->elem[i].phone << ","<< L->elem[i].show_name << ","<< L->elem[i].category << "\n";
		}
	}
}


void UI1()
{
	cout<<"1.添加节目信息------------|"<<endl;
	cout<<"2.删除节目信息------------|"<<endl;
	cout<<"3.对总成绩排名------------|"<<endl;
	cout<<"4.成绩查询----------------|"<<endl;
	cout<<"5.修改选手信息------------|"<<endl;
	cout<<"6.显示全部选手信息--------|"<<endl;
	cout<<"\t\t\t|------------7.对选手进行打分----------|"<<endl;
	cout<<"\t\t\t|------------0.退出选手信息系统--------|"<<endl;
}

void menu1(Seqlist* L, Judges* J)
{
	UI1();
	int i, have = 1;
	cout << "选择要进行的功能：";
	while (cin>>i)
	{
		switch (i)
		{
			case 1:Add(L); break;
			case 2:Del(L); break;
			case 3:Sort(L); break;
			case 4:Query1(L); break;
			case 5:Change(L); break;
			case 6:Show1(L); break;
			case 7:Grade(L, J); break;
			case 0:have = 0; break;
		}
		Copy1(L);
		if (have == 0)
			break;
		cout << "选择要进行的功能：" ;
	}
//	copy(L);
}

void Add(Seqlist* L)
{
	cout << "进入选手信息添加系统。" << endl;
	int i = L->last;
	cout << "\t  选手姓名：";
	cin >> L->elem[i].player_name;
	cout << "\t  选手性别：";
	cin >> L->elem[i].sex;
	cout << "\t  所在班级：";
	cin >> L->elem[i].classroom;
	cout << "\t  节目类型：";
	cin >> L->elem[i].category;
	cout << "\t  节目名称：";
	cin >> L->elem[i].show_name;
	cout << "\t  选手电话号：";
	cin >> L->elem[i].phone;
	L->elem[i].score = -1;
	L->last++;
	cout << "\t  选手信息添加成功。"<<endl;
}

int Find2(Seqlist* L)
{
	cout << "\t  选择要查找的方式：";
	cout << "1.名字查找，2.电话号号查找，3.节目名字查找\n";
	int have, i=0;
	string name, names, phones;
	cin >> have;
	switch (have)
	{
		case 1: {
			cout << "\t  输入名字：";
			cin >> name;
			while((i<L->last)&&(!(name==L->elem[i].player_name)))
				i++;
		}
				break;
		case 2: {
			cout << "\t  输入电话：";
			cin >> phones;
			while ((i<L->last) && (!(phones == L->elem[i].phone)))
				i++;
		}
				break;
		case 3: {
			cout << "\t  输入节目名字：";
			cin >> names;
			while ((i<L->last) && (!(names == L->elem[i].show_name)))
				i++;
		}
				break;
	}
	if (i < L->last)
		return i;
	else
		return -1;
}

void Del(Seqlist* L)
{
	cout<<"已进入选手信息删除系统\n";
	int s, i;
	s = Find2(L);
	if (s == -1)
		cout<<"未找到选手信息！\n";
	else
	{
		cout << "\t  要删除的选手信息是：" << endl;
		cout << "\t\t|   姓名   | 性别 |  班级信息  |  节目类型  |   节目名称   |	电话号	| 成绩 |" << endl;
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[s].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[s].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].score << "|" << endl;
		for (i = s; i<L->last; i++)
			L->elem[i] = L->elem[i + 1];
		L->last--;
		cout<<"\t删除成功\n";
	}
}

void Query1(Seqlist* L)
{
	cout << "\t  进入选手信息查询系统。" << endl;
	int s = Find2(L);
	if (s == -1)
		cout << "未找到选手信息！" << endl;
	else
	{
		cout << "\t  找到了" << L->elem[s].player_name << "选手。" << endl;
		cout << "\t\t|   姓名   | 性别 |  班级信息  |  节目类型  |   节目名称   |	电话号	| 成绩 |" << endl;
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[s].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[s].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].score << "|" << endl;
	}
}

void Change(Seqlist* L)
{
	cout << "\t  进入选手信息修改系统" << endl;
	int s = Find2(L);
	int have;
	if (s == -1)
		cout << "未找到选手信息！" << endl;
	else
	{
		cout << "\t  即将修改" << L->elem[s].player_name << "选手信息。" << endl;
		cout << "\t  选择要修改的信息：1.修改节目名字 2.修改节目类型 3.修改班级信息 4.修改电话号码" << endl;
		cin >> have;
		switch (have)
		{
			case 1:cin >> L->elem[s].show_name; break;
			case 2:cin >> L->elem[s].category; break;
			case 3:cin >> L->elem[s].classroom; break;
			case 4:cin >> L->elem[s].phone; break;
		}
		cout << "\t  修改完成，新信息为：" << endl;
		cout << "\t\t|   姓名   | 性别 |  班级信息  |  节目类型  |   节目名称   |	电话号	| 成绩 |" << endl;
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[s].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[s].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[s].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[s].score << "|" << endl;
	}
}

void Grade(Seqlist* L, Judges* J)
{
	int s, i, min, max;
	double sum = 0.0;
	int score[100];
	int num;//评委数
	int people = J->last;
	cout << people;
	num = J->last;

	s = Find2(L);
	if (s == -1)
		printf("未找到选手信息。\n");
	else
	{
		cout << "即将对" << L->elem[s].player_name << "选手进行打分。\n输入评委打分成绩（共" << num << "个评委）" << endl;
		for (i = 0; i<J->last; i++)
		{
			cout << J->elem[i].name << "评委给他的分数是：";
			cin>>score[i];
			sum += score[i];
		}
		min = score[0];
		max = score[0];
		for (i = 0; i<J->last; i++)
		{
			if (score[i]<min)
				min = score[i];
			if (score[i]>max)
				max = score[i];
		}
		if (num > 2)
		{
			sum = sum - max;
			sum = sum - min;
			people -= 2;
		}
		sum = sum / people;
		L->elem[s].score = sum;
		cout << "最后他的得分是：" << sum << ",他的分数将保存在他的信息中。。。。\n";
	}
}

void Show1(Seqlist* L)
{
	cout << "已进入选手信息显示系统，即将显示全部选手的信息：" << endl;
	int i;
	cout << "\t\t|   姓名   | 性别 |  班级信息  |  节目类型  |   节目名称   |	电话号	| 成绩 |" << endl;
	for (i = 0; i < L->last; i++)
	{
		cout << "\t\t|" << setw(10) << setfill(' ') << right << L->elem[i].player_name;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[i].sex;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[i].classroom;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[i].category;
		cout << "|" << setw(14) << setfill(' ') << right << L->elem[i].show_name;
		cout << "|" << setw(12) << setfill(' ') << right << L->elem[i].phone;
		cout << "|" << setw(6) << setfill(' ') << right << L->elem[i].score<<"|"<<endl;
	}
}

void quicksort_min(Seqlist* L, int left, int right)
{
	NodePlayer t, temp;
	int i, j;

	if (left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while (i != j)
	{
		while (L->elem[j].score >= temp.score && i<j)
			j--;
		while (L->elem[i].score <= temp.score&& i<j)
			i++;
		if (i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort_min(L, left, i - 1);
	quicksort_min(L, i + 1, right);
}

void quicksort_max(Seqlist* L, int left, int right)
{
	NodePlayer t, temp;
	int i, j;

	if (left>right)
		return;
	temp = L->elem[left];
	j = right;
	i = left;

	while (i != j)
	{
		while (L->elem[j].score <= temp.score && i<j)
			j--;
		while (L->elem[i].score >= temp.score&& i<j)
			i++;
		if (i<j)
		{
			t = L->elem[j];
			L->elem[j] = L->elem[i];
			L->elem[i] = t;
		}
	}

	L->elem[left] = L->elem[i];
	L->elem[i] = temp;

	quicksort_max(L, left, i - 1);
	quicksort_max(L, i + 1, right);
}

void Sort(Seqlist* L)
{
	int have;
	printf("\t  进入自动排序系统");
	cout << "\t  选择排名方法，1.从小到大，2.从大到小" << endl;
	cin >> have;
	if(have==1)
		quicksort_min(L, 0, L->last - 1);
	else
		quicksort_max(L, 0, L->last - 1);
	printf("排序完成！\n");
	Show1(L);
}

void entertain::getScore()
{
    int a[10];
    ofstream filescore("score.xls",ios::out);
    if(!filescore)
    {
        cerr<<"open error"<<endl;
    }
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
        filescore<<a[i]<<" ";
    }
    filescore.close();
}
void entertain::showScore()
{

}
void judge::setData()
{

}
void judge::showData()
{

}

string fileName = "judges.csv";

void Copy2(Judges* J)
{
	int i;
	ofstream file(fileName, ios::out);
	if (!file)
	{
		cout << "\t  文件打开失败！" << endl;
	}
	else
	{
		for (i = 0; i < J->last; i++)
		{
			file << J->elem[i].name << ","<< J->elem[i].sex << ","<< J->elem[i].phone << "\n";
		}
	}
}




void Load2(Judges* J)
{
	string str;
	int i = 1, j = 0, s = 0;
	ifstream file(fileName, ios::in);
	while (getline(file, str)) {
		istringstream sin(str);
		vector<string>fields;
		string field;
		while (getline(sin, field, ',')) {
			fields.push_back(field);
		}
		J->elem[s].name = Trim(fields[0]);
		J->elem[s].sex = Trim(fields[1]);
		J->elem[s].phone = Trim(fields[2]);
		s++;
	}
	J->last = s;
}

void UI2()
{
	printf("\t\t\t|-----------------菜单-----------------|\n");
	printf("\t\t\t|------------1.添加评委信息------------|\n");
	printf("\t\t\t|------------2.显示全部评委信息--------|\n");
	printf("\t\t\t|------------3.评委信息查询------------|\n");
	printf("\t\t\t|------------0.退出评委信息系统--------|\n");
}

void menu2(Judges* J)
{
	UI2();
	//	load2(J);//加载文件中评委数据
	int i, have = 1;
	printf("选择要进行的功能：");
	while (cin>>i)
	{
		have = 1;
		switch (i)
		{
		case 1: add(J); break;
		case 2: Show(J); break;
		case 3: Query2(J); break;
		case 0: have = 0; break;
		}
		Copy2(J);
		if (have == 0) {
			cout << "\t  裁判信息保存成功！" << endl;
			break;

		}
		printf("选择要进行的功能：");
	}
}

void add(Judges* J)
{
	int i;
	i = J->last;
	printf("\t  进入评委添加系统。\n");
	printf("\t  输入评委名字：");
	cin>>J->elem[i].name;
	printf("\t  输入评委性别：");
	cin>>J->elem[i].sex;
	printf("\t  输入评委电话：");
	cin>>J->elem[i].phone;
	J->last++;
	cout << "\t  添加评委信息成功。" << endl;
}

void Show(Judges* J)
{
	printf("进入显示全部评委信息系统：\n");
	int i;
	printf("\t\t|      姓名      | 性别 |        电话号码        |\n");
	for (i = 0; i < J->last; i++)
	{
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
		//cout<<"\t\t|     "<<J->elem[i].name<<"     |  "<<J->elem[i].sex<<"  |       "<<J->elem[i].phone<<"       |\n";
	}

}

int Find2(Judges* J)//查找函数，找到返回下标，找不到返回-1
{
	string Name;
	cout << "\t  请输入要查找的评委名字：";
	cin >> Name;
	int i = 0;
	while ((i < J->last) && !(J->elem[i].name == Name)) {
		i++;
	}
	if (i < J->last)
		return i;
	else
		return -1;
}

void Query2(Judges* J)
{
	cout << "\t  已进入评委信息查找系统"<<endl;
	int i;
	i = Find2(J);
	if (i != -1) {
		cout << "找到了" << J->elem[i].name << "评委的信息！" << endl;
		printf("\t\t|      姓名      | 性别 |        电话号码        |\n");
		cout << "\t\t|" << setw(16) << setfill(' ') << right << J->elem[i].name;
		cout << "|" << setw(6) << setfill(' ') << right << J->elem[i].sex;
		cout << "|" << setw(24) << setfill(' ') << right << J->elem[i].phone << "|" << endl;
	}
	else
		cout << "\t  抱歉，没有此人信息。" << endl;

}

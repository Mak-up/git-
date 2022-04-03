#include<bits/stdc++.h>
using namespace std;
string name_now;

const string getCurrentSystemTime()
{
  time_t t;
  struct tm *lt;
  time(&t);
  lt = localtime(&t); //转为时间结构。
  char date[60] = {0};
  sprintf(date, "%d-%02d-%02d",
          (int)lt->tm_year + 1900, (int)lt->tm_mon + 1, (int)lt->tm_mday);
  return string(date);
}

class manage
{
private:
	string number;//登录号码
	string code;//密码
public:
	//manage();//默认构造函数
	void getManage();//声明登录函数
	void reviseInformation();//修改信息函数
	void all_end();//统计活动最终情况
	void delete_activity();
	//~manage();//析构函数
};
//管理员登录，联系管理员可以修改用户账号密码

void manage::getManage()
{   system("cls");
	cout<<"************************************************欢迎登陆活动管理系统！*****************************************************"<<endl;
	cout<<"----------------------------------------------此页面是管理员登录界面---------------------------------------------------"<<endl;
	string a,b;
	cout<<"请输入您的账号："<<endl;
	cin>>a;
	cout<<"请输入密码："<<endl;
	cin>>b;
	string n;
	string c;
    ifstream in("manage.txt");//打开文件
	int i=0;//标签，判断账号的存在与否
    do
     {
	   if(in.eof())//文件尾就结束
       break;
	   
	   string s;
	   getline(in,s);//读入每一行
       istringstream sin(s);//定义sin流
       sin>>n>>c;
	   if((a==n)&&(c==b))//判断是否存在
         {
			 i=1;
             cout<<"登陆成功！"<<endl;
             name_now=a;
			 break; 
					            
         }
     }
	while(!in.eof());//判断是否到文件尾

    if(i==0)
	cout<<"输入不正确！" <<endl;
	    in.close();//关闭文件
	if(i!=0)reviseInformation();
    
}
//文件导入判读登录是否合法
void manage::reviseInformation()//修改信息函数
{
  int t=0;//标签，是否存在该账号
  string a,b,c,d;
  cout<<"-----------------------------请输入要修改的个人信息：------------------------------"<<endl;
  cout<<"账号："<<endl;
  cin>>c;
  //cout<<"密码："<<endl;
  //cin>>d;
  ifstream in("user.txt");//打开文件
  string s1;
  while( getline(in,s1))//读入数据
     {
		istringstream sin(s1);//定义sin流
        sin>>a>>b;
	    ofstream out("manage1.txt",ios::app);//打开文件
        if((a==c))//存在该账号
          {
		    t=1;
		    string p;
			cout<<"请输入修改的密码:" <<endl;
			cin>>p;
            out<<a<<" "<<p<<endl; 
			cout<<"修改成功"<<endl;
		  }
		  else
			  out<<a<<" "<<b<<endl;//未修改
		      out.close();//关闭文件
	 }
		in.close();//关闭文件

		ifstream filein("manage1.txt");//打开文档
		ofstream fileout("user.txt",ios::out);//打开文档并清空内容
		string s;
		while(getline(filein,s))//将修改后的内容写到文件中去
		{
			fileout<<s<<endl;
		}
		filein.close();//关闭文件
		fileout.close();//关闭文件

		if(t==0)//不存在该账号
        {
	       cout<<"账号错误！"<<endl;
	    }
		 system("del manage1.txt");
}
//打开用户文件修改密码
class user
{
private:
    string name;
    string password;
public:
	//user(void);
	string getName()const;//获得姓名
	//string get_password()const;//获得密码
	int getInformation();
	void get_user();//修改密码
	void show_now();
	void found_();
	void delete_();
	//~user(void);
};

void user::get_user()
{   system("cls");
	cout<<"************************************************欢迎登陆活动管理系统！*****************************************************"<<endl;
	cout<<"----------------------------------------------此页面是用户登录界面---------------------------------------------------"<<endl;
	string a,b;
	cout<<"请输入您的账号："<<endl;
	cin>>a;
	cout<<"请输入密码："<<endl;
	cin>>b;
	string n;
	string c;
    ifstream in("user.txt");//打开文件
	int i=0;//标签，判断账号的存在与否
    do
     {
	   if(in.eof())//文件尾就结束
       break;
	   
	   string s;
	   getline(in,s);//读入每一行
       istringstream sin(s);//定义sin流
       sin>>n>>c;
	   if((a==n)&&(c==b))//判断是否存在
         {
			 i=1;
             cout<<"登陆成功！"<<endl;
             name_now=a;
			 break; 					            
         }
     }
	while(!in.eof());//判断是否到文件尾

    if(i==0)
	cout<<"输入不正确！" <<endl;
   if(i!=0)
{
  
  system("pause");
  system("cls");
  cout << "___________________________ 活动管理系统____________________________\n";
  cout << "--------------------------请输入要进行的操作----------------------------\n";
  cout << "                  ┃ 1 创建活动                             \n";
  cout << "                  ┃ 2 查看当前征集活动                          \n";
  cout << "                  ┃ 3 截止活动详情                             \n";
  cout << "                  ┃ 4 删除活动                          \n";
  cout << "                  ┃ 5 返回上一级/退出登录                          \n";
  int temp;
  cin >> temp;
  switch (temp)
  {
  case 1:
  {
    found_();
    break;
  }
  case 2:
    cout << "目前开展的活动有：\n";
    show_now();
    break;
  case 3:
    cout << "截止报名活动参与详情：\n";
    break;
  case 4:
    cout << "你目前创办的活动有：\n";
    delete_();
    break;
  case 5:
    system("cls");
    break;
  default:
    cout << "操作有误";
    break;
  }

   }
	system("pause");
	in.close();//关闭文件
    
}

void user::show_now()
{
  system("cls");
 cout<<"------------------------------------------------下列活动火热开展中，欢迎你的加入！--------------------------------------------"<<endl;
 ifstream in("activity.txt");
// int i=0;//标签，判断账号的存在与否
 string a,b,c,d,e;
 if(!in.eof())
 {
    string s;
	  getline(in,s);
 }//削去labal行
    do
     {
	   if(in.eof())//文件尾就结束
       break;
	   
	   string s;
	   getline(in,s);//读入每一行
       istringstream sin(s);//定义sin流
       sin>>a>>b>>c>>d>>e;
	   if(e>=getCurrentSystemTime())//判断是否存在
         {
        cout<<"活动名称："<<a<<"   "<<"活动创办人："<<b<<"   "<<"活动开始时间："<<d<<"   "<<"活动截止报名时间"<<e<<endl;
        cout<<"************************************************************************************************\n";          
         }
     }
	while(!in.eof());//判断是否到文件尾


}

void user::found_()
{

cout << "请输入你所要创建活动的名字：\n";
    string name1;
    cin >> name1;
    cout << "请输入该活动最大参与人数：\n";
    int cnt;
    cin >> cnt;
    cout << "请输入活动的开始时间(格式形如:2017-01-08)：\n";
    string time;
    cin >> time;
    cout<<"请输入活动截止报名时间：\n";
    string time1;
    cin>>time1;
   ofstream out("activity.txt",ios::app);
   out<<"\n"<<name1<<" "<<name_now<<" "<<cnt<<" "<<time<<" "<<time1;
   out.close();
   cout<<"创建成功！";
   system("pause");
	
}

void user::delete_()
{
  cout<<"-----------------------------------------------此页面是活动删除界面,请谨慎操作qaq----------------------------------------------\n";
  cout<<"您创办的活动有：\n";
  ifstream in("activity.txt");
  int i=0;
  string a,b,c,d,e;
  do
  {

    if(in.eof())break;
    string s;
    getline(in,s);
    istringstream sin(s);
    sin>>a>>b>>c>>d>>e;
    if(b==name_now)
    {
       cout<<"活动名称："<<a<<"   "<<"活动创办人："<<b<<"   "<<"活动开始时间："<<d<<"   "<<"活动截止报名时间"<<e<<endl;
        cout<<"************************************************************************************************\n";
        i=1;   
    }  

  } while (!in.eof());
  in.close();
  if(i==0)cout<<"您还未有创办活动,无法进行此操作！"<<endl;
else
{	
  cout<<"请输入你要删除的活动:"<<endl;
  string delete_name;
  cin>>delete_name;




}

}




class activity
{
  public:
     string name;
	 void getnow();





};

void menu()
{
  int temp;
  while (1)
  {
    cout << "               ___________________________ 活动管理系统____________________________\n";
    cout << "                            -------------- 欢迎你的到来------------                                                \n";
    cout<<"               ------------------------  请问您以何种身份登录-----------------------------------------";
    cout<<"*******************************************************************************************************************"<<endl;
    cout << "                                   ┃   1 管理员            ┃                          \n";
    cout << "                                   ┃   2 用户              ┃                          \n";
    cout << "                                   ┃   3 退出系统           ┃                          \n";

   int t;
   cin>>t;
	switch(t)
	{
	
	case 1: {  manage A;A.getManage()  ;break;  }
	case 2:{  user B;B.get_user();break; }
	case 3:
		cout<<"感谢您的使用！"<<endl;//退出
		system("pause");
		exit(0);
	default :
		cout<<"输入错误！"<<endl;
		break;//错误提示
	}
    system("cls");
	}
}


int main()
{ 

  system("cls");

   menu();
//cout<<getCurrentSystemTime();

}




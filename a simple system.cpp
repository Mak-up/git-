#include <bits/stdc++.h>
#include<iostream>
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
  string number; //登录号码
  string code;   //密码
public:
  // manage();//默认构造函数
  void getManage();         //声明登录函数
  void reviseInformation(); //修改信息函数
  void all_end();           //统计活动最终情况
  void delete_activity();
  //~manage();//析构函数
};
//管理员登录，联系管理员可以修改用户账号密码

void manage::getManage()
{
  system("cls");
  cout << "************************************************欢迎登陆活动管理系统！*****************************************************" << endl;
  cout << "----------------------------------------------此页面是管理员登录界面---------------------------------------------------" << endl;
  string a, b;
  cout << "请输入您的账号：" << endl;
  cin >> a;
  cout << "请输入密码：" << endl;
  cin >> b;
  string n;
  string c;
  ifstream in("manage.txt"); //打开文件
  int i = 0;                 //标签，判断账号的存在与否
  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s;
    getline(in, s);       //读入每一行
    istringstream sin(s); //定义sin流
    sin >> n >> c;
    if ((a == n) && (c == b)) //判断是否存在
    {
      i = 1;
      cout << "登陆成功！" << endl;
      name_now = a;
      break;
    }
  } while (!in.eof()); //判断是否到文件尾

  if (i == 0)
    cout << "输入不正确！" << endl;
  in.close(); //关闭文件
  if (i != 0)
    reviseInformation();
}
//文件导入判读登录是否合法
void manage::reviseInformation() //修改信息函数
{
  int t = 0; //标签，是否存在该账号
  string a, b, c, d;
  cout << "-----------------------------请输入要修改的个人信息：------------------------------" << endl;
  cout << "账号：" << endl;
  cin >> c;
  // cout<<"密码："<<endl;
  // cin>>d;
  ifstream in("user.txt"); //打开文件
  string s1;
  while (getline(in, s1)) //读入数据
  {
    istringstream sin(s1); //定义sin流
    sin >> a >> b;
    ofstream out("manage1.txt", ios::app); //打开文件
    if ((a == c))                          //存在该账号
    {
      t = 1;
      string p;
      cout << "请输入修改的密码:" << endl;
      cin >> p;
      out << a << " " << p << endl;
      cout << "修改成功" << endl;
    }
    else
      out << a << " " << b << endl; //未修改
    out.close();                    //关闭文件
  }
  in.close(); //关闭文件

  ifstream filein("manage1.txt");         //打开文档
  ofstream fileout("user.txt", ios::out); //打开文档并清空内容
  string s;
  while (getline(filein, s)) //将修改后的内容写到文件中去
  {
    fileout << s << endl;
  }
  filein.close();  //关闭文件
  fileout.close(); //关闭文件

  if (t == 0) //不存在该账号
  {
    cout << "账号错误！" << endl;
  }
  system("del manage1.txt");
}
//打开用户文件修改密码

void register_()
{
  cout<<"请输入你要注册的用户名："<<endl;
  string name;
  cin>>name;
  cout<<"请输入你要设置的密码："<<endl;
  string password;
  cin>>password;
  ifstream in("user.txt");
  string s1,a;
  int flag=0;
  while (getline(in, s1)) //读入数据
  {
    istringstream sin(s1); //定义sin流
    sin >> a ;
    if ((a == name))                          //存在该账号
    {
        cout<<"账号已存在，创建失败！"<<endl;flag=1;
        system("pause");
        break;
    }                 //关闭文件
  }
  in.close(); //关闭文件
  if(!flag)
  {
    
    ofstream out("user.txt", ios::app);
    int now_attend = 0;
    out << "\n"
        << name <<" "<<password;
    out.close();
    ofstream out1("user1.txt",ios::app);
    out1<<"\n"<<name;
    out1.close();
    cout << "创建成功！";
    system("pause");

  }



}

class user
{
private:
  string name;
  string password;

public:
  // user(void);
  // string getName()const;//获得姓名
  // string get_password()const;//获得密码
  int getInformation();
  void get_user(); //修改密码
  void show_now();
  void attend();
  void show_found();
  void found_();
  void show_attend();
  void delete_();
  void comment();
  void search();
  void show_final();
  //~user(void);
};

void user::get_user()
{
  system("cls");
  cout << "************************************************欢迎登陆活动管理系统！*****************************************************" << endl;
  cout << "----------------------------------------------此页面是用户登录界面---------------------------------------------------" << endl;
  string a, b;
  cout << "请输入您的账号：" << endl;
  cin >> a;
  cout << "请输入密码：" << endl;
  cin >> b;
  string n;
  string c;
  ifstream in("user.txt"); //打开文件
  int i = 0;               //标签，判断账号的存在与否
  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s;
    getline(in, s);       //读入每一行
    istringstream sin(s); //定义sin流
    sin >> n >> c;
    if ((a == n) && (c == b)) //判断是否存在
    {
      i = 1;
      cout << "登陆成功！" << endl;
      name_now = a;
      break;
    }
  } while (!in.eof()); //判断是否到文件尾

  if (i == 0)
    cout << "输入不正确！" << endl;
  if (i != 0)
  {
  here:
system("pause");
system("cls");

    cout << "                              *******************************************************************************************************************" << endl;
    cout << "                              *                                              欢迎来到活动管理系统                                               *"<<endl;
    cout << "                              *******************************************************************************************************************" << endl;
    cout <<"                                                                              请输入您要进行的操作：                                                   "<<endl;
    cout << "                                                                      ********************************                                    "<<endl;
    cout << "                                                                      ***   1 创建活动             ***                                     "<<endl;
    cout  <<"                                                                      ********************************                                   "<<endl;
    cout << "                                                                      ***   2 查看当前征集活动      ***                               "<<endl;
    cout << "                                                                      ********************************                                      "<<endl;
    cout << "                                                                      ***   3 查看当前创建活动      ***                              "<<endl;
    cout << "                                                                      ********************************                              "<<endl;
    cout << "                                                                      ***   4 删除活动              ***                                     "<<endl;
    cout << "                                                                      ********************************                                   "<<endl;
    cout << "                                                                      ***   5 查看你参加的活动      ***                               "<<endl;
    cout << "                                                                      ********************************                                      "<<endl;
    cout << "                                                                      ***   6 查找活动             ***                                     "<<endl;
    cout << "                                                                      ********************************                                                                "<<endl;
    cout << "                                                                      ***   7 截止活动详情          ***                                     "<<endl;
    cout << "                                                                      ********************************                                                                "<<endl;
    cout << "                                                                      ***   8 返回上一级/退出登录   ***                                     "<<endl;
    cout << "                                                                      ********************************                                                                "<<endl;
   int temp;
    cin >> temp;
    switch (temp)
    {
    case 1:
    {
      found_();
      goto here;
      break;
    }
    case 2:
      cout << "目前开展的活动有：\n";
      show_now();
      goto here;
      break;
    case 3:
      show_found();
      goto here;
      break;
    case 4:
      cout << "你目前创办的活动有：\n";
      delete_();
      goto here;
      break;
    case 5:
      show_attend();
      goto here;
      break;
    case 6:
      search();
      goto here;
    case 7:
      show_final();
      goto here;
    case 8:
      system("cls");
      break;
    default:
      cout << "操作有误";
      system("pause");
      goto here;
      break;
    }
  }

  in.close(); //关闭文件
}

void user::show_now()
{
  system("cls");
  cout << "------------------------------------------------下列活动火热开展中，欢迎你的加入！--------------------------------------------" << endl;
  ifstream in("activity.txt");
  // int i=0;//标签，判断账号的存在与否
  string a, b, c, d, e;
  string s;
  getline(in, s);

  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s;
    getline(in, s);       //读入每一行
    istringstream sin(s); //定义sin流
    sin >> a >> b >> c >> d >> e;
    if (e >= getCurrentSystemTime()) //判断是否存在
    {
      cout << "活动名称：" << a << "   "
           << "活动创办人：" << b << "   "
           << "活动开始时间：" << d << "   "
           << "活动截止报名时间" << e << endl;
      cout << "************************************************************************************************\n";
    }
  } while (!in.eof()); //判断是否到文件尾
  cout <<endl<< "请输入您接下来的操作：" << endl;
  cout << "***************************************************************" << endl;
  cout << "***     1 参与活动           ****                         \n";
  cout<<"*****************************************************************"<<endl;
  cout << "***     2 返回上一级         ****                          \n";
  cout<<"*****************************************************************"<<endl;
  int temp;
  cin >> temp;
  switch (temp)
  {
  case 1:
    attend();
    break;
  case 2:
    break;
  default:
    cout << "输入错误！";
    break;
  }
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
  cout << "请输入活动截止报名时间：\n";
  string time1;
  cin >> time1;
  ifstream in("activity.txt");
  int i = 1;
  string s, a;
  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s;
    getline(in, s);       //读入每一行
    istringstream sin(s); //定义sin流
    sin >> a;
    if (a == name1) //判断是否存在
      i = 0;
  } while (!in.eof());
  if (i == 1)
  {
    ofstream out("activity.txt", ios::app);
    int now_attend = 0;
    out << "\n"
        << name1 << " " << name_now << " " << cnt << " " << time << " " << time1 << " " << now_attend;
    out.close();
    cout << "创建成功！";
    system("pause");
  }
  else
  {
    cout << "活动已存在，创建失败！" << endl;
    system("pause");
  }
}

void user::show_found()
{
  cout << "您创办的活动有：\n";
  ifstream in("activity.txt");
  int i = 0;
  string a, b, c, d, e, f;
  do
  {

    if (in.eof())
      break;
    string s;
    getline(in, s);
    istringstream sin(s);
    sin >> a >> b >> c >> d >> e >> f;
    if (b == name_now)
    {
      cout << "活动名称：" << a << "   "
           << "活动创办人：" << b << "   "
           << "活动开始时间：" << d << "   "
           << "活动截止报名时间" << e << "   "
           << "参与人数:" << f << "/" << c << endl;
      cout << "******************************************************************************************************\n";
      i = 1;
    }

  } while (!in.eof());
  in.close();
  if (i == 0)
    cout << "您目前还未创建活动";
}

void user::delete_()
{
  system("cls");
  cout << "-----------------------------------------------此页面是活动删除界面,请谨慎操作qaq----------------------------------------------\n";
  cout << "您创办的活动有：\n";
  ifstream in("activity.txt");
  int i = 0;
  string a, b, c, d, e;
  do
  {

    if (in.eof())
      break;
    string s;
    getline(in, s);
    istringstream sin(s);
    sin >> a >> b >> c >> d >> e;
    if (b == name_now)
    {
      cout << "活动名称：" << a << "   "
           << "活动创办人：" << b << "   "
           << "活动开始时间：" << d << "   "
           << "活动截止报名时间" << e << endl;
      cout << "************************************************************************************************\n";
      i = 1;
    }

  } while (!in.eof());
  in.close();
  if (i == 0)
    cout << "您还未有创办活动,无法进行此操作！" << endl;
  else
  {
    cout << "请输入你要删除的活动名称:" << endl;
    string delete_name;
    cin >> delete_name;
    cout << "您要删除的活动是：" << delete_name << ","
         << "请问是否确定删除？(Y:是,其他: 否)" << endl
         << "请输入您要进行的操作：" << endl;
    string sure;
    cin >> sure;
    if (sure == "Y")
    {
      ifstream in("activity.txt"); //打开文件
      string s1;
      string name, founder, st_time, en_time, max_size, now_size;
      int flag = 0;
      int start1=1;
      while (getline(in, s1)) //读入数据
      {
        istringstream sin(s1); //定义sin流
        sin >> name >> founder >> max_size >> st_time >> en_time >> now_size;
        ofstream out("del.txt", ios::app);
        if ((name == delete_name))
        {
          flag = 1;
          continue;
        }
        else
          if(start1==1)start1=0, out << name << " " << founder << " " << max_size << " " << st_time << " " << en_time << " " << now_size;
          else out << endl << name << " " << founder << " " << max_size << " " << st_time << " " << en_time << " " << now_size ; //未修改
        out.close();                                                                                                       //关闭文件
      }
      in.close(); //关闭文件

      ifstream filein("del.txt");                 //打开文档
      ofstream fileout("activity.txt", ios::out); //副本填充
      string s;
      int start=1;
      while (getline(filein, s)) //将修改后的内容写到文件中去
      {
        if(start==1) fileout<<s,start=0;
         else fileout << endl<< s ;
      }
      filein.close();  //关闭文件
      fileout.close(); //关闭文件

      if (flag == 0) //不存在该活动
      {
        cout << "活动名称错误！" << endl;
      }
      else
        cout << "删除成功！";
      system("del del.txt");
      system("pause");
    }
  }
}

void user::attend()
{
  string name;
  cout << "请输入您要参加的活动名称:\n";
  cin >> name;
  ifstream in("activity.txt");
  string a, b, c, d, e, f;
  int i = 0;
  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s;
    getline(in, s);       //读入每一行
    istringstream sin(s); //定义sin流
    sin >> a >> b >> c >> d >> e >> f;
    if (a == name && c > f) //判断是否存在
    {
      // cout<<"加入成功！\n";
      i = 1;
    }
  } while (!in.eof()); //判断是否到文件尾
  in.close();
  if (i == 0)
    cout << "加入失败，活动名称输入有误/人数已满" << endl;
  else
  {
    ifstream in("user1.txt"); //打开文件
    string s1, a;
    while (getline(in, s1)) //读入数据
    {
      istringstream sin(s1);
      sin >> a;
      if (a == name_now)
      {
        s1 += " ";
        s1 += name;
      }
      ofstream out("manage2.txt", ios::app); //打开文件
      out << s1 << endl;
      out.close();
    }
    in.close(); //关闭文件

    ifstream filein("manage2.txt");          //打开文档
    ofstream fileout("user1.txt", ios::out); //打开文档并清空内容
    string s2;
    while (getline(filein, s2)) //将修改后的内容写到文件中去
    {
      fileout << s2 << endl;
    }
    filein.close();
    fileout.close();

    system("del manage2.txt");

    //下面在活动文件参与人数加1
    ifstream in1("activity.txt");
    // ofstream out1("add.txt",ios::app);
    string name3, founder, max_size, st_time, en_time, now_size;
    string s3;
    while (getline(in1, s3)) //读入数据
    {
      istringstream sin(s3); //定义sin流
      sin >> name3 >> founder >> max_size >> st_time >> en_time >> now_size;
      ofstream out1("add.txt", ios::app);
      if (name == name3)
        now_size = to_string(stoi(now_size) + 1);
      out1 << name3 << " " << founder << " " << max_size << " " << st_time << " " << en_time << " " << now_size << endl;

      out1.close(); //关闭文件
    }
    in1.close(); //关闭文件

    ifstream filin("add.txt");                 //打开文档
    ofstream filout("activity.txt", ios::out); //副本填充
    string s;
    while (getline(filin, s)) //将修改后的内容写到文件中去
    {
      filout << s << endl;
    }
    filin.close();  //关闭文件
    filout.close(); //关闭文件
    cout << "加入成功！\n";

    system("del add.txt");
  }
}

void user::show_attend()
{
  cout << "下面是您报名参加的活动：\n";
  ifstream in("user1.txt");
  string name, a, name1;
  string s;

  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s, a1;
    getline(in, s); //读入每一行
    // cout<<s<<endl;
    istringstream sin(s); //定义sin流
    sin >> name;
    if (name == name_now) //判断是否存在
    {
      while (sin >> name1)
      {
        // cout << name1 << endl;
        ifstream filein("activity.txt");
        do
        {

          if (filein.eof())
            break;
          string s1;
          getline(filein, s1);
          istringstream sin1(s1);
          string a, b, c, d, e, f;
          sin1 >> a >> b >> c >> d >> e >> f;
          if (a == name1)
          {
            cout << "活动名称：" << a << "   "
                 << "活动创办人：" << b << "   "
                 << "活动开始时间：" << d << "   "
                 << "活动截止报名时间" << e << "   "
                 << "参与人数:" << f << "/" << c << endl;
            cout << "*******************************************************************************************************************************\n";
          }

        } while (!filein.eof());
        filein.close();
      }
    }
  } while (!in.eof());
  in.close();
  cout <<endl<< "请输入您接下来的操作：" << endl;
  cout << "***************************************************************" << endl;
  cout << "***     1 发表评论           ****                         \n";
  cout<<"*****************************************************************"<<endl;
  cout << "***     2 返回上一级         ****                          \n";
  cout<<"*****************************************************************"<<endl;
  int temp;
  cin >> temp;
  switch (temp)
  {
  case 1:
    comment();
    break;
  case 2:
    break;
  default:
    cout << "输入有误！" << endl;
    break;
  }
}

void user::comment()
{
  string name;
  cout << "请你输入要选择评论的活动名称：\n";
  cin >> name;
  cout << "请发表你的精彩评论！" << endl;
  string comment;
  cin >> comment;
  ofstream out("comment.txt", ios::app);
  out << endl
      << name << " " << name_now << ": " << comment;
  return;
}

class transform1
{
public:
  vector<int> stringToVecInt(const string &str)
  {
    union
    {
      char c[2];
      int i;
    } convert;

    // 段位清零
    convert.i = 0;

    vector<int> vec;

    for (unsigned i = 0; i < str.length(); i++)
    {
      // GBK编码首字符大于0x80
      if ((unsigned)str[i] > 0x80)
      {
        // 利用union进行转化，注意是大端序
        convert.c[1] = str[i];
        convert.c[0] = str[i + 1];
        vec.push_back(convert.i);
        i++;
      }
      else
        // 小于0x80，为ASCII编码，一个字节
        vec.push_back(str[i]);
    }
    return vec;
  }
  bool include(const std::string &str, const std::string &msg)
  {
    auto sour = stringToVecInt(str);
    auto find = stringToVecInt(msg);
    return search(sour.begin(), sour.end(), find.begin(), find.end()) != sour.end();
  }
};
//中文是gbk编码.GBK分两段：ASCII段和中文段。ASCII段使用单字节，和ASCII编码保持一致；中文（及特殊符号）段使用双字节编码。在双字节段中，第一字节的范围是81–FE（也就是不含80和FF），第二字节的一部分领域在40–7E，其他领域在80–FE2。
// 也就是说，在GBK编码中，中文有两个字节，首字节范围81~FE，尾字节范围40~7E。
// 这么说来，判断一个字符（或者中文的一个字）是否为中文，只要判断其是否大于0x80即可。在判断其大于时，获取两个字节，同时向下跳一字节，进行后续判断；如果不大于，则为ASCII字符，获取一个字节。

void user::search()
{
  cout << "请输入您要查找活动的关键词：" << endl;
  string idx;
  cin >> idx;
  ifstream in("activity.txt");
  string a, b, c, d, e, f;
  int flag;
  do
  {

    if (in.eof())
      break;
    string s;
    getline(in, s);
    istringstream sin(s);
    flag = 1;
    sin >> a >> b >> c >> d >> e >> f;

    transform1 A;
    if (A.include(a, idx))
    {
      cout << "活动名称：" << a << "   "
           << "活动创办人：" << b << "   "
           << "活动开始时间：" << d << "   "
           << "活动截止报名时间" << e << "   "
           << "参与人数:" << f << "/" << c << endl;
      cout << "********************************************************************************************************\n";
    }

  } while (!in.eof());
  in.close();
}

void user::show_final()
{
  system("cls");
  cout << "------------------------------------------------下列活动报名已截止，详情如下：--------------------------------------------" << endl;
  ifstream in("activity.txt");
  string a, b, c, d, e, f;
  string s;
  getline(in, s);

  do
  {
    if (in.eof()) //文件尾就结束
      break;

    string s;
    getline(in, s);       //读入每一行
    istringstream sin(s); //定义sin流
    sin >> a >> b >> c >> d >> e>>f;
    if (e < getCurrentSystemTime())
    {
      cout << "活动名称：" << a << "   "
           << "活动创办人：" << b << "   "
           << "活动开始时间：" << d << "   "
           << "报名人数" << f << "/" << c << endl;
      cout << "参与人员有：" << endl;
      ifstream filein("user1.txt");
      do
      {
        if (filein.eof()) //文件尾就结束
          break;
         string s;
         getline(filein,s);
         istringstream sin1(s);
          string name;
          sin1>>name;
          string name1;
          while(sin1>>name1)
          {
            if(name1==a)
            {
              cout<<name<<" ";
              break;
            }
          }
      } while (!filein.eof());
      filein.close();

      cout <<endl<< "*********************************************************************************************************************\n";
    }
  } while (!in.eof());
  in.close();
}

void menu()
{
  int temp;
  while (1)
  {
 system("cls");

    cout << "                              *******************************************************************************************************************" << endl;
    cout << "                              *                                              欢迎来到活动管理系统                                               *"<<endl;
    cout << "                              *******************************************************************************************************************" << endl;
    cout << "                                             *****************************                **********************                          "<<endl;
    cout << "                                             ***   1 管理员登录        ***                * 请注意，本系统仅为了  *                        "<<endl;
    cout  <<"                                             *****************************                * 方便活动管理设计,请   *                        "<<endl;
    cout << "                                             ***   2 用户登录          ***                * 各位用户遵守平台规则，*                        "<<endl;
    cout << "                                             *****************************                * 绿色上网,创建健康有益 *                        "<<endl;
    cout << "                                             ***   3 注册用户          ***                * 活动,不发表低俗,淫    *                        "<<endl;
    cout << "                                             *****************************                * 评论,违者将冻结账号！ *                         "<<endl;
    cout << "                                             ***   4 退出系统          ***                 **********************                          "<<endl;
    cout << "                                             *****************************                                                                "<<endl;
    cout<<"请输入您要进行的操作："<<endl;
    int t;
    cin >> t;
    switch (t)
    {

    case 1:
    {
      manage A;
      A.getManage();
      break;
    }
    case 2:
    {
      user B;
      B.get_user();
      break;
    }
    case 3:
    register_();
    break;
    case 4:
      cout << "感谢您的使用！" << endl; //退出
      system("pause");
      exit(0);
    default:
    {
      cout << "输入错误！" << endl;
      exit(0);
      break; //错误提示
    }
    }
    system("cls");
  }
}

int main()
{
  menu();
  // cout<<getCurrentSystemTime();
}

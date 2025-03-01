/*
 *文件名:   tasks.cpp
 *作者:     Nictheboy
 *内容:     实现游戏中的关卡
 *
 */
#ifndef FOR_XES
#include "hackgame.h"
#endif

//一下是新的剧情函数列表
bool task_new_1();
bool task_new_2();
bool task_new_3();
bool task_new_4();
bool task_new_5();
bool task_new_6();
bool task_new_7();
bool task_new_8();
bool task_new_9();
bool end_task();
typedef bool (*task_function)();
task_function task_added_function[10]={//新的剧情函数数组
    task_new_1,
    task_new_2,
    task_new_3,
    task_new_4,
    task_new_5,
    task_new_6,
    task_new_7,
    task_new_8,
    task_new_9,
    end_task
};

//下面是一下剧情函数

//用来结束游戏
void game_over(int i)//i=1:未删除日志
{
    switch(i)
    {
    case 1:
        cout<<BG_RED<<"您忘记删除日志了！！！警察发现了你的黑客行为，您被捕了"<<RESET<<endl;
        break;
    default:
        cout<<"Case Undifined!!!"<<endl;
    }
    delay(9999999);
    exit(0);
}

//这一堆函数控制剧情逻辑
void task_1_1()//这个任务还有让用户设置用户名密码的功能
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task1"); 
#endif
    clearScreen();
    cout<<"请您为自己起一个名字:";
    string tmp;
    getline(cin, tmp);
    localhost->username=tmp;
    cout<<"设置您的主机密码:";
    getline(cin, tmp);
    localhost->password=tmp;
    cout<<"设置您的主机名:";
    getline(cin, tmp);
    localhost->name=tmp; 
    clearScreen();
    //delay(2);
    cout<<BG_RED<<"您收到一封邮件！输入mail查看\n\n"<<RESET;
    
    sub_task_number=0;
    task_number=1;//设置关卡变量是因为mail程序根据关卡变量决定输出的邮件
    
    localhost->event_before_input=NULL;
    Internet->connect(COMPUTER1).computer->event_before_input=&task_1_2;//将任务绑定到主机2，用于检测玩家是否连接成功
}
void task_1_2()//玩家连接到主机2后，执行此程序
{
    sub_task_number=1;
    Internet->connect(COMPUTER1).computer->event_before_input=NULL;
    localhost->event_before_input=&task_2_1;//进入下一关
    //localhost->process_event_before_input();//先处理一下
}
void task_2_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task2");
#endif
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    task_number=2;
    localhost->event_before_input=&task_2_2;//下一子关卡
    localhost->process_event_before_input();//先处理一下
}
void task_2_2()
{
    using namespace FileSystem;
    //cout<<"okokokok\n";
    file *get=localhost->root->locate_file("data/wget.exe");
    //cout<<"okokokok\n";
    if (get)//是否有文件，检测是否拷贝了文件
    {
        task_3_1();
    }
}
void task_3_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task3");
#endif
    task_number=3;
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    localhost->event_before_input=&task_3_2;//同上
    localhost->process_event_before_input();
}
void task_3_2()
{
    if (localhost->root->locate_file("bin/wget.exe"))
    {
        localhost->event_before_input=&task_4_1;//同上
        localhost->process_event_before_input();
    }
}
void task_4_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task4");
#endif
    task_number=4;
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    localhost->event_before_input=task_4_2;//同上
    localhost->process_event_before_input();
}
void task_4_2()
{
    if (localhost->locate_file("/data/passguesser.exe"))//检测是否有文件
    {
        localhost->event_before_input=&task_5_1;
        localhost->process_event_before_input();
    }
}
void task_5_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task5");
#endif
    task_number=5;
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    localhost->event_before_input=task_5_2;//同上
    localhost->process_event_before_input();
}
void task_5_2()
{
    if (localhost->locate_file("/bin/passguesser.exe"))//检测是否有文件
    {
        localhost->event_before_input=&task_6_1;
        localhost->process_event_before_input();
    }
}
void task_6_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task6");
#endif
    task_number=6;
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    localhost->event_before_input=task_6_2;//同上
    localhost->process_event_before_input();
}
void task_6_2()
{
    //task_number=6;
    //cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    //localhost->event_before_input=task_6_2;
    if (localhost->locate_file("/data/portscan.exe"))//检测文件
    {
        if (Internet->connect(COMPUTER3).computer->locate_file("/log/connect.log"))//是否删除了日志
        {
            game_over(1);//没删除文件则游戏结束
        }
        else
        {
            localhost->event_before_input=task_7_1;//下一关
            localhost->process_event_before_input();
        }
    }
}
void task_7_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task7");
#endif
    task_number=7;
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    localhost->event_before_input=task_7_2;
    localhost->process_event_before_input();
}
void task_7_2()
{
    Computer *temp=new Computer("180.21.10.220");
    Internet->add_node(temp->netnode);
    temp->style=telnet;
    temp->password="root";//设密码
    temp->open_port("telnet",256);//打开端口
    temp->locate_dir("/bin")->add_file(new FileSystem::file("tracer.exe",&exe_tracer));//放文件
    localhost->event_before_input=task_7_3;
    localhost->process_event_before_input();
}

void task_7_3()
{
    if (localhost->locate_file("/data/tracer.exe"))//检测文件
    {
        if (Internet->connect("180.21.10.220").computer->locate_file("/log/connect.log"))//是否删除了日志
        {
            game_over(1);//没删除文件则游戏结束
        }
        else
        {
            localhost->event_before_input=task_8_1;//下一关
            localhost->process_event_before_input();
        }
    }
}

void task_8_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_task8");
#endif
    task_number=8;
    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    Computer *temp;
    net_node *tempnode;
    net_node *tempnode2;

    tempnode2 = new net_node("24.120.41.2");
    Internet->add_node(tempnode2);
        //cout<<"debug6"<<endl;

    temp=new Computer("24.120.41.0");
    tempnode = temp->netnode;
    tempnode2->add_node(temp->netnode,true);//连接这个主机的节点
    temp->password="password0abc";//设密码
    temp->open_port("telnet",91);//打开端口
    temp->style = telnet;
    temp->event_before_input = &task_8_2;
       // cout<<"debug7"<<endl;
    
    temp=new Computer("24.120.41.10");
    tempnode->add_node(temp->netnode,true);//连接这个主机的节点
    temp->password="pass_lispt202";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->locate_dir("data")->add_new_txt(
        "code.cpp",
        "int exe_ipconfig(int i,const char **t,Computer *c)\n{\n    cout<<\"本地网络配置器\"<<endl;\n    cout<<\"---------------------\"<<endl;\n    cout<<\"IPv4地址:\"<<c->netnode->ip<<endl;\n    cout<<\"默认网关:\"<<c->netnode->father->ip<<endl;\n    if (c->port_list.size()>0)"
    );
    temp->style = telnet;
       // cout<<"debug8"<<endl;

    temp=new Computer("24.120.41.20");
    tempnode->add_node(temp->netnode,true);//连接这个主机的节点
      //  cout<<"debug9"<<endl;

    //thread *looper = new thread(task_8_1_task);
    //looper->detach();

    connection_reply reply = Internet->connect(COMPUTER2);
    if (reply.computer == NULL)
    {
        cout<<"task_8_1():主机不存在"<<endl;
    }
    else
    {
        FileSystem::dir * http_dir = reply.computer->get_http_dir(21);
        if (http_dir == NULL)
        {
            cout<<"task_8_1():主机服务已关闭"<<endl;
        }
        else
        {
            http_dir->add_file(new FileSystem::file("sniffer.exe",&exe_sniffer));
        }
    }

    localhost->event_before_input = &task_8_2;
    localhost->process_event_before_input();
}

/*
void task_8_1_task()
{
    while (true)
    {
       // cout<<"debug1"<<endl;
        if (rand()%10 == 0)
        {
            connection_reply reply = Internet->connect("24.120.41.20");
            if (reply.computer)
            {
                net_node *to = reply.computer->netnode;
                to->send_package("24.120.41.10", "试图建立连接", "telnet");
                to->send_package("24.120.41.10", "校验握手", "telnet");
                to->send_package("24.120.41.10", "建立连接数据通道", "telnet");
                to->send_package("24.120.41.10", "连接成功", "TCP");
                this_thread::sleep_for(std::chrono::milliseconds(3000));
                to->send_package("24.120.41.10", "登陆:root 密码:pass_lispt202", "TCP");
            }
        }
      //  cout<<"debug2"<<endl;
        this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
*/

void task_8_2()
{
    if (rand()%5 == 0)//生成数据包
    {
        connection_reply reply = Internet->connect("24.120.41.20");
        if (reply.computer)
        {
            net_node *to = reply.computer->netnode;
            to->send_package("24.120.41.10", "试图建立连接", "telnet");
            to->send_package("24.120.41.10", "校验握手", "telnet");
            to->send_package("24.120.41.10", "建立连接数据通道", "telnet");
            to->send_package("24.120.41.10", "连接成功", "TCP");
            to->send_package("24.120.41.10", "登陆:root 密码:pass_lispt202", "TCP");
        }
    }
    if (localhost->locate_file("/data/code.cpp"))//检测文件
    {
        if (
                Internet->connect("24.120.41.0").computer->locate_file("/log/connect.log")  ||
                Internet->connect("24.120.41.0").computer->locate_file("/log/sniffer.log")  ||
                Internet->connect("24.120.41.10").computer->locate_file("/log/connect.log")
            )//是否删除了日志
        {
            game_over(1);//没删除文件则游戏结束
        }
        else
        {
            localhost->event_before_input=task_9_1;//下一关
            localhost->process_event_before_input();
        }
    }
}

void task_9_1()
{
#ifdef MAKE_SAVINGS  
    save_game_to_file("auto_created_saving_end");
#endif
    task_number = 9;
    connection_reply reply = Internet->connect(COMPUTER2);
    if (reply.computer == NULL)
    {
        cout<<"task_9_1():主机不存在"<<endl;
    }
    else
    {
        FileSystem::dir * http_dir = reply.computer->get_http_dir(21);
        if (http_dir == NULL)
        {
            cout<<"task_9_1():主机服务已关闭"<<endl;
        }
        else
        {
            http_dir->add_file(new FileSystem::file("mail2.exe",&exe_mail2));
        }
    }

    cout<<BG_RED<<"您收到一封邮件！输入mail查看"<<RESET<<endl;
    localhost->event_before_input=task_9_2;
    localhost->process_event_before_input();
}

void task_9_2(){
    if (task_added_function[task_number - 9]()){//调用对应的新的剧情函数
        //if条件成立说明函数返回true
        task_number++;//关卡号加一。这样下一次if判断条件时，会调用下一个剧情函数
        //check_and_autosave();//自动保存
    }
}

bool end_task(){//永远不会通过的任务
    return false;
}

//task10
//task_number = 9
bool task_new_1(){
    if (localhost->locate_file("/bin/mail2.exe"))//检测文件
    {
        send_mail("网络教程","nic",
            /*
            计算机网络可以分成两种：公网和子网

            比如说主机29.53.103.3就是直接连接到公网上的。我们可以用如下图示表示：
            ｜--------｜
            ｜Internet｜
            ｜--------｜
                 ｜
            29.53.103.3

            但有时主机没有直接连接到公网，比如说您的计算机就是连接到路由器：
            ｜--------｜
            ｜Internet｜
            ｜--------｜
                 ｜
            路由器（IP为188.131.133.248）
            由子网发来的数据包全部发向公网
            由公网发来的数据包全部发向192.168.0.0
                 ｜
               ------------- 子网
               ｜           ｜
            您的计算机       你们家的另一台计算机
            IP=192.168.0.0 IP=192.168.0.1
            */
            string("计算机网络可以分成两种：公网和子网\n\n")+
            "比如说主机29.53.103.3就是直接连接到公网上的。我们可以用如下图示表示：\n"+
            "｜--------｜\n"+
            "｜Internet｜\n"+
            "｜--------｜\n"+
            "     ｜\n"+
            "29.53.103.3\n\n"+
            "但有时主机没有直接连接到公网，比如说您的计算机就是连接到路由器：\n"+
            "｜--------｜\n"+
            "｜Internet｜\n"+
            "｜--------｜\n"+
            "    ｜\n"+
            "路由器（IP为188.131.133.248）\n"+
            "由子网发来的数据包全部发向公网\n"+
            "由公网发来的数据包全部发向192.168.0.0\n"+
            "     ｜\n"+
            "   ------------- 子网\n"+
            "   ｜           ｜\n"+
            "您的计算机       你们家的另一台计算机\n"+
            "IP=192.168.0.0 IP=192.168.0.1\n"
        );
        return true;
    }
    return false;//循环
}

//task_number = 10
bool task_new_2(){
    send_mail("删除博客","Fightingme",
        string("帮帮我吧！有个该死的**发了个博客骂我是**，您能不能帮我删了啊！！！\n")+
        "那个博客网站的ip是52.79.3.105，那个用户叫jiaoyy"
    );

    //临时指针
    Computer *temp;
    net_node *tempnode;
    FileSystem::dir *tempdir;

    //新建一个节点
    tempnode=new net_node("52.79.3.104");
    Internet->add_node(tempnode);
    //新建一个主机
    temp=new Computer("52.79.3.105");
    tempnode->add_node(temp->netnode,true);//连接这个主机的节点
    temp->style=telnet;
    temp->password="123456";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->username="mainserver";
    temp->locate_dir("/data")->add_new_dir("web");
    tempdir = temp->locate_dir("/data/web");
    tempdir->add_new_txt("网络说明.txt","数据库服务器(用户root，密码no_one_know_this)：\n192.168.0.1\n192.168.0.2");
    tempdir->add_new_dir("doc");
    tempdir = temp->locate_dir("/data/web/doc");
    tempdir->add_new_txt("index.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("login.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("blog.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user_profile.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    

    temp=new Computer("192.168.0.1");
    tempnode->add_node(temp->netnode,false);//连接这个主机的节点
    temp->style=telnet;
    temp->password="no_one_know_this";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->name="db1";
    tempdir=temp->locate_dir("/data");
    tempdir->add_new_txt("user_profile_1.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user_profile_2.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user_profile_3.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user_profile_4.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user_profile_为节约空间省略1867个文件.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user_profile_1872.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");


    temp=new Computer("192.168.0.2");
    tempnode->add_node(temp->netnode,false);//连接这个主机的节点
    temp->style=telnet;
    temp->password="no_one_know_this";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->name="db2";
    temp->locate_dir("/data")->add_new_dir("blogs");
    tempdir = temp->locate_dir("/data/blogs");
    tempdir->add_new_txt("jiaoyy_blog1.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("jiaoyy_blog2.txt","Fightingme这个**，我******（不文明的语言此处遮挡）");
    tempdir->add_new_txt("jiaoyy_blog3.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("sfehuhu_blog1.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("为节约空间省略92784个文件.txt","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");

    return true;
}

//task_number = 11
bool task_new_3(){
    Computer * temp = Internet->connect("52.79.3.104").node->connect("192.168.0.2").computer;
    if(!(temp->locate_file("/data/blogs/jiaoyy_blog2.txt"))){
        if(temp->locate_file("/log/connect.log")||
           Internet->connect("52.79.3.104").node->connect("52.79.3.105").computer->locate_file("/log/connect.log")||
           Internet->connect("52.79.3.104").node->connect("192.168.0.1").computer->locate_file("/log/connect.log")){
            game_over(1);
            return false;
        }else{
            send_mail("[通关]删除那个该死的玩意","Fightingme","谢谢！");
            return true;//下一个剧情函数
        }
    }else{
        return false;
    }
}

//task11
//task_number = 12
bool task_new_4(){
    send_mail("帮个忙呗","lzq",
        string("我听我一个同学说，你会黑客技术。我觉得你可以帮我个忙\n")+
        "我语文特别差，每次都考不及格。要期末考试了，您，尊敬的"+localhost->username+"，能不能帮我弄到我们考试卷子\n"+
        "我们学校总的IP是43.52.120.9，但是学校有好多电脑，我也不知道语文办公室电脑的内网IP。但办公室在三楼308"
    );

    //临时指针
    Computer *temp;
    net_node *tempnode;
    FileSystem::dir *tempdir;

    //新建一个节点
    tempnode=new net_node("43.52.120.0");
    Internet->add_node(tempnode);


    //新建一个主机
    temp=new Computer("43.52.120.9");
    tempnode->add_node(temp->netnode,true);//连接这个主机的节点
    temp->style=telnet;
    temp->password="8848";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->name="ssf_school_web_server";
    temp->locate_dir("/data")->add_new_dir("web");
    temp->locate_dir("/data")->add_new_dir("files");
    tempdir = temp->locate_dir("/data/web");
    tempdir->add_new_dir("doc");
    tempdir = temp->locate_dir("/data/web/doc");
    tempdir->add_new_txt("index.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("login.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("data.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir->add_new_txt("user.php","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    tempdir = temp->locate_dir("/data/files");
    tempdir->add_new_txt("校长讲话.mp4","这个文件与游戏无关\n[TODO]谁愿意为GHG作贡献的可以帮助把这里补上内容:)，我是懒得写了");
    temp->locate_dir("/data")->add_new_txt("note.txt","各个办公室只有一个计算机可由内网访问，IP的命名规则是这样的：第n层的第m个房间的ip为192.168.n.m\n如，办公室204的IP是192.168.2.4，213的IP是192.168.2.13，等等\n用户名都是admin，密码为空");

    //新建一个主机
    temp=new Computer("192.168.3.8");
    tempnode->add_node(temp->netnode,false);//连接这个主机的节点
    temp->style=telnet;
    temp->password="";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->username="admin";
    temp->name="语文办公室主机";
    temp->locate_dir("/data")->add_new_dir("teaching");
    temp->locate_dir("/data/teaching")->add_new_dir("ppt");
    temp->locate_dir("/data/teaching")->add_new_dir("doc");
    temp->locate_dir("/data/teaching/doc")->add_new_txt("论语.txt","子曰：”学而不思则罔，思而不学则怠“");
    temp->locate_dir("/data/teaching/doc")->add_new_txt("final_exam.doc","本试卷共999道大题，9999道小题，总计100000分。考试时间共三天。第一大题：基础与运用……");
    
    
    return true;
}

//task_number = 13
bool task_new_5(){
    if(localhost->locate_file("/data/final_exam.doc")){
        if(Internet->connect("43.52.120.0").node->connect("43.52.120.9").computer->locate_file("/log/connect.log")||
           Internet->connect("43.52.120.0").node->connect("192.168.3.8").computer->locate_file("/log/connect.log")){
            game_over(1);
            return false;
        }else{
            send_mail("[通关]该死的期末考试","李梓淇","谢谢！不过，这卷子。。。题可真多");
            return true;//下一个剧情函数
        }
    }else{
        return false;
    }
}

//task12
//task_number = 14
bool task_new_6(){
    send_mail("入侵C站","张子辰",string("同学！我听说你擅长黑客技术。我现在遇到了一个该死的麻烦，希望你帮我解决一下。\n")
                +"有一个人社区名叫李萨碧，id是43689021。他把我做的作品Survive当成自己的作品发布，正常情况下我可以举报他，但这次他先骗到了最新版Survive的代码，然后自己先发到社区上。我自己发出来后，他不但不承认这个版本是我做的，还把我举报了。\n"
                +"你是黑客，黑客要主持正义。你帮我黑入C站，并且把这个人的作品删掉。\n"
                +"有关信息：\n"
                +"   C站网址：code.xueersi.com\n"
                +"   李萨碧的id：43689021\n"
                +"   要删除的作品的id：4110506\n"
                +"提示：\n"
                +"   可能需要使用scp -u"
    );

    //临时指针
    Computer *temp;
    net_node *tempnode;
    FileSystem::dir *tempdir;

    net_node::add_dns_map("code.xueersi.com","61.135.179.238");

    //新建一个主机
    temp=new Computer("61.135.179.238");
    tempnode = temp->netnode;
    Internet->add_node(temp->netnode);
    temp->style=telnet;
    temp->password="123456";//设密码
    temp->open_port("telnet",600);//打开端口
    temp->name="smart_firewall";
    temp->locate_dir("/data")->add_new_dir("firewall_config");
    temp->locate_dir("/data/firewall_config")->add_new_txt("port_map.config","#这个文件是对防火墙的设置\n#第一项是子网主机地址，后面两项是子网主机端口和外网端口\n#NULL表示拒绝外网访问\n172.0.0.1 23 600\n192.168.0.1 80 80\n192.168.0.2 NULL\n192.168.0.3 NULL");

    //新建一个主机
    temp=new Computer("192.168.0.1");
    tempnode->add_node(temp->netnode);
    temp->style=telnet;
    temp->password="password0abc";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->locate_dir("/data")->add_new_dir("web");
    temp->locate_dir("/data/web")->add_new_txt("【说明】.txt","这个文件与游戏无关！");
    temp->locate_dir("/data")->add_new_dir("config");
    temp->locate_dir("/data/config")->add_new_txt("vm_host.config","#对虚机服务器的配置文件\n[vm_host]\naddress=192.168.0.2\nvcn_port=72");
    temp->locate_dir("/data/config")->add_new_txt("db_host.config","#对社区数据服务器的配置文件\n[db_host]\naddress=192.168.0.3\nmysql_port=3306");

    //新建一个主机
    temp=new Computer("192.168.0.2");
    tempnode->add_node(temp->netnode);
    temp->style=telnet;
    temp->password="password0abc";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->locate_dir("/data")->add_new_dir("machines");
    temp->locate_dir("/data/machines")->add_new_dir("lib");
    temp->locate_dir("/data/machines/lib")->add_new_txt("【说明】.txt","这个文件与游戏无关！");
    temp->locate_dir("/data/machines")->add_new_dir("temp_data");
    temp->locate_dir("/data/machines/temp_data")->add_new_txt("彩蛋.txt","你找到了一个彩蛋");

    //新建一个主机
    temp=new Computer("192.168.0.3");
    tempnode->add_node(temp->netnode);
    temp->style=telnet;
    temp->password="password0abc";//设密码
    temp->open_port("telnet",23);//打开端口
    temp->locate_dir("/data")->add_new_dir("database");
    temp->locate_dir("/data/database")->add_new_dir("user");
    temp->locate_dir("/data/database")->add_new_dir("projects");
    temp->locate_dir("/data/database/user")->add_new_txt("userconfig.sql","这个文件与游戏无关！");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110500.xml","#此处省略一大堆数据\n......");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110501.xml","#此处省略一大堆数据\n......");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110502.xml","彩蛋！");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110503.xml","#此处省略一大堆数据\n......");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110504.xml","#此处省略一大堆数据\n......");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110505.xml","#此处省略一大堆数据\n......");
    temp->locate_dir("/data/database/projects")->add_new_txt("pid_4110506.xml","<project id=4110506>\n<author>李萨碧</author>\n......");
    temp->locate_dir("/data/database/projects")->add_new_txt("此处省略一大堆数据.txt","此处省略一大堆数据");
    return true;
}

bool task_new_7(){
    if(!(Internet->connect("code.xueersi.com").node->connect("192.168.0.3").computer->locate_file("/data/database/projects/pid_4110506.xml"))){
        if(Internet->connect("code.xueersi.com").computer->locate_file("/log/connect.log")||
           Internet->connect("code.xueersi.com").computer->locate_file("/log/telnet.log")||
           Internet->connect("code.xueersi.com").computer->locate_file("/data/passguesser.exe")||
           Internet->connect("code.xueersi.com").node->connect("192.168.0.1").computer->locate_file("/log/connect.log")||
           Internet->connect("code.xueersi.com").node->connect("192.168.0.2").computer->locate_file("/log/connect.log")||
           Internet->connect("code.xueersi.com").node->connect("192.168.0.3").computer->locate_file("/log/connect.log")){
            game_over(1);
            return false;
        }else{
            send_mail("[通关]入侵C站","张子辰","你成功了维持了正义！");
            send_mail("[活动]寻找彩蛋","Nictheboy","本关中有三个彩蛋！请你仔细寻找，找到后回复我！\n有神秘大奖！");
            return true;//下一个剧情函数
        }
    }else{
        return false;
    }
}

bool task_new_8(){
    return false;
}

bool task_new_9(){
    return false;//永远不会通关
}

void jump_through_task(int index){
    if(index>=9){
        if (index > 9){
            jump_through_task(index-1);
        }
        switch(index){
        case 9:
            localhost->locate_dir("/bin")->add_file(new FileSystem::file("mail2.exe",&exe_mail2));
            task_number = 9;
            localhost->event_before_input=task_9_2;
            //localhost->process_event_before_input();
            break;
        case 10:
            task_number = 12;
            /*
            send_mail("网络教程","nic",
                    string("计算机网络可以分成两种：公网和子网\n\n")+
                    "比如说主机29.53.103.3就是直接连接到公网上的。我们可以用如下图示表示：\n"+
                    "｜--------｜\n"+
                    "｜Internet｜\n"+
                    "｜--------｜\n"+
                    "     ｜\n"+
                    "29.53.103.3\n\n"+
                    "但有时主机没有直接连接到公网，比如说您的计算机就是连接到路由器：\n"+
                    "｜--------｜\n"+
                    "｜Internet｜\n"+
                    "｜--------｜\n"+
                    "    ｜\n"+
                    "路由器（IP为188.131.133.248）\n"+
                    "由子网发来的数据包全部发向公网\n"+
                    "由公网发来的数据包全部发向192.168.0.0\n"+
                    "     ｜\n"+
                    "   ------------- 子网\n"+
                    "   ｜           ｜\n"+
                    "您的计算机       你们家的另一台计算机\n"+
                    "IP=192.168.0.0 IP=192.168.0.1\n"
            ,false);
            send_mail("删除博客","Fightingme",
                string("帮帮我吧！有个该死的**发了个博客骂我是**，您能不能帮我删了啊！！！\n")+
                "那个博客网站的ip是52.79.3.105，那个用户叫jiaoyy",false
            );
            send_mail("[通关]删除那个该死的玩意","Fightingme","谢谢！",false);
            */
            break;
        case 11:
            /*
            send_mail("帮个忙呗","lzq",
                string("我听我一个同学说，你会黑客技术。我觉得你可以帮我个忙\n")+
                "我语文特别差，每次都考不及格。要期末考试了，您，尊敬的"+localhost->username+"，能不能帮我弄到我们考试卷子\n"+
                "我们学校总的IP是43.52.120.9，但是学校有好多电脑，我也不知道语文办公室电脑的内网IP。但办公室在三楼308"
            ,false);
            send_mail("[通关]该死的期末考试","李梓淇","谢谢！不过，这卷子。。。题可真多",false);
            */
            task_number = 14;
            break;
        default:
            cout<<"ERROR:jump_through_task(int index):关卡不存在"<<endl;
            break;
        }
    }else{
        cout<<"ERROR:jump_through_task(int index):index<9"<<endl;
    }
}

#include "hackgame.h"

//启动时显示logo
void logo()
{
    /*旧版logo
    cout<<"#####################\n";
    cout<<"#                   #\n";
    //cout<<"#    梦时工作室     #\n";
    //cout<<"#   QQ:1046228226   #\n";
    cout<<"#作者的QQ:2492515121 #\n";
    //cout<<"#    "<<BG_RED<<"我QQ被封号了"<<RESET<<"   #\n";
    cout<<"#                   #\n";
    cout<<"#####################\n";
    cout<<"～～-------------～～\n";
    cout<<"｜   黑 客 游 戏   ｜\n";
    //cout<<"｜   学而思原版    ｜\n";
    cout<<"｜  2000行 实力版  ｜\n";
    cout<<"｜欢迎各位引用/模仿｜\n";
    cout<<"～～ ---------- ～～\n";
    cout<<PROGRAM_INFO<<endl;
    cout<<"该 版 本 暂 未 全 部 完 成 ！\n";
    */
    cout<<"(c) 2020, Ink, Nictheboy. All rights reserved.\n";
    ChangeColor(GREEN);
    cout<<"        -----#####------#--------#--------#####------\n";
    cout<<"       ----#-----#-----#--------#-------#-----#-----\n";
    cout<<"      ---#------------#--------#------#------------\n";
    cout<<"     ---#------------##########------#------------\n";
    cout<<"    ---#--######----#--------#------#--######----\n";
    cout<<"   ---#-----#------#--------#------#-----#------\n";
    cout<<"  ----#----#------#--------#-------#----#------\n";
    cout<<" -----#####------#--------#--------#####------\n";
    ChangeColor(RESET);
    cout << "版本: GHG V2.0.0 Release\n";
    //cout<<"GHG：HackGame\n";
    /*cout<<"作者：Nictheboy, Ink.\n作者QQ：2492515121（搞技术的）（Nictheboy）"
      << ", 2492515121 （Ink.）\n\n";
    cout<<"感谢 梦时工作室 和 Easeye工作室 提供的支持！\n";*/
    ChangeColor(CYAN);
    cout << "请按回车键进入游戏：\n";
    ChangeColor(RESET);
    int tmp = getchar();
}
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

// 景点的类
struct Attractions
{
    int at_number;           // 景观自身的编号
    string at_name, at_type; // 名称 & 种类
    int x, y;                // 表述位置
    int save;                // 维护方式
};

// 收集和保存维护信息
struct Save
{
    int save_number;          // 维护信息自身的编号
    int at_number;            // 维护的景点编号
    int sa_type;              // 维护的种类
    string finisher;          // 维护的完成人
    int sa_x = -1, sa_y = -1; // 维护的位置
                              // 默认-1，表示没有输入位置
    string sa_data;           // 维护的日期
    int cost;                 // 本次维护的费用
};

// 消防设施的具体信息
struct Fire
{
    int fi_number;  // 消防设施的编号
    int fi_type;    // 消防设施的种类
    int fi_size;    // 消防设施的数量
    int fi_x, fi_y; // 消防设施的位置
    int fi_state;   // 消防设施的状态 用0——9的数字来表示设施完好程度
};

struct Tourist
{
    int to_number;  // 游客编号
    int to_sex;     // 游客性别
    int to_age;     // 游客年龄段
    string at_name; // 所去景点
    int to_type;    // 游玩方式
    int to_time;    // 游玩时长
};

struct Fin
{
    int in = 0;
    int out = 0;
} all_fin;

struct User
{
    int user_number; // 员工编号
    int pa;          // 员工账号登陆密码
    bool n1 = false; // 表示管理员的权限
    bool n2 = false; // 表示操作员的权限
    bool n3 = false; // 表示财务人员的权限
};

// map用来储存密码
// 当前设置编号不能大于1e5，可根据实际需求进行修改
set<int> all_user;
vector<User> user_op(100001);

set<int> at_number;
vector<Attractions> At(100001);

set<int> sa_number;
vector<Save> Sa(100001);

set<int> to_number;
vector<Tourist> To(100001);

set<int> fi_number;
vector<Fire> Fi(100001);

// 默认 0：未成年人散客，1：成年人散客，2：老年人散客，3：团体票价;
// 单位为元/小时
int price[4] = {30, 40, 20, 15};

// 默认员工编号为1的人为管理员
// 密码为114514
void make_data()
{
    FILE *p;

    // 初始化员工列表
    p = fopen("list_user.dat", "w+");
    all_user.insert(1);
    user_op[1].user_number = 1;
    user_op[1].n1 = true;
    user_op[1].pa = 114514;
    fwrite(&user_op[1], 1, sizeof(struct User), p);
    fclose(p);
    // 初始化维护信息
    remove("list_sa.dat");
    p = fopen("list_sa.dat", "w+");
    fclose(p);
    // 初始化景观列表
    remove("list_at.dat");
    p = fopen("list_at.dat", "w+");
    fclose(p);
    // 初始化消防设施
    remove("list_fi.dat");
    p = fopen("list_fi.dat", "w+");
    fclose(p);
    // 初始化游客信息
    remove("list_to.dat");
    p = fopen("list_to.dat", "w+");
    fclose(p);
    // 初始化财政信息
    remove("list_fin.dat");
    p = fopen("list_fin.dat", "w+");
    fclose(p);
}

void read_from_data()
{
    FILE *p;

    p = fopen("list_user.dat", "r");
    if (p == NULL)
    {
        cout << "文件打开错误，正在初始化用户信息------------" << '\n';
        make_data();
        cout << "用户信息初始化成功" << '\n';
        cout << "请重新选择你的操作" << '\n';
        return;
    }
    else
    {
        // 读取用户权限信息;
        User xx;
        while (fread(&xx, 1, sizeof(struct User), p))
        {
            user_op[xx.user_number].user_number = xx.user_number;
            user_op[xx.user_number].pa = xx.pa;
            user_op[xx.user_number].n1 = xx.n1;
            user_op[xx.user_number].n2 = xx.n2;
            user_op[xx.user_number].n3 = xx.n3;
            all_user.insert(xx.user_number);
        }
        cout << "用户信息读取完成" << '\n';
    }
    // 读取景观信息;
    p = fopen("list_at.dat", "r");
    if (p == NULL)
    {
        cout << "ERROR:景观信息读取失败" << '\n';
    }
    else
    {
        Attractions xx;
        while (fread(&xx, 1, sizeof(struct Attractions), p))
        {
            At[xx.at_number].at_number = xx.at_number;
            At[xx.at_number].at_name = xx.at_name;
            At[xx.at_number].at_type = xx.at_type;
            At[xx.at_number].save = xx.save;
            At[xx.at_number].x = xx.x;
            At[xx.at_number].y = xx.y;
            at_number.insert(xx.at_number);
        }
        cout << "景观信息读取成功" << '\n';
        fclose(p);
    }

    // 读取维护信息
    p = fopen("list_sa.dat", "r");
    if (p == NULL)
    {
        cout << "ERROR:维护信息读取失败" << '\n';
    }
    else
    {
        Save xx;
        while (fread(&xx, 1, sizeof(struct Save), p))
        {
            Sa[xx.save_number].save_number = xx.save_number;
            Sa[xx.save_number].at_number = xx.at_number;
            Sa[xx.save_number].cost = xx.cost;
            Sa[xx.save_number].finisher = xx.finisher;
            Sa[xx.save_number].sa_data = xx.sa_data;
            Sa[xx.save_number].sa_type = xx.sa_type;
            Sa[xx.save_number].sa_x = xx.sa_x;
            Sa[xx.save_number].sa_y = xx.sa_y;
            sa_number.insert(xx.save_number);
        }
        cout << "景观信息读取成功" << '\n';
        fclose(p);
    }

    // 读取游客信息
    p = fopen("list_to.dat", "r");
    if (p == NULL)
    {
        cout << "游客信息读取失败" << '\n';
    }
    else
    {
        Tourist xx;
        while (fread(&xx, 1, sizeof(struct Tourist), p))
        {
            To[xx.to_number].to_number = xx.to_number;
            To[xx.to_number].at_name = xx.at_name;
            To[xx.to_number].to_age = xx.to_age;
            To[xx.to_number].to_sex = xx.to_sex;
            To[xx.to_number].to_time = xx.to_time;
            To[xx.to_number].to_type = xx.to_type;
            to_number.insert(xx.to_number);
        }
        cout << "游客信息读取成功" << '\n';
        fclose(p);
    }

    // 读取消防设施信息
    p = fopen("list_fi.dat", "r");
    if (p == NULL)
    {
        cout << "消防设施信息读取失败" << '\n';
    }
    else
    {
        Fire xx;
        while (fread(&xx, 1, sizeof(struct Fire), p))
        {
            Fi[xx.fi_number].fi_number = xx.fi_number;
            Fi[xx.fi_number].fi_size = xx.fi_size;
            Fi[xx.fi_number].fi_state = xx.fi_state;
            Fi[xx.fi_number].fi_type = xx.fi_type;
            Fi[xx.fi_number].fi_x = xx.fi_x;
            Fi[xx.fi_number].fi_y = xx.fi_y;
            fi_number.insert(xx.fi_number);
        }
        cout << "消防设施信息读取成功" << '\n';
        fclose(p);
    }
}

// 保存所有更新的信息，再退出系统
void Save_data()
{
    cout << "正在保存更改，请不要关闭窗口" << '\n';
    cout << "--------------------------" << '\n';
    FILE *p;

    p = fopen("list_user.dat", "w+");
    for (auto it : all_user)
    {
        fwrite(&user_op[it], 1, sizeof(struct User), p);
    }
    fclose(p);

    p = fopen("list_at.dat", "w+");
    for (auto it : at_number)
    {
        fwrite(&At[it], 1, sizeof(struct Attractions), p);
    }
    fclose(p);

    p = fopen("list_sa.dat", "w+");
    for (auto it : sa_number)
    {
        fwrite(&Sa[it], 1, sizeof(struct Save), p);
    }
    fclose(p);

    p = fopen("list_to.dat", "w+");
    for (auto it : to_number)
    {
        fwrite(&To[it], 1, sizeof(struct Tourist), p);
    }
    fclose(p);

    p = fopen("list_fi.dat", "w+");
    for (auto it : fi_number)
    {
        fwrite(&Fi[it], 1, sizeof(struct Fire), p);
    }
    fclose(p);

    p = fopen("list_fin.dat", "w+");
    fwrite(&all_fin, 1, sizeof(struct Fin), p);
    fclose(p);

    cout << "------------------------" << '\n';
    Sleep(300);
    cout << "保存更改完毕，可以关闭窗口" << '\n';
}

// 增删改查用户
inline void user1()
{
    int Type;
    cout << "请选择你想进行的操作：" << '\n';
    cout << "1:增加新用户" << '\n';
    cout << "2:删除用户" << '\n';
    cout << "3:修改用户权限" << '\n';
    cout << "4:查询用户" << '\n';
    cout << "5:退出系统" << '\n';
    cin >> Type;
    int number;
    while (Type != 5)
    {
        if (Type == 1)
        {
            cout << "请输入你想增加的用户编号" << '\n';
            cin >> number;

            // 未找到该员工编号
            while (number != -1 && (number > 1e5 || all_user.find(number) != all_user.end()))
            {
                Sleep(100);
                if (number > 1e5)
                {
                    cout << "输入的编号格式错误,请重新输入用户编号" << '\n';
                }
                else
                {
                    cout << "该用户编号已存在,请重新输入用户编号" << '\n';
                }
                cout << "或输入-1退出该系统" << '\n';
                cin >> number;
            }

            if (number == -1)
            {
                cout << "添加失败" << '\n';
            }
            else
            {
                all_user.insert(number);
                int P1 = 1, P2 = -1;
                cout << "请输入登陆密码:" << '\n';
                cin >> P1;
                cout << "请再次输入登陆密码" << '\n';
                cin >> P2;
                while (P1 != P2)
                {
                    cout << "输入错误,请重新输入" << '\n';
                    cout << '\n';
                    cout << "请输入登陆密码:" << '\n';
                    cin >> P1;
                    cout << "请再次输入登陆密码" << '\n';
                    cin >> P2;
                }
                user_op[number].pa = P1;
                user_op[number].user_number = number;
                cout << "增加成功" << '\n';
            }
        }
        else if (Type == 2)
        {
            cout << "请输入你想删除的用户编号" << '\n';
            cin >> number;

            // 未找到该员工编号
            while (number != -1 && (number > 10000 || all_user.find(number) == all_user.end()))
            {
                Sleep(100);
                if (number > 10000)
                {
                    cout << "你输入的用户编号格式错误,请重新输入" << '\n';
                }
                else
                {
                    cout << "未找到你想删除的用户编号,请重新输入" << '\n';
                }
                cout << "或输入-1退出该系统" << '\n';
                cin >> number;
            }

            if (number == -1)
            {
                cout << "退出删除系统成功" << '\n';
            }
            else
            {
                // 在人员名单中删除
                all_user.erase(number);
                // 初始化权限
                user_op[number].n1 = false;
                user_op[number].n2 = false;
                user_op[number].n3 = false;
                cout << "删除成功" << '\n';
            }
        }
        else if (Type == 3)
        {
            cout << "请输入你想修改权限的用户编号" << '\n';
            cin >> number;

            while (number != -1 && (number > 10000 || all_user.find(number) == all_user.end()))
            {
                Sleep(100);
                if (number > 10000)
                {
                    cout << "你输入的用户编号格式错误,请重新输入" << '\n';
                }
                else
                {
                    cout << "未找到你想修改的用户编号,请重新输入" << '\n';
                }
                cout << "或输入-1退出该系统" << '\n';
                cin >> number;
            }

            if (number == -1)
            {
                cout << "权限修改失败" << '\n';
            }
            else
            {
                // m表示修改操作类型，n表示要修改的权限类型
                int m, n;
                cout << "请选择你要进行的修改操作" << '\n';
                cout << "1:删除用户权限" << '\n';
                cout << "2:赋予用户权限" << '\n';
                cout << "3:退出该系统" << '\n';
                cin >> m;
                while (m != 3)
                {
                    cin >> n;
                    if (m == 1)
                    {
                        if (n == 1)
                        {
                            user_op[number].n1 = false;
                        }
                        else if (n == 2)
                        {
                            user_op[number].n2 = false;
                        }
                        else
                        {
                            user_op[number].n3 = false;
                        }
                    }
                    else if (m == 2)
                    {
                        if (n == 1)
                        {
                            user_op[number].n1 = true;
                        }
                        else if (n == 2)
                        {
                            user_op[number].n2 = true;
                        }
                        else
                        {
                            user_op[number].n3 = true;
                        }
                    }
                    Sleep(100);
                    cout << "操作成功，请继续选择你的修改操作" << '\n';
                    cout << "1:删除用户权限" << '\n';
                    cout << "2:赋予用户权限" << '\n';
                    cout << "3:退出该系统" << '\n';
                    cin >> m;
                }
                cout << "权限修改成功" << '\n';
            }
        }
        else if (Type == 4)
        {
            cout << "请输入你想查询的用户编号" << '\n';
            cin >> number;

            while (number != -1 && (number > 10000 || all_user.find(number) == all_user.end()))
            {
                Sleep(100);
                if (number > 10000)
                {
                    cout << "你输入的用户编号格式错误,请重新输入" << '\n';
                }
                else
                {
                    cout << "未找到你想查询的用户编号,请重新输入" << '\n';
                }
                cout << "或输入-1退出该系统" << '\n';
                cin >> number;
            }

            if (number == -1)
            {
                cout << "查询失败" << '\n';
            }
            else
            {
                cout << "用户:" << number << '\n';

                // 默认管理员拥有所有权限;
                if (user_op[number].n1)
                {
                    cout << "管理员权限:是" << '\n';
                    cout << "操作员权限:是" << '\n';
                    cout << "财务人员权限:是" << '\n';
                }
                else
                {
                    cout << "管理员权限:否\n";
                    cout << "操作员权限:";
                    user_op[number].n2 ? cout << "是" : cout << "否";
                    cout << '\n';
                    cout << "财务人员权限:";
                    user_op[number].n3 ? cout << "是" : cout << "否";
                    cout << '\n';
                    cout << "查询完成" << '\n';
                }
            }
        }

        Sleep(300);
        cout << "操作完成,请继续选择你的操作" << '\n';
        cout << "请选择你想进行的操作：" << '\n';
        cout << "1:增加新用户" << '\n';
        cout << "2:删除用户" << '\n';
        cout << "3:修改用户权限" << '\n';
        cout << "4:查询用户" << '\n';
        cout << "5:退出系统" << '\n';
        cin >> Type;
    }
    cout << "退出成功" << '\n';
}

// 分配权限
inline void user2()
{
    cout << "进入权限分配系统成功,请输入你要修改权限的员工编号" << '\n';
    int number;
    cin >> number;

    while (number != -1 && (number > 10000 || all_user.find(number) == all_user.end()))
    {
        Sleep(100);
        if (number < 10000)
        {
            cout << "你输入的用户编号格式错误,请重新输入" << '\n';
        }
        else
        {
            cout << "未找到你想修改权限的员工编号,请重新输入" << '\n';
        }
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }
    if (number == -1)
    {
        cout << "分配权限失败" << '\n';
    }
    else
    {
        cout << "成功找到该人员编号" << '\n';
        int m, n;
        Sleep(100);
        cout << "请选择你要进行的修改操作" << '\n';
        cout << "1:删除用户权限" << '\n';
        cout << "2:赋予用户权限" << '\n';
        cout << "3:退出该系统" << '\n';
        cin >> m;
        while (m != 3)
        {
            cout << "请输入你要修改的具体权限：" << '\n';
            cout << "1:管理员权限" << '\n';
            cout << "2:操作员权限" << '\n';
            cout << "3:财务人员权限" << '\n';
            cin >> n;
            if (m == 1)
            {
                if (n == 1)
                {
                    user_op[number].n1 = false;
                }
                else if (n == 2)
                {
                    user_op[number].n2 = false;
                }
                else
                {
                    user_op[number].n3 = false;
                }
            }
            else if (m == 2)
            {
                if (n == 1)
                {
                    user_op[number].n1 = true;
                }
                else if (n == 2)
                {
                    user_op[number].n2 = true;
                }
                else
                {
                    user_op[number].n3 = true;
                }
            }
            Sleep(100);
            cout << "权限修改成功" << '\n';
            cout << "请继续选择你的修改操作" << '\n';
            cout << "1:删除用户权限" << '\n';
            cout << "2:赋予用户权限" << '\n';
            cout << "3:退出该系统" << '\n';
            cin >> m;
        }
    }
    cout << "退出权限修改系统成功" << '\n';
}

inline void add_At()
{
    Attractions x;
    int number;
    cout << "请输入要添加的景观编号:\n";
    cin >> number;
    while (number != -1 && (number > 1e5 || at_number.find(number) != at_number.end()))
    {
        Sleep(100);
        if (number > 1e5)
        {
            cout << "输入格式错误,请重新输入景观编号" << '\n';
        }
        else
        {
            cout << "该编号已经存在,请重新输入景观编号" << '\n';
        }
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }
    if (number == -1)
    {
        cout << "添加失败" << '\n';
    }
    else
    {
        At[number].at_number = number;
        cout << "请输入景观名称:\n";
        cin >> At[number].at_name;
        cout << "请输入景观种类:\n";
        cout << "1:亭 2:湖 3:山 4:草坪 5:路 6:庙 7:林" << '\n';
        cin >> At[number].at_type;
        cout << "请输入景观坐标:x,y\n";
        cin >> At[number].x >> At[number].y;
        cout << "请输入维护方式:\n";
        cout << "1:扫 2:擦 3:喷 4:剪 5:修" << '\n';
        cin >> At[number].save;
        Sleep(100);
        cout << "添加成功" << '\n';
    }
}

inline void change_At()
{
    int number;
    cout << "请输入要修改的景观编号" << '\n';
    cin >> number;
    while (number != -1 && (at_number.find(number) == at_number.end() || number > 10000))
    {
        Sleep(100);
        if (number > 10000)
        {
            cout << "输入格式错误，请重新输入景观编号" << "\n";
        }
        else
        {
            cout << "未找到要修改的景观编号,请重新输入景观编号" << '\n';
        }
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }
    if (number == -1)
    {
        cout << "修改失败" << '\n';
    }
    else
    {
        cout << "景观查找成功" << '\n';
        Sleep(100);
        int ch;
        cout << "请输入你要修改的元素:" << '\n';
        cout << "1:景观名称" << '\n';
        cout << "2:景观种类" << '\n';
        cout << "3:景观位置" << '\n';
        cout << "4:景观维护方式" << '\n';
        cout << "5:退出该系统" << '\n';
        cin >> ch;
        while (ch != 5)
        {
            if (ch == 1)
            {
                cout << "请输入更改后的名称:" << '\n';
                cin >> At[number].at_name;
            }
            else if (ch == 2)
            {
                cout << "请输如更改后的种类:" << '\n';
                cout << "1:亭 2:湖 3:山 4:草坪 5:路 6:庙 7:林" << '\n';
                cin >> At[number].at_type;
            }
            else if (ch == 3)
            {
                cout << "请输入更改后的景观位置:x,y" << '\n';
                cin >> At[number].x >> At[number].y;
            }
            else if (ch == 4)
            {
                cout << "请输入更改后的维护方式:" << '\n';
                cin >> At[number].save;
            }

            Sleep(100);
            cout << "操作完成，请选择你的下一步要修改的内容" << '\n';
            cout << "1:景观名称" << '\n';
            cout << "2:景观种类" << '\n';
            cout << "3:景观位置" << '\n';
            cout << "4:景观维护方式" << '\n';
            cout << "5:退出该系统" << '\n';
            cin >> ch;
        }
        cout << "退出景观修改系统成功" << '\n';
    }
}

inline void del_At()
{
    int number;
    cout << "请输入要删除的景观编号:" << '\n';
    cin >> number;
    while (number != -1 && at_number.find(number) == at_number.end())
    {
        Sleep(100);
        cout << "未查询到该景观编号,请重新输入景观编号" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }
    if (number == -1)
    {
        cout << "删除失败" << '\n';
    }
    else
    {
        at_number.erase(number);
        cout << "删除成功" << '\n';
    }
}

inline void user3_At()
{
    int Type;
    cout << "请选择你要进行的操作:" << '\n';
    cout << "1:添加新的景观信息" << '\n';
    cout << "2:修改原有的景观信息" << '\n';
    cout << "3:删除景观信息" << '\n';
    cout << "4:退出该系统" << '\n';
    cin >> Type;
    while (Type != 4)
    {
        if (Type == 1)
        {
            add_At();
        }
        else if (Type == 2)
        {
            change_At();
        }
        else if (Type == 3)
        {
            del_At();
        }

        Sleep(100);
        cout << "操作成功,请继续选择你要进行的操作" << '\n';
        cout << "1:添加新的景观信息" << '\n';
        cout << "2:修改原有的景观信息" << '\n';
        cout << "3:删除景观信息" << '\n';
        cout << "4:退出该系统" << '\n';
        cin >> Type;
    }
    cout << "退出系统成功" << '\n';
}

inline void add_Fi()
{
    int number;
    cout << "请输入要添加的消防设施编号:\n";
    cin >> number;
    while (number != -1 && (number > 1e5 || fi_number.find(number) != fi_number.end()))
    {
        if (number > 1e5)
        {
            cout << "输入格式错误,请重新输入消防设施编号" << '\n';
        }
        else
        {
            cout << "该编号已经存在,请重新输入消防设施编号" << '\n';
        }
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }
    if (number == -1)
    {
        cout << "添加失败" << '\n';
    }
    else
    {
        Fi[number].fi_number = number;
        cout << "请输入消防设施种类:\n";
        cout << "1:消火栓 2:水桶 3:消防车" << '\n';
        cin >> Fi[number].fi_type;
        cout << "请输入消防设施的数量" << '\n';
        cin >> Fi[number].fi_size;
        cout << "请输入消防设施坐标:x,y\n";
        cin >> Fi[number].fi_x >> Fi[number].fi_y;
        cout << "请输入消防设施的状态:\n";
        cout << "1:完好 2:轻微损坏 3:严重损坏" << '\n';
        cin >> Fi[number].fi_state;
        cout << "添加成功" << '\n';
    }
}

inline void change_Fi()
{
    int number;
    cout << "请输入要修改的消防设施编号:" << '\n';
    cin >> number;
    while (number != -1 && fi_number.find(number) == fi_number.end())
    {
        cout << "未找到你要修改的消防设施编号,请重新输入" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }
    if (number == -1)
    {
        cout << "修改失败" << '\n';
    }
    else
    {
        int ch;
        cout << "请输入你要修改的元素:" << '\n';
        cout << "1:修改消防设施的种类" << '\n';
        cout << "2:修改消防设施的数量" << '\n';
        cout << "3:修改消防设施的位置" << '\n';
        cout << "4:修改消防设施的状态" << '\n';
        cout << "5:退出该系统" << '\n';
        cin >> ch;
        while (ch != 5)
        {
            if (ch == 1)
            {
                cout << "请输如更改后的种类:" << '\n';
                cout << "1:消火栓 2:水桶 3:消防车" << '\n';
                cin >> Fi[number].fi_type;
            }
            else if (ch == 2)
            {
                cout << "请输入更改后的数量" << '\n';
                cin >> Fi[number].fi_size;
            }
            else if (ch == 3)
            {
                cout << "请输入更改后的位置:x,y" << '\n';
                cin >> Fi[number].fi_x >> Fi[number].fi_y;
            }
            else if (ch == 4)
            {
                cout << "请输入更改后的状态:" << '\n';
                cout << "1:完好 2:轻微损坏 3:严重损坏" << '\n';
                cin >> Fi[number].fi_state;
            }

            Sleep(100);
            cout << "操作完成，请选择你的下一步操作" << '\n';
            cout << "1:修改消防设施的种类" << '\n';
            cout << "2:修改消防设施的数量" << '\n';
            cout << "3:修改消防设施的位置" << '\n';
            cout << "4:修改消防设施的状态" << '\n';
            cout << "5:退出该系统" << '\n';
            cin >> ch;
        }
        cout << "退出消防设施修改系统成功" << '\n';
    }
}

inline void del_Fi()
{
    int number;
    cout << "请输入你要删除的消防设施编号:" << '\n';
    cin >> number;
    while (number != -1 && fi_number.find(number) == fi_number.end())
    {
        cout << "未找到你要删除的消防设施编号,请重新输入消防设施编号" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }

    if (number == -1)
    {
        cout << "删除失败" << '\n';
    }
    else
    {
        fi_number.erase(number);
        cout << "删除成功" << '\n';
    }
}

inline void user3_Fi()
{
    int Type;
    cout << "请选择你要进行的操作:" << '\n';
    cout << "1:添加新消防设施" << '\n';
    cout << "2:修改原有的消防设施" << '\n';
    cout << "3:删除消防设施" << '\n';
    cout << "4:退出该系统" << '\n';
    cin >> Type;
    while (Type != 4)
    {
        if (Type == 1)
        {
            add_Fi();
        }
        else if (Type == 2)
        {
            change_Fi();
        }
        else if (Type == 3)
        {
            del_Fi();
        }
        cin >> Type;
    }

    Sleep(100);
    cout << "操作成功,请继续选择你要进行的操作" << '\n';
    cout << "1:添加新消防设施" << '\n';
    cout << "2:修改原有的消防设施" << '\n';
    cout << "3:删除消防设施" << '\n';
    cout << "4:退出该系统" << '\n';
    cout << "退出系统成功" << '\n';
}

inline void add_Sa()
{
    int number;
    cout << "请输入你要添加的维护信息编号:" << '\n';
    cin >> number;
    while (number != -1 && (number > 1e5 || sa_number.find(number) != sa_number.end()))
    {
        if (number > 1e5)
        {
            cout << "输入格式错误,请重新输入维护信息编号" << '\n';
        }
        else
        {
            cout << "该编号以存在,请重新输入维护信息编号" << '\n';
        }
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }

    if (number == -1)
    {
        cout << "添加失败" << '\n';
    }
    else
    {
        Sa[number].save_number = number;
        sa_number.insert(number);
        cout << "请输入对应维护的景观编号:" << '\n';
        cin >> Sa[number].at_number;
        cout << "请输入维护种类:" << '\n';
        cout << "1:扫 2:擦 3:喷 4:剪 5:修" << '\n';
        cin >> Sa[number].sa_type;
        cout << "请输入执行维护的人员:" << '\n';
        cin >> Sa[number].finisher;
        cout << "请输入进行维护的位置:" << '\n';
        cin >> Sa[number].sa_x >> Sa[number].sa_y;
        cout << "请输入维护的时间" << '\n';
        cin >> Sa[number].sa_data;

        cout << "请输入本次维护的费用" << '\n';
        cin >> Sa[number].cost;
        all_fin.out += Sa[number].cost;

        cout << "添加成功" << '\n';
    }
}

inline void change_Sa()
{
    int number;
    cout << "请输入你要修改的维护信息编号" << '\n';
    cin >> number;
    while (number != -1 && sa_number.find(number) == sa_number.end())
    {
        cout << "未找到要修改的编号,请重新输入维护信息编号" << '\n';
        cout << "或输入-1退出该系统<<" << '\n';
        cin >> number;
    }

    if (number == -1)
    {
        cout << "修改失败" << '\n';
    }
    else
    {
        int ch;
        cout << "请输入你要修改的元素:" << '\n';
        cout << "1:修改所维护的景观编号" << '\n';
        cout << "2:修改维护种类" << '\n';
        cout << "3:修改维护的完成人" << '\n';
        cout << "4:修改维护信息的位置" << '\n';
        cout << "5:修改维护信息的日期" << '\n';
        cout << "6:修改本次维护的花费" << '\n';
        cout << "7:退出该系统" << '\n';
        cin >> ch;
        while (ch != 7)
        {
            if (ch == 1)
            {
                cout << "请输如更改后的景观编号:" << '\n';
                cin >> Sa[number].at_number;
            }
            else if (ch == 2)
            {
                cout << "请输入更改后的维护种类" << '\n';
                cout << "1:扫 2:擦 3:喷 4:剪 5:修" << '\n';
                cin >> Sa[number].sa_type;
            }
            else if (ch == 3)
            {
                cout << "请输入更改后的完成人姓名" << '\n';
                cin >> Sa[number].finisher;
            }
            else if (ch == 4)
            {
                cout << "请输入更改后的位置:" << '\n';
                cin >> Sa[number].sa_x >> Sa[number].sa_y;
            }
            else if (ch == 5)
            {
                cout << "请输入更改后的日期:" << '\n';
                cin >> Sa[number].sa_data;
            }
            else if (ch == 6)
            {
                int Cost;
                cout << "请输入修改后的花费" << '\n';
                cin >> Cost;
                all_fin.out += Cost - Sa[number].cost;
                Sa[number].cost = Cost;
            }
            cout << "操作完成，请选择你的下一步操作" << '\n';
            cout << "1:修改所维护的景观编号" << '\n';
            cout << "2:修改维护种类" << '\n';
            cout << "3:修改维护的完成人" << '\n';
            cout << "4:修改维护信息的位置" << '\n';
            cout << "5:修改维护信息的日期" << '\n';
            cout << "6:修改本次维护的花费" << '\n';
            cout << "7:退出该系统" << '\n';
            cin >> ch;
        }
        cout << "退出维护信息修改系统成功" << '\n';
    }
}

inline void del_Sa()
{
    int number;
    cout << "请输入要删除的维护信息编号:" << '\n';
    cin >> number;
    while (number != -1 && sa_number.find(number) == sa_number.end())
    {
        cout << "未找到该编号,请重新输入要删除的维护信息编号" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }

    if (number == -1)
    {
        cout << "删除失败" << '\n';
    }
    else
    {
        sa_number.erase(number);
        all_fin.out -= Sa[number].cost;
        cout << "删除成功" << '\n';
    }
}

inline void user3_Sa()
{
    int Type;
    cout << "请选择你要进行的操作:" << '\n';
    cout << "1:记录新的维护操作" << '\n';
    cout << "2:修改原有的维护记录" << '\n';
    cout << "3:删除原有的维护记录" << '\n';
    cout << "4:退出该系统" << '\n';
    cin >> Type;
    while (Type != 4)
    {
        if (Type == 1)
        {
            add_Sa();
        }
        else if (Type == 2)
        {
            change_Sa();
        }
        else if (Type == 3)
        {
            del_Sa();
        }

        cout << "操作成功,请继续选择你要进行的操作" << '\n';
        cout << "或输入4退出该系统" << '\n';
        cin >> Type;
    }
    cout << "退出系统成功" << '\n';
}

// 其他信息操作
inline void user3()
{
    int Type;
    cout << "请选择你要进行的操作:" << '\n';
    cout << "1:景观信息维护" << '\n';
    cout << "2:消防设施信息维护" << '\n';
    cout << "3:各景观维护信息统计" << '\n';
    cout << "4:退出该系统" << '\n';
    cin >> Type;

    while (Type != 4)
    {
        if (Type == 1)
        {
            user3_At();
        }
        else if (Type == 2)
        {
            user3_Fi();
        }
        else if (Type == 3)
        {
            user3_Sa();
        }
        cout << "操作完成,请继续选择你的操作" << '\n';
        cout << "或输入4退出该系统" << '\n';
        cin >> Type;
    }

    cout << "退出其他信息操作系统成功" << '\n';
}

inline void add_To()
{
    int number;
    cout << "请输入要添加的游客编号:" << '\n';
    cin >> number;
    while (number != -1 && (number > 1e5 || to_number.find(number) != to_number.end()))
    {
        if (number > 1e5)
        {
            cout << "输入编号格式错误,请重新输入游客编号" << '\n';
        }
        else
        {
            cout << "该编号已经存在,请重新输入游客编号" << '\n';
        }
        cout << "或输入-1退出该系统" << '\n';
    }

    if (number == -1)
    {
        cout << "添加失败" << '\n';
    }
    else
    {
        To[number].to_number = number;
        to_number.insert(number);
        cout << "请输入游客的性别:0-男,1-女" << '\n';
        cin >> To[number].to_sex;

        int age;
        cout << "请输入游客的年龄:" << '\n';
        cin >> age;
        // 设置0为未成年人，1为成年人，2为老年人;
        if (age < 18)
        {
            To[number].to_age = 0;
        }
        else if (age < 65)
        {
            To[number].to_age = 1;
        }
        else
        {
            To[number].to_age = 2;
        }

        cout << "请输入游客的姓名:" << '\n';
        cin >> To[number].at_name;
        cout << "请输入游客的游玩方式:" << '\n';
        cout << "0:散客游玩 1:跟团游玩" << '\n';
        cin >> To[number].to_type;
        cout << "请输入游客的游玩时长" << '\n';
        cin >> To[number].to_time;

        // 计算收入;
        if (To[number].to_type == 1)
        {
            all_fin.in += price[3] * To[number].to_time;
        }
        else
        {
            all_fin.in += price[To[number].to_age] * To[number].to_time;
        }

        cout << "添加成功" << '\n';
    }
}

inline void change_To()
{
    int number;
    cout << "请输入你要修改的游客编号" << '\n';
    cin >> number;
    while (number != -1 && to_number.find(number) == to_number.end())
    {
        cout << "未找到要修改的游客编号,请重新输入游客编号" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }

    if (number == -1)
    {
        cout << "修改失败" << '\n';
    }
    else
    {
        int ch;
        cout << "请输入你要修改的元素:" << '\n';
        cout << "1:修改游客性别" << '\n';
        cout << "2:修改游客年龄" << '\n';
        cout << "3:修改游客姓名" << '\n';
        cout << "4:修改游客游玩方式" << '\n';
        cout << "5:修改游客游玩时长" << '\n';
        cout << "6:退出该系统" << '\n';
        cin >> ch;
        while (ch != 6)
        {
            if (ch == 1)
            {
                cout << "请输如更改后的有了性别:0-男,1-女" << '\n';
                cin >> To[number].to_sex;
            }
            else if (ch == 2)
            {
                int age;
                cout << "请输入修改后的年龄:" << '\n';
                cin >> age;
                // 更新财务账单
                if (age < 18)
                {
                    age = 0;
                }
                else if (age < 65)
                {
                    age = 1;
                }
                else
                {
                    age = 2;
                }
                all_fin.in += To[number].to_time * (price[age] - price[To[number].to_age]);
                To[number].to_age = age;
            }
            else if (ch == 3)
            {
                cout << "请输入更改后的完成人姓名" << '\n';
                cin >> To[number].at_name;
            }
            else if (ch == 4)
            {
                int type;
                cout << "请输入更改后的游玩方式:" << '\n';
                cout << "0:散客游玩 1:跟团游玩" << '\n';
                cin >> type;
                // 更新财务账单
                if (type == 1)
                {
                    all_fin.in += (price[3] - price[To[number].to_age]) * To[number].to_time;
                }
                else
                {
                    all_fin.in += (price[To[number].to_age] - price[3]) * To[number].to_time;
                }
                To[number].to_type = type;
            }
            else if (ch == 5)
            {
                int time;
                cout << "请输入更改后的游玩时长:" << '\n';
                cin >> time;
                // 更新财务账单
                if (To[number].to_type == 1)
                {
                    all_fin.in += price[3] * (time - To[number].to_time);
                }
                else
                {
                    all_fin.in += price[To[number].to_age] * (time - To[number].to_time);
                }
                To[number].to_time = time;
            }
            cout << "操作完成，请选择你的下一步操作" << '\n';
            cin >> ch;
        }
        cout << "退出游客信息修改系统成功" << '\n';
    }
}

inline void del_To()
{
    int number;
    cout << "请输入你要删除的游客编号:" << '\n';
    cin >> number;
    while (number != -1 && to_number.find(number) == to_number.end())
    {
        cout << "未找到你要删除的游客编号,请重新输入游客编号" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> number;
    }

    if (number == -1)
    {
        cout << "删除失败" << '\n';
    }
    else
    {
        to_number.erase(number);
        if (To[number].to_type == 1)
        {
            all_fin.out -= To[number].to_time * price[3];
        }
        else
        {
            all_fin.out -= To[number].to_time * price[To[number].to_age];
        }
        cout << "删除成功" << '\n';
    }
}

// 查询总账单
inline void check_Fin()
{
    cout << "总收入：" << all_fin.in << '\n';
    cout << "总支出：" << all_fin.out << '\n';
}

// 处理财务信息
inline void user4()
{
    int Type;
    cout << "请选择你要进行的操作:" << '\n';
    cout << "1:添加新的游客信息" << '\n';
    cout << "2:修改原有的游客信息" << '\n';
    cout << "3:删除原有的游客信息" << '\n';
    cout << "4:查询账单" << '\n';
    cout << "5:退出该系统" << '\n';
    cin >> Type;
    while (Type != 5)
    {
        if (Type == 1)
        {
            add_To();
        }
        else if (Type == 2)
        {
            change_To();
        }
        else if (Type == 3)
        {
            del_To();
        }
        else if (Type == 4)
        {
            check_Fin();
        }

        cout << "操作完成,请继续选择你的操作" << '\n';
        cout << "或输入5退出该系统" << '\n';
        cin >> Type;
    }
    cout << "退出财务管理系统成功" << '\n';
}

int main()
{
    // 初始化管理员权限
    read_from_data();

    cout << "请输入要登陆的账号" << '\n';
    // start：输入的人员编号
    int start;
    cin >> start;
    // 如果输入为-1，表示操作完成，退出系统
    while (start != -1)
    {
        // 如果没有在人员列表中找到这个编号，直接返回，重新读取
        if (all_user.find(start) == all_user.end())
        {
            cout << "抱歉,没有查询到该人员编号" << '\n';
            cout << "请重新输入员工编号:" << '\n';
            cin >> start;
            continue;
        }

        int Pa;
        cout << "成功找到该用户编号,请输入登陆密码:" << '\n';
        cin >> Pa;
        while (Pa != -1 && Pa != user_op[start].pa)
        {
            cout << "输入密码错误,请重新输入登陆密码" << '\n';
            cout << "或输入-1退出该系统,重新输入账号" << '\n';
            cin >> Pa;
        }
        if (Pa == -1)
        {
            cout << "登陆失败,请重新输入用户编号" << '\n';
            cin >> start;
            continue;
        }

        cout << "登陆成功,欢迎使用该系统" << '\n';

        if (user_op[start].n1 == true)
        {
            int Op;
            // 如果该人员是管理员,默认管理员拥有所有权限
            cout << "欢迎使用该系统，管理员" << '\n';
            cout << "请选择你想进行的操作:" << '\n';
            cout << "1:增删改查用户" << '\n';
            cout << "2:分配权限" << '\n';
            cout << "3:其他信息操作" << '\n';
            cout << "4:处理财务信息" << '\n';
            cout << "5:结束操作" << '\n';
            cin >> Op;
            while (Op != 5)
            {
                // 在进入新系统前重新换行，规整
                cout << '\n';
                if (Op == 1)
                {
                    user1();
                }
                else if (Op == 2)
                {
                    user2();
                }
                else if (Op == 3)
                {
                    user3();
                }
                else if (Op == 4)
                {
                    user4();
                }
                cout << "操作成功，请选择你的下一步操作" << '\n';
                cout << "1:增删改查用户" << '\n';
                cout << "2:分配权限" << '\n';
                cout << "3:其他信息操作" << '\n';
                cout << "4:处理财务信息" << '\n';
                cout << "5:结束操作" << '\n';
                cin >> Op;
            }
        }
        else if (user_op[start].n2 == true)
        {
            // 如果该员工是操作员
            cout << '\n';
            user2();
        }
        else if (user_op[start].n3 == true)
        {
            // 如果该人员是财务人员
            cout << '\n';
            user3();
        }
        else
        {
            // 如果没有任何权限
            cout << "抱歉，你没有权限访问这个系统" << '\n';
        }
        cout << "操作完成,请输入新的员工编号:" << '\n';
        cout << "或输入-1退出该系统" << '\n';
        cin >> start;
    }
    cout << "退出系统成功,欢迎下次使用" << '\n';
    Save_data();
}

//字符串展开(大模拟)
//https://ac.nowcoder.com/acm/contest/20960/1001


//减号是一种简写
//用连续递增的字母或数字串替代其中的减号
//若减号不位于字符串的开头或结尾,且其两侧为同类型的字符(都是小写字母或都是数字)
//且右侧字符的 ASCII 码大于左侧字符时，则需要展开
//p1=1,若减号两侧为字母，则用小写字母填充；若为数字，则用数字填充
//p1=2,若减号两侧为字母，则用大写字母填充；若为数字，则用数字填充
//p1=3,无论减号两侧为何种字符，都用星号填充
//p2控制每个填充字符重复的次数
//p3控制是否逆序输出填充部分,
//p3=1,维持原有顺序
//p3=2,采用逆序输出
//右侧字符是左侧字符的直接后继,只需删除减号
//右侧字符的 ASCII 码小于等于左侧字符，则保持原样输出

#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3; //输入写成全局变量,方便管理
string s,ans;


//设计大量if,else判断时,封装成函数
bool check(char begin,char end){
    if (begin>=end) return false;
    if (begin>='a' && begin<='z' && end>='a' && end<='z') return true;
    if (begin>='0' && begin<='9' && end>='0' && end<='9') return true;
    return false;
}

//处理字符串时,封装成函数
string rep(char t){
    bool flag=false;
    if (t>='0' and t<='9') flag=true;
    //string(x,'a'),生成x个'a'
    if (p1==1) return string(p2,t);
    else if (p1==2){
        if (flag) return string(p2,t);
        else return string(p2,t-32);
    }
    return string(p2,'*');
}
int main(){
    cin>>p1>>p2>>p3>>s;
    //字符串长度,s.size()
    int n=s.size();
    for (int i=0;i<n;i++){
        if (s[i]!='-') ans+=s[i];
        //注意C++不能使用0<i<n的写法,必须分开写然后用&&连接
        else if (i>0 && i<n){
            //多个变量赋值时的写法
            char begin=s[i-1],end=s[i+1];
            if (check(begin,end)){
                //循环写成一行,简洁美观
                if (p3==1) for (char t=begin+1;t<end;t++) ans+=rep(t);
                if (p3==2) for (char t=end-1;t>begin;t--) ans+=rep(t);
            }
            else ans+=s[i];
        }
        else ans+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}
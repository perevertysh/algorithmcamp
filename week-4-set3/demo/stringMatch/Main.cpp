#include <bits/stdc++.h>
using namespace std;

// ================= 代码实现开始 =================

/* 请在这里定义你需要的全局变量 */
std::vector<int> Next;

// 这是匹配函数，将所有匹配位置求出并返回
// n：串 A 的长度
// A：题目描述中的串 A
// m：串 B 的长度
// B：题目描述中的串 B
// 返回值：一个 vector<int>，从小到大依次存放各匹配位置
vector<int> match(int n, string A, int m, string B) {
    /* 请在这里设计你的算法 */
    Next.resize(m);//初始化

    int j=Next[0]=-1; //j为匹配失败时跳转到的位置
    for(int i=1;i<m;++i){
        while( j>0&&B[i]!=B[j+1])
            j=Next[j];
        if(B[i]==B[j+1])
            ++j;    //当前位置匹配,++j
        Next[i]= j; //记录当前位的next数组
    }
    j=-1;   //j为当前模式串匹配到的位置

    vector<int > ans;      //这是答案,返回值
    for(int i=0;i<n;++i){
        while( j>=0&&A[i]!=B[j+1])    //如果下一位无法匹配,则用Next数组跳转
            j=Next[j];
        if(A[i]==B[j+1])
            ++j;    //当前位置匹配,++j
        if(j==m-1)
            ans.push_back(i-m+1 );  //如果整个模式串匹配,则找到答案i-(m-1)//
    }
    return ans;
}   

// ================= 代码实现结束 =================

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    string A, B;
    cin >> n >> A;
    cin >> m >> B;
    vector<int> ans = match(n, A, m, B);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
        cout << *it << '\n';
    return 0;
}

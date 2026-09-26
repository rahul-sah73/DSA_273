#include<iostream>
#include<string>
#include<cstring>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
#define CMDS 5
#define MAXWORDS 100
#define TOKENS 4
int cl[CMDS];
char *lists[CMDS][MAXWORDS];
char *tokens[TOKENS]={"[N]","[AV]","[V]","[AJ]"};
char *cmds[CMDS]=
{"NOUNS","ADVERBS","VERBS","ADJECTIVES","END"};
int t=-1, c[CMDS]={0};
int get_idx(string s) {
    for(int i=0;i<CMDS;i++) if(s==string(cmds[i])) return i;
    return -1;
}
void add(string w) { if (t != -1) lists[t][cl[t]++] = strdup(w.c_str()); }
void proc(string w) { int i=get_idx(w); if(i!=-1) t=i; else add(w); }
void read_w() { string w; while(cin>>w) { if(w=="END") break; proc(w); } }
void chk(string s, int i, int &m, int &ty) {
    int p=s.find(tokens[i]); if(p!=string::npos) if(p<m) { m=p; ty=i; }
}
int find_t(string s, int &ty) {
    int m=10000; ty=-1; for(int i=0;i<TOKENS;i++) chk(s, i, m, ty); return m;
}
void sub(string s) {
    while(true) {
        int ty=-1, p=find_t(s, ty);
        if(p==10000) break;
        const char *rep = (c[ty] < cl[ty]) ? lists[ty][c[ty]++] : "";
        s.replace(p, strlen(tokens[ty]), rep);
    }
    cout<<s<<"\n";
}
int main() {
    string s; getline(cin, s);
    while(s.length() && s.back()=='\r') s.pop_back();
    read_w(); sub(s); sub(s); return 0;
}

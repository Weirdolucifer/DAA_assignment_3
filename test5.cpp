#include<bits/stdc++.h>
using namespace std;
long long steps = 0;
int var_i,var_j;
struct node{
    struct node *child[26];
    int isleaf;
};
struct node *getnode()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    steps += 26;
    for(int i=0;i<26;i++){
        temp->child[i]=NULL;
        steps++;
    }
    temp->isleaf=0;
    steps++;
    return temp;
}
void add(struct node * root,string s){
    struct node *temp;
    temp=root;
    int ind;
    steps += s.size()+1;
    for(int i=0;i<s.size();i++){
        ind=s[i]-'a';
        steps += 2;
        if(temp->child[ind]==NULL){
            steps += 2;
            temp->child[ind]=getnode();
            temp->child[ind]->isleaf=0;
        }
        steps ++;
        temp=temp->child[ind];
    }
    steps++;
    temp->isleaf=1;
    //cout<<(char)(ind+'a')<<endl;
}
int find(struct node * root,string s){
    struct node * temp;
    temp = root;
    int ind;
    string answ;
    steps += s.size()+4;
    int temp_i = var_i;
    //return 0;
    for(int i=0;i<s.size();i++){
        ind = s[i] - 'a';
        steps += 3;
        if(temp->isleaf==1){
            cout<<temp_i<<" "<<var_j<<" -> "<<var_i-1<<" "<<var_j<<endl; 
         	cout<<answ<<endl;
        }
        if(temp -> child[ind]==NULL){
            return 0;
        }
        steps++;
        temp = temp->child[ind];
        answ.push_back(s[i]);
        steps++;   
        var_i++;
    }
    if(temp->isleaf==1){
        cout<<temp_i<<" "<<var_j<<" -> "<<var_i-1<<" "<<var_j<<endl;
        cout<<answ<<endl;
    }
    steps++;
    return temp -> isleaf;
}
int main(){
    srand(time(NULL));
    int n;
    cin>>n;
    string s;
    struct node * root=NULL;
    root=getnode();
    steps+=2;
    for(int i=1;i<=n;i++){
        cin>>s;
        steps+=2;
        add(root,s);
    }
    long long var = steps;
    int t;
    cin>>t;
    while(t--){
        steps = 0;
        int m;
       // m = rand()%10;
        cin>>m;
        steps++;
        string str[m+1];
        cout<<"***************\n";
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                //int tm = rand()%26;
                //str[i].push_back((char)(tm + 'a'));
                char x;
                cin>>x; 
                str[i].push_back(x);  
            }
            cout<<str[i]<<"\n";
        }
        cout<<"***************\n";
        int cnt;
        for(int i=0;i<m;i++){
            string tmp;
            steps++;
            cnt=0;
            for(int j=0;j<m;j++){
                steps++; 
                   cnt++;  
                tmp.push_back(str[j][i]);
            }
            steps++;
            var_i = 0, var_j = i;
            find(root,tmp);
            cnt=m;
            for(int j=0;j<m;j++){
                steps++;
                reverse(tmp.begin(), tmp.end());
                steps+=cnt;
                //tmp.pop_back();
                int xa=tmp.length();
                xa--;
                tmp[xa]='\0';
                steps++;
                cnt--;
                reverse(tmp.begin(), tmp.end());
                steps += cnt;
                var_i=j+1;
                find(root,tmp);
                steps++;
            }
        }   
        cout<<m<<" "<<steps<<endl;
    }
    return 0;
}

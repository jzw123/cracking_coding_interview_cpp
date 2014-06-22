//implement setofstacks

#include <iostream>
using namespace std;

const int STACK_SIZE = 5;
const int STACK_NUM = 10;
const int MAX_INT = ~(1<<31);//2147483647

class stack{
private:
    int *buf;
    int cur;
    int capacity;
    
public:
    stack(int capa = STACK_SIZE){
        buf = new int[capa];
        cur = -1;
        capacity = capa;
    }
    ~stack(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur] = val;
    }
    void pop(){
        if(empty())
            cout << "there is no element to pop" << endl;
        else
            --cur;
    }
    int top(){
        if(empty())
            return -MAX_INT;
        else
            return buf[cur];
    }
    
    bool empty(){
        return cur==-1;
    }
    bool full(){
        return cur==capacity-1;
    }
};

class SetOfStacks{//without popAt()
private:
    stack *st;
    int cur;
    int capacity;
    
public:
    SetOfStacks(int capa=STACK_NUM){
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks(){
        delete[] st;
    }
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    void pop(){
        while(st[cur].empty() && cur != -1) --cur;
        if(cur == -1)
            cout << "there is nothing to pop" << endl;
        else
            st[cur].pop();
    }
    int top(){
        while(st[cur].empty() && cur != -1) --cur;
        if(cur == -1)
            return -MAX_INT;
        else
            return st[cur].top();
    }
    
    bool empty(){
        if(cur==0) return st[0].empty();
        else return false;
    }
    bool full(){
        if(cur==capacity-1) return st[cur].full();
        else return false;
    }
};

class SetOfStacks1{
private:
    stack *st;
    int cur;
    int capacity;
    
public:
    SetOfStacks1(int capa=STACK_NUM){
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks1(){
        delete[] st;
    }
    
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    
    void pop(){
        while(st[cur].empty() && cur >= 0) --cur;
        if(cur == -1)
            cout << "there is no element to pop" << endl;
        else
            st[cur].pop();
    }
    
    void popAt(int idx){
        while(st[idx].empty() && idx >= 0) --idx;
        if(idx == -1)
            cout << "there is no element to pop" << endl;
        else
            st[idx].pop();
    }
    
    int top(){
        while(st[cur].empty() && cur >= 0) --cur;
        if(cur == -1)
            return -MAX_INT;
        else
            return st[cur].top();
    }
    
    bool empty(){
        while(cur!=-1 && st[cur].empty()) --cur;
        if(cur==-1) return true;
        else return false;
    }
    
    bool full(){
        if(cur==capacity-1) return st[cur].full();
        else return false;
    }
};
int main(){
    // SetOfStacks ss;
    // for(int i=0; i<STACK_SIZE+1; ++i){
    //     ss.push(i);
    // }
    // while(!ss.empty()){
    //     cout<<ss.top()<<endl;
    //     ss.pop();
    // }
    SetOfStacks1 ss1;
    for(int i=0; i<3*STACK_SIZE+1; ++i){
        ss1.push(i);
    }
    for(int i=0; i<STACK_SIZE; ++i){
        ss1.popAt(0);
        //ss1.popAt(1);
        ss1.popAt(2);
    }
    ss1.popAt(3);
    while(!ss1.empty()){
        cout<<ss1.top()<<endl;
        ss1.pop();
    }
    
    return 0;
}
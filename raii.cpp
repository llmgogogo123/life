#include<iostream>
#include<cstdio>
using namespace std;
/*void bad(){
    FILE* f=fopen("text.txt","w");
    if(!f) return;
    fputs("hello",f);
    throw runtime_error("出错了");
    fclose(f);
}
int main(){
    try{
        bad();
    } catch (exception& e){
        cout<<"捕获："<<e.what()<<endl;
    }
        return 0;
}*/
class FileHandle{
    FILE* f;
    public:
    FileHandle(const char* path){
        f=fopen(path,"w");
        if(!f) throw runtime_error("打不开文件");
        cout<<"打开文件"<<endl;
    }
    ~FileHandle(){
        if(f){
        fclose(f);
        cout<<"关闭文件"<<endl;
        }
    }
    void write(const char* s){
        fputs(s,f);
    }
};
void good(){
    FileHandle h("text.txt");
    h.write("hello");
    throw runtime_error("出错了");
}
int main(){
    try{
        good();
    } catch(exception& e){
        cout<<"捕获"<<e.what()<<endl;
    }
    return 0;
}
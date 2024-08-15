#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

string toLowerCase(string s){
    for(char &i: s){
        if(i>='A' and i<='Z'){
            i += 32;
        }
    }
    return s;
}

string toUpperCase(string s){
    for(char &i: s){
        if(i>='a' and i<='z'){
            i -= 32;
        }
    }
    return s;
}


class File{
    private:
    string name, content;
    int size;
    bool isHidden, isDeleted, readOnly;

    public:
    File(string n, bool hide=false){
        name = n;
        size=10;
        isHidden=hide;
        isDeleted=false;
        content="";
        readOnly=false;
    }
     
    // Delete the file, but make them in memory
    void deleteFile(){
        if(this->readOnly){
            cout<<"You don't have permission\n";
            return;
        }
        this->isDeleted=true;
    }

    // add content in the file
    void addContent(string s){
        // cout<<"Yes Content set\n";
        if(this->readOnly){
            cout<<"You don't have permission\n";
            return;
        }
        this->content = s;
    }

    // show content of file
    void showContent(){
        // cout<<"Yes content show\n";
        cout<<"File name: "<<name<<endl;
        cout<<"Content\n"<<this->content<<endl;
    }

    // make the file hide
    void hideFile(){
        this->isHidden=true;
    }
    // make file unhide
    void unhideFile(){
        this->isHidden=false;
    }

    // change the access permission of the file
    void changePermission(){
        this->readOnly = !this->readOnly;
    }

    // Show the file details like, name, size, permission type
    void showFileDetail(){
        string per="";
        if(this->readOnly){
            per = "ReadOnly";
        }
        else per = "ReadWrite";

        cout<<"File name: "<<this->name<<" size: "<<this->size<<" Permission "<<per<<endl;
    }

    bool checkDelStatus(){
        return !isDeleted;
    }
    bool checkHiddenStatus(){
        return !isHidden;
    }

};

class Directory{

    string name;
    map<string, File*>files;
    map<string, Directory*>folders;
    int filesCount, totalFilesCount;
    bool isDeleted;

    public:

    Directory(string n){
        this->name = n;
        filesCount = 0;
        totalFilesCount=0;
        isDeleted=false;
    }

    // list all avialable files with their info in the given directory
    void listAllFilesInfo(bool hideAlso=false){
        if(hideAlso){
            cout<<"Total Files : "<<totalFilesCount<<endl;
        }
        else{
            cout<<"Total Files : "<<filesCount<<endl;
        }
        for(auto f: files){
            if(f.second->checkDelStatus() and (hideAlso or f.second->checkHiddenStatus())) 
                f.second->showFileDetail();
        }
    }

    // list all avialable files with their info in the given directory
    void listAllFiles(bool hideAlso=false){
        if(hideAlso){
            cout<<"Total Files : "<<totalFilesCount<<endl;
        }
        else{
            cout<<"Total Files : "<<filesCount<<endl;
        }
        for(auto f: files){
            if(f.second->checkDelStatus() and (hideAlso or f.second->checkHiddenStatus())) 
                cout<<f.first<<"\n";
        }
    }

    // to del the direcotry, but make them in memory
    void delteDirectory(){
        this->isDeleted = true;
    }

    // to delete file from the directory
    void DelteFile(string filename){
        if(files.count(filename)){
            files[filename]->deleteFile();
            totalFilesCount--;
            filesCount--;
        }
        else cout<<"No File Exist\n";
    }

    // to hide file from the directory
    void hideFile(string filename){
        if(files.count(filename)){
            files[filename]->hideFile();
            filesCount--;
        }
        else cout<<"No File Exist\n";
    }

    // to add file in particular directory
    void addFile(string filename){
        if(files.count(filename)){
            cout<<"File Already Exist";
        }
        else{
            files[filename] = new File(filename);
            totalFilesCount++;
            filesCount++;
        }
    }

    // to add hidden file in particular directory
    void addHiddenFile(string filename){
        if(files.count(filename)){
            cout<<"File Already Exist";
        }
        else{
            files[filename] = new File(filename, true);
            totalFilesCount++;
            filesCount++;
        }
    }

    // to add content in file in particular directory
    void addFileContent(string filename, string content){
        if(files.count(filename)){
            // cout<<"Here enter\n";
            files[filename]->addContent(content);
        }
        else{
            cout<<"No File Exist\n";
        }
    }

    // to show content in file in particular directory
    void showFileContent(string filename){
        // cout<<"here gpoes\n";
        if(files.count(filename)){
            // cout<<"Here also enter\n";
            files[filename]->showContent();
        }
        else{
            cout<<"No File Exist\n";
        }
    }

    // to change file permission in particular directory
    void changePermission(string filename){
        if(files.count(filename)){
            files[filename]->changePermission();
        }
        else{
            cout<<"No File Exist\n";
        }
    }

    void addFolder(string foldername){
        if(folders.count(foldername)){
            cout<<"Folder Already Exist";
        }
        else{
            folders[foldername] = new Directory(foldername);
            filesCount++;
            totalFilesCount++;
        }
    }

    void deleteFolder(string foldername){
        if(folders.count(foldername)){
            folders[foldername]->delteDirectory();
            filesCount--;
            totalFilesCount--;
        }
        else{
            cout<<"No folder Exist\n";
        }
    }

    void showDirectoryDetails(){
        cout<<"Directory Name: "<<name<<endl;
        cout<<"Total Files: "<<filesCount<<endl;
    }
};

vector<string> fetchPath(string s){
    stringstream ss(s);
    string path;

    vector<string>res;

    while(getline(ss, path, '/')){
        res.push_back(path);
    }
    return res;
}

int main(int agrc, char *argc[]){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n;
    cin>>n;

    map<string, Directory*>memory;
    string currDir = "";

    for(int i=0; i<n; i++){
        string command;
        cin>>command;

        if(command=="addFile"){
            string filename;
            cin>>filename;
            filename = toLowerCase(filename);

            memory[currDir]->addFile(filename);
        }
        else if(command=="addHiddenFile"){
            string filename;
            cin>>filename;
            filename = toLowerCase(filename);
            memory[currDir]->addHiddenFile(filename);
        }
        else if(command == "setContent" or command == "getContent"){
            string path, content;
            cin>>path;
            if(command == "setContent")cin>>content;
            vector<string>res = fetchPath(path);
            if(res.size()==1){
                if(command=="setContent") memory[currDir]->addFileContent(toLowerCase(res[0]), content);
                else memory[currDir]->showFileContent(toLowerCase(res[0]));
            }
            else{
                if(command == "setContent")memory[toUpperCase(res[res.size()-2])]->addFileContent(res[res.size()-1], content);
                else memory[toUpperCase(res[res.size()-2])]->showFileContent(toLowerCase(res[res.size()-1]));
            }
        }
        else if(command == "setReadOnly"){
            string filename;
            cin>>filename;
            filename = toLowerCase(filename);

            memory[currDir]->changePermission(filename);
        }
        else if(command == "listFiles" or command == "listAllFiles"){
            bool hide = command=="listAllFiles";
            memory[currDir]->listAllFiles(hide);
        }
        else if(command == "listDetails"){
            memory[currDir]->listAllFilesInfo(true);
        }
        else if(command == "addDir"){
            string dirname;
            cin>>dirname;
            dirname = toUpperCase(dirname);

            if(!currDir.empty()){
                memory[currDir]->addFolder(dirname);
            }
            else{
                if(memory.count(dirname)){
                    cout<<"Directory Already Exist\n";
                }
                else{
                    memory[dirname] = new Directory(dirname);
                }
            }
            currDir = dirname;
        }
        else if(command == "details"){
            memory[currDir]->showDirectoryDetails();
        }
        else if(command == "goDir" or command == "goPrevDirectory"){
            string dir;
            if(command == "goDir"){
                cin>>dir;
                dir = toUpperCase(dir);
            }
            else{
                auto it = memory.find(currDir);
                if(it!=memory.begin())it--;
                dir = it->first;
            }
            currDir = dir;
        }
        else if(command == "remove"){
            
        }
    }
    

    return 0;
}
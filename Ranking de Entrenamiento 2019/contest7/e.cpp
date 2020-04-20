//CF ProblemSet 66C - Petya and File System

#include <bits/stdc++.h>

using namespace std;

int diskChecker(char c){
    if(c == 'C') 
        return 0;
    if(c == 'D')
        return 1;
    if(c == 'E')
        return 2;
    if(c == 'F')
        return 3;

    return 4;
}

int divFileFolder(string route){
    for(int i=route.size()-1; i>=0; i--){
        if(route[i] == '\\')
            return i;
    }
    return -1;
}

int firstFolder(string route){
    bool fSlash = false;
    for(int i=0; i<route.size(); i++){
        if(fSlash){
            if(route[i] == '\\')
                return i;
        }
        if(route[i] = '\\'){
            fSlash = true;
        }
    }
    return -1;
}

int main(){
  
    int mxFolder = -1, mxFile = -1;
    map<string,int> fileSystem; //Files
    map<string,int> folderSystem; //Folders
    //vector< pair<int,int> > systemMax(5, make_pair(0,0));//maxFolders, maxArchivos

    string s;
    while(cin >> s){ //C:\Folders\File.il
        int nFiles = 0; //Para cada ruta
        int disk = diskChecker(s[0]);
        //systemMax[disk].second++;
        //nFiles++;
        
        //CheckAllSubfolders
        int i=divFileFolder(s);
        //int lastFolder = firstFolder(s);
        int frec;
        while(i != 2){
            s = s.substr(0,i);
            frec = folderSystem[s];
            fileSystem[s] += nFiles;
            folderSystem[s]++;
            mxFolder = max(mxFolder, folderSystem[s]);
            mxFile = max(mxFile, fileSystem[s]);
            if(frec == 0)
                nFiles++;
            i = divFileFolder(s);
        }       
    }
    /*
    for(int i=0; i<5; i++){
        mxFolder = max(mxFolder, systemMax[i].first);
        mxFile = max(mxFile, systemMax[i].second);
    }*/
    
    cout << mxFile<< " " << mxFolder << endl;
    
    
}

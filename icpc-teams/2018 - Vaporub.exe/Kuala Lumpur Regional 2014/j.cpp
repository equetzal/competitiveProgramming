//UVaLive p6809 - Spokes Wheel 

#include <bits/stdc++.h>

using namespace std;

const char* hex_char_to_bin(char c){
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

string hex_str_to_bin_str(const std::string& hex){
    std::string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hex_char_to_bin(hex[i]);
    return bin;
}

int left(string cad, string &obj){
    for(int it=0; it<32; it++){
        if(cad == obj)
           return it;
        rotate(cad.begin(), cad.begin()+1, cad.end());
    }
    return 10000;
}

int right(string cad, string &obj){
    for(int it=0; it<32; it++){
        if(cad == obj)
           return it;
        rotate(cad.rbegin(), cad.rbegin()+1, cad.rend());
    }
    return 10000;
}

int main(){
    int cases;
    cin >> cases;


    for(int i=0; i<cases; i++){
        string hexI, hexF, binI, binF, binAny;
        cin >> hexI >> hexF;

        binI = hex_str_to_bin_str(hexI);
        binF = hex_str_to_bin_str(hexF);

        binI.insert(0,32-binI.size(), '0');
        binF.insert(0,32-binF.size(), '0');

        int ansL = left(binI,binF);
        int ansR = right(binI,binF);

        string ans = "Not possible";
        if(ansL != 10000)
            ans = "Left";
        if(ansR != 10000)
            if(ansR == ansL)
                ans = "Any";
            else if(ansR < ansL){
                ans = "Right";
                ansL = ansR;
            }

        cout << "Case #" << (i + 1) << ": ";
        if (ansL != 10000)
            cout << ansL << " ";
        cout << ans << endl;
    }
}

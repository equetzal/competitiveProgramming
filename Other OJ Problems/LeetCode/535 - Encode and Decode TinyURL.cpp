//LC 535 - Encode and Decode TinyURL

class Solution {
public:
    unsigned long long int id = 0;
    map<string,string> url;//short, long
    //short size = log62(2^64)
    
    char nToChar(short n){
        if(n < 10)
            return char(n)+'0';
        if(n < 37)
            return char(n-10)+'A';
        if(n < 63)
            return char(n-36)+'a';
        
        return 0;
    }
    
    unsigned long long int charToN(char c){
        if(isdigit(c))
            return (unsigned long long int)(c-'0');
        if(isupper(c))
            return (unsigned long long int)(c-'A'+10);
        if(islower(c))
            return (unsigned long long int)(c-'a'+36);
        
        return 0;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string enc;
        auto val = id;
        id++;
        short characterInt;
        do{
            characterInt = id%62;
            enc.push_back(nToChar(characterInt));
            val /= 62;
        }while(val > 0);
        
        for(int i=enc.size()-1; i<11; i++){
            enc.push_back('0');
        }
        
        url[enc] = longUrl;    
        
        return enc;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

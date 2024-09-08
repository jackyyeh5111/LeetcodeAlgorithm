class Codec {
public:
    char escaper = '#';
    char delimiter = '@';
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string & str : strs) {
            string str_with_escaper = "";
            for (char ch : str) {
                if (ch == escaper || ch == delimiter)
                    str_with_escaper += escaper;
                str_with_escaper += ch;
            }
            encoded += (str_with_escaper + delimiter);
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string encoded) {
        vector<string> output;
        
        /* 
             input: ["#", "str2"]
             output: ##@str2
         */
        int pos = 0;
        string decoded_str = "";
        while(pos < encoded.size()) {
            if (encoded[pos] == escaper) {
                pos++;
                decoded_str += encoded[pos];
            }
            else if (encoded[pos] == delimiter) {
                output.push_back(decoded_str);
                decoded_str = "";
            }
            else {
                decoded_str += encoded[pos];
            }
            pos++;
        }
        return output;
    }
};

/* 
    str1@str2
    
     input: ["@", "str2"]
    output: #@@str2
     
     input: ["#", "str2"]
    output: ##@str2
     
     input: ["#@", "str2"]
    output: ###@@str2

    // escaper cannot be the same with delimiter
     input: ["@@", ""]
    output: @@@@@
             ^      
 */
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
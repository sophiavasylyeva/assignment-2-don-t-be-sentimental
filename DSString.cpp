#include "DSString.h"
//#include <cstring>

/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions 
 * from <string.h> or <cstring> other than for conversion from a c-sting.
 */  

DSString::DSString() {
    data = new char[1]; //initializes private variables
    data[0] = '\0';
    len = 0;
}


DSString::DSString(const char *s)  {
    len = 0;
    while(s[len] != '\0'){          //fixed from strlen(s)
        ++len;
    }
   
    data = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        data[i] = s[i];
    }
    data[len] = '\0'; 

}

DSString::DSString(const DSString &s) {
    len = s.len;
    data = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        data[i] = s.data[i];
    }
     data[len] = '\0';


}   //copy constructor

DSString::~DSString() {
    delete[] data;
}   //destructor 
                  
DSString &DSString::operator=(const DSString &s){
        if(this != &s){
            delete[] data;
            len = s.len;
            data = new char[len+1];
            for(int i = 0; i <= len; i++){      //replaces strcpy(data, s.data)
                data[i] = s.data[i];
            }
            data[len] = '\0';
        }

        return *this;

} //assignment operator

size_t DSString::length() const {
    return len;
} // returns the length of the string

char &DSString::operator[](size_t position) const {     
    if(position > len-1){
        throw std::out_of_range("Index out of bounds"); //checks if position is greater than len-1 so function doesn't go out of bounds              
    }    
    return data[position];
} // returns a reference to the character at the given index

// ABOVE FUNCYION: this functions does not check if position is 
//greater than len - 1, meaning that the user of 
//this function could go out of bounds of data

DSString DSString::operator+(const DSString &s) const {
    DSString obj;
    //delete[] obj.data;
    obj.len = len + s.len;
    obj.data = new char[obj.len + 1];
    for(int  i = 0; i < len; i++){      //replaces strcpy 
        obj.data[i] = data[i];
    }
    for(int i = 0; i <= s.len; i++){    //replaces strcat (append)
        obj[i + len] = s.data[i];
    }
    obj.data[obj.len] = '\0';           //fixes seg fault for constructor
    return obj;
    //before you return, you do not place the null 
    //terminator at the end of obj, causing a seg 
    //fault when the DSString(const char*) 
    //constructor is called

} // Overloaded operator+ which appends the string in the argument to this string

//Standard relational operators to compare and order your strings.
bool DSString::operator==(const DSString &object) const {
    if(len != object.len)
        return false;
    for(int i = 0; i <= len; i++){
        if (data[i] != object.data[i])
            return false;
    }
    return true;            //replaces strcmp(object.data, data)

}

bool DSString::operator<(const DSString &o) const {
    for(int i = 0; i < len; i++){
        if(data[i] < o.data[i])
            return true;                //replaces strcmp(data, o.data)
        else if(data[i] > o.data[i])
            return false;
    }
        return false;       
}

/**
     * The substring method returns a new string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
DSString DSString::substring(size_t start, size_t numChars) const {
    if(start + numChars > len){
        throw std::out_of_range("out of bounds");   //checks for out of bounds
    }
    DSString substring;
    //delete[] substring.data;
    substring.len = numChars;
    substring.data = new char[numChars+1];
        for(int i = 0; i < numChars; i++) {
            substring.data[i] = data[start+i];
        }
    substring.data[numChars] = '\0';
    return substring;
}

/**
     * @brief Returns a new string object with all characters in lowercase
     *
     * @return DSString
     */
DSString DSString::toLower() const {
    DSString lower = data;
    for(int i = 0; i <= len; i++){
        lower.data[i] = tolower(lower.data[i]);
    }
    lower.len = len;
    return lower;
}

/**
     * the c_str function returns a pointer to a null-terminated c-string holding the
     * contents of this object. Since data already has a `\0`
     * at the end of the string in DSString so you can just return a pointer to data.
     **/
char *DSString::c_str() const {
    return data; 
}

/**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. Remember:
     * This operator needs to be implemented outside of the class as
     * a friend because it operates on the stream and not the DSString object.
     **/
std::ostream &operator<<(std::ostream &output, const DSString &s) {
    output << s.data;
    return output;
}

std::vector<DSString> DSString::tokenizer(){
    int start = 0;
    std::vector<DSString> s;
    for(int i  = 0; i <= len; i++){
        if(!isalpha(data[i])){
            if(start < i)
                s.push_back(substring(start, i - start));  
            start = i + 1;
        }
    }
    if(start < len)
        s.push_back(substring(start,len - start));  
    return s;
}


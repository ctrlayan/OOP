#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Define two string variables
    string str1, str2;
    
    // Check if both strings are empty
    cout << "--- Checking if strings are empty ---" << endl;
    if (str1.empty())
        cout << "String 1 is empty" << endl;
    else
        cout << "String 1 is not empty" << endl;
    
    if (str2.empty())
        cout << "String 2 is empty" << endl;
    else
        cout << "String 2 is not empty" << endl;
    
    // Assign values
    str1 = "Amjad Khan";
    str2 = "studying at University";
    
    // Determine their lengths
    cout << "\n--- Length of strings ---" << endl;
    cout << "Length of str1: " << str1.length() << endl;
    cout << "Length of str2: " << str2.size() << endl;
    
    // Locate and display character at index 2
    cout << "\n--- Character at index 2 ---" << endl;
    cout << "str1[2]: " << str1[2] << endl;
    cout << "str2[2]: " << str2.at(2) << endl;
    
    // Compare both strings
    cout << "\n--- String comparison ---" << endl;
    if (str1 > str2)
        cout << "str1 is greater than str2" << endl;
    else if (str1 < str2)
        cout << "str2 is greater than str1" << endl;
    else
        cout << "Both strings are equal" << endl;
    
    // Append "is" to the end of str1
    str1.append(" is");
    cout << "After appending 'is' to str1: " << str1 << endl;
    
    // Replace character 'd' with 'q'
    int dIndex = str1.find('d');
    str1.replace(dIndex,1,"q");
    cout << "After replacing 'd' with 'q' in str1: " << str1 << endl;
    
    // Concatenate str2 with str1
    string str3 = str1 + " " + str2;
    cout << "After concatenating str2 with str1: " << str3 << endl;
    cout <<endl;

    // Five additional string functions
    cout << "--- Additional String Functions Demonstration ---" << endl;
    
    // 1. substr() - extract substring
    string sub = str1.substr(0, 5);
    cout << "1. substr(0,5) of str1: " << sub << endl;
    
    // 2. find() - find a substring
    int found = str2.find("University");
    cout << "2. 'University' found at index: " << found << endl;
    
    // 3. replace() - replace characters
    str2.replace(0, 9, "Learning");
    cout << "3. After replace(0,9,'Learning'): " << str2 << endl;
    
    // 4. erase() - erase characters
    str2.erase(8, 5);
    cout << "4. After erase(8,5): " << str2 << endl;
    
    // 5. swap() - swap two strings
    string temp = "Temporary";
    cout << "5. Before swap - str1: " << str1 << "  |  temp: " << temp << endl;
    str1.swap(temp);
    cout << "   After swap  - str1: " << str1 << "  |  temp: " << temp << endl;
    
    return 0;
}
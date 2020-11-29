#include <iostream>
#include <string>

int countQuotes(std::string stringFromUser)
{
    int count = 0;
    for (int i = 0; i < stringFromUser.length(); i++)
    {
        if (stringFromUser[i] == '\'')
            count++;
    }
    return count;
}

std::string returnResult(std::string str,
                         int countQuots)
{
    std::string outputStr = "";
    int searchQuotes = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (countQuots >= 2)
        {
            if (str[i] == '\'')
            {
                ++searchQuotes;
                if (searchQuotes == 1)
                    continue;
                else if (searchQuotes == 2)
                    break;
            }
            
            if (searchQuotes == 1)
            {
                outputStr += str[i];
            }
        }
        else
            break;
    }
    return outputStr;
}

int main()
{
    std::string str;
    std::cin >> str;
    int count = countQuotes(str);
    
    std::cout << returnResult(str, count);

    return 0;
}

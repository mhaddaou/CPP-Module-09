#include <iostream>
#include <string>
#include <math.h>

int main()
{
std::string str = "156.45";
float result= 0.0f;
int len = str.length();
int dotpos = 0;
for (int n = 0; n < len; n++) {
if (str[n] == '.') {
dotpos = len - n - 1;
}
else {
result = result * 10 + (str[n]-'0');
}
}
result /= pow(10,dotpos);
std::cout<<result + 1;
}

// int power(int n,int m)
// {
//     if(m==1)
//         return n;
//     return n*(power(n,m-1));
// }


#include "countWordsInString.h"


unsigned int countWordsInString(string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}
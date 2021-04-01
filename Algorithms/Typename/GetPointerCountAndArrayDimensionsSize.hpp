#ifndef GET_POINTER_COUNT_AND_ARRAY_DIMENSIONS_SIZE_H
#define GET_POINTER_COUNT_AND_ARRAY_DIMENSIONS_SIZE_H
#include <string>
#include <vector>

#define GET_TYPE_STR(TYPENAME) typeid(TYPENAME).name()

/*
What does this function ?
*This function is doing devoting array dimensions size and num declared pointers in 'typename_str'('typename_str' is must be typename of any data type , you must use typeid(typename).name() function and store it the this argument.).
Example :

typedef int **[4][8][3] type;
vector<unsigned> array_dimension_size;
unsigned pointer_count;
GetNumArrayPointers(typeid(type).name() , array_dimension_size , pointer_count)
if we to print array_dimension_size and pointer_count and output is like it:
pointer_count = 2
array_dimension_size = {4 , 8 , 3}
Note :
if you want Use GET_TYPE_STR instead of typeid(type).name() !


*/

/**/

void GetNumArrayPointers(const std::string& typename_str ,
std::vector<unsigned>& array_dimension_size , unsigned& pointer_count){
  for (unsigned i = 0; i < typename_str.size(); i++){
    char __char = typename_str[i];
    if (__char == 'A'){//Check if Typename have an array dimension !
    size_t location = 0x00;//Readed numeric characters count !
    unsigned count = std::stoul(string(&typename_str[i + 1]) , &location , 0);
    if (location){
      if (typename_str[i + location + 1] == '_')
      {array_dimension_size.push_back(count);i += location + 1;}
      else break;
    }
    else break;
    }
    else if (__char == 'P')
    pointer_count++;
    else break;

  }
}


#endif

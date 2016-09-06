#include <iostream>
#include <string>

#include "StreamSource.h"

int main(int argc,char* argv[])
{
   if(argc < 4)
   {
      std::cout << "Incomplete arguments" << std::endl;
      std::cout << "<olstring> <newstring> <filename>" << std::endl;
   }
   else if(argc > 4)
   {
      std::cout << "Extra arguments" << std::endl; 
      std::cout << "<olstring> <newstring> <filename>" << std::endl;
   }
   else
   {
      std::string search_word = static_cast<std::string>(argv[1]);
      std::string replacement_word = static_cast<std::string>(argv[2]);
      
      StreamSource streamObj(static_cast<std::string>(argv[3]),
                             search_word,
                             replacement_word);
   
      int match_count = 0;
      char ch;
      while (!streamObj.get(ch).eof())
      {
         if(!streamObj.currently_replacing() && ch == search_word[match_count])
         {
            ++match_count;
            if(match_count < search_word.size())
               continue;
         }
         if(match_count == search_word.size())
            //we should start getting characters from replacement string
            streamObj.matched_search_string();
         else if(match_count > 0)
            //we should start getting characters from the search string
            streamObj.found_partial_match(match_count, ch); //ch is our pushback
         else
            streamObj.put(ch);
         
         match_count = 0;
      }
   }
   return 0;
}
#include "StreamSource.h"

StreamSource :: StreamSource(const std::string filename,std::string oldstring, 
                              std::string newstring) 
:ns(newstring),os(oldstring),search_get(false),replacement_get(false),
replacement_count(0),string_length(0),search_origin(0),search_count(0),
bufferObj(filename)
{
}

StreamSource :: ~StreamSource()
{
}

bool StreamSource :: currently_replacing()
{
   return replacement_get;
}

void StreamSource :: matched_search_string()
{
   string_length = ns.size();
   replacement_count = ns.size();
}

/*
 * eof()
 + return false if we just retrieved a character from the search string
 or the replacement string. Otherwise return BufferFile's eof()
 */

bool StreamSource :: eof()
{
   if (search_get || replacement_get) 
      return false;
   else
      return bufferObj.eof();
}

StreamSource& StreamSource :: get(char& ch)
{
   if(search_count > 0)
   {
      ch = os[string_length - search_count--];
      search_get = true;
   }
   else if(replacement_count > 0)
   {
      ch = ns[string_length - replacement_count--];
      replacement_get = true;
   }
   else
   {
      search_get = replacement_get = false;
      bufferObj.get(ch);
   }
   return *this;
}

void StreamSource :: put(char& ch)
{
   bufferObj.put(ch);
}

void StreamSource :: found_partial_match(int match_count,char ch)
{
   if(search_get)
      ++search_origin;
   else
   {
      search_origin = 0;
      string_length = match_count;
      bufferObj.do_over(ch);
   }
   put(os[search_origin]);
   search_count = string_length - 1 - search_origin;
}

#ifndef STREAMSOURCE_H
#define STREAMSOURCE_H

#include <fstream>
#include <string>

#include "BufferedFile.h"

class StreamSource
{
public:
   StreamSource(const std::string filename,std::string newstring, std::string oldstring);
   ~StreamSource();
   StreamSource& get(char&);
   void put(char&);
   bool currently_replacing();
   void matched_search_string();
   bool eof();
   void found_partial_match(int,char ch);
   
private:
   BufferedFile bufferObj;
   std::string os;
   std::string ns;
   int replacement_count;
   int search_origin;
   int search_count;
   int string_length;
   bool search_get;
   bool replacement_get; 
};

#endif

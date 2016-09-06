#ifndef BUFFEREDFILE_H
#define BUFFEREDFILE_H

#include <iostream>
#include <fstream>

#include "TrackingDeque.h"

class BufferedFile : public std::fstream
{
public:
   BufferedFile(const std::string&);
   ~BufferedFile();
   BufferedFile& get(char&);
   void put(char&);
   bool eof();
   void do_over(char&);
   void rawget(char&);
   
private:
   TrackingDeque<char> tdObj;
   std::streampos getpos;
   std::streampos putpos;
   bool end_of_file;
   std::string filename;
};

#endif
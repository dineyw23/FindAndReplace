#include "BufferedFile.h"
#include <unistd.h>

BufferedFile :: BufferedFile(const std::string& file)
:end_of_file(false),getpos(0), putpos(0),filename(file)
{
   std::fstream::open(file, std::ios::out | std::ios::in);
}

BufferedFile :: ~BufferedFile()
{
   std::fstream::close();
   truncate(filename.c_str(), putpos);
}

void BufferedFile :: do_over(char& ch)
{
   //just a one-liner, push ch onto the front of the queue
   tdObj.push_front(ch);
}

void BufferedFile :: put(char& ch)
{
   if(getpos == putpos && !end_of_file)
   {
      char temp;
      rawget(temp);
      tdObj.push_back(temp);
   }
   //To put into the file.
   seekp(putpos);
   std::fstream::put(ch);
   putpos = std::fstream::tellp();
}

void BufferedFile::rawget(char& ch)
{
   seekg(getpos);
   std::fstream::get(ch);
   //Check end of file -> Very imp
   if (std::fstream::eof())
   {
      std::fstream::clear();
      end_of_file = true;
   }
   getpos = std::fstream::tellg();
}

BufferedFile& BufferedFile :: get(char& ch)
{//if the queue isn't empty, assign front of queue to ch
   if(!tdObj.empty())
   {
      ch = tdObj.front();
      tdObj.pop_front();
   }
   else
   {// else get from the file
      rawget(ch);
   }
   return *this;
}

bool BufferedFile :: eof()
{
   if (!tdObj.empty()) 
      return false;
   else
      return end_of_file;
}




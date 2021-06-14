#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

#include <string>

using namespace std;

class FileNotFoundException {
   private:
    string message;

   public:
    FileNotFoundException(const string& message);
    string get_message();
    ~FileNotFoundException();
};

FileNotFoundException::FileNotFoundException(const string& message) {
    this->message = message;
}

string FileNotFoundException::get_message() {
    return this->message;
}

FileNotFoundException::~FileNotFoundException() {
}

#endif
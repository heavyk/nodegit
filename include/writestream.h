#ifndef GITWRITESTREAM_H
#define GITWRITESTREAM_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitWritestream : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_writestream *GetValue();
    git_writestream **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitWritestream(git_writestream *raw, bool selfFreeing);
    ~GitWritestream();
 
    static NAN_METHOD(JSNewFunction);

    git_writestream *raw;
};

#endif

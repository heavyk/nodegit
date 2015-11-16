#ifndef GITTIME_H
#define GITTIME_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitTime : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_time *GetValue();
    git_time **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitTime(git_time *raw, bool selfFreeing);
    ~GitTime();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Time);
    static NAN_METHOD(Offset);
    git_time *raw;
};

#endif

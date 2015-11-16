#ifndef GITINDEXTIME_H
#define GITINDEXTIME_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitIndexTime : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_index_time *GetValue();
    git_index_time **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitIndexTime(git_index_time *raw, bool selfFreeing);
    ~GitIndexTime();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Seconds);
    static NAN_METHOD(Nanoseconds);
    git_index_time *raw;
};

#endif

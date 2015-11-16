#ifndef GITPUSH_H
#define GITPUSH_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/push_options.h"
// Forward declaration.
struct git_push {
};

using namespace node;
using namespace v8;

class GitPush : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_push *GetValue();
    git_push **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

     

  private:


    GitPush(git_push *raw, bool selfFreeing);
    ~GitPush();
     
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(InitOptions);
    git_push *raw;
};

#endif

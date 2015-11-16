#ifndef GITPUSHUPDATE_H
#define GITPUSHUPDATE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"

using namespace node;
using namespace v8;

class GitPushUpdate : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_push_update *GetValue();
    git_push_update **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitPushUpdate(git_push_update *raw, bool selfFreeing);
    ~GitPushUpdate();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(SrcRefname);
    static NAN_METHOD(DstRefname);
    static NAN_METHOD(Src);
    static NAN_METHOD(Dst);
    git_push_update *raw;
};

#endif

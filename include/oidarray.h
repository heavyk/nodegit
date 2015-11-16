#ifndef GITOIDARRAY_H
#define GITOIDARRAY_H
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

class GitOidarray : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_oidarray *GetValue();
    git_oidarray **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

    

  private:


    GitOidarray(git_oidarray *raw, bool selfFreeing);
    ~GitOidarray();
    
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Ids);
    static NAN_METHOD(Count);

    static NAN_METHOD(Free);
    git_oidarray *raw;
};

#endif

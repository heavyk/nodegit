#ifndef GITREBASEOPERATION_H
#define GITREBASEOPERATION_H
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

class GitRebaseOperation : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_rebase_operation *GetValue();
    git_rebase_operation **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitRebaseOperation(git_rebase_operation *raw, bool selfFreeing);
    ~GitRebaseOperation();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Type);
    static NAN_METHOD(Id);
    static NAN_METHOD(Exec);
    git_rebase_operation *raw;
};

#endif

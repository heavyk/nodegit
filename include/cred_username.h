#ifndef GITCREDUSERNAME_H
#define GITCREDUSERNAME_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/cred.h"

using namespace node;
using namespace v8;

class GitCredUsername : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cred_username *GetValue();
    git_cred_username **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCredUsername(git_cred_username *raw, bool selfFreeing);
    ~GitCredUsername();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Parent);
    static NAN_METHOD(Username);
    git_cred_username *raw;
};

#endif

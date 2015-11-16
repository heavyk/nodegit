#ifndef GITCREDDEFAULT_H
#define GITCREDDEFAULT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitCredDefault : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cred_default *GetValue();
    git_cred_default **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCredDefault(git_cred_default *raw, bool selfFreeing);
    ~GitCredDefault();
 
    static NAN_METHOD(JSNewFunction);

    git_cred_default *raw;
};

#endif

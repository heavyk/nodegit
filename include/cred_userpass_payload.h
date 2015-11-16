#ifndef GITCREDUSERPASSPAYLOAD_H
#define GITCREDUSERPASSPAYLOAD_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/cred_helpers.h>
}


using namespace node;
using namespace v8;

class GitCredUserpassPayload : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cred_userpass_payload *GetValue();
    git_cred_userpass_payload **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitCredUserpassPayload(git_cred_userpass_payload *raw, bool selfFreeing);
    ~GitCredUserpassPayload();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Username);
    static NAN_METHOD(Password);
    git_cred_userpass_payload *raw;
};

#endif

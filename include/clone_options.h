#ifndef GITCLONEOPTIONS_H
#define GITCLONEOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/checkout_options.h"
  #include "../include/fetch_options.h"
 
using namespace node;
using namespace v8;

class GitCloneOptions : public Nan::ObjectWrap {
  public:
    GitCloneOptions(git_clone_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_clone_options *GetValue();
    git_clone_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

                 
  private:
    GitCloneOptions();
    ~GitCloneOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

             Nan::Persistent<Object> checkout_opts;
  
        static NAN_GETTER(GetCheckoutOpts);
        static NAN_SETTER(SetCheckoutOpts);

             Nan::Persistent<Object> fetch_opts;
  
        static NAN_GETTER(GetFetchOpts);
        static NAN_SETTER(SetFetchOpts);

   
        static NAN_GETTER(GetBare);
        static NAN_SETTER(SetBare);

  
        static NAN_GETTER(GetLocal);
        static NAN_SETTER(SetLocal);

   
        static NAN_GETTER(GetCheckoutBranch);
        static NAN_SETTER(SetCheckoutBranch);

             Nan::Persistent<Value> repository_cb_payload;
  
        static NAN_GETTER(GetRepositoryCbPayload);
        static NAN_SETTER(SetRepositoryCbPayload);

             Nan::Persistent<Value> remote_cb_payload;
  
        static NAN_GETTER(GetRemoteCbPayload);
        static NAN_SETTER(SetRemoteCbPayload);

  
    git_clone_options *raw;
};

#endif

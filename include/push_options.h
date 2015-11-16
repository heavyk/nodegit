#ifndef GITPUSHOPTIONS_H
#define GITPUSHOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/remote_callbacks.h"
 
using namespace node;
using namespace v8;

class GitPushOptions : public Nan::ObjectWrap {
  public:
    GitPushOptions(git_push_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_push_options *GetValue();
    git_push_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

       
  private:
    GitPushOptions();
    ~GitPushOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetPbParallelism);
        static NAN_SETTER(SetPbParallelism);

             Nan::Persistent<Object> callbacks;
  
        static NAN_GETTER(GetCallbacks);
        static NAN_SETTER(SetCallbacks);

  
    git_push_options *raw;
};

#endif

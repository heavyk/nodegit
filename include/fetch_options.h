#ifndef GITFETCHOPTIONS_H
#define GITFETCHOPTIONS_H
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

class GitFetchOptions : public Nan::ObjectWrap {
  public:
    GitFetchOptions(git_fetch_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_fetch_options *GetValue();
    git_fetch_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

           
  private:
    GitFetchOptions();
    ~GitFetchOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

             Nan::Persistent<Object> callbacks;
  
        static NAN_GETTER(GetCallbacks);
        static NAN_SETTER(SetCallbacks);

  
        static NAN_GETTER(GetPrune);
        static NAN_SETTER(SetPrune);

   
        static NAN_GETTER(GetUpdateFetchhead);
        static NAN_SETTER(SetUpdateFetchhead);

  
        static NAN_GETTER(GetDownloadTags);
        static NAN_SETTER(SetDownloadTags);

  
    git_fetch_options *raw;
};

#endif

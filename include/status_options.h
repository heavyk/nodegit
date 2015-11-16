#ifndef GITSTATUSOPTIONS_H
#define GITSTATUSOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/strarray.h"
 
using namespace node;
using namespace v8;

class GitStatusOptions : public Nan::ObjectWrap {
  public:
    GitStatusOptions(git_status_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_status_options *GetValue();
    git_status_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

         
  private:
    GitStatusOptions();
    ~GitStatusOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

  
        static NAN_GETTER(GetShow);
        static NAN_SETTER(SetShow);

  
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

             Nan::Persistent<Object> pathspec;
  
        static NAN_GETTER(GetPathspec);
        static NAN_SETTER(SetPathspec);

  
    git_status_options *raw;
};

#endif

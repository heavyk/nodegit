#ifndef GITREBASEOPTIONS_H
#define GITREBASEOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/checkout_options.h"
 
using namespace node;
using namespace v8;

class GitRebaseOptions : public Nan::ObjectWrap {
  public:
    GitRebaseOptions(git_rebase_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_rebase_options *GetValue();
    git_rebase_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

         
  private:
    GitRebaseOptions();
    ~GitRebaseOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetQuiet);
        static NAN_SETTER(SetQuiet);

   
        static NAN_GETTER(GetRewriteNotesRef);
        static NAN_SETTER(SetRewriteNotesRef);

             Nan::Persistent<Object> checkout_options;
  
        static NAN_GETTER(GetCheckoutOptions);
        static NAN_SETTER(SetCheckoutOptions);

  
    git_rebase_options *raw;
};

#endif

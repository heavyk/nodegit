#ifndef GITREVERTOPTIONS_H
#define GITREVERTOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/merge_options.h"
  #include "../include/checkout_options.h"
 
using namespace node;
using namespace v8;

class GitRevertOptions : public Nan::ObjectWrap {
  public:
    GitRevertOptions(git_revert_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_revert_options *GetValue();
    git_revert_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

         
  private:
    GitRevertOptions();
    ~GitRevertOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetMainline);
        static NAN_SETTER(SetMainline);

             Nan::Persistent<Object> merge_opts;
  
        static NAN_GETTER(GetMergeOpts);
        static NAN_SETTER(SetMergeOpts);

             Nan::Persistent<Object> checkout_opts;
  
        static NAN_GETTER(GetCheckoutOpts);
        static NAN_SETTER(SetCheckoutOpts);

  
    git_revert_options *raw;
};

#endif

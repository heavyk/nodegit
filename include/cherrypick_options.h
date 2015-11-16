#ifndef GITCHERRYPICKOPTIONS_H
#define GITCHERRYPICKOPTIONS_H
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

class GitCherrypickOptions : public Nan::ObjectWrap {
  public:
    GitCherrypickOptions(git_cherrypick_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_cherrypick_options *GetValue();
    git_cherrypick_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

         
  private:
    GitCherrypickOptions();
    ~GitCherrypickOptions();

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

  
    git_cherrypick_options *raw;
};

#endif

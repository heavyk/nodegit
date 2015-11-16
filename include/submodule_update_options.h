#ifndef GITSUBMODULEUPDATEOPTIONS_H
#define GITSUBMODULEUPDATEOPTIONS_H
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

class GitSubmoduleUpdateOptions : public Nan::ObjectWrap {
  public:
    GitSubmoduleUpdateOptions(git_submodule_update_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_submodule_update_options *GetValue();
    git_submodule_update_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

         
  private:
    GitSubmoduleUpdateOptions();
    ~GitSubmoduleUpdateOptions();

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

   
        static NAN_GETTER(GetCloneCheckoutStrategy);
        static NAN_SETTER(SetCloneCheckoutStrategy);

  
    git_submodule_update_options *raw;
};

#endif

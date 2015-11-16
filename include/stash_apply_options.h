#ifndef GITSTASHAPPLYOPTIONS_H
#define GITSTASHAPPLYOPTIONS_H
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

class GitStashApplyOptions : public Nan::ObjectWrap {
  public:
    GitStashApplyOptions(git_stash_apply_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_stash_apply_options *GetValue();
    git_stash_apply_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

                static int progress_cb_cppCallback (
              git_stash_apply_progress_t progress
                ,
               void * payload
            );

          static void progress_cb_async(uv_async_t* req, int status);
          static void progress_cb_setupAsyncPromisePolling(uv_async_t* req);
          static void progress_cb_asyncPromisePolling(uv_async_t* req, int status);
          struct ProgressCbBaton {
              git_stash_apply_progress_t progress;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
     
  private:
    GitStashApplyOptions();
    ~GitStashApplyOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

  
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

             Nan::Persistent<Object> checkout_options;
  
        static NAN_GETTER(GetCheckoutOptions);
        static NAN_SETTER(SetCheckoutOptions);

             Nan::Callback* progress_cb;
  
        static NAN_GETTER(GetProgressCb);
        static NAN_SETTER(SetProgressCb);

             Nan::Persistent<Value> progress_payload;
  
        static NAN_GETTER(GetProgressPayload);
        static NAN_SETTER(SetProgressPayload);

  
    git_stash_apply_options *raw;
};

#endif

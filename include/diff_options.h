#ifndef GITDIFFOPTIONS_H
#define GITDIFFOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/strarray.h"
  #include "../include/diff.h"
  #include "../include/diff_delta.h"
 
using namespace node;
using namespace v8;

class GitDiffOptions : public Nan::ObjectWrap {
  public:
    GitDiffOptions(git_diff_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_options *GetValue();
    git_diff_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

                  static int notify_cb_cppCallback (
              const git_diff * diff_so_far
                ,
               git_diff_delta * delta_to_add
                ,
               const char * matched_pathspec
                ,
               void * payload
            );

          static void notify_cb_async(uv_async_t* req, int status);
          static void notify_cb_setupAsyncPromisePolling(uv_async_t* req);
          static void notify_cb_asyncPromisePolling(uv_async_t* req, int status);
          struct NotifyCbBaton {
              const git_diff * diff_so_far;
              git_diff_delta * delta_to_add;
              const char * matched_pathspec;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
                 
  private:
    GitDiffOptions();
    ~GitDiffOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

  
        static NAN_GETTER(GetIgnoreSubmodules);
        static NAN_SETTER(SetIgnoreSubmodules);

             Nan::Persistent<Object> pathspec;
  
        static NAN_GETTER(GetPathspec);
        static NAN_SETTER(SetPathspec);

             Nan::Callback* notify_cb;
  
        static NAN_GETTER(GetNotifyCb);
        static NAN_SETTER(SetNotifyCb);

             Nan::Persistent<Value> notify_payload;
  
        static NAN_GETTER(GetNotifyPayload);
        static NAN_SETTER(SetNotifyPayload);

   
        static NAN_GETTER(GetContextLines);
        static NAN_SETTER(SetContextLines);

   
        static NAN_GETTER(GetInterhunkLines);
        static NAN_SETTER(SetInterhunkLines);

   
        static NAN_GETTER(GetIdAbbrev);
        static NAN_SETTER(SetIdAbbrev);

  
        static NAN_GETTER(GetMaxSize);
        static NAN_SETTER(SetMaxSize);

   
        static NAN_GETTER(GetOldPrefix);
        static NAN_SETTER(SetOldPrefix);

   
        static NAN_GETTER(GetNewPrefix);
        static NAN_SETTER(SetNewPrefix);

  
    git_diff_options *raw;
};

#endif

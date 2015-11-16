#ifndef GITCHECKOUTOPTIONS_H
#define GITCHECKOUTOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/diff_file.h"
  #include "../include/strarray.h"
  #include "../include/tree.h"
  #include "../include/index.h"
 
using namespace node;
using namespace v8;

class GitCheckoutOptions : public Nan::ObjectWrap {
  public:
    GitCheckoutOptions(git_checkout_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_checkout_options *GetValue();
    git_checkout_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

                        static int notify_cb_cppCallback (
              git_checkout_notify_t why
                ,
               const char * path
                ,
               const git_diff_file * baseline
                ,
               const git_diff_file * target
                ,
               const git_diff_file * workdir
                ,
               void * payload
            );

          static void notify_cb_async(uv_async_t* req, int status);
          static void notify_cb_setupAsyncPromisePolling(uv_async_t* req);
          static void notify_cb_asyncPromisePolling(uv_async_t* req, int status);
          struct NotifyCbBaton {
              git_checkout_notify_t why;
              const char * path;
              const git_diff_file * baseline;
              const git_diff_file * target;
              const git_diff_file * workdir;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
              static int progress_cb_cppCallback (
              const char * path
                ,
               size_t completed_steps
                ,
               size_t total_steps
                ,
               void * payload
            );

          static void progress_cb_async(uv_async_t* req, int status);
          static void progress_cb_setupAsyncPromisePolling(uv_async_t* req);
          static void progress_cb_asyncPromisePolling(uv_async_t* req, int status);
          struct ProgressCbBaton {
              const char * path;
              size_t completed_steps;
              size_t total_steps;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
                            static int perfdata_cb_cppCallback (
              const git_checkout_perfdata * perfdata
                ,
               void * payload
            );

          static void perfdata_cb_async(uv_async_t* req, int status);
          static void perfdata_cb_setupAsyncPromisePolling(uv_async_t* req);
          static void perfdata_cb_asyncPromisePolling(uv_async_t* req, int status);
          struct PerfdataCbBaton {
              const git_checkout_perfdata * perfdata;
              void * payload;
 
            uv_async_t req;
            int result;
            Nan::Persistent<Object> promise;
            bool done;
          };
     
  private:
    GitCheckoutOptions();
    ~GitCheckoutOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetCheckoutStrategy);
        static NAN_SETTER(SetCheckoutStrategy);

   
        static NAN_GETTER(GetDisableFilters);
        static NAN_SETTER(SetDisableFilters);

   
        static NAN_GETTER(GetDirMode);
        static NAN_SETTER(SetDirMode);

   
        static NAN_GETTER(GetFileMode);
        static NAN_SETTER(SetFileMode);

   
        static NAN_GETTER(GetFileOpenFlags);
        static NAN_SETTER(SetFileOpenFlags);

   
        static NAN_GETTER(GetNotifyFlags);
        static NAN_SETTER(SetNotifyFlags);

             Nan::Callback* notify_cb;
  
        static NAN_GETTER(GetNotifyCb);
        static NAN_SETTER(SetNotifyCb);

             Nan::Persistent<Value> notify_payload;
  
        static NAN_GETTER(GetNotifyPayload);
        static NAN_SETTER(SetNotifyPayload);

             Nan::Callback* progress_cb;
  
        static NAN_GETTER(GetProgressCb);
        static NAN_SETTER(SetProgressCb);

             Nan::Persistent<Value> progress_payload;
  
        static NAN_GETTER(GetProgressPayload);
        static NAN_SETTER(SetProgressPayload);

             Nan::Persistent<Object> paths;
  
        static NAN_GETTER(GetPaths);
        static NAN_SETTER(SetPaths);

             Nan::Persistent<Object> baseline;
  
        static NAN_GETTER(GetBaseline);
        static NAN_SETTER(SetBaseline);

             Nan::Persistent<Object> baseline_index;
  
        static NAN_GETTER(GetBaselineIndex);
        static NAN_SETTER(SetBaselineIndex);

   
        static NAN_GETTER(GetTargetDirectory);
        static NAN_SETTER(SetTargetDirectory);

   
        static NAN_GETTER(GetAncestorLabel);
        static NAN_SETTER(SetAncestorLabel);

   
        static NAN_GETTER(GetOurLabel);
        static NAN_SETTER(SetOurLabel);

   
        static NAN_GETTER(GetTheirLabel);
        static NAN_SETTER(SetTheirLabel);

             Nan::Callback* perfdata_cb;
  
        static NAN_GETTER(GetPerfdataCb);
        static NAN_SETTER(SetPerfdataCb);

             Nan::Persistent<Value> perfdata_payload;
  
        static NAN_GETTER(GetPerfdataPayload);
        static NAN_SETTER(SetPerfdataPayload);

  
    git_checkout_options *raw;
};

#endif
